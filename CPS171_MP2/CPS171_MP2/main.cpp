/*
  CPS271_MP2 - KERBAA Train report

  This program is to read 4 lines of data from a .txt file in the source folder, the 4 lines of data each represent the name of railroad,
  the destination, number of ore cars, and the current price of coal per short ton. In return, the program will write the derived data to a .txt file
  returning the total weight of coal, total value of shipment, and total surcharge of the shipment.

  Created by Oliver McMillen on 9/12/23.
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

ifstream fin;
ofstream fout;
string str;
string railroadName;
string destination;
const double carWeightCapacity = 74.5;
const double currentSurcharge = 0.0031;
int numOreCars;
double pricePerShortTonCoal;
double totalShipmentWeight;
double totalShipmentValue;
double totalShipmentSurcharge;


int main(int argc, const char * argv[]) {
    fin.open("dataFileIn.txt");
    
    // Opens .txt file and reads expected 4 lines of data, if the specified file is not found, echo "File not found!" to the console
    if (fin.fail())
        cout << endl << "File not found!" << endl;
    else{
            getline(fin, str);
            railroadName = str;
        
            getline(fin, str);
            destination = str;
        
            getline(fin, str);
            numOreCars = stoi(str);
        
            getline(fin, str);
            pricePerShortTonCoal = stof(str);
        
        fin.close();
    }
    
    totalShipmentWeight = (numOreCars * carWeightCapacity);
    totalShipmentValue = (totalShipmentWeight * pricePerShortTonCoal);
    totalShipmentSurcharge = (totalShipmentValue * currentSurcharge);
    
    // Creates .txt file to write data to, if sytem cannot create new file it will echo "File couldn't be opened!" to the console.
    fout.open("dataFileOut.txt");

    if (fout.fail())
        fout << endl << "File couldn't be opend!" << endl;
    else{
        fout << "KERBAA & M COAL TRAIN REPORT – Oliver McMillen" << endl << endl;

        fout << "Railroad name: " << railroadName << endl;
        fout << "Destination: " << destination << endl << endl;

        fout << "Number of ore cars:" << setfill('.') << setw(12) << "." << setfill(' ') << right << setw(13) << numOreCars << endl;
        fout << fixed << setprecision(2);
        fout << "Total weight of coal" << setfill('.') << setw(11) << "." << setfill(' ') << right << setw(16) << totalShipmentWeight << " short tons" << endl;
        fout << "Current Cost per short ton" << setfill('.') << setw(6) << "$" << setfill(' ') << right << setw(15) << pricePerShortTonCoal << endl;
        fout << "Total value of shipment" << setfill('.') << setw(9) << "$" << setfill(' ')  << right << setw(15) << totalShipmentValue << endl;  //For some reason the double isn't taking affect
        fout << "Current surcharge" << setfill('.') << setw(14) << "." << setfill(' ') << right << setw(16) << currentSurcharge * 100 << " %" << endl;

        fout << "Total Surcharge(Est)" << setfill('.') << setw(12) << "$" << setfill(' ') <<  right << setw(15) << totalShipmentSurcharge << endl << endl;

        fout.close();
        cout << "File written successfully" << endl;
    }
    
    return 0;
}
