//  CPS271_MP1 - Time to mow lawn calculator
//
//  Calculates the amount of time it will take to mow a lawn given the lawn length and
//  width, house length and width, and your walking speed. Fixed 1.5ft mowing diameter (Size of mower)
//
//  Created by Oliver McMillen on 9/6/23.
//

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(int argc, const char * argv[]) {
    const double mowerWidth = 1.5; //18 inches = 1.5 feet
    const int oneMinuteInSeconds = 60;
    const int oneMileInFeet = 5280;
    double lawnLength;
    double lawnWidth;
    double houseLength;
    double houseWidth;
    double mowArea;
    double mowingRate;
    double walkingMilesPerHour;
    double walkingFeetPerMinute;
    double timeToMow;
    
    cout << "Mowing the lawn by Oliver McMillen\n";
    cout << "\nPlease enter the following:\n";

    cout << "Length of lawn(ft): ";
    cin >> lawnLength;
    cout << "Width of lawn(ft): ";
    cin >> lawnWidth;
    cout << "Length of house(ft): ";
    cin >> houseLength;
    cout << "Width of house(ft): ";
    cin >> houseWidth;
    cout << "Walking speed (miles per hour): ";
    cin >> walkingMilesPerHour;
    
    cout << fixed << setprecision(2) <<
        right << setw(8) << lawnLength << endl <<
        right << setw(8) << lawnWidth << endl <<
        right << setw(8)  << houseLength << endl <<
        right << setw(8) << houseWidth << endl <<
        right << setw(8) << walkingMilesPerHour << endl;

    
    mowArea = (lawnLength * lawnWidth) - (houseLength * houseWidth); //Calculates mowing area in sq. ft.
    cout << "\nThe area of lawn to be mowed is " << mowArea << " sq. ft." << endl;
    
    walkingFeetPerMinute = ((walkingMilesPerHour * oneMileInFeet) / oneMinuteInSeconds);   //Calculates walking MPH to feet per minute
    mowingRate = walkingFeetPerMinute * mowerWidth;    //Calculates mowing rate with the lawn mower into sq. ft. per minute
    cout << "You can mow " << mowingRate << " sq. ft. per minute" << endl;
    
    timeToMow = (mowArea / mowingRate); // Calculates mowing area in sq. ft. divided by mowing rate sq. ft. per minute
    cout << "Time to mow the lawn is " << timeToMow << " minutes\n" << endl;
    
    return 0;
}
