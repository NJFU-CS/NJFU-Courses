#include "BigInt.h"

int main() {
	int n;
	cin >> n;
	BigInt a;
	a = n;
	BigInt i;
	BigInt one;
	one = 1;
	BigInt res;
	res = 1;
	for (i = 1; a > i; i += one) {
		res *= i;
	}
	cout << res;
	clock_t e = clock();
	return 0;
}