//Gunnar Dulle
//CS-230
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

#include "YearlyInterest.h"

float YearlyInterestCalculator(float yearlyBalance, float monthlyDeposit, float annualInterest) { //Function to calculate and give amount of interest accrued for a year
	float monthlyBalance = yearlyBalance;
	float monthlyInterest;
	for (int k = 0; k < 12; k++) {
		monthlyInterest = (monthlyBalance + monthlyDeposit) * ((annualInterest / 100) / 12);
		monthlyBalance = (monthlyBalance + monthlyDeposit + monthlyInterest);
	}
	return monthlyInterest;
}

float YearlyBalanceCalculator(float yearlyBalance, float monthlyDeposit, float annualInterest) { //Function to calculate and give balance at end of year
	float monthlyBalance = yearlyBalance;
	float monthlyInterest;
	for (int j = 0; j < 12; j++) {
		monthlyInterest = (monthlyBalance + monthlyDeposit)* ((annualInterest / 100) / 12);
		monthlyBalance = (monthlyBalance + monthlyDeposit + monthlyInterest);
	}
	return monthlyBalance;
}

void main() {
	vector<YearlyInterest> yearList;  //Variable decleration
	YearlyInterest currYear;
	float initialInvestment;
	float monthlyDeposit;
	float annualInterest;
	int numYears;
	float currInterestNoMonth;
	float currBalanceNoMonth;
	float currBalance;
	float currInterest;

 	cout << "***********************************" << endl; //Print statements for input prompts
	cout << "*********** Data Input ************" << endl;
	try {
		cout << "Initial Investment Amount: $" << endl;
		cin >> initialInvestment;
		if (initialInvestment <= 0) {
			throw runtime_error("Initial investment must exceed $0.");
		}
		cout << "Monthly Deposit Amount: $" << endl;
		cin >> monthlyDeposit;
		if (monthlyDeposit < 0) {
			throw runtime_error("Monthly deposit cannot be negative.");
		}
		cout << "Annual Interest: %" << endl;
		cin >> annualInterest;
		if (annualInterest < 0) {
			throw runtime_error("Annual interest cannot be negative.");
		}
		cout << "Number of years: " << endl;
		cin >> numYears;
		if (numYears < 1) {
			throw runtime_error("Number of years cannot be less than 1.");
		}
		cout << "Press enter to continue..." << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
	}
	catch (runtime_error& excpt) {
		cout << excpt.what() << endl;
		cout << "Cannot compute investment." << endl;
	}

	currBalance = initialInvestment;
	currBalanceNoMonth = initialInvestment;

	currYear.SetYear(1); //Creates first year object in vector
	currInterestNoMonth = initialInvestment * (annualInterest / 100);
	currYear.SetYearEndInterestNoMonth(currInterestNoMonth);
	currBalanceNoMonth = currBalanceNoMonth + currInterestNoMonth;
	currYear.SetYearEndBalanceNoMonth(currBalanceNoMonth);
	currYear.SetYearEndInterest(YearlyInterestCalculator(currBalance, monthlyDeposit, annualInterest));
	currYear.SetYearEndBalance(YearlyBalanceCalculator(currBalance, monthlyDeposit, annualInterest));
	yearList.push_back(currYear);
	
	for (int i = 1; i < numYears; i++) { //For loop to create objects for remaining years given
		int n = i + 1;
		currYear.SetYear(n);
		currInterestNoMonth = yearList.at(i-1).GetYearEndBalanceNoMonth() * (annualInterest / 100);
		currYear.SetYearEndInterestNoMonth(currInterestNoMonth);
		currBalanceNoMonth = yearList.at(i-1).GetYearEndBalanceNoMonth() + currInterestNoMonth;
		currYear.SetYearEndBalanceNoMonth(currBalanceNoMonth);
		currYear.SetYearEndInterest(YearlyInterestCalculator(yearList.at(i-1).GetYearEndBalance(), monthlyDeposit, annualInterest));
		currYear.SetYearEndBalance(YearlyBalanceCalculator(yearList.at(i-1).GetYearEndBalance(), monthlyDeposit, annualInterest));
		yearList.push_back(currYear);
	}

	cout << "Balance and Interest Without Additional Monthly Deposits" << endl;  //Print statements for chart of interest without monthly deposits
	cout << "========================================================" << endl;
	cout << "Year      Year End Balance      Year End Earned Interest" << endl;
	cout << "--------------------------------------------------------" << endl;
	for (int p = 0; p < numYears; p++) {
		cout << yearList.at(p).GetYear() << "                    $" << fixed << setprecision (2) << yearList.at(p).GetYearEndBalanceNoMonth() << "                        $" << yearList.at(p).GetYearEndInterestNoMonth() << endl;
	}
	cout << endl;
	cout << endl;
	
	cout << "  Balance and Interest With Additional Monthly Deposits  " << endl; //Print statements for chart of interest with monthly deposits
	cout << "=========================================================" << endl;
	cout << "Year      Year End Balance       Year End Earned Interest" << endl;
	cout << "---------------------------------------------------------" << endl;
	for (int q = 0; q < numYears; q++) {
		cout << yearList.at(q).GetYear() << "                    $" << fixed << setprecision (2) << yearList.at(q).GetYearEndBalance() << "                          $" << yearList.at(q).GetYearEndInterest() << endl;
	}
}