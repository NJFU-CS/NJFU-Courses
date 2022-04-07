#include "BigInt.h"

using namespace std;

ostream& operator<<(ostream &out, const BigInt &a)
{
	out << a.data[a.data.size() - 1];
	for (int i = a.data.size() - 2; i >= 0; i--)
		out << setw(WIDTH) << setfill('0') << a.data[i];
	return out;
}

BigInt::BigInt() {
	data.clear();
}

BigInt::BigInt(const BigInt &b) {
	data.clear();
	for (int i = 0; i < b.data.size(); i++)data.push_back(b.data[i]);
}

BigInt BigInt::negative() const {
	BigInt c = *this;
	c.data[c.data.size() - 1] = -c.data[c.data.size() - 1];
	return c;
}

bool BigInt::operator>(const BigInt &num) const {
	return (*this - num).isPos();
}

BigInt BigInt::operator+(const BigInt &b) const
{
	BigInt c;
	c.data.clear();
	int alen = data.size(), blen = b.data.size();
	for (int i = 0, g = 0;; i++)
	{
		if (g == 0 && i >= alen && i >= blen)break;
		int x = g;
		if (i < alen)x += data[i];
		if (i < blen)x += b.data[i];
		c.data.push_back(x % BASE);
		g = x / BASE;
	}
	return c;
}

BigInt BigInt::operator-(const BigInt &b) const
{
	BigInt c;
	c.data.clear();
	if (b.data[b.data.size() - 1] < 0) {
		return *this + b.negative();
	}
	int alen = data.size(), blen = b.data.size();
	for (int i = 0, g = 0;; i++)
	{
		if (g == 0 && i >= alen && i >= blen)break;
		int x = g;
		if (i < alen)x += data[i];
		if (i < blen)x -= b.data[i];
		bool borrowBit = false;
		if (x < 0) {
			if (i >= alen - 1 && i >= blen - 1) {
				c.data.push_back(x % BASE);
				return c;
			}
			x += BASE;
			borrowBit = true;
		}
		c.data.push_back(x % BASE);
		g = x / BASE;
		if (borrowBit) {
			g--;
		}
	}
	if (c.data[c.data.size() - 1] == 0 && c.data.size() > 1) {
		c.data.pop_back();
	}
	return c;
}

BigInt BigInt::operator*(const BigInt &b) const
{
	BigInt c;
	c.data.clear();
	int alen = data.size(), blen = b.data.size();
	for (int i = 0, g = 0;; i++)
	{
		if (i >= alen + blen - 1 && g == 0)break;
		long long sum = 0;
		for (int j = max(0, i - blen + 1); j <= i && j < alen; j++) {
			sum += (long long)(data[j])*(long long)(b.data[i - j]);
		}
		sum += g;
		c.data.push_back(sum%BASE);
		g = sum / BASE;
	}
	return c;
}

BigInt BigInt::operator/(const BigInt &b) const {
	BigInt a = *this;
	BigInt res;
	res = 0;
	BigInt zero;
	zero = 0;
	if (b > a) {
		return zero;
	}
	while (a > zero) {
		BigInt ten, one, k, i;
		ten = 10;
		one = 1;
		for (k = 1;; k *= ten) {
			if ((a - k * ten * b).isMinus()) {
				break;
			}
		}
		for (i = 1;; i += one) {
			if ((a - i * k * b).isMinus()) {
				break;
			}
		}
		i -= one;
		a -= i * k * b;
		res += i * k;
	}
	return res;
}

BigInt BigInt::operator%(const BigInt &b) const {
	BigInt c = *this;
	return c - c / b * b;
}

BigInt BigInt::operator=(const string str)
{
	data.clear();
	int x, len = (str.length() - 1) / WIDTH + 1;
	for (int i = 0; i < len; i++)
	{
		int end = str.length() - i * WIDTH;
		int start = max(0, end - WIDTH);
		sscanf_s(str.substr(start, end - start).c_str(), "%d ", &x);
		data.push_back(x);
	}
	return *this;
}

BigInt BigInt::operator=(long long num)
{
	data.clear();
	do
	{
		data.push_back(num%BASE);
		num /= BASE;
	} while (num > 0);
	return *this;
}

BigInt BigInt::operator=(BigInt &num) {
	data.clear();
	for (int i = 0; i < num.data.size(); i++)data.push_back(num.data[i]);
	return *this;
}

BigInt BigInt::operator=(BigInt &&num) {
	data.clear();
	for (int i = 0; i < num.data.size(); i++)data.push_back(num.data[i]);
	return *this;
}
