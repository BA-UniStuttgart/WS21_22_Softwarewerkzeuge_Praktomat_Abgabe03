#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fms.h"

//  Divider used for printing the Tables
static const char* DIV = "---------------------------------------------------------------------";

//  Converts decimal degrees to radians and returns the sin value
//  @x Decimal degree value
//  @return sin value of x converted to radians
double Sin_Deg(double x) {
    return sin( (x) * M_PI / 180.0 );
}

//  Converts decimal degrees to radians and returns the cos value
//  @x Decimal degree value
//  @return cos value of x converted to radians
double Cos_Deg(double x) {
    return cos( (x) * M_PI / 180.0 );
}

//  Calculates the distance between two pairs of latitudes and longitudes
//  @lat1 Latitude value in decimal degrees
//  @lon1 Longitude value in decimal degrees
//  @lat2 Latitude value in decimal degrees
//  @lon2 Longitude value in decimal degrees
//  @return Distance between both points
double Calculate_Degree(double lat1, double lon1, double lat2, double lon2) {
    return 6378.388 * acos( Sin_Deg(lat1) * Sin_Deg(lat2) + Cos_Deg(lat1) * Cos_Deg(lat2) * Cos_Deg(lon2 - lon1) );
}

//  Converts Coordinates ({degree, minute, second}) to decimal degrees
//  @coordinate The Coordinate
//  @return Coordinate as decimal degrees
static double _coordinate_to_degree(const Coordinate* coordinate) {
    return coordinate->degree + ( coordinate->minute / 60 ) + ( coordinate->second / 3600 );
}

//  Converts raw minutes to Time ({hour, minute})
//  @minutes Raw minutes value
//  @return The corresponding Time value
static Time _minutes_to_time(unsigned int minutes) {
    Time time = { minutes / 60, minutes % 60 };
    return time;
}

//  Converts Time ({hour, minute}) to raw minutes
//  @time Time value
//  @return The corresponding minutes value
static unsigned int _time_to_minutes(const Time* time) {
    return time->hour * 60 + time->minute;
}

//  Calculates the duration between two Time points
//  @start Time Start Point
//  @end Time End Point
//  @return The Duration
static Time _calculate_duration(const Time* start, const Time* end) {
    return _minutes_to_time( _time_to_minutes(end) - _time_to_minutes(start) );
}

void Generate_Distance_Table(const FMS* p_FMS) {

    //  Iterate over each Airline contained in FMS
    for(const Airline* airline = p_FMS->p_Airline; airline != p_FMS->p_Airline + p_FMS->cnt_Airline; airline++) {
        
        //  Table Lables
        printf("%10s|%10s|%4s|%4s|%8s\n", 
            "Airline", 
            "Flight No.", 
            "from", 
            "to", 
            "Distance"
        );

        //  Dividers
        printf("%.10s|%.10s|%.4s|%.4s|%.8s\n", DIV, DIV, DIV, DIV, DIV);

        const char* _table_Airline = airline->airlineName;  //  Table Value for Key "Airline"
        const char* _resume_Airline = _table_Airline;       //  Resume Value for "Airline"

        //  Iterate over each Airplane contained in Airline
        for(const Airplane* airplane = airline->p_Airplane; airplane != airline->p_Airplane + airline->cnt_Airplane; airplane++) {
            
            const char* _resume_Airplane_Name = airplane->airplaneName; //  Resume Value for the Airplane Name
            double _resume_Distance_Total = 0;                          //  Resume Value for the Total Distance travelled

            //  Iterate over each Flightpath contained in Airplane
            for(const FlightPath* flightPath = airplane->p_FlightPath; flightPath != airplane->p_FlightPath + airplane->cnt_FlightPath; flightPath++) {

                char* _table_FlightNo = flightPath->flightPathName;         //  Table Value for Key "Flight No"
                char* _table_From = flightPath->p_DepartureAirport->iata;   //  Table Value for Key "from"
                char* _table_To = flightPath->p_ArrivalAirport->iata;       //  Table Value for Key "to"

                //  Table Value for Key "Distance"
                //  Convert latitude & longitude to decimal degrees, then calculate the distance 
                double _table_Distance = Calculate_Degree(
                    _coordinate_to_degree(&flightPath->p_DepartureAirport->latitude),
                    _coordinate_to_degree(&flightPath->p_DepartureAirport->longitude),
                    _coordinate_to_degree(&flightPath->p_ArrivalAirport->latitude),
                    _coordinate_to_degree(&flightPath->p_ArrivalAirport->longitude)
                );

                printf("%10s|%10s|%4s|%4s|%1s%5.2lf\n",
                    _table_Airline,
                    _table_FlightNo,
                    _table_From,
                    _table_To,
                    " ",
                    _table_Distance
                );

                //  Update the Total Distance
                _resume_Distance_Total += _table_Distance;
            }

            //  Print the Resume
            printf("\nTotal flight distance for %s %s is %.2lf\n\n",
                _resume_Airline,
                _resume_Airplane_Name,
                _resume_Distance_Total
            );
        }
    }
}

void Generate_Duration_Table(const FMS* p_FMS) {

    //  Iterate over each Airline contained in FMS
    for(Airline* airline = p_FMS->p_Airline; airline != p_FMS->p_Airline + p_FMS->cnt_Airline; airline++) {
        
        //  Table Lables
        printf("%10s|%10s|%4s|%4s|%8s\n",
            "Airline",
            "Flight No.",
            "from",
            "to",
            "Duration"
        );

        //  Dividers
        printf("%.10s|%.10s|%.4s|%.4s|%.8s\n", DIV, DIV, DIV, DIV, DIV);

        const char* _table_Airline = airline->airlineName;    //  Table Value for Key "Airline"
        const char* _resume_Airline = _table_Airline;         //  Resume Value for "Airline"

        //  Iterate over each Airplane contained in Airline
        for(const Airplane* airplane = airline->p_Airplane; airplane != airline->p_Airplane + airline->cnt_Airplane; airplane++) {

            const char* _resume_Airplane_Name = airplane->airplaneName; // Resume Value for "Airplane Name"
            unsigned int _time_minutes_Total = 0;                       // Total Duration in minutes

            //  Iterate over each Flightpath contained in Airplane
            for(const FlightPath* flightPath = airplane->p_FlightPath; flightPath != airplane->p_FlightPath + airplane->cnt_FlightPath; flightPath++) {

                const char* _table_FlightNo = flightPath->flightPathName;       //  Table Value for Key "Flight No"
                const char* _table_From = flightPath->p_DepartureAirport->iata; //  Table Value for Key "from"
                const char* _table_To = flightPath->p_ArrivalAirport->iata;     //  Table Value for Key "to"

                //  Table Value for Key "Duration"
                Time _table_Duration = _calculate_duration(&flightPath->departure, &flightPath->arrival);

                printf("%10s|%10s|%4s|%4s|%2s%02d:%02d\n",
                    _table_Airline,
                    _table_FlightNo,
                    _table_From,
                    _table_To,
                    " ",
                    _table_Duration.hour, _table_Duration.minute
                );

                //  Update the Total Time
                _time_minutes_Total += _time_to_minutes(&_table_Duration);
            }

            //  Convert the Total Time in minutes to a Time Point
            Time _resume_Time_Total = _minutes_to_time(_time_minutes_Total);

            //  Print the Resume
            printf("\nTotal flight Time for %s %s is %02d:%02d\n\n", 
                _resume_Airline,
                _resume_Airplane_Name,
                _resume_Time_Total.hour, _resume_Time_Total.minute
            );
        }
    }

}

void Generate_Time_Table(const FMS* p_FMS) {

    //  Table Lables
    printf("%10s|%10s|%4s|%4s|%9s|%8s|%8s\n", 
        "Airline", 
        "Flight No.", 
        "from", 
        "to", 
        "Departure", 
        "Arrival", 
        "Airplane"
    );

    //  Dividers
    printf("%.10s|%.10s|%.4s|%.4s|%.9s|%.8s|%.8s\n", DIV, DIV, DIV, DIV, DIV, DIV, DIV);

    //  Iterate over each Airline contained in FMS
    for(const Airline* airline = p_FMS->p_Airline; airline != p_FMS->p_Airline + p_FMS->cnt_Airline; airline++) {

        const char* _table_Airline = airline->airlineName; //  Table Value for Key "Airline"

        //  Iterate over each Airplane contained in Airline
        for(const Airplane* airplane = airline->p_Airplane; airplane != airline->p_Airplane + airline->cnt_Airplane; airplane++) {

            const char* _table_Airplane = airplane->airVehicleRegistration; //  Table Value for Key "Airplane"

            //  Iterate over each Flightpath contained in Airplane
            for(const FlightPath* flightPath = airplane->p_FlightPath; flightPath != airplane->p_FlightPath + airplane->cnt_FlightPath; flightPath++) {

                const char* _table_FlightNo = flightPath->flightPathName;       //  Table Value for Key "Flight No"
                const Time* _table_Departure = &flightPath->departure;          //  Table Value for Key "Departure"
                const Time* _table_Arrival = &flightPath->arrival;              //  Table Value for Key "Arrival"
                const char* _table_From = flightPath->p_DepartureAirport->iata; //  Table Value for Key "from"
                const char* _table_To = flightPath->p_ArrivalAirport->iata;     //  Table Value for Key "to"

                printf("%10s|%10s|%4s|%4s|%4s%02d:%02d|%3s%02d:%02d|%8s\n",
                    _table_Airline,
                    _table_FlightNo,
                    _table_From,
                    _table_To,
                    " ", _table_Departure->hour, _table_Departure->minute,
                    " ", _table_Arrival->hour, _table_Arrival->minute,
                    _table_Airplane
                );
            }
        }
    }
}