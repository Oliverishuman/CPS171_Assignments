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

//Reference parameteres send data back to the initial variable calling the function, in order to print the data in the format
bool searchTableForWord(char tableToSearch[tableSize][tableSize], string word, string& direction, int& startRow, int& startCol){

    int wordLength = size(word);
    transform(word.begin(), word.end(), word.begin(), ::toupper);

    //Horizontal search
    for (int i = 0; i < tableSize; i++) {
        for (int j = 0; j <= tableSize - wordLength; j++) {
            string substring(&tableToSearch[i][j], wordLength);
//            cout << substring << " (at position " << i << "," << j << ")" << endl;
            if (word == substring) {
                startRow = i;
                startCol = j;
                direction = "Horizontal";
                return true;
            }
        }
    }
    
    //Vertical search
    for (int i = 0; i <= tableSize - wordLength; i++) {
        for (int j = 0; j < tableSize; j++) {
            string substring;
            for (int k = 0; k < wordLength; k++) {
                substring += tableToSearch[i + k][j];
            }
            if (word == substring) {
                startRow = i;
                startCol = j;
                direction = "Vertical";
                return true;
            }
        }
    }
    
    //Diagonal search
    for (int i = 0; i <= tableSize - wordLength; i++) {
        for (int j = 0; j <= tableSize - wordLength; j++) {
            string substring;
            for (int k = 0; k < wordLength; k++) {
                substring += tableToSearch[i + k][j + k];
            }
            
            if (word == substring) {
                startRow = i;
                startCol = j;
                direction = "Diagonal";
                return true;
            }
        }
    }
    
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
        
        //Print words to search
        cout << "Words to search:" << endl;
        printWordsToSearch(wordsToSearch);
        
        cout << endl;

        //For each word in the list of words, search the word and print the result
        for (string word : wordsToSearch){
            int startRow;
            int startCol;
            string direction;
            
            bool result = searchTableForWord(tableToSearch, word, direction, startRow, startCol);

            if (result != 0){
                cout << word << " has been found at " << startRow << "," << startCol << " going " << direction <<  endl;
            } else {
                cout << word << " is not found" << endl;
            }
        }
        
        cout << endl;
        return 0;
        
    }
}
