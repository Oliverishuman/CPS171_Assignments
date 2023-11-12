/*
  main.cpp
  CPS171_MP6

 Read the file in
 Fill in the 2D array of a size 8x8
 find the words in the table
 
  Created by Oliver McMillen on 11/10/23.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

ifstream fileIn;
string str;
const int tableSize = 8;
const int wordsToSearchSize = 6;


void printTable(char tableToSearch[tableSize][tableSize]){
    for (int f = 0; f < tableSize; f++) {
        for (int p = 0; p < tableSize; p++) {
            cout << tableToSearch[f][p] << " ";
        }
        cout << endl;
    }
}

void printWordsToSearch(string wordsToSearch[wordsToSearchSize]){
    for (int k=0; k < wordsToSearchSize; k++){
        cout << wordsToSearch[k] + "\n";
    }
}

bool searchTableForWord(char tableToSearch[tableSize][tableSize], string word){
    int wordLength = size(word);
    
    cout << wordLength << endl;
    
    return false;
}

int main(int argc, const char * argv[]) {

    char tableToSearch[tableSize][tableSize];
    string wordsToSearch [wordsToSearchSize];
    int k=0;
    
    fileIn.open("DataFileIn.txt");
    if (fileIn.fail())
        cout << endl << "File not found!" << endl;
    else{
        //Create 2D array to store data
        for (int i = 0; i < tableSize; ++i) { //Rows
            for (int j = 0; j < tableSize; ++j) { //Columns
                fileIn >> tableToSearch[i][j];
            }
        }
        

        //Store words to search into array
        while(getline(fileIn, str)){
            fileIn >> wordsToSearch[k];
            k++;
        }
        fileIn.close();
        
        
    
        
        //Print table to search
        cout << "Table to search:" << endl;
        printTable(tableToSearch);
        
        cout << endl;
        
        //Print words to search
        cout << "Words to search:" << endl;
        printWordsToSearch(wordsToSearch);
        
        cout << endl;

        searchTableForWord(tableToSearch, "Fit");
        
        cout << endl;
        return 0;
        
    }
}
