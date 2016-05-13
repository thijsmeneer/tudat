/*    Copyright (c) 2010-2015, Delft University of Technology
 *    All rights reserved.
 *
 *    Redistribution and use in source and binary forms, with or without modification, are
 *    permitted provided that the following conditions are met:
 *      - Redistributions of source code must retain the above copyright notice, this list of
 *        conditions and the following disclaimer.
 *      - Redistributions in binary form must reproduce the above copyright notice, this list of
 *        conditions and the following disclaimer in the documentation and/or other materials
 *        provided with the distribution.
 *      - Neither the name of the Delft University of Technology nor the names of its contributors
 *        may be used to endorse or promote products derived from this software without specific
 *        prior written permission.
 *
 *    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS
 *    OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *    MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *    COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 *    EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 *    GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 *    AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 *    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 *    OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *    Changelog
 *      YYMMDD    Author            Comment
 *      100906    J. Melman         First creation of code.
 *      110124    K. Kumar          Split into .h and .cpp files.
 *      110629    F.M. Engelen      Added specific gas constants.
 *      120127    D. Dirkx          Moved to Tudat core, removed variables related to
 *                                  obliquity of ecliptic.
 *      120203    K. Kumar          Added missing specific gas constant value; need unit test.
 *      121212    K. Kumar          Migrated namespace to directory-based protocol and added
 *                                  backwards compatibility.
 *      130111    D. Dirkx          Added Planck, Boltzmann, and Stefan-Boltzmann constants.
 *
 *    References
 *      Standish, E.M. (1995) "Report of the IAU WGAS Sub-Group on Numerical Standards",
 *          in Highlights of Astronomy (I. Appenzeller, ed.), Table 1, Kluwer Academic Publishers,
 *          Dordrecht.
 *      Standish, E.M. (1998) "JPL Planetary and Lunar Ephemerides, DE405/LE405",
 *          JPL IOM 312. F-98-048.
 *      Anderson, J.D. Jr. Hypersonic and High-Temperature Gas Dynamics, Second Edition, p469,
 *          2006.
 *      NASA. Astrodynamics Constants, http://ssd.jpl.nasa.gov/?constants#ref, 6th September, 2011,
 *          last accessed: 21st February, 2012.
 *      NIST. NIST reference on constants, units and uncertainty.
 *          http://physics.nist.gov/cuu/Constants/index.html, last accessed: 11th January, 2013.
 *      Wolfram Research, http://scienceworld.wolfram.com/physics/Stefan-BoltzmannLaw.html,
 *          last accessed: 11th January 2013.
 *
 *    Notes
 *      Backwards compatibility of namespaces is implemented for Tudat Core 2 in this file. The
 *      code block marked "DEPRECATED!" at the end of the file should be removed in Tudat Core 3.
 *
 */

#ifndef TUDAT_PHYSICAL_CONSTANTS_H
#define TUDAT_PHYSICAL_CONSTANTS_H

#include <cmath>

#include "Tudat/Mathematics/BasicMathematics/mathematicalConstants.h"

namespace tudat
{

namespace physical_constants
{

//! Julian day in seconds (NASA, 2012).
const static double JULIAN_DAY = 86400.0;

//! Julian day in seconds (NASA, 2012), in long double precision.
const static double JULIAN_DAY_LONG = 86400.0L;

//! Function to get the length of a Julian day in seconds, with templated precision.
/*!
 *  Function to get the length of a Julian day in seconds, with templated precision.
 *  \return Length of a Julian day in seconds, with templated precision.
 */
template< typename ScalarType >
ScalarType getJulianDay( );

//! Julian year in Julian days (NASA, 2012).
const static double JULIAN_YEAR_IN_DAYS = 365.25;

//! Julian year in Julian days (NASA, 2012), in long double precision.
const static double JULIAN_YEAR_IN_DAYS_LONG = 365.25L;

//! Function to get the length of a Julian year in days, with templated precision.
/*!
 *  Function to get the length of a Julian year in days with templated precision.
 *  \return Length of a Julian year in days, with templated precision.
 */
template< typename ScalarType >
ScalarType getJulianYearInDays( );

//! Julian year in seconds. Result of JULIAN_YEAR_IN_DAYS * JULIAN_DAY.
const static double JULIAN_YEAR = 3.15576e7;

//! Sidereal day in seconds (NASA, 2012).
const static double SIDEREAL_DAY = 86164.09054;

//! Sidereal year in Julian days in quasar reference frame (NASA, 2012).
const static double SIDEREAL_YEAR_IN_DAYS = 365.25636;

//! Sidereal year in quasar reference frame. Result of SIDEREAL_YEAR_IN_DAYS * JULIAN_DAY.
const static double SIDEREAL_YEAR = 3.1558149504e7;

//! Speed of light in meters per second (Standish, 1995).
const static double SPEED_OF_LIGHT = 299792458.0;

//! Speed of light in meters per second (Standish, 1995), in long double precision.
const static double SPEED_OF_LIGHT_LONG = 299792458.0L;

//! Function to get the speed of light in meters per second with templated precision.
/*!
 *  Function to get the speed of light in meters per second with templated precision.
 *  \return Speed of light in meters per second with templated precision.
 */
template< typename ScalarType >
ScalarType getSpeedOfLight( );

//! Gravitational constant in meter^3 per kilogram per second^2, (Standish, 1995).
const static double GRAVITATIONAL_CONSTANT = 6.67259e-11;

//! Astronomical Unit in meters (Standish, 1998).
const static double ASTRONOMICAL_UNIT = 1.49597870691e11;

//! The specific gas constant of air in J per kg Kelvin (J/(kg K)) (Anderson, 2006).
const static double SPECIFIC_GAS_CONSTANT_AIR = 2.87e2;

//! Planck's constant in m^{2} kg/s, (NIST, 2013).
const static double PLANCK_CONSTANT = 6.62606957E-34;

//! The Boltzmann constant (gas constant per particle) in  m^{2} kg / ( s^{2} K ), (NIST, 2013).
const static double BOLTZMANN_CONSTANT = 1.3806488E-23;

//! Stefan-Boltzmann constant.
/*!
 * Stefan-Boltzmann constant, used for calculating black body radiation intensity, (Wolfram, 2013)
 * in J / (s m^{2} K{4} )
 */
const static double STEFAN_BOLTZMANN_CONSTANT = 2.0 *
        std::pow( mathematical_constants::PI, 5.0 ) *
        std::pow( BOLTZMANN_CONSTANT, 4.0 ) /
        ( 15.0 * SPEED_OF_LIGHT * SPEED_OF_LIGHT *
          PLANCK_CONSTANT * PLANCK_CONSTANT * PLANCK_CONSTANT );

//! Precomputed inverse-square of speed of light.
const static double INVERSE_SQUARE_SPEED_OF_LIGHT = 1.0 / ( SPEED_OF_LIGHT * SPEED_OF_LIGHT );

//! Precomputed inverse 3rd power of speed of light.
const static double INVERSE_CUBIC_SPEED_OF_LIGHT = 1.0 / ( SPEED_OF_LIGHT * SPEED_OF_LIGHT * SPEED_OF_LIGHT );

//! Precomputed inverse 4th power of speed of light.
const static double INVERSE_QUARTIC_SPEED_OF_LIGHT = INVERSE_SQUARE_SPEED_OF_LIGHT * INVERSE_SQUARE_SPEED_OF_LIGHT;

//! Precomputed inverse 5th power of speed of light.
const static double INVERSE_QUINTIC_SPEED_OF_LIGHT = INVERSE_SQUARE_SPEED_OF_LIGHT * INVERSE_CUBIC_SPEED_OF_LIGHT;

//! Permeability of vacuum.
const static double VACUUM_PERMEABILITY = 4.0 * mathematical_constants::PI * 1.0E-7;

//! Permittivity of vacuum.
const static double VACUUM_PERMITTIVITY = INVERSE_SQUARE_SPEED_OF_LIGHT / VACUUM_PERMEABILITY;

//! Relative time rate difference between TCG and TT time scales.
const static double LG_TIME_RATE_TERM = 6.969290134E-10;

//! Relative time rate difference between TCG and TT time scales, in long double precision.
const static long double LG_TIME_RATE_TERM_LONG = 6.969290134E-10L;

//! Function to get the TCG and TT relative rate difference with templated precision.
/*!
 *  Function to get the TCG and TT relative rate difference with templated precision.
 *  \return TCG and TT relative rate difference with templated precision.
 */
template< typename ScalarType >
ScalarType getLgTimeRateTerm( );

//! Relative time rate difference between TCB and TDB time scales.
const static double LB_TIME_RATE_TERM = 1.550519768E-8;

//! Relative time rate difference between TCB and TDB time scales, in long double precision.
const static long double LB_TIME_RATE_TERM_LONG = 1.550519768E-8L;

//! Function to get the TCB and TDB relative rate difference with templated precision.
/*!
 *  Function to get the TCB and TDB relative rate difference with templated precision.
 *  \return TCB and TDB relative rate difference with templated precision.
 */
template< typename ScalarType >
ScalarType getLbTimeRateTerm( );

} // namespace physical_constants

} // namespace tudat

#endif // TUDAT_PHYSICAL_CONSTANTS_H