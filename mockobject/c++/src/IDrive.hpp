/**
 * @file src/IDrive.hpp
 * This file contains the interface declaration for a drive.
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
#ifndef _IDRIVE_HPP_
#define _IDRIVE_HPP_

#define NO_ERROR 0

#include <iostream>
#include <vector>

using namespace::std;

class IDrive
{
public:
    // Motor methods
    virtual unsigned short gotoPosition(long pos) = 0; 
};
#endif // _IDrive_HPP_
