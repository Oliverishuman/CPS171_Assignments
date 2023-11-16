/*
 main.cpp
 CPS171_MP6

 Program is written to receive an input .txt file with an 8x8 table of characters and a list of words to search for.
 The program will store the 8x8 table in a 2-Dimensional array, and store the words to search in a standard array.
 Each word in the list will be searched, if a match is found the row and column of the starting letter will be listed,
 otherwise, the word will have a direction of "Not found"
 
 Created by Oliver McMillen on 11/10/23.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

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

/*
 Reference parameteres send data back to the initial
 variable calling the function, in order to print the data in the format
 */
bool searchTableForWord(char tableToSearch[tableSize][tableSize], string word, string& direction, int& startRow, int& startCol){

    int wordLength = int(size(word));
    //Changes all characters in word to uppercase
    transform(word.begin(), word.end(), word.begin(), ::toupper);

    //Horizontal search
    for (int i = 0; i < tableSize; i++) {
        for (int j = 0; j <= tableSize - wordLength; j++) {
            //Create substring of next letters horizontally within range of word length
            string substring(&tableToSearch[i][j], wordLength);
            
            //If word to search matches the substring, assign the variables to output
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
            //Create substring of next letters vertically within range of word length
            for (int k = 0; k < wordLength; k++) {
                substring += tableToSearch[i + k][j];
            }
            
            //If word to search matches the substring, assign the variables to output
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
            //Create substring of next letters diagonally within range of word length
            for (int k = 0; k < wordLength; k++) {
                substring += tableToSearch[i + k][j + k];
            }

            //If word to search matches the substring, assign the variables to output
            if (word == substring) {
                startRow = i;
                startCol = j;
                direction = "Diagonal";
                return true;
            }
        }
    }
    //If no match is found, return false
    return false;
}


int main(int argc, const char * argv[]) {
    ifstream fileIn;
    string str;

    char tableToSearch[tableSize][tableSize];
    string wordsToSearch[wordsToSearchSize];
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
    
        //Store words to search into wordsToSearch array
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


        //Output header
        cout << fixed << setw(8) << "Word" << setw(14) << "Row"
        << setw(18) << "Column " << setw(20) << "Direction" << endl;
        cout << "----------------------------------------------------------------" << endl;
        
        //For each word in the list of words, search the word and define the result, then output based on result
        for (string word : wordsToSearch){
            int startRow;
            int startCol;
            string direction;
            
            bool result = searchTableForWord(tableToSearch, word, direction, startRow, startCol);

            if (result) {
                cout << fixed << right << setw(8) << word << setw(14) << startRow << setw(17) << startCol << setw(21) << direction << endl;
            } else {
                cout << fixed << right << setw(8) << word << setw(14) << " " << setw(17) << " " << setw(21) << "Not Found" << endl;
            }
        }
        
        cout << endl;
        return 0;
        
    }
}

