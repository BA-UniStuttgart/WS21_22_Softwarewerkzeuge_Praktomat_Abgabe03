#ifndef _FMS_H_
#define _FMS_H_

typedef struct Coordinate {
    int degree;
    int minute;
    int second;
} Coordinate;

typedef struct Time {
    unsigned char hour;
    unsigned char minute;
} Time;

typedef struct Airport {
    char* icao;
    char* iata;
    Coordinate latitude;
    Coordinate longitude;
    float heightAMSL;
} Airport;

typedef struct FlightPath {
    char* flightPathName;
    Airport* p_DepartureAirport;
    Airport* p_ArrivalAirport;
    Time departure;
    Time arrival;
} FlightPath;

typedef struct Airplane {
    char* airplaneName;
    char* airVehicleRegistration;
    FlightPath* p_FlightPath;
    unsigned int cnt_FlightPath;
} Airplane;

typedef struct Airline {
    char* airlineName;
    Airplane* p_Airplane;
    unsigned int cnt_Airplane;
} Airline;

typedef struct FMS {
    Airline* p_Airline;
    unsigned int cnt_Airline;
} FMS;

void Generate_Time_Table(FMS* p_FMS);
void Generate_Duration_Table(FMS* p_FMS);
void Generate_Distance_Table(FMS* p_FMS);

double Sin_Deg(double x);
double Cos_Deg(double x);
double Calculate_Degree(double lat1, double lon1, double lat2, double lon2);

#endif