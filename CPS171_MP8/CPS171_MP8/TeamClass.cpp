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
    if(currentPosition < 11){
        teamPlayers[currentPosition] = player;
        currentPosition++;
    }
}


void TeamClass::displayPlayers(){
    string players = "";
    
    for (int i=0; i < 11; i++){
//        cout << teamPlayers[i].getNumber() << " " << teamPlayers[i].getFirstName() << " " << endl;
        
        cout << fixed << right << setw(2) << i+1 << fixed << setw(3) << left << "." << setw(12) << teamPlayers[i].getFirstName()
        << setw(18) << teamPlayers[i].getLastName() << setw(17) << teamPlayers[i].getNumber() << setw(21) << teamPlayers[i].getPoints() << endl;
    }
  
}
