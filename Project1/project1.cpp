// initialize stream
#include <iostream>
#include <limits>
using namespace std;

int main() {

    // variable initialization
    double loan = 0;
    double interestRate = -1;
    double monthlyPaid = 0;
    int currentMonth = 0;
    double interestTotal = 0;
    double interestMonthly = 0;
    double principalMonthly = 0;


    // currency format
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    // loan amount input
    do {
        cout << "\nLoan Amount: ";
        cin >> loan;
        if (!cin) {
            cout << "Invalid loan";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        else if (loan <= 0) {
            cout << "Invalid loan";
        }

    } while (!cin || loan <= 0);
    

    // interest rate input
    do {
        cout << "\nInterest Rate (% per year): ";
        cin >> interestRate;
        if (!cin) {
            cout << "Invalid interest rate";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            interestRate = -1;
        }
        else if (interestRate < 0) {
            cout << "Invalid interest rate";
            interestRate = -1;
        }
  
    } while (!cin || interestRate < 0);

    // interest rate calculations
    interestRate /= 12;
    double interestRateC = interestRate / 100;
    double tempInterest = loan * interestRateC;

    // monthly payment input
    do {
        cout << "\nMonthly Payments: ";
        cin >> monthlyPaid;
        
        if (!cin) {
            cout << "Invalid payment";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (monthlyPaid <= 0) {
            cout << "Invalid payment";
        }
        else if (monthlyPaid <= tempInterest) {
            cout << "Insufficent payment";
        }

    } while (!cin || monthlyPaid <= 0 || monthlyPaid <= tempInterest);

    cout << endl;

    

    // ammortization table header
    cout << "*****************************************************************\n"
         << "\tAmortization Table\n"
         << "*****************************************************************\n"
         << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n";

    // ammortization table math
    while (loan > 0) {
        if (currentMonth == 0) {
            cout << currentMonth++ << "\t$" << loan;
            if (loan < 1000) {
                cout << "\t";
            }
            cout << "\t" << "N/A\tN/A\tN/A\t\tN/A\n";
        }
        else {
        
            interestMonthly = loan * interestRateC;
            interestTotal += interestMonthly;
            principalMonthly = monthlyPaid - interestMonthly;
            loan -= principalMonthly;   

            if (loan < 0) {
                principalMonthly += loan;
                monthlyPaid = principalMonthly + interestMonthly;
                loan = 0;
            }


            cout << currentMonth << "\t$" << loan; 
            if (loan < 1000) {
                cout << "\t";    
            }    
            cout << "\t$" << monthlyPaid << "\t" << interestRate << "\t$" << interestMonthly << "\t\t$" << principalMonthly << "\n";

            currentMonth++;
        }
    }

    // ammoritiztion table footer
    cout << "****************************************************************\n";
    cout << "\nIt takes " << --currentMonth << " months to pay off "
         << "the loan.\n"
         << "Total interest paid is: $" << interestTotal;
    cout << endl << endl;
    return 0;

}