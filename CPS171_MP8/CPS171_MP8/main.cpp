//
//  main.cpp
//  CPS171_MP8
//
//  Created by Oliver McMillen on 12/8/23.
//

#include <iostream>
#include <fstream>
#include "TeamClass.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    ifstream inFile;
    string str;

    
    inFile.open("teams.txt");
    
    //If file is not found, print error message to console
    if (inFile.fail())
        cout << endl << "File not found!" << endl;
    else{
        cout << "Soccer Game - MP8 by Oliver McMillen" << endl << endl;
        
//        while(getline(inFile, str)){
//            cout << "This is str: " << str << endl << endl;
//        }
        
        
        TeamClass team1 = TeamClass();
        team1.setName("Smuckles");
//
        cout << "This is the team name: " << team1.getName() << endl;
        cout << "This is their points: " << team1.getPoints() << endl;
        
        inFile.close();
    }
    
    cout << endl;
    return 0;
}
