//
//  TeamClass.cpp
//  CPS171_MP8
//
//  Created by Oliver McMillen on 12/8/23.
//

#include "TeamClass.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

void TeamClass::setName(string name){
    teamName = name;
}

string TeamClass::getName(){
    return teamName;
}

void TeamClass::setNumber(int teamnumber){
    teamNumber = teamnumber;
}

int TeamClass::getNumber(){
    return teamNumber + 1;
}

void TeamClass::setPoints(int points){
    teamPoints = points;
}

int TeamClass::getPoints(){
    int playerPoints = 0;
    teamPoints = 0;
    
    for (int i=0; i < 11; i++){
        playerPoints = teamPlayers[i].getPoints();
        teamPoints += playerPoints;
    }
    
    return teamPoints;
}

void TeamClass::addPlayer(PlayerClass player){
    if(currentPlayerPosition < 11){
        teamPlayers[currentPlayerPosition] = player;
        currentPlayerPosition++;
    }
}


void TeamClass::displayPlayers(){
    string players = "";
    
    for (int i=0; i < 11; i++){
        
        cout << fixed << right << setw(2) << i+1 << fixed << setw(3) << left << "." << setw(11) << teamPlayers[i].getFirstName()
        << setw(18) << teamPlayers[i].getLastName() << setw(17) << teamPlayers[i].getNumber() << setw(21) << teamPlayers[i].getPoints() << endl;
    }
}

PlayerClass TeamClass::getTopPlayerPoints(){
    int maxPoints=0;
    string fName;
    string lName;
    int currentPoints=0;
    PlayerClass maxPointsPlayer;
    
    for (int i=0; i < 11; i++){
        currentPoints = teamPlayers[i].getPoints();
        
        if (currentPoints >= maxPoints){
            maxPoints = currentPoints;
            maxPointsPlayer = teamPlayers[i];
        }
        
    }
    return maxPointsPlayer;
}
