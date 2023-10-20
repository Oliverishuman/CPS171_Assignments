/*
 CPS171_MP4 - Project Name here
 

 
 Created by Oliver McMillen on 10/19/23.
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int particularAbNumber;



int main(int argc, const char * argv[]) {
    int numberToInspect = 0;
    int properDivisor = 0;

    
    //Iterate through 1-100
    for (int i=0; i <= 1000; i++){
        
        //If iterated number is even
        if (i % 2 == 0){
            numberToInspect = i;
            int sumOfDivisors = 0;
            int countOfDivisors = 0;
            
            string stringOfProperDivisors = "";
            

            
            //As long as j is less than the number to inspect, continue
            for (int j=1; j < numberToInspect; j++){
                
                //If number to inspect divided by j has remainder of 0, print the out to the line.
                if (numberToInspect % j == 0){
                    properDivisor = j;

                    
                    stringOfProperDivisors += to_string(properDivisor) + ", ";
                    sumOfDivisors += properDivisor;
                    countOfDivisors++;
                }
                
            }
            stringOfProperDivisors.pop_back();
            stringOfProperDivisors.pop_back();
            stringOfProperDivisors += ".";
            
            if (sumOfDivisors > numberToInspect){
                if (countOfDivisors == 5){
                    cout <<"this is: " << numberToInspect << endl;
                    cout << properDivisor << " ";
                    cout << endl << "The list of proper divisors is: " << stringOfProperDivisors << endl;
                    cout << "The sum of proper divisors is: " << sumOfDivisors << endl;
                    cout << "The count of proper divisors is: " << countOfDivisors << endl;
                    cout << endl;
                }
            }
        }

        
    }

    
    return 0;
}
