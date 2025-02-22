#include<iostream>
using namespace std;

bool primeHai(int n){
	//simplest
	int kitne=0;
	for (int i{1} ; i<=n ; i++ ) {
		if ( n % i == 0 ) 
			kitne++;

	}
	if (kitne==2) return true;
	return false;
}


int main() {
	int n;
	cin >> n;
	cout << primeHai(n) ;

	return 0;
}

