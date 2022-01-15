#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fms.h"

static const char* DIV = "---------------------------------------------------------------------";

double Sin_Deg(double x) {
    return sin( x * M_PI / 180.0 );
}

double Cos_Deg(double x) {
    return cos( x * M_PI / 180.0 );
}

double Calculate_Degree(double lat1, double lon1, double lat2, double lon2) {
    return 6378.388 * acos( Sin_Deg(lat1) * Sin_Deg(lat2) + Cos_Deg(lat1) * Cos_Deg(lat2) * Cos_Deg(lon2 - lon1) );
}

//  Converts raw minutes to Time
static Time _minutes_to_time(unsigned int minutes) {
    Time time = { minutes / 60, minutes % 60 };
    return time;
}

//  Converts Time to raw minutes
static unsigned int _time_to_minutes(Time* time) {
    return time->hour * 60 + time->minute;
}

//  Calculates the duration between two Time points
static Time _calculate_duration(Time* start, Time* end) {
    return _minutes_to_time( _time_to_minutes(end) - _time_to_minutes(start) );
}

void Generate_Distance_Table(FMS* p_FMS) {

    for(Airline* airline = p_FMS->p_Airline; airline != p_FMS->p_Airline + p_FMS->cnt_Airline; airline++) {

        printf("%10s|%10s|%4s|%4s|%8s\n", 
            "Airline", 
            "Flight No.", 
            "from", 
            "to", 
            "Distance"
        );

        printf("%.10s|%.10s|%.4s|%.4s|%.8s\n", DIV, DIV, DIV, DIV, DIV);

        char* _table_Airline = airline->airlineName;
        char* _resume_Airline = _table_Airline;

        for(Airplane* airplane = airline->p_Airplane; airplane != airline->p_Airplane + airline->cnt_Airplane; airplane++) {

            char* _resume_Airplane_Name = airplane->airplaneName;
            double _resume_Distance_Total = 0;

            for(FlightPath* flightPath = airplane->p_FlightPath; flightPath != airplane->p_FlightPath + airplane->cnt_FlightPath; flightPath++) {

                char* _table_FlightNo = flightPath->flightPathName;
                char* _table_From = flightPath->p_DepartureAirport->iata;
                char* _table_To = flightPath->p_ArrivalAirport->iata;
                double _table_Distance = Calculate_Degree(
                    flightPath->p_DepartureAirport->latitude.degree,
                    flightPath->p_DepartureAirport->longitude.degree,
                    flightPath->p_ArrivalAirport->latitude.degree,
                    flightPath->p_ArrivalAirport->longitude.degree
                );

                printf("%10s|%10s|%4s|%4s|%6.2lf\n",
                    _table_Airline,
                    _table_FlightNo,
                    _table_From,
                    _table_To,
                    _table_Distance
                );

                _resume_Distance_Total += _table_Distance;
            }

            printf("\nTotal flight distance for %s %s is %.2lf\n\n",
                _resume_Airline,
                _resume_Airplane_Name,
                _resume_Distance_Total
            );
        }
    }
}

void Generate_Duration_Table(FMS* p_FMS) {

    for(Airline* airline = p_FMS->p_Airline; airline != p_FMS->p_Airline + p_FMS->cnt_Airline; airline++) {

        printf("%10s|%10s|%4s|%4s|%8s\n",
            "Airline",
            "Flight No.",
            "from",
            "to",
            "Duration"
        );

        printf("%.10s|%.10s|%.4s|%.4s|%.8s\n", DIV, DIV, DIV, DIV, DIV);

        char* _table_Airline = airline->airlineName;
        char* _resume_Airline = _table_Airline;

        for(Airplane* airplane = airline->p_Airplane; airplane != airline->p_Airplane + airline->cnt_Airplane; airplane++) {

            char* _resume_Airplane_Name = airplane->airplaneName;
            unsigned int _time_minutes_Total = 0;

            for(FlightPath* flightPath = airplane->p_FlightPath; flightPath != airplane->p_FlightPath + airplane->cnt_FlightPath; flightPath++) {

                char* _table_FlightNo = flightPath->flightPathName;
                char* _table_From = flightPath->p_DepartureAirport->iata;
                char* _table_To = flightPath->p_ArrivalAirport->iata;

                Time _table_Duration = _calculate_duration(&flightPath->departure, &flightPath->arrival);

                printf("%10s|%10s|%4s|%4s|%3s%02d:%02d\n",
                    _table_Airline,
                    _table_FlightNo,
                    _table_From,
                    _table_To,
                    " ",
                    _table_Duration.hour, _table_Duration.minute
                );

                _time_minutes_Total += _time_to_minutes(&_table_Duration);
            }

            Time _resume_Time_Total = _minutes_to_time(_time_minutes_Total);
            printf("\nTotal flight Time for %s %s is %02d:%02d\n\n", 
                _resume_Airline,
                _resume_Airplane_Name,
                _resume_Time_Total.hour, _resume_Time_Total.minute
            );
        }
    }

}

void Generate_Time_Table(FMS* p_FMS) {

    printf("%10s|%10s|%4s|%4s|%9s|%8s|%8s\n", 
        "Airline", 
        "Flight No.", 
        "from", 
        "to", 
        "Departure", 
        "Arrival", 
        "Airplane"
    );

    printf("%.10s|%.10s|%.4s|%.4s|%.9s|%.8s|%.8s\n", DIV, DIV, DIV, DIV, DIV, DIV, DIV);

    for(Airline* airline = p_FMS->p_Airline; airline != p_FMS->p_Airline + p_FMS->cnt_Airline; airline++) {

        char* _table_Airline = airline->airlineName;

        for(Airplane* airplane = airline->p_Airplane; airplane != airline->p_Airplane + airline->cnt_Airplane; airplane++) {

            char* _table_Airplane = airplane->airVehicleRegistration;

            for(FlightPath* flightPath = airplane->p_FlightPath; flightPath != airplane->p_FlightPath + airplane->cnt_FlightPath; flightPath++) {

                char* _table_FlightNo = flightPath->flightPathName;
                Time* _table_Departure = &flightPath->departure;
                Time* _table_Arrival = &flightPath->arrival;
                char* _table_From = flightPath->p_DepartureAirport->iata;
                char* _table_To = flightPath->p_ArrivalAirport->iata;

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