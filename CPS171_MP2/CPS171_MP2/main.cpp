//  CPS171_MP2
//
//  Created by Oliver McMillen on 9/6/23.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

ifstream inFile;
string str;

string railroadName;
string destination;
int numOreCars;
double pricePerShortTonCoal;
double totalShipmentWeight;
double totalShipmentValue;
double totalShipmentSurcharge;
const double carCapacity = 74.5;
const double currentSurcharge = 0.0031;


int main(int argc, const char * argv[]) {
    inFile.open("dataFileIn.txt");
    
    if (inFile.fail())
        cout << endl << "File not found!" << endl;
    else{
            getline(inFile, str);
            railroadName = str;
        
            getline(inFile, str);
            destination = str;
        
            getline(inFile, str);
            numOreCars = stoi(str);
        
            getline(inFile, str);
            pricePerShortTonCoal = stof(str);
        
        inFile.close();
    }
    
    totalShipmentWeight = (numOreCars * carCapacity);
    totalShipmentValue = (totalShipmentWeight * pricePerShortTonCoal);
    totalShipmentSurcharge = (totalShipmentValue * currentSurcharge);
    
    cout << "KERBAA & M COAL TRAIN REPORT – Oliver McMillen" << endl << endl;
    
    cout << "Railroad name: " << railroadName << endl;
    cout << "Destination: " << destination << endl << endl;
    
    cout << "Number of ore cars: " << numOreCars << endl;
    cout << "Total weight of shipment: " << totalShipmentWeight << " short tons" << endl;
    cout << "Current Cost per short ton: " << pricePerShortTonCoal << endl;
    cout << "Total value of shipment: " << totalShipmentValue << endl;  //For some reason the double isn't taking affect
    cout << "Current surcharge: " << currentSurcharge * 100 << "%" << endl;

    cout << "Total Surcharge(EST): " << totalShipmentSurcharge << endl << endl;

    return 0;
}
