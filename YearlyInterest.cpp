//Gunnar Dulle
//CS-230
#include "YearlyInterest.h"
#include <iostream>
#include <iomanip>

using namespace std;

YearlyInterest::YearlyInterest() {  //Default constructor
	int interestYear = 0;
	float balanceNoMonth = 0.00;
	float interestNoMonth = 0.00;
	float endYearBalance = 0.00;
	float endYearInterest = 0.00;
}

YearlyInterest::YearlyInterest(int currentInterestYear, float yearBalanceNoMonth, float yearInterestNoMonth, float yearBalance, float yearInterest) {
	interestYear = currentInterestYear;
	balanceNoMonth = yearBalanceNoMonth;
	interestNoMonth = yearInterestNoMonth;
	endYearBalance = yearBalance;
	endYearInterest = yearInterest;
}

//Mutators
void YearlyInterest::SetYear(int currentInterestYear) {
	interestYear = currentInterestYear;
}

void YearlyInterest::SetYearEndBalanceNoMonth(float yearBalanceNoMonth) {
	balanceNoMonth = yearBalanceNoMonth;
}

void YearlyInterest::SetYearEndInterestNoMonth(float yearInterestNoMonth) {
	interestNoMonth = yearInterestNoMonth;
}

void YearlyInterest::SetYearEndBalance(float yearBalance) {
	endYearBalance = yearBalance;
}

void YearlyInterest::SetYearEndInterest(float yearInterest) {
	endYearInterest = yearInterest;
}

//Accessors
int YearlyInterest::GetYear() const {
	return interestYear;
}

float YearlyInterest::GetYearEndBalanceNoMonth() const {
	return balanceNoMonth;
}

float YearlyInterest::GetYearEndInterestNoMonth() const {
	return interestNoMonth;
}

float YearlyInterest::GetYearEndBalance() const {
	return endYearBalance;
}

float YearlyInterest::GetYearEndInterest() const {
	return endYearInterest;
}

