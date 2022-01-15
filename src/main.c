#include <stdio.h>
#include "fms.h"

extern FMS fms;

int main() {

    Generate_Time_Table(&fms);

    printf("\n");

    Generate_Duration_Table(&fms);
    Generate_Distance_Table(&fms);

    return 0;
}