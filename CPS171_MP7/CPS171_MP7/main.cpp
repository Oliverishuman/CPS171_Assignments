/*
  main.cpp
  CPS171_MP7

  Created by Oliver McMillen on 11/27/23.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <list>


using namespace std;

list<string> splitString(string sentenceToBeSplit, list<string>& listOfWords, string& correctSpellingWord)
{
    string word;
    stringstream splitstream(sentenceToBeSplit);
//    string correctSpellingWord;
    
    //List is initialized as empty each time the function is called
    listOfWords = {};
    
    while (splitstream >> word) {
        //Sets the correct spelling of the word if not set already
        if (correctSpellingWord.empty()){
            correctSpellingWord = word;
        }
        listOfWords.insert(listOfWords.end(), word);
    }
    
    //Returns a list of words from a specific line interpreted from the .txt file
    return listOfWords;
}



int main(int argc, const char * argv[]) {
    ifstream inFile;
    string str;
    list<string> listOfWords = {};
    
    enum errorStatus{CORRECT, SUBSTITUTION, TRANSPOSITION, DELETION, INSERTION, ERROR};
    errorStatus errorStatus;
    string errorString;
    
    inFile.open("mp7spelling.txt");
    
    //If file is not found, echo error message to console
    if (inFile.fail())
        cout << endl << "File not found!" << endl;
    else{
        cout << "Spelling Errors - MP3 by Oliver McMillen" << endl << endl;

        //While there is a new line with contents, proceed
        while(getline(inFile, str)){
            string correctSpellingWord;

            /*
            Call splitString function to split each word from sentence into a list.
            Reference parameter for the listOfWords so I can continue to use the data
            For each line in the txt file, a new list is created and the previous list is wiped.
            */
            splitString(str, listOfWords, correctSpellingWord);
            
            //Print list of words for each new list created
            cout << "**** Starting new line ****" << endl;
            cout << "The word being checked is " << correctSpellingWord << endl << endl;
            for (auto word : listOfWords){
                cout << "User word is " << word << "\n";
                
                
                cout  << "The user word " << endl << endl;
            }
            cout << endl;
        }
        
        
        //Check what list of words for the last new list created
//        cout << "*** Printing the last words added to the empty list ***" << endl;
//        for (auto word : listOfWords){
//                cout << word << "\n";
//        }
        
        inFile.close();
    }

    return 0;
}
