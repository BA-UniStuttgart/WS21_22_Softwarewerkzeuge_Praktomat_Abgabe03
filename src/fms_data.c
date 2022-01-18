#include "fms.h"

#define _SIZEOF_(A) sizeof(A) / sizeof(A[0])

Airport AIRPORT_MUC = {
    //  field: icao
    "EDDM",

    //  field: iata
    "MUC",

    //  field: latitude
    { 48, 21, 14 }, //  { field: degree, field: minute, field: second }

    //  field: longitude
    { 11, 47, 10 }, //  { field: degree, field: minute, field: second }

    //  field: heightAMSL
    448
};

Airport AIRPORT_HAM = {
    //  field: icao
    "EDDH",

    //  field: iata
    "HAM",

    //  field: latitude
    { 53, 37, 49 }, //  { field: degree, field: minute, field: second }

    //  field: longitude
    { 9, 59, 18 },  //  { field: degree, field: minute, field: second }

    //  field: heightAMSL
    11
};

Airport AIRPORT_FRA = {
    //  field: icao
    "EDDF",

    //  field: iata
    "FRA",

    //  field: latitude
    { 50, 1, 59 },  //  { field: degree, field: minute, field: second }

    //  field: longitude
    { 8, 34, 14 },  //  { field: degree, field: minute, field: second }

    //  field: heightAMSL
    100
};

Airport AIRPORT_DUS = {
    //  field: icao
    "EDDL",

    //  field: iata
    "DUS",

    //  field: latitude
    { 51, 16, 51 }, //  { field: degree, field: minute, field: second }

    //  field: longitude
    { 6, 45, 26 },  //  { field: degree, field: minute, field: second }

    //  field: heightAMSL
    36
};

Airport AIRPORT_BER = {
    //  field: icao
    "EDDB",

    //  field: iata
    "BER",

    //  field: latitude
    { 52, 21, 44 }, //  { field: degree, field: minute, field: second }

    //  field: longitude
    { 13, 30, 2 },  //  { field: degree, field: minute, field: second }

    //  field: heightAMSL
    47.5
};

Airport AIRPORT_CGN = {
    //  field: icao
    "EDDK",

    //  field: iata
    "CGN",

    //  field: latitude
    { 50, 51, 57 }, //  { field: degree, field: minute, field: second }

    //  field: longitude
    { 7, 8, 34 },   //  { field: degree, field: minute, field: second }

    //  field: heightAMSL
    77
};

Airport AIRPORT_STR = {
    //  field: icao
    "EDDS",

    //  field: iata
    "STR",

    //  field: latitude
    { 48, 41, 24 }, //  { field: degree, field: minute, field: second }

    //  field: longitude
    { 9, 13, 19 },  //  { field: degree, field: minute, field: second }

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
        { 11, 30 }, // { field: hour, field: minute }

        //  field: arrival
        { 14, 30 }  // { field: hour, field: minute }
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
        { 15, 30 }, // { field: hour, field: minute }

        //  field: arrival
        { 16, 30 }  // { field: hour, field: minute }
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
        { 18, 30 }, // { field: hour, field: minute }

        //  field: arrival
        { 20, 30 }  // { field: hour, field: minute }
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
        { 20, 45 }, // { field: hour, field: minute }

        //  field: arrival
        { 22, 0 }   // { field: hour, field: minute }
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
        { 23, 30 }  // { field: hour, field: minute }
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
        { 3, 0 },   // { field: hour, field: minute }

        //  field: arrival
        { 4, 15 }   // { field: hour, field: minute }
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
        { 8, 0 },   // { field: hour, field: minute }

        //  field: arrival
        { 10, 0 }   // { field: hour, field: minute }
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
        { 10, 12 }, // { field: hour, field: minute }

        //  field: arrival
        { 13, 15 }  // { field: hour, field: minute }
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
        { 18, 0 },  // { field: hour, field: minute }

        //  field: arrival
        { 20, 30 }  // { field: hour, field: minute }
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
        { 21, 45 }, // { field: hour, field: minute }

        //  field: arrival
        { 23, 30 }  // { field: hour, field: minute }
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
        { 8, 0 }, // { field: hour, field: minute }

        //  field: arrival
        { 10, 0 } // { field: hour, field: minute }
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
        { 10, 15 }, // { field: hour, field: minute }

        //  field: arrival
        { 13, 0 }   // { field: hour, field: minute }
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
        { 13, 10 }, // { field: hour, field: minute }

        //  field: arrival
        { 15, 0 }   // { field: hour, field: minute }
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
        { 15, 12 }, // { field: hour, field: minute }

        //  field: arrival
        { 17, 0 }   // { field: hour, field: minute }
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
        { 22, 0 },  // { field: hour, field: minute }

        //  field: arrival
        { 24, 0 }   // { field: hour, field: minute }
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
        "TUIFly",

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