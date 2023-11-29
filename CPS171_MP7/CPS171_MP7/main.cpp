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

list<string> splitString(string sentenceToBeSplit, list<string>& listOfWords)
{
    string word;
    stringstream splitstream(sentenceToBeSplit);
    
    //List is initialized as empty each time the function is called
    listOfWords = {};
    
    while (splitstream >> word) {
        listOfWords.insert(listOfWords.end(), word);
    }
    
    //Returns a list of words from a specific line interpreted from the .txt file
    return listOfWords;
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
        
        cout << "Spelling Errors - MP3 by Oliver McMillen" << endl << endl;

        //While there is a new line with contents, proceed
        while(getline(inFile, str)){
            /*
            Call splitString function to split each word from sentence into a list.
            Reference parameter for the listOfWords so I can continue to use the data
            For each line in the txt file, a new list is created and the previous list is wiped.
            */
            splitString(str, listOfWords);
            
            //Check what list of words for each new list created
            cout << "**** Printing new list now ****" << endl;
            for (auto word : listOfWords){
                cout << word << "\n";
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
