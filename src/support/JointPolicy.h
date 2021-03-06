/**\file JointPolicy.h
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
 * $Id: JointPolicy.h 4016 2010-03-11 16:56:02Z mtjspaan $
 */

/* Only include this header file once. */
#ifndef _JOINTPOLICY_H_
#define _JOINTPOLICY_H_ 1

/* the include directives */
#include <iostream>
#include "Globals.h"

///JointPolicy is a class that represents a joint policy.
/** It contains the notion of the depth of a policy: a positive number
 * that specifies for how many time steps this policy is
 * specified. I.e., if depth < horizon, the object represents a
 * partially specified policy (specified for time steps
 * 0,...,depth-1)*/
class JointPolicy
{
private:    

    /**\brief The depth of this joint policy.
     *
     * The depth of the policy is the number of stages for which it specifies actions.
     * It ranges from: \n
     *     0 (the empty policy), \n
     *     1 (a policy specified only for ts=0), \n
     *     :
     *     MAXHORIZON (a policy specified for all stages, the default value). \n
     */
    size_t _m_depth;

protected:
    ///some other numbers we cache:
    size_t _m_nrAgents;
  
public:
    // Constructor, destructor and copy assignment.

    /// Constructor, initializes the depth to the maximum horizon.
    JointPolicy(size_t nrAg) : 
        _m_depth(MAXHORIZON),
        _m_nrAgents(nrAg)
    {};
    /// copy constructor:
    JointPolicy(const JointPolicy& o)
        : _m_depth(o._m_depth),_m_nrAgents(o._m_nrAgents)
    {};
    /// copy assignment operator
    virtual JointPolicy& operator= (const JointPolicy& o)
    {
        if (this == &o) return *this;   // Gracefully handle self assignment
        _m_depth = o._m_depth;
        _m_nrAgents = o._m_nrAgents;
        return *this;
    }
 
    ///Returns the depth of the joint policy.  \sa _m_depth
    size_t GetDepth() const {return _m_depth;}
    /// Sets the depth of the joint policy.  \sa _m_depth
    virtual void SetDepth(size_t d) {_m_depth = d;}

    /// Returns the number of agents for which the joint policy is defined.
    size_t GetNrAgents() const 
    { return _m_nrAgents; }

    /// Destructor.
    virtual ~JointPolicy(){}
      
    /// Returns a pointer to a copy of this class.
    virtual JointPolicy* Clone() const = 0;

    /// Prints a description of a joint policy to a string.
    virtual std::string SoftPrint() const = 0;
    /// Prints a description of a joint policy to cout.
    virtual void Print() const
        { std::cout << SoftPrint();}
};


#endif /* !_JOINTPOLICY_H_ */

// Local Variables: ***
// mode:c++ ***
// End: ***
