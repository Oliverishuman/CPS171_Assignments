//
//  main.cpp
//  CPS171_MP5
//
//  Created by Oliver McMillen on 10/31/23.
//

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int readAccountNumber(){
    int accNumberEntered = 0;
    bool numberNotAssigned = true;
    string errorMsg = "You must enter a number between 1 - 10,000. Please try again.";
    
    while(numberNotAssigned == true){
        cout << "Enter account number: ";
        cin >> accNumberEntered;
        
        // if number is within range of 1 and 10000
        if (accNumberEntered >= 1 && accNumberEntered <= 10000){
            // if number is even (remainder of number divided by 2 is 0)
            if( accNumberEntered % 2 == 0 ){
                //                cout << "This is your account number " << accNumberEntered << endl;
                numberNotAssigned = false;
            }
            // if number entered is not even, prompt user to try again
            else {
                cout << errorMsg << endl;
            }
        }
        // if number entered is not within range, prompt user to try again
        else {
            cout << errorMsg << endl;
        }
    }
    return accNumberEntered;
}

double readBalanceAmount(){
    double accBalanceEntered = 0;
    bool balanceNotAssigned = true;
    string errorMsg = "You must enter an even number between 1 - 200,000. Please try again.";
    
    while(balanceNotAssigned == true){
        cout << "Enter opening balance: ";
        cin >> accBalanceEntered;
        
        // if number is within range of 1 and 10000
        if (accBalanceEntered >= 1 && accBalanceEntered <= 200000){
            balanceNotAssigned = false;
        }
        // if number entered is not within range, prompt user to try again
        else {
            cout << errorMsg << endl;
        }
    }
    return accBalanceEntered;
}

double addReturnBonus(double openingBalance){
    double finalOpeningBalance = 0;
    double addedBonus = 0;
    
    if (openingBalance >= 1 && openingBalance <= 100){
        addedBonus = openingBalance * 0.02;
        finalOpeningBalance = openingBalance + addedBonus;
    }
    else if (openingBalance >= 101 && openingBalance <= 500){
        addedBonus = openingBalance * 0.03;
        finalOpeningBalance = openingBalance + addedBonus;
    }
    else if (openingBalance >= 501 && openingBalance <= 1000){
        addedBonus = openingBalance * 0.04;
        finalOpeningBalance = openingBalance + addedBonus;
    }
    else {
        addedBonus = openingBalance * 0.05;
        finalOpeningBalance = openingBalance + addedBonus;
    }
    
    return finalOpeningBalance;
}



int main(int argc, const char * argv[]) {
    bool showMainMenu = true;
    int numOfCustomers = 4;
    char mainMenuSelection;
    //    int accountNumber;
    double initialOpeningBalance;
    double finalOpeningBalance;
    int arrayAccountNumbers [4];
    double arrayAccountBalances [4];
    
    cout << "Oliver McMIllen, CPS 171 - SEC D01.\t Due Date: November 3rd, 2023" << endl;
    
    for (int i=0; i <= numOfCustomers - 1; i++){
        cout << endl << "For customer " << i + 1 << endl;
        initialOpeningBalance = readBalanceAmount();
        arrayAccountNumbers[i] = readAccountNumber();
        
        //Adds return bonus and associates final opening balance with the array
        finalOpeningBalance = addReturnBonus(initialOpeningBalance);
        arrayAccountBalances[i] = finalOpeningBalance;
        
        cout << "This is your Account Number " << arrayAccountNumbers[i] << endl;
        cout << "This is your opening Balance " << arrayAccountBalances[i] << endl;
        
    }
    
    
    
    while(showMainMenu == true){
        
        cout << endl << "Main Menu (Please enter 'A', 'B', or 'C' for your choice)" << endl;
        cout << "\tA - \tDo Deposit" << endl;
        cout << "\tB - \tView Accounts" << endl;
        cout << "\tC - \tExit the program" << endl;
        cin >> mainMenuSelection;
        
        //to upper function reduces user error
        switch (toupper(mainMenuSelection)) {
            case 'A':
                cout << "Deposit not set up" << endl;
                break;
            case 'B':
                cout << "printAllInfo() function not set up" << endl;
                break;
            case 'C':
                cout << "Goodbye!" << endl;
                showMainMenu = false; break;
            default:
                //Do not set showMainMenu to false or the loop will not repeat back to the output of 'Main Menu...'
                cout << "Error! Please try again." << endl;
        }
    }
    
    return 0;
}
