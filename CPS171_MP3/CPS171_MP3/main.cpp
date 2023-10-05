//
//  main.cpp
//  CPS171_MP3
//
//  Created by Oliver McMillen on 9/21/23.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

ifstream inFile;
string str;

//TODO
//Use array to ready in data and interpret, then use if else/switch statement on that array segment, then erase array each record
string cellData[3];
string testVar;

int main(int argc, const char * argv[]) {
    
    inFile.open("dataFileIn.txt");
    
    if (inFile.fail())
        cout << endl << "File not found!" << endl;
    else{

        cout << "Cellphone charges - MP3 by Oliver McMillen" << endl << endl;
        cout << setw(8) << left << "Time" << setw(10) << "Duration" << setw(15) << "Type of call" << setw(25)
        << "Minutes used so far" << setw(10) << "Cost" << endl;
        
        // While no end of file error exists, read in data
        while(!inFile.eof()){
            getline(inFile, str);
            cout << left << setw(33) << str << setw(25)<< "123" << "$1.30" << endl;
            
        }
        inFile.close();
    }
    
    
    return 0;
}
