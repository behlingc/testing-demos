/**
 * @file src/DriveMock.cpp
 * This file contains the implementation for the mock object to test the carier.
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

#include "DriveMock.hpp"

// Mock methods
void DriveMock::addExpectedPosition(long pos)
{
    expectedPosions.push_back(pos); // add position to the end of the vector
    return;
}

void DriveMock::verify(void)
{
    unsigned int fail = 0;

    actualPositionsIter = actualPosions.begin();
	
    for (expectedPositionsIter = expectedPosions.begin(); 
         expectedPositionsIter != expectedPosions.end(); 
         expectedPositionsIter++ ) {	
        if(*expectedPositionsIter != *actualPositionsIter) {
            printf("FAIL: Expected: %ld Actual: %ld\n", *expectedPositionsIter, *actualPositionsIter);
            fail = 1;	
        }
        actualPositionsIter++;
        if(!fail) {
            printf("PASS\n");
        }
    }
    return;
}

// Motor methods to simulate
unsigned short DriveMock::gotoPosition(long pos)
{
    actualPosions.push_back(pos); // add position to the end of the vector
    return NO_ERROR;	
}

