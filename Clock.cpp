#include "Clock.h"
#include <iostream>
using namespace std;

Clock::Clock() {
	setHour(0);
	setMinute(0);
	setSecond(0);
}

Clock::Clock(const int& h,const int& m, const int& s){ 
	if (h < 0 || h>23 || m < 0 || m>59 || s < 0 || s>59) {
		throw "Wrong time format.";
		setHour(h);
		setMinute(m);
		setSecond(s);
	}
	hour = 0;
	minute = 0;
	second = 0;
	setHour(h);
	setMinute(m);
	setSecond(s);
}
Clock::Clock(const Clock& c) {
	hour = c.hour;
	minute = c.minute;
	second = c.second;
}

void Clock::setHour(int h) {
	if (h > 23) {
		hour = 0;
		setMinute(0);
		setSecond(0);
		throw "Invalid time - more than 24 hours.";
	}
	if (h < 0) {
		hour = 0;
		setMinute(0);
		setSecond(0);
		throw "Invalid time - negative number of hours.";
	}
	hour = h;
}
void Clock::setMinute(int m) {
	if (m > 59) {
		setHour(0);
		minute=0;
		setSecond(0);
		throw "Invalid time - more than 60 minutes.";
	}
	if (m < 0){
		setHour(0);
		minute = 0;
		setSecond(0);
		throw "Invalid time - negative number of minutes.";
	}
	minute = m;
}
void Clock::setSecond(int s) {
	if (s > 59) {
		setHour(0);
		setMinute(0);
		second=0;
		throw "Invalid time - more than 60 seconds.";
	}
	if (s < 0){
		setHour(0);
		setMinute(0);
		second = 0;
		throw "Invalid time - negative number of seconds.";
	}
	second = s;
}
int Clock::getHour() const {
	return hour;
}
int Clock::getMinute()const {
	return minute;
}
int Clock::getSecond()const {
	return second;
}

Clock Clock::operator+=(const int& s) {
	if (second + s <= 59) {
		second += s;
	}
	else {
		int temp = second + s;
		second = temp % 60;
		temp /= 60;
		if (minute + temp <= 59) {
			minute += temp;
		}
		else {
			int help = minute + temp;
			minute = help % 60;
			help /= 60;
			if (hour + help <= 23) {
				hour += help;
			}
			else {
				int tmp = hour + help;
				hour = tmp % 24;
			}
		}
	}
	return *this;
}

ostream& operator<<(ostream& os,const Clock& c) {
	if (c.hour < 10) {
		os << "0";
	}
	os << c.hour << ":";
	if (c.minute < 10) {
		os << "0";
	}
	os << c.minute << ":";
	if (c.second < 10) {
		os << "0";
	}
	os << c.second;
	return os;
}
istream& operator>>(istream& is, Clock& c) {
	char tav;
	int h, m, s;
	is >> h >> tav >> m >> tav >> s;
	c.setHour(h); c.setMinute(m); c.setSecond(s);
	return is;
}
