#include<iostream>
using std::cout;

void setArray(int arr[3])
{
	arr[0]=-10;
	arr[1]=-20;
	arr[2]=-100;

	return ;
}

int main()
{
	int myArr[3] = {0,0,0};

	setArray(myArr);

	cout << myArr[0] << myArr[1] << myArr[2] << '\n';

	return 0;
}
