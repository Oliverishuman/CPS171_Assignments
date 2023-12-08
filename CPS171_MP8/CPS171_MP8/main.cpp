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
                cout << endl;
            }
            
            //If team name is empty, SET TEAM NAME for the new team to iterate
            if (teamName == " "){
                teamName = str;
                arrOfTeams[i].setName(teamName);
                continue;
            }
            
            cout << teamName << endl;

            //Initializes new player class for each line read after the team name
            PlayerClass player = PlayerClass();
            
            //SplitString fucntion will SPLIT SENTENCE INTO WORDS so variables can be assigned
            splitString(str, listOfWords);
            int count = 0;
            for (auto word : listOfWords){
                cout << word << endl;
                
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
    cout << endl;
    
    
    
    
    //For each team, print the name and their points
    for (int j=0; j < 4; j++){
        cout << arrOfTeams[j].getName() << ", their points are: " << arrOfTeams[i].getPoints() << endl;
        cout << arrOfTeams[j].displayPlayers() << endl << endl;


    }

    cout << endl;
    return 0;
}
