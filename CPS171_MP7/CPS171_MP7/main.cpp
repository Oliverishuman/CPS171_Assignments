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
enum errorStatus{CORRECT, SUBSTITUTION, TRANSPOSITION, DELETION, INSERTION, ERROR};


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







errorStatus checkWordSpelling(string userWord, string correctSpellingWord, errorStatus& errorStatus){
    errorStatus = ERROR;

    if (userWord == correctSpellingWord){
        errorStatus = CORRECT;
    }
    long userWordLength = userWord.length();
    long correctSpellingWordLength = correctSpellingWord.length();
    
    
    if (userWordLength == correctSpellingWordLength){
        int count=0;
        
        for (int j=0; j < userWordLength; j++){
            if (userWord[j] != correctSpellingWord[j]){
                count++;
            }
        }
        
        if (count == 1){
            errorStatus = SUBSTITUTION;
        }
    }
    
    for (int i = 0; i < correctSpellingWordLength; i++) {
        //If character at position 'i' in userWord is not equal to that in correctSpellingWord
        if (userWord[i] != correctSpellingWord[i]) {
            //Transposition check
            if (i + 1 < userWordLength && userWord[i] == correctSpellingWord[i + 1] && userWord[i + 1] == correctSpellingWord[i]) {
                errorStatus = TRANSPOSITION;
            }

            //Deletion check
            if (userWordLength == correctSpellingWordLength - 1 && userWord.substr(i) == correctSpellingWord.substr(i + 1)) {
                errorStatus = DELETION;
            }

            //Insertion check
            if (userWordLength == correctSpellingWordLength + 1 && userWord.substr(i+1) == correctSpellingWord.substr(i)) {
                errorStatus = INSERTION;
            }
//            if (userWordLength == correctSpellingWordLength + 1) {
//                errorStatus = INSERTION;
//            }
            
            
            break;
        }
    }
    
    return errorStatus;
}








int main(int argc, const char * argv[]) {
    ifstream inFile;
    string str;
    list<string> listOfWords = {};
    

    
    inFile.open("mp7spelling.txt");
    
    //If file is not found, echo error message to console
    if (inFile.fail())
        cout << endl << "File not found!" << endl;
    else{
        cout << "Spelling Errors - MP7 by Oliver McMillen" << endl << endl;

        //While there is a new line with contents, proceed
        while(getline(inFile, str)){
            string correctSpellingWord;
            errorStatus errorStatus;
            string errorString;
            
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
                
                
                checkWordSpelling(word, correctSpellingWord, errorStatus);
//                cout << errorStatus << endl;
                
                //Validates the error status and prints proper message
                if (errorStatus == 5){
                    errorString = "is too bad to be a mispelling";
                } else if (errorStatus == 4){
                    errorString = "has one character inserted";
                }else if (errorStatus == 3){
                    errorString = "has one character deleted";
                } else if (errorStatus == 2){
                    errorString = "contains a transposition";
                } else if (errorStatus == 1){
                    errorString = "has one character substituted";
                }else if (errorStatus == 0){
                    errorString = "is correct";
                }
                
                
                cout  << "The user word " << errorString << endl << endl;
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
