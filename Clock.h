#pragma once
#include <iostream>
using namespace std;

class Clock
{
private:
	int hour;
	int minute;
	int second;
public:
	Clock();
	Clock(const int& h=0,const int& m=0,const int& s=0);
	Clock(const Clock& c);
	void setHour(int h);
	void setMinute(int m);
	void setSecond(int s);
	int getHour() const;
	int getMinute()const;
	int getSecond()const;
	Clock operator+=(const int& s);
	friend ostream& operator<<(ostream& os, const Clock& c);
	friend istream& operator>>(istream& is, Clock& c);
};

