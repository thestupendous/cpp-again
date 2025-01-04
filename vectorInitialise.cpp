#include<vector>
#include "standardHeader.h"

int main(){
	vector<int> ar{3,4,5,6.,(static_cast<int>(6.9))};

	for (auto x: ar)
	{
		cout << x << ',';
	}

	cout << '\n';

	return 0;
}
