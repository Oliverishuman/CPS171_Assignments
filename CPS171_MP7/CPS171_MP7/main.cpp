/*
  main.cpp
  CPS171_MP7

  Created by Oliver McMillen on 11/27/23.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>


using namespace std;

void splitString(string str, char del){
    
    // declaring temp string to store the curr "word" upto del
    
    string temp = "";

    for(int i=0; i<(int)str.size(); i++){
        // If cur char is not del, then append it to the cur "word", otherwise
        // you have completed the word, print it, and start a new word.
        
        if(str[i] != del){
            temp += str[i];
            
        }
        else{
            
            cout << temp << " ";
            temp = "";
            
        }
    }
    cout << temp;
}

int main(int argc, const char * argv[]) {
    ifstream inFile;
    string str;
    
    
    inFile.open("mp7spelling.txt");
    
    //If file is not found, echo error message to console
    if (inFile.fail())
        cout << endl << "File not found!" << endl;
    else{
        
        cout << "Spelling Errors - MP3 by Oliver McMillen" << endl << endl;

        while(getline(inFile, str)){
            cout << str << endl;
//            cout << stringToArray(str) << endl;
            
        }
        
        inFile.close();
    }

    return 0;
}
