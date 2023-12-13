//
//  TeamClass.hpp
//  CPS171_MP8
//
//  Created by Oliver McMillen on 12/8/23.
//

#ifndef TeamClass_hpp
#define TeamClass_hpp

#endif /* TeamClass_hpp */

#include <stdio.h>
#include <string>
#include <iostream>
#include "PlayerClass.hpp"


#pragma once
using namespace std;

class TeamClass {
    public:
        void setName(string name);
        string getName();
    
        void setPoints(int points);
        int getPoints();
    
        void setNumber(int teamnumber);
        int getNumber();
    
        void addPlayer(PlayerClass player);
    
        void displayPlayers();
        PlayerClass getTopPlayerPoints();
    
    private:
        string teamName;
        int teamNumber;
        int teamPoints = 0;
        PlayerClass teamPlayers[11];
        int currentPlayerPosition = 0;

};
