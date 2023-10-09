/*
 CPS171_MP3 - Monthly Cell Phone Bill Calculator
 
 This program is to read in a text file in the resources folder, each line in the text file contains 3 points of data,
 1st is the time of call, 2nd is the duration of the call, and 3rd is the type, L = long distane, A = Local area.
 
 The program will read each record, declare whether it's a day or night call, how many minutes should be charged based on the
 requirements, and charge the proper rate according to the type of call.
 
 It will output a list to the console containing a header with the column names and data from the text file, as well as the total
 cost of minutes charged over 200 minutes and the monthly bill total costOfCall.
 
 Created by Oliver McMillen on 10/2/23.
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;
const int dayCallStart = 600; //Day call starts at 6 AM
const int dayCallEnd = 1759; //Day call ends at 5:59 PM
const int monthlyMinuteLimit = 200; //The number of minutes the basic monthly rate covers
const double basicMonthlyRate = 39.99; //The $ amount of the basic monthly rate of 200 minutes

int main(int argc, const char * argv[]) {
    ifstream inFile;
    char typeOfCall;
    int timeCallMade;
    int durationOfCall;
    int futureMinutesUsed;
    int minutesUsedTotal = 0;
    int chargedMinutes = 0;
    double monthlyBillTotal = 0.0;
    double over200MinutesTotalCost = 0.0;
    double costOfCall = 0.00;
    bool isDayCall;
    
    
    inFile.open("dataFileIn.txt");
    
    //If file is not found, echo error message to console
    if (inFile.fail())
        cout << endl << "File not found!" << endl;
    else{
        
        cout << "Cellphone charges - MP3 by Oliver McMillen" << endl << endl;
        cout << setw(8) << left << "Time" << setw(10) << "Duration" << setw(15) << "Type of call" << setw(23)
        << "Minutes used so far" << "costOfCall" << endl;
        
        //While file instream is not empty, do this
        while(inFile >> timeCallMade >> durationOfCall >> typeOfCall){
            futureMinutesUsed = durationOfCall + minutesUsedTotal;
            
            //If the call is made at or after dayCallStart && at or before dayCallEnd, then it is a day call
            if (timeCallMade >= dayCallStart && timeCallMade <= dayCallEnd){
                isDayCall = true;
            }
            else{
                isDayCall = false;
            }
            
            
            if (isDayCall == false){
                cout << left << setw(8) << timeCallMade << setw(10) << durationOfCall << setw(15) << typeOfCall
                << setw(23) << "Night call is free"  << endl;
            }
            else{
                
                //If current minutes used is less than 200 and future minutes used is greater than 200, then calculate charged minutes
                if (minutesUsedTotal < monthlyMinuteLimit && futureMinutesUsed > monthlyMinuteLimit){
                    chargedMinutes = (futureMinutesUsed - monthlyMinuteLimit);
                    
                    //If minutes used is greater or equal to 200, then the duration of call equals charged minutes
                } else if (minutesUsedTotal >= monthlyMinuteLimit){
                    chargedMinutes = durationOfCall;
                } else {
                    chargedMinutes = 0;
                }
                
                //Accumulates total minutes used
                minutesUsedTotal += durationOfCall;
                
                //If type of call is Local Area
                if (typeOfCall == 'A'){
                    costOfCall = chargedMinutes * (0.29);
                //If type of call is long distance
                } else if (typeOfCall == 'L'){
                    costOfCall = chargedMinutes * (0.69);
                }
                
                cout << fixed << left << setw(8) << timeCallMade << setw(10) << durationOfCall << setw(15)
                << typeOfCall << setw(23) << minutesUsedTotal << setprecision(2) << "$" << costOfCall << endl;
                
                //Accumulates the total costOfCall of charges over 200 minutes
                over200MinutesTotalCost += costOfCall;
            }
        }
    }
    monthlyBillTotal = over200MinutesTotalCost + basicMonthlyRate;
    
    cout << "\nThe total charged over 200 minutes is $" << fixed << setprecision(2) << over200MinutesTotalCost
    << endl;
    
    cout << "The monthly bill total is $" << fixed << setprecision(2) << monthlyBillTotal
    << " (Includes the basic monthly rate of $" << basicMonthlyRate << ")" << endl << endl;
    
    inFile.close();
    return 0;
}
