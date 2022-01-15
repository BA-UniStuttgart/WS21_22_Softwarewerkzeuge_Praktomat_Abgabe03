#include "fms.h"

#define _SIZEOF_(A) sizeof(A) / sizeof(A[0])

Airport AIRPORT_MUC = {
    //  field: icao
    "EDDM",

    //  field: iata
    "MUC",

    //  field: latitude
    { /* field: degree */ 48, /* field: minute */ 21, /* field: second */ 14 },

    //  field: longitude
    { /* field: degree */ 11, /* field: minute */ 47, /* field: second */ 10 },

    //  field: heightAMSL
    448
};

Airport AIRPORT_HAM = {
    //  field: icao
    "EDDH",

    //  field: iata
    "HAM",

    //  field: latitude
    { /* field: degree */ 53, /* field: minute */ 37, /* field: second */ 49 },

    //  field: longitude
    { /* field: degree */ 9, /* field: minute */ 59, /* field: second */ 18 },

    //  field: heightAMSL
    11
};

Airport AIRPORT_FRA = {
    //  field: icao
    "EDDF",

    //  field: iata
    "FRA",

    //  field: latitude
    { /* field: degree */ 50, /* field: minute */ 1, /* field: second */ 59 },

    //  field: longitude
    { /* field: degree */ 8, /* field: minute */ 34, /* field: second */ 14 },

    //  field: heightAMSL
    100
};

Airport AIRPORT_DUS = {
    //  field: icao
    "EDDL",

    //  field: iata
    "DUS",

    //  field: latitude
    { /* field: degree */ 51, /* field: minute */ 16, /* field: second */ 51 },

    //  field: longitude
    { /* field: degree */ 6, /* field: minute */ 45, /* field: second */ 26 },

    //  field: heightAMSL
    36
};

Airport AIRPORT_BER = {
    //  field: icao
    "EDDB",

    //  field: iata
    "BER",

    //  field: latitude
    { /* field: degree */ 52, /* field: minute */ 21, /* field: second */ 44 },

    //  field: longitude
    { /* field: degree */ 13, /* field: minute */ 30, /* field: second */ 2 },

    //  field: heightAMSL
    47.5
};

Airport AIRPORT_CGN = {
    //  field: icao
    "EDDK",

    //  field: iata
    "CGN",

    //  field: latitude
    { /* field: degree */ 50, /* field: minute */ 51, /* field: second */ 57 },

    //  field: longitude
    { /* field: degree */ 7, /* field: minute */ 8, /* field: second */ 34 },

    //  field: heightAMSL
    77
};

Airport AIRPORT_STR = {
    //  field: icao
    "EDDS",

    //  field: iata
    "STR",

    //  field: latitude
    { /* field: degree */ 48, /* field: minute */ 41, /* field: second */ 24 },

    //  field: longitude
    { /* field: degree */ 9, /* field: minute */ 13, /* field: second */ 19 },

    //  field: heightAMSL
    360
};

char A380_FLIGHTPATH_NAME[] = "LH 2147";
FlightPath A380_FLIGHTPATHS[] = {
    //  MUC-HAM
    {
        //  field: flightPathName
        A380_FLIGHTPATH_NAME,

        //  field: p_DepartureAirport
        &AIRPORT_MUC,

        //  field: p_ArrivalAirport
        &AIRPORT_HAM,

        // field: departure
        { /* field: hour */ 11, /* field: minute */ 30 },

        //  field: arrival
        { /* field: hour */ 14, /* field: minute */ 30 }
    },

    //  HAM-FRA
    {
        //  field: flightPathName
        A380_FLIGHTPATH_NAME,

        //  field: p_DepartureAirport
        &AIRPORT_HAM,

        //  field: p_ArrivalAirport
        &AIRPORT_FRA,

        // field: departure
        { /* field: hour */ 15, /* field: minute */ 30 },

        //  field: arrival
        { /* field: hour */ 16, /* field: minute */ 30 }
    },

    //  FRA-MUC
    {
        //  field: flightPathName
        A380_FLIGHTPATH_NAME,

        //  field: p_DepartureAirport
        &AIRPORT_FRA,

        //  field: p_ArrivalAirport
        &AIRPORT_MUC,

        // field: departure
        { /* field: hour */ 18, /* field: minute */ 30 },

        //  field: arrival
        { /* field: hour */ 20, /* field: minute */ 30 }
    },

    //  MUC-HAM
    {
        //  field: flightPathName
        A380_FLIGHTPATH_NAME,

        //  field: p_DepartureAirport
        &AIRPORT_MUC,

        //  field: p_ArrivalAirport
        &AIRPORT_HAM,

        // field: departure
        { /* field: hour */ 20, /* field: minute */ 45 },

        //  field: arrival
        { /* field: hour */ 22, /* field: minute */ 0 }
    },

    //  HAM-MUC
    {
        //  field: flightPathName
        A380_FLIGHTPATH_NAME,

        //  field: p_DepartureAirport
        &AIRPORT_HAM,

        //  field: p_ArrivalAirport
        &AIRPORT_MUC,

        // field: departure
        { /* field: hour */ 22, /* field: minute */ 30 },

        //  field: arrival
        { /* field: hour */ 23, /* field: minute */ 30 }
    },
};

char A320_FLIGHTPATH_NAME[] = "EW 5953";
FlightPath A320_FLIGHTPATHS[] = {
    //  MUC-DUS
    {
        //  field: flightPathName
        A320_FLIGHTPATH_NAME,

        //  field: p_DepartureAirport
        &AIRPORT_MUC,

        //  field: p_ArrivalAirport
        &AIRPORT_DUS,

        // field: departure
        { /* field: hour */ 3, /* field: minute */ 0 },

        //  field: arrival
        { /* field: hour */ 4, /* field: minute */ 15 }
    },

    //  DUS-BER
    {
        //  field: flightPathName
        A320_FLIGHTPATH_NAME,

        //  field: p_DepartureAirport
        &AIRPORT_DUS,

        //  field: p_ArrivalAirport
        &AIRPORT_BER,

        // field: departure
        { /* field: hour */ 8, /* field: minute */ 0 },

        //  field: arrival
        { /* field: hour */ 10, /* field: minute */ 0 }
    },

    //  BER-CGN
    {
        //  field: flightPathName
        A320_FLIGHTPATH_NAME,

        //  field: p_DepartureAirport
        &AIRPORT_BER,

        //  field: p_ArrivalAirport
        &AIRPORT_CGN,

        // field: departure
        { /* field: hour */ 10, /* field: minute */ 12 },

        //  field: arrival
        { /* field: hour */ 13, /* field: minute */ 15 }
    },

    //  CGN-MUC
    {
        //  field: flightPathName
        A320_FLIGHTPATH_NAME,

        //  field: p_DepartureAirport
        &AIRPORT_CGN,

        //  field: p_ArrivalAirport
        &AIRPORT_MUC,

        // field: departure
        { /* field: hour */ 18, /* field: minute */ 0 },

        //  field: arrival
        { /* field: hour */ 20, /* field: minute */ 30 }
    },

    //  MUC-DUS
    {
        //  field: flightPathName
        A320_FLIGHTPATH_NAME,

        //  field: p_DepartureAirport
        &AIRPORT_MUC,

        //  field: p_ArrivalAirport
        &AIRPORT_DUS,

        // field: departure
        { /* field: hour */ 21, /* field: minute */ 45 },

        //  field: arrival
        { /* field: hour */ 23, /* field: minute */ 30 }
    }
};

char B747_FLIGHTPATH_NAME[] = "X3 2174";
FlightPath B747_FLIGHTPATHS[] = {
    //  HAM-STR
    {
        //  field: flightPathName
        B747_FLIGHTPATH_NAME,

        //  field: p_DepartureAirport
        &AIRPORT_HAM,

        //  field: p_ArrivalAirport
        &AIRPORT_STR,

        // field: departure
        { /* field: hour */ 8, /* field: minute */ 0 },

        //  field: arrival
        { /* field: hour */ 10, /* field: minute */ 0 }
    },

    //  STR-BER
    {
        //  field: flightPathName
        B747_FLIGHTPATH_NAME,

        //  field: p_DepartureAirport
        &AIRPORT_STR,

        //  field: p_ArrivalAirport
        &AIRPORT_BER,

        // field: departure
        { /* field: hour */ 10, /* field: minute */ 15 },

        //  field: arrival
        { /* field: hour */ 13, /* field: minute */ 0 }
    },

    //  BER-FRA
    {
        //  field: flightPathName
        B747_FLIGHTPATH_NAME,

        //  field: p_DepartureAirport
        &AIRPORT_BER,

        //  field: p_ArrivalAirport
        &AIRPORT_FRA,

        // field: departure
        { /* field: hour */ 13, /* field: minute */ 10 },

        //  field: arrival
        { /* field: hour */ 15, /* field: minute */ 0 }
    },

    //  FRA-HAM
    {
        //  field: flightPathName
        B747_FLIGHTPATH_NAME,

        //  field: p_DepartureAirport
        &AIRPORT_FRA,

        //  field: p_ArrivalAirport
        &AIRPORT_HAM,

        // field: departure
        { /* field: hour */ 15, /* field: minute */ 12 },

        //  field: arrival
        { /* field: hour */ 17, /* field: minute */ 0 }
    },

    //  HAM-FRA
    {
        //  field: flightPathName
        B747_FLIGHTPATH_NAME,

        //  field: p_DepartureAirport
        &AIRPORT_HAM,

        //  field: p_ArrivalAirport
        &AIRPORT_FRA,

        // field: departure
        { /* field: hour */ 22, /* field: minute */ 0 },

        //  field: arrival
        { /* field: hour */ 24, /* field: minute */ 0 }
    }
};

Airplane LUFTHANSA_AIRPLANES[] = {
    //  A380
    {
        //  field: airplaneName
        "A380",

        //  field: airVehicleRegistration
        "D-AIMA",

        //  field: p_FlightPath
        A380_FLIGHTPATHS,

        //  field: cnt_FlightPath
        _SIZEOF_(A380_FLIGHTPATHS)
    }
};

Airplane EUROWINGS_AIRPLANES[] = {
    //  A320
    {
        //  field: airplaneName
        "A320",

        //  field: airVehicleRegistration
        "D-AIAB",

        //  field: p_FlightPath
        A320_FLIGHTPATHS,

        //  field: cnt_FlightPath
        _SIZEOF_(A320_FLIGHTPATHS)
    }
};

Airplane TUIFLY_AIRPLANES[] = {
    //  B747
    {
        //  field: airplaneName
        "B747",

        //  field: airVehicleRegistration
        "D-ABCD",

        //  field: p_FlightPath
        B747_FLIGHTPATHS,

        //  field: cnt_FlightPath
        _SIZEOF_(B747_FLIGHTPATHS)
    }
};

Airline FMS_AIRLINES[] = {

    //  Lufthansa
    {
        //  field: airlineName
        "Lufthansa",

        //  field: p_Airplane
        LUFTHANSA_AIRPLANES,

        //  field: cnt_Airplane
        _SIZEOF_(LUFTHANSA_AIRPLANES)
    },

    //  EuroWings
    {
        //  field: airlineName
        "EuroWings",

        //  field: p_Airplane
        EUROWINGS_AIRPLANES,

        //  field: cnt_Airplane
        _SIZEOF_(EUROWINGS_AIRPLANES)
    },

    //  TUIfly
    {
        //  field: airlineName
        "TUIfly",

        //  field: p_Airplane
        TUIFLY_AIRPLANES,

        //  field: cnt_Airplane
        _SIZEOF_(TUIFLY_AIRPLANES)
    }
};

FMS fms = { 
    //  field: p_Airline
    FMS_AIRLINES,

    //  field: cnt_Airline
    _SIZEOF_(FMS_AIRLINES)
};