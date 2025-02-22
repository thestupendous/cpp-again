
#include<iostream>
using namespace std;

bool palindromeHai(int n){
	int rev=0,copy=n;
	while (copy) {
		rev = rev*10 + copy%10;
		copy /= 10;
	}

	while (rev) {
		if ( rev%10 != n%10 ) return false;
		rev /= 10;
		n /= 10;

	}

	return true;
}


int main() {
	int n;
	cin >> n;
	cout << palindromeHai(n) << '\n';
	return 0;
}

