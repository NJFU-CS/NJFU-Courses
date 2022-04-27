#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
const int BASE = 1000000;
const int WIDTH = 6;

class BigInt
{
private:
	vector<int> data;
public:
	BigInt();
	BigInt(const BigInt &b);
	BigInt operator=(const string str);
	BigInt operator=(long long num);
	BigInt operator=(BigInt &num);
	BigInt operator=(BigInt &&num);
	bool isMinus() { return data[data.size() - 1] < 0; }
	bool isPos() { return data[data.size() - 1] > 0; }
	bool isZero() { return data[data.size() - 1] == 0; }
	bool operator>(const BigInt &num) const;
	BigInt operator+(const BigInt &b) const;
	void operator+=(const BigInt &b) { *this = *this + b; }
	BigInt operator-(const BigInt &b) const;
	void operator-=(const BigInt &b) { *this = *this - b; }
	BigInt operator*(const BigInt &b) const;
	void operator*=(const BigInt &b) { *this = *this * b; }
	BigInt operator/(const BigInt &b) const;
	void operator/=(const BigInt &b) { *this = *this / b; }
	BigInt operator%(const BigInt &b) const;
	void operator%=(const BigInt &b) { *this = *this % b; }
	BigInt negative() const;
	friend ostream& operator<<(ostream &out, const BigInt &a);
};