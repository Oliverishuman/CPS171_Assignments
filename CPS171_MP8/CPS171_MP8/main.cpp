//
//  main.cpp
//  CPS171_MP8
//
//  Created by Oliver McMillen on 12/8/23.
//

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
    TeamClass arrOfTeams[4];
    int i= 0;
    string teamName = " ";
    list<string> listOfWords = {};
    
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
//                cout << endl;
            }
            
            //If team name is empty, SET TEAM NAME for the new team to iterate
            if (teamName == " "){
                teamName = str;
                arrOfTeams[i].setName(teamName);
                continue;
            }
            
//            cout << teamName << endl;

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
        arrOfTeams[j].displayPlayers(); cout << endl;
        
        //Write code here and write rest of funtions to implement in classes
    }
    
    for (int k=0; k < 4; k++){
        cout << "The player with the most points on Team #" << k+1 << " is " << arrOfTeams[k].getTopPlayerPoints().getFirstName() << " " << arrOfTeams[k].getTopPlayerPoints().getLastName(); cout << endl;

    }

    cout << endl;
    return 0;
}
