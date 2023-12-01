/*
 CPS171_MP7 - Spelling Coreection
 
 This program reads in a .txt file containing multiple lines of strings. In the .txt file, each line first contains
 a correct spelling of a specific word, then follows are multiple attempts at spelling that word.
 
 First the program will call a function to split each line into an independent list of strings. Then for each list,
 each word in the list will be passed through the checkWordSpelling function. This will return an error status, which
 then depicts which message is printed to the console. Lastly, the program will print to the console a count of
 each error status.
 
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
    
    //List is cleared each time the function is called
    listOfWords.clear();
    
    while (splitstream >> word) {
        //Sets the correct spelling of the word if empty
        if (correctSpellingWord.empty()){
            correctSpellingWord = word;
        } else {
            //Only inserts words to the list if the correctSpellingWord is set
            listOfWords.insert(listOfWords.end(), word);
        }
    }
    
    return listOfWords;
}

errorStatus checkWordSpelling(string wordToCheck, string correctSpellingWord, errorStatus& errorStatus){
    errorStatus = ERROR;
    int errorCount = 0;
    long wordLength = 0;
    long wordToCheckLength = wordToCheck.length();
    long correctSpellingWordLength = correctSpellingWord.length();
    
    //Sets wordLength to the length of the longest word to iterate through ao no letters are missed
    if (wordToCheckLength < correctSpellingWordLength){
        wordLength = correctSpellingWordLength;
    } else {
        wordLength = wordToCheckLength;
    }
    
    //Correct Check
    if (wordToCheck == correctSpellingWord){
        errorStatus = CORRECT;
    } else if (wordToCheckLength == correctSpellingWordLength){
        for (int j=0; j < wordLength; j++){
            
            /*
             Transposition Check
             If the current letter in wordToCheck matches the next letter in correctSpellingWord, and the
             next letter in wordToCheck matches the current letter in correctSpellingWord, it's transposition
             */
            if (wordToCheck[j] == correctSpellingWord[j + 1] && wordToCheck[j + 1] == correctSpellingWord[j]) {
                errorStatus = TRANSPOSITION;
                errorCount++;
                
                //Incrememnts the position so the next iteration isn't mistaken by the transposed letter
                j++;
            }
            //Substitution Check
            else if (wordToCheck[j] != correctSpellingWord[j]){
                errorStatus = SUBSTITUTION;
                errorCount++;
            }
        }
        
    } else {
        for (int i = 0; i < wordLength; i++) {
            if (wordToCheck[i] != correctSpellingWord[i]) {
                
                //Deletion Check
                if (wordToCheckLength == correctSpellingWordLength - 1) {
                    if (wordToCheck.substr(i) == correctSpellingWord.substr(i + 1)){
                        errorStatus = DELETION;
                        errorCount++;
                        break;
                    }
                }
                
                //Insertion Check
                else if (wordToCheckLength == correctSpellingWordLength + 1) {
                    if (wordToCheck.substr(i+1) == correctSpellingWord.substr(i)){
                        errorStatus = INSERTION;
                        errorCount++;
                        break;
                    }
                }
                
                /*
                 If both word lengths are not equal to each other,
                 and the letter does not meet insertion or deletion criteria, it must be substitution
                 */
                errorStatus = SUBSTITUTION;
                errorCount++;
                
            }
        }
    }
    
    //Error Check
    if (errorCount >= 2){
        errorStatus = ERROR;
    }
    
    return errorStatus;
}


int main(int argc, const char * argv[]) {
    ifstream inFile;
    string str;
    list<string> listOfWords = {};
    int correctCount=0;
    int subCount=0;
    int transCount=0;
    int deleteCount=0;
    int insertCount=0;
    int errorCount=0;
    
    
    inFile.open("mp7spelling.txt");
    
    //If file is not found, print error message to console
    if (inFile.fail())
        cout << endl << "File not found!" << endl;
    else{
        cout << "Spelling Correction - MP7 by Oliver McMillen" << endl << endl;
        
        while(getline(inFile, str)){
            string correctSpellingWord;
            string errorString;
            errorStatus errorStatus;
            
            /*
             Call splitString function to split each word from sentence into a list.
             Reference parameter for the listOfWords so I can continue to use the data
             For each line in the txt file, a new list is created and the previous list is wiped.
             */
            splitString(str, listOfWords, correctSpellingWord);
            
            cout << "******** Starting new line ********" << endl;
            cout << "The word being checked is " << correctSpellingWord << endl << endl;
            
            //For each word, check error and print correct message
            for (auto word : listOfWords){
                cout << "User word is " << word << "\n";
                
                checkWordSpelling(word, correctSpellingWord, errorStatus);
                
                if (errorStatus == 5){
                    errorString = "is too bad to be a mispelling";
                    errorCount++;
                } else if (errorStatus == 4){
                    errorString = "has one character inserted";
                    insertCount++;
                } else if (errorStatus == 3){
                    errorString = "has one character deleted";
                    deleteCount++;
                } else if (errorStatus == 2){
                    errorString = "contains a transposition";
                    transCount++;
                } else if (errorStatus == 1){
                    errorString = "has one character substituted";
                    subCount++;
                } else if (errorStatus == 0){
                    errorString = "is correct";
                    correctCount++;
                }
                
                cout  << "The user word " << errorString << endl << endl;
            }
            cout << endl;
        }
        
        cout << "There were " << correctCount << " correct words" << endl;
        cout << "There were " << subCount << " words with a substitution" << endl;
        cout << "There were " << transCount << " words with a transposition" << endl;
        cout << "There were " << deleteCount << " words with a deletion" << endl;
        cout << "There were " << insertCount << " words with an insertion" << endl;
        cout << "There were " << errorCount << " words that were way off" << endl;
        
        inFile.close();
    }
    
    cout << endl;
    return 0;
}
