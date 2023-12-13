/*
  main.cpp
  CPS171_MP8
 
 This program is to read in text from a file named teams.txt. This file contains 4 soccer teams, each with 11 players listed below.
 Each team will be stored in an array, and each player will be stored into an array located inside the respective team. 
 For each team, the program will list out the team name, team points, and the information for each player belonging
 to that team. The program will then output the players with the most points on each team. Lastly, it
 will display the 2 teams with the most points.

  Created by Oliver McMillen on 12/8/23.
*/

#include <iostream>
#include <fstream>
#include <list>
#include <sstream>
#include <string>
#include "TeamClass.hpp"
#include "PlayerClass.hpp"

using namespace std;

list<string> splitString(string sentenceToBeSplit, list<string>& listOfWords)
{
    string word;
    stringstream splitstream(sentenceToBeSplit);
    
    //List is cleared each time the function is called
    listOfWords.clear();
    
    while (splitstream >> word) {
            listOfWords.insert(listOfWords.end(), word);
    }
    
    return listOfWords;
}


int main(int argc, const char * argv[]) {
    ifstream inFile;
    string str;
    string teamName = " ";
    list<string> listOfWords = {};
    TeamClass arrOfTeams[4];
    TeamClass teamFirstHighestPoints;
    TeamClass teamSecondHighestPoints;
    int i = 0;
    int FirstMaxPoints = 0;
    int SecondMaxPoints = 0;

    
    inFile.open("teams.txt");
    
    //If file is not found, print error message to console
    if (inFile.fail())
        cout << endl << "File not found!" << endl;
    else{
        cout << "Soccer Game - MP8 by Oliver McMillen" << endl << endl;
        
        while(getline(inFile, str)){
            
            //Detects new line in teams.txt file, which INDICATES NEW TEAM
            if (str == " "){
                i++;
                teamName = " ";
            }
            
            //If team name is empty, SET TEAM NAME for the new team to iterate
            if (teamName == " "){
                teamName = str;
                arrOfTeams[i].setName(teamName);
                arrOfTeams[i].setNumber(i);
                continue;
            }
            
            //Initializes new player class for each line read after the team name
            PlayerClass player = PlayerClass();
            
            //SplitString fucntion will SPLIT SENTENCE INTO WORDS so variables can be assigned
            splitString(str, listOfWords);
            int count = 0;
            for (auto word : listOfWords){
                if (count == 0){
                    int playerNumber = stoi(word);
                    player.setNumber(playerNumber);
                } else if (count == 1){
                    string playerFirstName = word;
                    player.setFirstName(playerFirstName);
                } else if (count == 2){
                    string playerLastName = word;
                    player.setLastName(playerLastName);
                } else if (count == 3){
                    int playerPoints = stoi(word);
                    player.setPoints(playerPoints);
                }
                count++;
            }
            arrOfTeams[i].addPlayer(player);
        }
        inFile.close();
    }
    
    //For each team, print the name and their points, along with their players information
    for (int j=0; j < 4; j++){
        TeamClass iteratingTeam = arrOfTeams[j];
        int teamNumber = j+1;
        string teamName = iteratingTeam.getName();
        int teamPoints = iteratingTeam.getPoints();
        
        cout << "TEAM #" << teamNumber << endl;
        cout << "Team name: " << teamName << endl;
        cout << "Team points: " << teamPoints << endl << endl;
        
        cout << "Players of TEAM #" << teamNumber << ": " << teamName <<  endl;
        cout << fixed << right << setw(12) << "Player Name" << setw(26) << "Player Number"
         << setw(17) << "Player Points" << endl;
        cout << fixed << right << setw(12) << "***********" << setw(26) << "*************"
         << setw(17) << "*************" << endl;
        arrOfTeams[j].displayPlayers(); cout << endl << endl;
        
    }
    
    //For each team, print the player name with the most points
    for (int k=0; k < 4; k++){
        cout << "The player with the most points on Team #" << k+1 << " is " << arrOfTeams[k].getTopPlayerPoints().getFirstName() 
        << " " << arrOfTeams[k].getTopPlayerPoints().getLastName(); cout << endl;
    }
        cout << endl;
        
        cout << "The top two teams with the most points are:" << endl;
        for (int n=0; n < 4; n++){
            /* If first max points is less than current number, set to current number
             and set second max points to the previous first max points value */
            if (FirstMaxPoints < arrOfTeams[n].getPoints()){
                SecondMaxPoints = FirstMaxPoints;
                teamSecondHighestPoints = teamFirstHighestPoints;
                
                FirstMaxPoints = arrOfTeams[n].getPoints();
                teamFirstHighestPoints = arrOfTeams[n];
            }

        }
    //Print the sentence displaying the two teams with the most points
        cout << "Team #" <<  teamFirstHighestPoints.getNumber() << " with points " << teamFirstHighestPoints.getPoints() << " and Team #" << teamSecondHighestPoints.getNumber() << " with points " << teamSecondHighestPoints.getPoints() << endl;

    cout << endl;
    return 0;
}
