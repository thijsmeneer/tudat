/*    Copyright (c) 2010-2017, Delft University of Technology
 *    All rigths reserved
 *
 *    This file is part of the Tudat. Redistribution and use in source and
 *    binary forms, with or without modification, are permitted exclusively
 *    under the terms of the Modified BSD license. You should have received
 *    a copy of the license with this file. If not, please or visit:
 *    http://tudat.tudelft.nl/LICENSE.
 */

#define BOOST_TEST_MAIN

#include "unitTestSupport.h"
#include <Tudat/External/JsonInterface/Environment/rotationModel.h>

namespace tudat
{

namespace unit_tests
{

#define INPUT( filename ) \
    ( json_interface::inputDirectory( ) / boost::filesystem::path( __FILE__ ).stem( ) / filename ).string( )

BOOST_AUTO_TEST_SUITE( test_json_rotationModel )

// Test 1: rotation model types
BOOST_AUTO_TEST_CASE( test_json_rotationModel_types )
{
    BOOST_CHECK_EQUAL_ENUM( INPUT( "types" ),
                            simulation_setup::rotationModelTypes,
                            simulation_setup::unsupportedRotationModelTypes );
}

// Test 2: simple rotation model
BOOST_AUTO_TEST_CASE( test_json_rotationModel_simple )
{
    using namespace simulation_setup;
    using namespace spice_interface;
    using namespace json_interface;

    // Load spice kernels.  (FIXME: remove kernels that are not needed for computeRotationQuaternionBetweenFrames)
    const std::string kernelsPath = input_output::getSpiceKernelPath( );
    loadSpiceKernelInTudat( kernelsPath + "de-403-masses.tpc");
    loadSpiceKernelInTudat( kernelsPath + "pck00009.tpc");
    loadSpiceKernelInTudat( kernelsPath + "de421.bsp");

    // Create RotationModelSettings from JSON file
    const boost::shared_ptr< RotationModelSettings > fromFileSettings =
            parseJSONFile< boost::shared_ptr< RotationModelSettings > >( INPUT( "simple" ) );

    // Create RotationModelSettings manually
    const std::string originalFrame = "ECLIPJ2000";
    const std::string targetFrame = "IAU_Earth";
    const double initialTime = 42.0;
    const Eigen::Quaterniond initialOrientation =
            spice_interface::computeRotationQuaternionBetweenFrames( originalFrame, targetFrame, initialTime );
    const double rotationRate = 2.0e-5;
    const boost::shared_ptr< RotationModelSettings > manualSettings =
            boost::make_shared< SimpleRotationModelSettings >( originalFrame,
                                                               targetFrame,
                                                               initialOrientation,
                                                               initialTime,
                                                               rotationRate );

    // Compare
    BOOST_CHECK_EQUAL_JSON( fromFileSettings, manualSettings );
}

// Test 3: Spice rotation model
BOOST_AUTO_TEST_CASE( test_json_rotationModel_spice )
{
    using namespace simulation_setup;
    using namespace json_interface;

    // Create RotationModelSettings from JSON file
    const boost::shared_ptr< RotationModelSettings > fromFileSettings =
            parseJSONFile< boost::shared_ptr< RotationModelSettings > >( INPUT( "spice" ) );

    // Create RotationModelSettings manually
    const std::string originalFrame = "foo";
    const std::string targetFrame = "oof";
    const boost::shared_ptr< RotationModelSettings > manualSettings =
            boost::make_shared< RotationModelSettings >( spice_rotation_model,
                                                         originalFrame,
                                                         targetFrame );

    // Compare
    BOOST_CHECK_EQUAL_JSON( fromFileSettings, manualSettings );
}

BOOST_AUTO_TEST_SUITE_END( )

} // namespace unit_tests

} // namespace tudat
