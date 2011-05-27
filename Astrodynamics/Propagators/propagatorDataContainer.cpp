/*! \file propagatorDataContainer.cpp
 *    Source file that defines the class that contains all the data required by
 *    the Tudat propagators.
 *
 *    Path              : /Astrodynamics/Propagators/
 *    Version           : 3
 *    Check status      : Checked
 *
 *    Author            : K. Kumar
 *    Affiliation       : Delft University of Technology
 *    E-mail address    : K.Kumar@tudelft.nl
 *
 *    Checker           : J.C.P. Melman
 *    Affiliation       : Delft University of Technology
 *    E-mail address    : J.C.P.Melman@tudelft.nl
 *
 *    Date created      : 20 September, 2010
 *    Last modified     : 1 February, 2010
 *
 *    References
 *
 *    Notes
 *
 *    Copyright (c) 2010 Delft University of Technology.
 *
 *    This software is protected by national and international copyright.
 *    Any unauthorized use, reproduction or modification is unlawful and
 *    will be prosecuted. Commercial and non-private application of the
 *    software in any form is strictly prohibited unless otherwise granted
 *    by the authors.
 *
 *    The code is provided without any warranty; without even the implied
 *    warranty of merchantibility or fitness for a particular purpose.
 *
 *    Changelog
 *      YYMMDD    Author            Comment
 *      100920    K. Kumar          File created.
 *      100926    K. Kumar          Fiename changed, comments added.
 *      110201    K. Kumar          Changed filename; updated constructor.
 */

// Include statements.
#include "propagatorDataContainer.h"

// Using declarations.
using std::endl;

//! Default constructor.
PropagatorDataContainer::PropagatorDataContainer( )
{
    // Initilize variables.
    pointerToInitialState_ = new State;
    pointerToCurrentState_ = new State;
    pointerToFinalState_ = new State;
}

//! Default destructor.
PropagatorDataContainer::~PropagatorDataContainer( )
{
    // Deallocate pointers.
    delete pointerToInitialState_;
    delete pointerToCurrentState_;
    delete pointerToFinalState_;

    for ( iteratorPropagationHistory_ = propagationHistory_.begin( );
          iteratorPropagationHistory_ != propagationHistory_.end( );
          iteratorPropagationHistory_++ )
    {
        delete iteratorPropagationHistory_->second;
    }

}

//! Overload ostream to print class information.
std::ostream& operator<<( std::ostream& stream,
                          PropagatorDataContainer& propagatorDataContainer )
{
    stream << "This is a PropagatorDataContainer object." << endl;
    stream << "The initial state is set to: "
           << propagatorDataContainer.pointerToInitialState_ << endl;
    stream << "The current state is set to: "
           << propagatorDataContainer.pointerToCurrentState_ << endl;
    stream << "The final state is set to: "
           << propagatorDataContainer.pointerToFinalState_ << endl;

    // Return stream.
    return stream;
}

// End of file.