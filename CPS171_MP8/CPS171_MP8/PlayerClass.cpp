//
//  PlayerClass.cpp
//  CPS171_MP8
//
//  Created by Oliver McMillen on 12/8/23.
//

#include "PlayerClass.hpp"

void PlayerClass::setFirstName(string firstName){
    playerFirstName = firstName;
}

string PlayerClass::getFirstName(){
    return playerFirstName;
}

void PlayerClass::setLastName(string lastName){
    playerLastName = lastName;
}

string PlayerClass::getLastName(){
    return playerLastName;
}

void PlayerClass::setPoints(int points){
    playerPoints = points;
}

int PlayerClass::getPoints(){
    return playerPoints;
}

void PlayerClass::setNumber(int number){
    playerNumber = number;
}

int PlayerClass::getNumber(){
    return playerNumber;
}
