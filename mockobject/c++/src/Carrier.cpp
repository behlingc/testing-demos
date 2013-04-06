/**
 * @file src/Carrier.cpp
 * This file contains the implementation for a carier.
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
#include "Carrier.hpp"

// Constructor
Carrier::Carrier(IDrive *xDrive, IDrive *yDrive, IDrive *zDrive)
{
    this->xDrive = xDrive;
    this->yDrive = yDrive;
    this->zDrive = zDrive;
}

// Carrier methods
unsigned short Carrier::gotoPosition(long xPos, long yPos, long zPos)
{
    // In a real world this implementaion is to simple.
    // The execution order may depend on obstacles in the 3D scene.
    // But here we want to see a mock object usage. 
    xDrive->gotoPosition(xPos);
    yDrive->gotoPosition(yPos);
    zDrive->gotoPosition(zPos);

    return NO_ERROR;	
}

