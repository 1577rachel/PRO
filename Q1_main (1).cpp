#include <iostream>
#include "Clock.h"
#include "Account.h"
#pragma warning (disable:4996)
using namespace std;

enum action{
	stop,
	balance,
	deposit,
	withdraw,
	sumDeposit,
	sumWithdraw
};
action menu(){
	cout << "enter 1 to get account balance" << endl;
	cout << "enter 2 to deposit money" << endl;
	cout << "enter 3 to withdraw money" << endl;
	cout << "enter 4 to see the sum of all withdraws" << endl;
	cout << "enter 5 to see the sum of all Deposits" << endl;
	cout << "enter 0 to stop" << endl;
	int x;
	cin >> x;
	return (action)x;
}
int findAccount(Account* bank, int size){
	int number, code;
	cout << "please enter account number: ";
	cin >> number;
	int i = 0;
	while (i < size && bank[i].getAccountNumber() != number)
		i++;
	if (i == 10)
		throw "ERROR: no such account number!";
	cout << "please enter the code: ";
	cin >> code;
	if (bank[i].getCode() == code)
		return i;
	else throw "ERROR: wrong code! ";
}
void printTransaction(Account a, action ac, Clock& c){
	cout << c << "\t";
	;
	switch (ac){
	case balance: cout << "account #: " << a.getAccountNumber() << "\t";
		cout << "balance: " << a.getBalance() << endl;
		break;
	case deposit:
	case withdraw: cout << "account #: " << a.getAccountNumber() << "\t";
		cout << "new balance: " << a.getBalance() << endl;
		break;
	case sumDeposit:
		cout << "sum of all deposits: " << Account::getSumDeposit() << endl;
		break;
	case sumWithdraw:
		cout << "sum of all withdraws: " << Account::getSumWithdraw() << endl;
		break;
	}
}
void getBalance(Account* bank, int size, Clock& c){
	int i = findAccount(bank, size);
	c += 20;
	printTransaction(bank[i], balance, c);
}
void cashDeposit(Account* bank, int size, Clock& c){
	int i = findAccount(bank, size);
	float amount;
	cout << "enter the amount of the check: ";
	cin >> amount;
	if (amount > 10000)
		throw "ERROR: cannot deposit more than 10000 NIS!";
	bank[i].deposit(amount);
	c += 30;
	printTransaction(bank[i], deposit, c);
}
void cashWithdraw(Account* bank, int size, Clock& c){
	int i = findAccount(bank, size);
	float amount;
	cout << "enter the amount of money to withdraw: ";
	cin >> amount;
	if (balance - amount < -6000)
		throw "ERROR: cannot have less than - 6000 NIS!";
	if (amount > 2500)
		throw "ERROR: cannot withdraw more than 2500 NIS!";

	bank[i].withdraw(amount);
	c += 50;
	printTransaction(bank[i], withdraw, c);
}
int main(){
	bool flag = 1;
	bool done = 0;
	Clock c(8);
	Account bank[10];
	if (!done) {
		cout << "enter account number, code and email for 10 accounts:\n";
		for (int i = 0; i < 10; i++) {
			try {
				cin >> bank[i];
				for (int j = 0; j < i; j++)
					if (bank[i].getAccountNumber() == bank[j].getAccountNumber())
						throw "ERROR: account number must be unique!\n";
			}
			catch (const char* msg) {
				cout << c << '\t' << msg<<endl;
				i--;
			}
		}
		done = 1;
	}
			while(flag){
				try {
					flag = 0;
					action ac = menu();
					while (ac) {
						switch (ac) {
						case balance: getBalance(bank, 10, c);
							break;
						case withdraw:cashWithdraw(bank, 10, c);
							break;
						case deposit:cashDeposit(bank, 10, c);
							break;
						case sumDeposit:c += 60;
							printTransaction(bank[0], sumDeposit, c);
							break;
						case sumWithdraw:c += 60;
							printTransaction(bank[0], sumWithdraw, c);
						}
						ac = menu();
					}
				}
				catch (const char* msg) {
					cout << c<<"\t"<<msg<<endl;
					flag = 1;
				}
			}
	return 0;
}

/*example:
enter account number, code and email for 10 accounts:
1234 1234 11a@gmail.com
12345 1234 22b@gmail.com
2341 1234 33c@gmail.com
4321 1234 44d@gmail.com
5432 1234 55e@gmail.com
2121 1234 66f@gmail.com
1212 1234 77g@gmail.com
3232 1234 88h@gmail.com
4343 1234 99i@gmail.com
2345 1234 00j@gmail.com
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop
2
please enter account number: 1234
please enter the code: 1234
enter the amount of the check: 1200
08:00:30        account #: 1234 new balance: 1200
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop
0
C:\Users\User\Desktop\עבודות אוריה\מכון טל\שנה א\סמסטר ב\C++\exercise4\Debug\exercise4.exe (process 13664) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

more example:
enter account number, code and email for 10 accounts:
1 1111 aaa@gmail.com
2 2222 aaa@gmail.il
08:00:00        ERROR: email must end at .com or .co.il!
2 2222 aaa@gmail.com
3 3333 bbb@gmail.com
4 4444 ccc@gmail.com
5 5555 ddd@gmail.com
6 6666 eee@gmail.com
7 7777 fff@gmail.com
8 8888 ggg@gmail.com
9 9999 hhh@gmail.com
10 1010 iii@gmail.com
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop
1
please enter account number: 1
please enter the code: 4444
08:00:00ERROR: wrong code!
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop
0

C:\Users\User\Desktop\עבודות אוריה\מכון טל\שנה א\סמסטר ב\C++\exercise4\Debug\exercise4.exe (process 3264) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .*/
