/*
 CPS171_MP4 - Project Name here
 
 
 
 Created by Oliver McMillen on 10/19/23.
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

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
            
            
            //Abundannt numbers will be printed to console, if a number has 6 divisors the loop will stop.
            if (countOfDivisors == 6){
                cout << numberToInspect <<" is the first natural number with 6 proper divisors." << endl;
                cout << "The proper divisors of "<< numberToInspect << " are " << stringOfProperDivisors << endl;
                cout << "The sum of the proper divisors is " << sumOfDivisors
                << " which is less than the number " << numberToInspect << endl;
                cout << "There are " << countOfDivisors << " proper divisors for the number " << numberToInspect << endl;
                cout << endl;
                break;
                
            } else if (sumOfDivisors > numberToInspect){
                cout <<"The number " << numberToInspect << " is an ABUNDANT number." << endl;
                cout << "The proper divisors of "<< numberToInspect << " are " << stringOfProperDivisors << endl;
                cout << "The sum of the proper divisors is " << sumOfDivisors
                << " which is greater than the number " << numberToInspect << endl;
                cout << "There are " << countOfDivisors << " proper divisors for the number " << numberToInspect << endl;
                cout << endl;
            }
        }
        
    }
    
    return 0;
}
