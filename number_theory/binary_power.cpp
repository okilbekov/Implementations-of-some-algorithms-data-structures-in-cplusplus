#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;

int binary_power(int n, int power) { // return n^power % MOD
	if(power == 0)
		return 1;

	if(power % 2 == 0) {
		int temp = binary_power(n, power / 2);
		return temp * temp % MOD;
	}
	else {
		return a * binary_power(n, power - 1) % MOD;
	}
}

int main() {
	int n, power;
	cin >> n >> power;
	cout << binary_power(n, power) << endl;

	return 0;
}