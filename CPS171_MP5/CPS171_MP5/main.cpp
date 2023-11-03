/*
 main.cpp
 CPS171_MP5
 
 This program is designed to start by receiving input for 4 customers.
 Then, it will allow for menu options for which the user can either view all
 account balances, deposit money into an account, or exit the program.
 Opening balance input must be between 1 and 200,000.
 Account number input must be an even number between 1 an 10,000.
 
 Created by Oliver McMillen on 10/31/23.
 
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


int readAccountNumber(){
    int accNumberEntered = 0;
    bool numberNotAssigned = true;
    string errorMsg = "You must enter an even number between 1 - 10,000. Please try again.";
    
    while(numberNotAssigned == true){
        cout << "Enter account number: ";
        cin >> accNumberEntered;
        
        // if number is within range of 1 and 10000
        if (accNumberEntered >= 1 && accNumberEntered <= 10000){
            // if number is even (remainder of number divided by 2 is 0)
            if( accNumberEntered % 2 == 0 ){
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
    string errorMsg = "You must enter an number between 1 - 200,000. Please try again.";
    
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



void printAllInfo(int numOfCustomers, int accountNumbers[], double accountBalances[]){
    
    cout << endl << "===========================Balance Accounts===========================" << endl;
    cout << "=====================================================================" << endl;
    
    for (int i=0; i <= numOfCustomers-1; i++){
        cout << "\tBalance amount for account number " << accountNumbers[i] << " is \t$" <<fixed << setprecision(2) << accountBalances[i] << endl;
    }
    cout << "=====================================================================" << endl;
}

double calculateDeposit(double balanceToPass){
    double amountToDeposit=0;
    
    cout << "What amount would you like to deposit: ";
    cin >> amountToDeposit;
    
    return (balanceToPass + amountToDeposit);
}

//MAIN
int main(int argc, const char * argv[]) {
    const int numOfCustomers = 4;
    bool showMainMenu = true;
    bool accNumberMatched = false;
    char mainMenuSelection;
    double initialOpeningBalance;
    double finalOpeningBalance;
    int arrayAccountNumbers [numOfCustomers];
    double arrayAccountBalances [numOfCustomers];
    int inputAccountNumber;
    
    cout << "*********************************************************************" << endl;
    cout << "*********************************************************************" << endl;
    cout << "Oliver McMIllen, CPS 171 - SEC D01.\t Due Date: November 3rd, 2023" << endl;
    cout << "*********************************************************************" << endl;
    cout << "*********************************************************************" << endl;
    
    for (int i=0; i <= numOfCustomers-1 ; i++){
        cout << endl << "For customer " << i + 1 << endl;
        initialOpeningBalance = readBalanceAmount();
        arrayAccountNumbers[i] = readAccountNumber();
        
        //Adds return bonus and associates final opening balance with the array
        finalOpeningBalance = addReturnBonus(initialOpeningBalance);
        arrayAccountBalances[i] = finalOpeningBalance;
        
    }
    
    cout << endl << "**ALL CUSTOMERS ENTERED**" << endl;
    
    while(showMainMenu == true){
        
        cout << endl << "Main Menu (Please enter 'A', 'B', or 'C' for your choice)" << endl;
        cout << "\tA - \tDo Deposit" << endl;
        cout << "\tB - \tView Accounts" << endl;
        cout << "\tC - \tExit the program" << endl;
        cin >> mainMenuSelection;
        
        //to upper function reduces user error
        switch (toupper(mainMenuSelection)) {
                
            case 'A': //Deposit
                while(accNumberMatched == false){
                    double currentBalance=0;
                    cout << endl << "Enter the account number for deposit: ";
                    cin >> inputAccountNumber;
                    
                    //Iterate through number of customers and compare spot in array to input entry
                    for (int j=0; j <= numOfCustomers-1; j++){
                        if (inputAccountNumber == arrayAccountNumbers[j]) {
                            currentBalance = arrayAccountBalances[j];
                            cout << "Your current balance is: " << currentBalance << endl;
                            arrayAccountBalances[j] = calculateDeposit(currentBalance);
                            
                            cout << "Your balance is now $" << arrayAccountBalances[j] << endl;
                            //Prevent loop from continuing
                            accNumberMatched = true;
                            break;
                        }
                    }
                    if (accNumberMatched == false){
                        cout << "No account matched! Try again." << endl;
                    }
                }
                accNumberMatched = false;
                break;
            case 'B': //View All Balances
                printAllInfo(numOfCustomers, arrayAccountNumbers,arrayAccountBalances);
                break;
            case 'C': //Exit
                cout << "Goodbye!" << endl;
                showMainMenu = false; break;
            default:
                cout << "Error! Please try again." << endl;
        }
    }
    
    return 0;
}
