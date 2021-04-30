#include "Account.h"
#include <iostream>
#include "Clock.h"
#include<string>
using namespace std;

float Account:: sumWithdraw = 0;
float Account:: sumDeposit = 0;

Account::Account() {
	accountNumber = 0;
	code = 0;
	balance = 0;
}
Account::Account(const int& a, const int& c, const float& b, const string& m) {
	setAccuontNumber(a);
	setCode(c);
	setBalance(b);
	setMail(m);
}
Account::Account(const Account& a) {
	accountNumber = a.accountNumber;
	code = a.code;
	balance = a.balance;
	mail = a.mail;
}
void Account::setAccuontNumber(int a) {
	accountNumber = a;
}
void Account::setCode(int c) {
	if (c < 1000 || c>9999) {
		throw "ERROR: code must be of 4 digits!";
	}
	code = c;
}
void Account::setBalance(float b) {
	balance = b;
}
void Account::setMail(string m) {
	if (m.find('@') == -1)
		throw "ERROR: email must contain @!";
	if (m.find(".com") == -1 && m.find(".co.il") == -1)
		throw "ERROR: email must end at .com or .co.il!";
	mail = m;
}
int Account::getAccountNumber() const {
	return accountNumber;
}
int Account::getCode() const {
	return code;
}
float Account::getBalance() const {
	return balance;
}
string Account::getMail() const {
	return mail;
}
istream& operator>>(istream& is, Account& a) {
	int ac, c;
	string str;
	is >> ac >> c >> str;
	a.setAccuontNumber(ac);
	a.setCode(c);
	a.setBalance(0);
	a.setMail(str);
	return is;
}
void Account::withdraw(int nis) {
	if (nis > 2500)
		throw "ERROR: cannot withdraw more than 2500 NIS!";
	if (balance - nis < -6000)
		throw "ERROR: cannot have less than - 6000 NIS!";
	balance -= nis;
	sumWithdraw += nis;
}
void Account::deposit(int nis) {
	if (nis > 10000)
		throw "ERROR: cannot deposit more than 10000 NIS!";
	balance += nis;
	sumDeposit += nis;
}
float Account:: getSumWithdraw() {
	return sumWithdraw;
}
 float Account:: getSumDeposit() {
	return sumDeposit;
}
