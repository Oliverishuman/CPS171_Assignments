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
#include "TeamClass.hpp"

using namespace std;

list<string> splitString(string sentenceToBeSplit, list<string>& listOfWords)
{
    string word;
    stringstream splitstream(sentenceToBeSplit);
    
    //List is cleared each time the function is called
    listOfWords.clear();
    
    while (splitstream >> word) {
        //Sets the correct spelling of the word if empty
            //Only inserts words to the list if the correctSpellingWord is set
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
                cout << "******NEW TEAM******" << endl << endl;
            }
            
            //If team name is empty, SET TEAM NAME for the new team to iterate
            if (teamName == " "){
                teamName = str;
                arrOfTeams[i].setName(teamName);
                continue;
            }
            
            cout << teamName << endl;

            //SplitString fucntion will SPLIT SENTENCE INTO WORDS so variables can be assigned
            splitString(str, listOfWords);
            for (auto word : listOfWords){
                cout << "Word is " << word << endl;
            }
            cout << endl;
            

            
 

        }
        inFile.close();
    }
    
    //For each team, print the name and their points
    for (int i=0; i < 4; i++){
        cout << arrOfTeams[i].getName() << ", their points are: " << arrOfTeams[i].getPoints() << endl;

    }

    cout << endl;
    return 0;
}











//        TeamClass team1 = TeamClass();
//        team1.setName("Smuckles");
//        team1.setPoints(3507);
////
//        cout << "This is the team name: " << team1.getName() << endl;
//        cout << "This is their points: " << team1.getPoints() << endl;
