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
            
        } else {
            listOfWords.insert(listOfWords.end(), word);
        }
    }
    
    //Returns a list of words from a specific line interpreted from the .txt file
    return listOfWords;
}







errorStatus checkWordSpelling(string userWord, string correctSpellingWord, errorStatus& errorStatus){
    errorStatus = ERROR;
    int errorCount = 0;
    long wordLength = 0;
    
    
    long userWordLength = userWord.length();
    long correctSpellingWordLength = correctSpellingWord.length();
    
    if (userWordLength < correctSpellingWordLength){
        wordLength = correctSpellingWordLength;
    } else{
        wordLength = userWordLength;
    }
    
    if (userWord == correctSpellingWord){
        errorStatus = CORRECT;
        
        cout << "error status: " << errorStatus << endl;

    } else if (userWordLength == correctSpellingWordLength){
        
        
        for (int j=0; j < wordLength; j++){
            cout << "-letter " << userWord[j] << endl;
            /*
             If the letter in userWord matches the next letter in correctSpellingWord, and the
             next letter in userWord matches the current letter in correctSpellingWord, its's transposition
            */
            if (userWord[j] == correctSpellingWord[j + 1] && userWord[j + 1] == correctSpellingWord[j]) {
                errorStatus = TRANSPOSITION;
                errorCount++;
                //Incrememnts the position so the next iteration isn't mistaken by the transposed letter
                j++;
                
                cout << "error status: " << errorStatus << endl;

            }
            //Else if statement because a substitution and transposition cannot occur with the same letter
            else if (userWord[j] != correctSpellingWord[j]){
                errorStatus = SUBSTITUTION;
                errorCount++;
                
                cout << "error status: " << errorStatus << endl;
                

            }
        }
        
    } else {
        for (int i = 0; i < wordLength; i++) {
            cout << "-letter " << userWord[i] << endl;

            //If character at position 'i' in userWord is not equal to that in correctSpellingWord
            if (userWord[i] != correctSpellingWord[i]) {
                
                //Deletion check
                if (userWordLength == correctSpellingWordLength - 1) {
                    if (userWord.substr(i) == correctSpellingWord.substr(i + 1)){
                        
                        
                        errorStatus = DELETION;
                        errorCount++;
                        //                    i++;
                        
                        cout << "error status: " << errorStatus << endl;
                        break;
                    }
                }
                
                //Insertion check
                else if (userWordLength == correctSpellingWordLength + 1) {
                    if (userWord.substr(i+1) == correctSpellingWord.substr(i)){
                        errorStatus = INSERTION;
                        errorCount++;
                        
                        cout << "error status: " << errorStatus << endl;
                        break;
                    }
                }
//                else if (userWordLength == correctSpellingWordLength + 1 && userWord.substr(0,i) == correctSpellingWord.substr(0,i)){
//                    errorStatus = INSERTION;
//                    errorCount++;
//                }

                    errorStatus = SUBSTITUTION;
                    errorCount++;
                    
                    cout << "error status: " << errorStatus << endl;
                
                //Substituition check if userWord length is not the same as correctSpellingWordLength
//                if (userWord[i + 1] == correctSpellingWord[i + 1]){
//                    errorStatus = SUBSTITUTION;
//                    errorCount++;
//                    
//                    cout << "error status: " << errorStatus << endl;
//
//                }
                
//                break;
            }
        }
    }
    
        if (errorCount >= 2){
            errorStatus = ERROR;
        }
    cout << "error count: " << errorCount << endl;
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
    
    
    inFile.open("mp7spelling_copy.txt");
    
    //If file is not found, echo error message to console
    if (inFile.fail())
        cout << endl << "File not found!" << endl;
    else{
        cout << "Spelling Correction - MP7 by Oliver McMillen" << endl << endl;
        
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
                
                //Validates the error status and prints proper message
                if (errorStatus == 5){
                    errorString = "is too bad to be a mispelling";
                    errorCount++;
                } else if (errorStatus == 4){
                    errorString = "has one character inserted";
                    insertCount++;
                }else if (errorStatus == 3){
                    errorString = "has one character deleted";
                    deleteCount++;
                } else if (errorStatus == 2){
                    errorString = "contains a transposition";
                    transCount++;
                } else if (errorStatus == 1){
                    errorString = "has one character substituted";
                    subCount++;
                }else if (errorStatus == 0){
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
