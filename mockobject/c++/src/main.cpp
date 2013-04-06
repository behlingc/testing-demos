/**
 * @file src/main.cpp
 * This file contains the main routine.
 *
 * @author Carsten Behling
 * @copyright
 *    2013 Carsten Behling <behlin_c@gmx.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 */
#include <stdio.h>
#include <stdlib.h>

#include "Carrier.hpp"
#include "DriveMock.hpp"

#define X 0
#define Y 1
#define Z 2

int main(int argc, char *argv[])
{
    // Test route for the carrier.
    long testPos1[3] = {90, 10, -56};
    long testPos2[3] = {-33, 10, -5};
    long testPos3[3] = {1, 5, 0};

    // Create the drive mock objects for the carrier. 
    DriveMock *xDriveMock = new DriveMock();
    DriveMock *yDriveMock = new DriveMock();
    DriveMock *zDriveMock = new DriveMock();

    // Create the carrier object and pass the drive mock objects
    // instead real Drive objects (that are also derived from IDrive).
    Carrier *carrier = new Carrier(xDriveMock, yDriveMock, zDriveMock);

    // Set up the expected test results.
    xDriveMock->addExpectedPosition(testPos1[X]);
    yDriveMock->addExpectedPosition(testPos1[Y]);
    zDriveMock->addExpectedPosition(testPos1[Z]);
    xDriveMock->addExpectedPosition(testPos2[X]);
    yDriveMock->addExpectedPosition(testPos2[Y]);
    zDriveMock->addExpectedPosition(testPos2[Z]);
    xDriveMock->addExpectedPosition(testPos3[X]);
    yDriveMock->addExpectedPosition(testPos3[Y]);
    zDriveMock->addExpectedPosition(testPos3[Z]);

    // Now run the route with the carrier.
    carrier->gotoPosition(testPos1[X], testPos1[Y], testPos1[Z]);
    carrier->gotoPosition(testPos2[X], testPos2[Y], testPos2[Z]);
    carrier->gotoPosition(testPos3[X], testPos3[Y], testPos3[Z]);
 
    // Verify the test results.
    // In a real world test system the verify method is more confortable.
    // E.g. a identifier string should be passed and PASS or FAIL
    // should be returned by the verify method instead of putting
    // out the test result there on the console.
    printf("Verifing xDrive\n");
    xDriveMock->verify();
#if 0
    printf("Verifing yDrive\n");
    yDriveMock->verify();
    printf("Verifing zDrive\n");
    zDriveMock->verify();
#endif 
    return 0;
}

