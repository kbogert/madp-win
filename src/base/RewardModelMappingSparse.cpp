/**\file RewardModelMappingSparse.cpp
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
 * $Id: RewardModelMappingSparse.cpp 2962 2008-11-02 15:04:43Z mtjspaan $
 */

#include "RewardModelMappingSparse.h"

using namespace std;

RewardModelMappingSparse::RewardModelMappingSparse(size_t nrS, size_t nrJA, string s_str,
            string ja_str) : 
    RewardModel(nrS, nrJA),
    _m_R(nrS,nrJA)
{
    _m_s_str = s_str;
    _m_ja_str = ja_str;
}

RewardModelMappingSparse::~RewardModelMappingSparse()
{
}

string RewardModelMappingSparse::SoftPrint() const
{
    stringstream ss;
    double r;
    ss << _m_s_str <<"\t"<< _m_ja_str <<"\t"
       << "R(" << _m_s_str <<","<< _m_ja_str
       <<  ") (rewards of 0 are not printed)"<<endl;
    for(Index s_i = 0; s_i < _m_nrStates; s_i++)
        for(Index ja_i = 0; ja_i < _m_nrJointActions; ja_i++)
        {
            r=Get(s_i, ja_i);
            if(std::abs(r)>0)
                ss << s_i << "\t" << ja_i << "\t" << r << endl;
        }
    return(ss.str());
}

