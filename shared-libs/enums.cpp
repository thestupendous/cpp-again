//enums using variable argument function

#include <iostream>
#include<cstdarg>
using namespace std;

#if 0	//hidden bcz using variable arg function
	#define cc <<","<<
#endif

void printEnums(int size, ... ) {
	va_list list;
	va_start(list,size);
	
	int argument = 0;
	for (int i(0); i<size; i++) {
		argument = va_arg(list,int);
		cout<<argument<<",";
	}
	cout<<endl;
}




int main()
{
	enum Pet { dog,cat,cow,buffalo};
	enum Items {pen,candy,notebook,blackChana};

#if 0	//hidden bcz using variable arg function
	cout<<dog cc cat cc cow cc buffalo <<endl;
	cout<<pen cc candy cc notebook cc blackChana << endl;
#endif	

	printEnums(4,dog,cat,cow,buffalo);
	printEnums(4,pen,candy,notebook,blackChana);

	cout << "dog == pen ? , ans = " << ( (dog==pen) ? "yes\n" : "no\n" ); // ye kya kya dekhna pad raha hai bhai

	Pet AnandsPet = dog;
	Pet AndrewsPet = buffalo;
	Pet ChinkysPet = dog;

	cout<<"Anand's pet is cat ? , ans = "<<  ( (AnandsPet == cat) ? "yes\n" : "no\n" );

	cout<<"Anand's pet is same as Chinky's pet ?, ans = "<< ( (AnandsPet == ChinkysPet) ? "yes\n" : "no\n" );


	Items CustPinkyTook = candy;
	Items CustPappuTook = notebook;

	return 0;
}
