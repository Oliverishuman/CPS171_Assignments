//
//  TeamClass.hpp
//  CPS171_MP8
//
//  Created by Oliver McMillen on 12/8/23.
//

#ifndef TeamClass_hpp
#define TeamClass_hpp

#include <stdio.h>

#endif /* TeamClass_hpp */

#include <stdio.h>
#include <string>
#include <iostream>

#pragma once
using namespace std;

class TeamClass {
    public:
        void setName(string name);
    
        string getName();
        int getPoints();
    private:
        string teamName;
        int points = 250504;

};
