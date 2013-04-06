/**
 * @file src/DriveMock.hpp
 * This file contains the declaration for the mock object to test the carier.
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
#ifndef _DRIVEMOCK_HPP_
#define _DRIVEMOCK_HPP_

#define NO_ERROR 0

#include <iostream>
#include <vector>

#include "IDrive.hpp"

using namespace::std;

class DriveMock : public IDrive
{
private:
    vector<long> expectedPosions;                 // container to add the expected Positions
    vector<long>::iterator expectedPositionsIter; // creates an iterator necessary to traverse expectedPositions 	
    vector<long> actualPosions;                   // container to add the expected Positions
    vector<long>::iterator actualPositionsIter;   // creates an iterator necessary to traverse expectedPositions

public:
    // Mock methods
    void addExpectedPosition(long pos);           // add an expected position
    void verify();                                // check results at the end of the test
  
    // Motor methods to simulate
    unsigned short gotoPosition(long pos); 
};
#endif // _DRIVEMOCK_HPP_
