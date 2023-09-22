//
//  main.cpp
//  ClassExamples
//
//  Created by Oliver McMillen on 8/31/23.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    int a = 5, b = 7, c = 11;
    double average = (a + b + c)/3.0;
    cout <<average<< endl;
    
    a += 3;
    cout << "a: "<<a<<endl;
    
    int r;
    r = c%2;
    cout<<"remainder: "<<r<<endl;
    
    return 0;
}
