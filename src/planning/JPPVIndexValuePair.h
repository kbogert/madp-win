/**\file JPPVIndexValuePair.h
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
 * $Id: JPPVIndexValuePair.h 3603 2009-08-25 10:38:25Z mtjspaan $
 */

/* Only include this header file once. */
#ifndef _JPPVINDEXVALUEPAIR_H_
#define _JPPVINDEXVALUEPAIR_H_ 1

/* the include directives */
#include <iostream>
#include "Globals.h"
#include "JointPolicyValuePair.h"

class JointPolicyPureVector;
class PartialJointPolicyDiscretePure;
class Interface_ProblemToPolicyDiscretePure;

/**\brief JPPVIndexValuePair represents a (JointPolicyPureVector,Value) pair.
 * It stores the LIndex of the the JointPolicyPureVector.
 *
 * In contrast, JPPVValuePair maintains a pointer to the JointPolicyPureVector.
 * This class only stores the LIndex of the JointPolicyPureVector, 
 * allowing to free memory.
 * Therefore, this class should be preferred over JPPVValuePair when a lot of
 * policies (i.e., policy items) will be retained in memory. E.g., in MAA* like
 * algorithms.
 *
 * For instance the NewPPI() function in GMAA_MAAstar uses this class (and 
 * consequently frees the memory).
 * */
class JPPVIndexValuePair : public JointPolicyValuePair
{
private:    

    JointPolicyPureVector* _m_jpol;
    LIndex _m_jpolIndex;
    size_t _m_jpolDepth;
    const Interface_ProblemToPolicyDiscretePure *_m_pu;
    
    void AllocateJPPV();

protected:
    
public:
    // Constructor, destructor and copy assignment.

    JPPVIndexValuePair(JointPolicyPureVector* jp, double value);
    JPPVIndexValuePair(const JointPolicyPureVector& jp, double value);

    /// Destructor.
    ~JPPVIndexValuePair();

    JointPolicyDiscretePure* GetJPol();
    JointPolicyPureVector* GetJPPV();

    std::string SoftPrint() const;
    std::string SoftPrintBrief() const;
};


#endif /* !_JPPVINDEXVALUEPAIR_H_ */

// Local Variables: ***
// mode:c++ ***
// End: ***
