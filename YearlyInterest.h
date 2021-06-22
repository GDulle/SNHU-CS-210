//Gunnar Dulle
//CS-230
#ifndef YEARLY_INTEREST_H
#define YEARLY_INTEREST_H

#include <string>
#include <vector>

using namespace std;

class YearlyInterest {
public:
	YearlyInterest(); //Default constructor
	YearlyInterest(int currentInterestYear, float yearBalanceNoMonth, float yearInterestNoMonth, float yearBalance, float yearInterest); //Constructor
	void SetYear(int currentInterestYear);  //Mutators
	void SetYearEndBalanceNoMonth(float yearBalanceNoMonth);
	void SetYearEndInterestNoMonth(float yearInterestNoMonth);
	void SetYearEndBalance(float yearBalance);
	void SetYearEndInterest(float yearInterest);
	int GetYear() const;  //Accessors
	float GetYearEndBalanceNoMonth() const;
	float GetYearEndInterestNoMonth() const;
	float GetYearEndBalance() const;
	float GetYearEndInterest() const;
private: //Variables
	int interestYear;
	float balanceNoMonth;
	float interestNoMonth;
	float endYearBalance;
	float endYearInterest;
};

#endif
