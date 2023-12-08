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

void TeamClass::setPoints(int points){
    teamPoints = points;
}

int TeamClass::getPoints(){
    return teamPoints;
}

void TeamClass::addPlayer(PlayerClass player){
    if(currentPosition < 11){
        teamPlayers[currentPosition] = player;
        currentPosition++;
    }
}


string TeamClass::displayPlayers(){
    string players = "";
    
    for (int i=0; i < 11; i++){
        players += teamPlayers[i].getFirstName() + " ";
    }
    return players;
}
