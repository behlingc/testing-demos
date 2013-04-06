/**
 * @file src/Carrier.hpp
 * This file contains the declaration for a carier.
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
#ifndef _Carrier_HPP_
#define _Carrier_HPP_

#define NO_ERROR 0

#include <iostream>
#include <vector>

#include "IDrive.hpp"

using namespace::std;

class Carrier
{
public:
    // Drives
    IDrive *xDrive;
    IDrive *yDrive;
    IDrive *zDrive;

    // Constructor
    Carrier(IDrive *xDrive, IDrive *yDrive, IDrive *zDrive);

    // Carier methods.
    unsigned short gotoPosition(long xPos, long yPos, long zPos); 
};
#endif // _Carrier_HPP_

