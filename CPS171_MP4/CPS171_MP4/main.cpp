/*
 CPS171_MP4 - Repitition

The program is to print all the abundant numbers and their details, that are smaller or equal to
that of the smallest natural number with exactly six proper divisors. Then, it should print
out the number with exactly six proper divisors and it's details.
 
 Created by Oliver McMillen on 10/19/23.
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <list>

using namespace std;

int main(int argc, const char * argv[]) {
    int numberToInspect = 0;
    int properDivisor = 0;
    
    //Iterate through 1-100
    for (int i=1; i <= 1000; i++){
            int sumOfDivisors = 0;
            int countOfDivisors = 0;
            int iterationCount = 0;
            string stringOfProperDivisors = "";
            string plusSignProperDivisors = "";
            list<string> listOfProperDivisors = {};
            numberToInspect = i;


            
            //For while j is less than the number to inspect
            for (int j=1; j < numberToInspect; j++){
                /*
                 If the number to inspect divided by j has remainder of 0,
                 then j is a proper divisor. Accumulate sum of proper divisors and accumulate count,
                 then add to list of proper divisors.
                 
                */
                if (numberToInspect % j == 0){
                    
                    properDivisor = j;
                    
                    sumOfDivisors += properDivisor;
                    countOfDivisors++;
                    listOfProperDivisors.insert(listOfProperDivisors.end(),  to_string(properDivisor));
                
                }
            }

            //For each loop to iterate through listOfProperDivisions elements
            for (auto each : listOfProperDivisors) {
                    if (iterationCount < countOfDivisors - 1){
                        stringOfProperDivisors += each + ", ";
                        plusSignProperDivisors += each + "+";
                    }
                    else if (iterationCount == countOfDivisors - 1){
                        stringOfProperDivisors += "and " + each;
                        plusSignProperDivisors += each;
                    }
                    iterationCount++;
                
            }
            
            //Abundannt numbers will be printed to console, if a number has 6 divisors the loop will stop.
            if (countOfDivisors == 6){
                cout << endl << numberToInspect <<" is the first natural number with 6 proper divisors." << endl;
                cout << "The proper divisors of "<< numberToInspect << " are " << stringOfProperDivisors << endl;
                cout << "The sum of the proper divisors is " << plusSignProperDivisors << " or " << sumOfDivisors
                << " which is less than the number " << numberToInspect << "." << endl;
                cout << "There are " << countOfDivisors << " proper divisors for the number " << numberToInspect << endl;
                cout << endl;
                break;
            }
            else if (sumOfDivisors > numberToInspect){
                cout << endl << "The number " << numberToInspect << " is an ABUNDANT number." << endl;
                cout << "The proper divisors of "<< numberToInspect << " are " << stringOfProperDivisors << endl;
                cout << "The sum of the proper divisors is " << plusSignProperDivisors << " or " << sumOfDivisors
                << " which is greater than the number " << numberToInspect << "." << endl;
                cout << "There are " << countOfDivisors << " proper divisors for the number " << numberToInspect << endl;
                cout << endl;
            }
    }
    
    return 0;
}
