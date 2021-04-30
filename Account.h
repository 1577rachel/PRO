#pragma once
#include <iostream>
#include "Clock.h"
#include<string>
using namespace std;
class Account
{
private:
	int accountNumber;
	int code;
	float balance;
	string mail;
	void setAccuontNumber(int a);
	void setCode(int c);
	static float sumWithdraw;
	static float sumDeposit;
public:
	Account();
	Account(const int& a, const int& c,const float& b,const string& m);
	Account(const Account& a);
	void setBalance(float b);
	void setMail(string m);
	int getAccountNumber() const;
	int getCode() const;
	float getBalance() const;
	string getMail() const;
	friend istream& operator>>(istream& is, Account& a);
	void withdraw(int nis);
	void deposit(int nis);
	static float getSumWithdraw();
	static float getSumDeposit();
};

