/*
 CPS171_MP3 - Monthly Cell Phone Bill Calculator
 
 This program is to read in a text file in the resources folder, each line in the text file contains 3 points of data,
 1st is the time of call, 2nd is the duration of the call, and 3rd is the type, L = long distane, A = Local area.
 
 The program will read each record, declare whether it's a day or night call, how many minutes should be charged based on the
 requirements, and charge the proper rate according to the type of call.
 
 It will output a list to the console containing a header with the column names, resulting with a total monthly bill amount.
 
 Created by Oliver McMillen on 10/2/23.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;
const int dayCallStart = 600;
const int dayCallEnd = 1759;
const int nightCallStart = 1800;
const int nightCallEnd = 559;
const int monthlyMinuteLimit = 200;

int main(int argc, const char * argv[]) {
    ifstream inFile;
    char typeOfCall;
    int timeCallMade;
    int durationOfCall;
    int futureMinutesUsed;
    int minutesUsedTotal = 0;
    int chargedMinutes = 0;
    double monthlyBillTotal = 0.0;
    double cost;
    bool isDayCall;
    
    
    inFile.open("dataFileIn.txt");
    
    if (inFile.fail())
        cout << endl << "File not found!" << endl;
    else{
        
        cout << "Cellphone charges - MP3 by Oliver McMillen" << endl << endl;
        cout << setw(8) << left << "Time" << setw(10) << "Duration" << setw(15) << "Type of call" << setw(23)
        << "Minutes used so far" << "Cost" << endl;
        
        //While file instream is not empty
        while(inFile >> timeCallMade >> durationOfCall >> typeOfCall){
            futureMinutesUsed = durationOfCall + minutesUsedTotal;
            
            //If the call is made after 6AM and before 5:59 PM then it is a day call
            if (timeCallMade >= dayCallStart && timeCallMade <= dayCallEnd){
                isDayCall = true;
            }
            else{
                isDayCall = false;
            }
            
            //If it is a night call, else if it is a day call
            if (isDayCall == false){
                cout << left << setw(8) << timeCallMade << setw(10) << durationOfCall << setw(15) << typeOfCall << setw(23) << "Night call is free"  << endl;
            }
            else{
                
                //If current minutes used is less than 200 and future minutes used will be greater than 200
                if (minutesUsedTotal < monthlyMinuteLimit && futureMinutesUsed > monthlyMinuteLimit){
                    //Calculate charged minutes over 200
                    chargedMinutes = (futureMinutesUsed - monthlyMinuteLimit);
                } else if (minutesUsedTotal >= monthlyMinuteLimit){
                    //If minutes used is greater or equal to 200, duration of call equals charged minutes
                    chargedMinutes = durationOfCall;
                }
                
                //Accumulates total minutes used
                minutesUsedTotal += durationOfCall;
                
                if (typeOfCall == 'A'){
                    cost = chargedMinutes * (0.29);
                } else if (typeOfCall == 'L'){
                    cost = chargedMinutes * (0.69);
                } else {
                    cost = 0.00;
                }
                
                cout << fixed << left << setw(8) << timeCallMade << setw(10) << durationOfCall << setw(15)
                << typeOfCall << setw(23) << minutesUsedTotal << setprecision(2) << "$" << cost << endl;
                
                monthlyBillTotal += cost;
            }
        }
    }
    
    cout << "\nThe monthly bill is $" << fixed << setprecision(2) << monthlyBillTotal << endl;
    return 0;
}
