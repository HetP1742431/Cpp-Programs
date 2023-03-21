// Name : Het Bharatkumar Patel
// SID : 1742431
// CCID : hetbhara
// AnonID : 1000348298
// CMPUT 275, Winter 2023

// Weekly Exercise #1: Twin Primes
// ----------------------------------


#include <iostream>
using namespace std;


bool isPrime(int n) {
	if (n == 1) {
		return false;
	}

	int x = 2;
	while (x*x <= n) {
		if (n % x == 0) {
			return false;
		}
		x++;
	}
	return true;
}


void twinPrimes(int k) {
	int count = 0;
	for (int p = 3; p <= 79559; p++) {
		if (count == k) {
			break;
		} else if (isPrime(p) == true && isPrime(p+2) == true) {
			cout << p << " " << p+2 << endl;
			count++;
		}
	}
}


int main() {
	char a;
	int b;
	cin >> a >> b;

	if (a == 'p') {
		if (isPrime(b) == true) {
			cout << "prime" << endl;
		} else {
			cout << "not prime" << endl;
		}
	} else if (a == 't') {
		twinPrimes(b);
	}
	return 0;
}
