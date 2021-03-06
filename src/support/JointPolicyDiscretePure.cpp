/**\file JointPolicyDiscretePure.cpp
 *
 * Authors:
 * Frans Oliehoek <faolieho@science.uva.nl>
 * Matthijs Spaan <mtjspaan@isr.ist.utl.pt>
 *
 * Copyright 2008 Universiteit van Amsterdam, Instituto Superior Tecnico
 *
 * This file is part of MultiAgentDecisionProcess.
 *
 * MultiAgentDecisionProcess is free software: you can redistribute it
 * and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * MultiAgentDecisionProcess is distributed in the hope that it will
 * be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with MultiAgentDecisionProcess.  If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * $Id: JointPolicyDiscretePure.cpp 3598 2009-08-20 12:29:54Z mtjspaan $
 */

#include "JointPolicyDiscretePure.h"
using namespace std;

//Default constructor
JointPolicyDiscretePure::JointPolicyDiscretePure(
        const Interface_ProblemToPolicyDiscretePure& pu,
        PolicyGlobals::IndexDomainCategory idc ) :
    JointPolicyDiscrete( pu , idc )
{
    
}
//Copy constructor.    
JointPolicyDiscretePure::JointPolicyDiscretePure(const 
        JointPolicyDiscretePure& o) 
    :
    JointPolicyDiscrete( o )
{
}
//Destructor
//JointPolicyDiscretePure::~JointPolicyDiscretePure()
//{
//}
//Copy assignment operator
JointPolicyDiscretePure& JointPolicyDiscretePure::operator= (const JointPolicyDiscretePure& o)
{
    if (this == &o) return *this;   // Gracefully handle self assignment
    JointPolicyDiscrete::operator= ( o );   //call parent
  // Put the normal assignment duties here...

    return *this;
}

double JointPolicyDiscretePure::GetJointActionProb( 
        Index i, Index ja ) const
{
    return (ja == GetJointActionIndex(i));
    
}
double JointPolicyDiscretePure::GetActionProb( Index agentI,
        Index i, Index a ) const
{
    return (a == GetActionIndex(agentI, i));    
}

void JointPolicyDiscretePure::SetInterfacePTPDiscretePure(
        Interface_ProblemToPolicyDiscretePure* pu)
{
    SetInterfacePTPDiscrete(pu);
}

