//
//  TeamClass.cpp
//  CPS171_MP8
//
//  Created by Oliver McMillen on 12/8/23.
//

#include "TeamClass.hpp"

void TeamClass::setName(string name){
    teamName = name;
}

string TeamClass::getName(){
    return teamName;
}

int TeamClass::getPoints(){
    return points;
}
