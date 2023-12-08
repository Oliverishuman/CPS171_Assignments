//
//  PlayerClass.hpp
//  CPS171_MP8
//
//  Created by Oliver McMillen on 12/8/23.
//

#ifndef PlayerClass_hpp
#define PlayerClass_hpp

#endif /* PlayerClass_hpp */

#include <stdio.h>
#include <string>
#include <iostream>

#pragma once
using namespace std;

class PlayerClass {
    public:
        void setFirstName(string firstName);
        string getFirstName();
    
        void setLastName(string lastName);
        string getLastName();
    
        void setPoints(int points);
        int getPoints();
    
        void setNumber(int number);
        int getNumber();
    
    private:
        string playerFirstName;
        string playerLastName;
        int playerPoints = 0;
        int playerNumber = 0;

};
