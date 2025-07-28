#include "input-processor.h"

// type: int    - 'i'
//       char   - 'c'
//       string - 's'
//       double - 'd'


// for giving default prompt provide "def" in third argument
void inputValue( int &toInput, string_view prompt) {
	if (prompt!="none") {
	  if (prompt == "def") {
	    cout << "enter int value : ";
	  } else {
	    cout << prompt;
	  }
	}
	
	cin >> toInput;
}

void inputValue( string &toInput, string_view prompt) {
	if (prompt!="none") {
	  if (prompt == "def") {
	    cout << "enter string value : ";
	  } else {
	    cout << prompt;
	  }
	}
	
	cin >> toInput;
}

void inputValue( double &toInput, string_view prompt) {
	if (prompt!="none") {
	  if (prompt == "def") {
	    cout << "enter double value : ";
	  } else {
	    cout << prompt;
	  }
	}
	
	cin >> toInput;
}

void inputValue( char &toInput, string_view prompt) {
	if (prompt!="none") {
	  if (prompt == "def") {
	    cout << "enter char value : ";
	  } else {
	    cout << prompt;
	  }
	}
	
	cin >> toInput;
}

void inputArray( const int &size, int * toInput, string_view prompt) {
	if (prompt!="none") {
	  if (prompt == "def") {
	    cout << "enter " << size << "int values : ";
	  } else {
	    cout << prompt;
	  }
	}
	
	for (int i{0};i<size;i++) {
		cin >> toInput[i];
	}
}

void inputArray( const int &size, string * toInput, string_view prompt) {
	if (prompt!="none") {
	  if (prompt == "def") {
	    cout << "enter " << size << "string values : ";
	  } else {
	    cout << prompt;
	  }
	}
	
	for (int i{0};i<size;i++) {
		cin >> toInput[i];
	}
}

void inputArray( const int &size, double * toInput, string_view prompt) {
	if (prompt!="none") {
	  if (prompt == "def") {
	    cout << "enter " << size << "double values : ";
	  } else {
	    cout << prompt;
	  }
	}
	
	for (int i{0};i<size;i++) {
		cin >> toInput[i];
	}
}

void inputArray( const int &size, char * toInput, string_view prompt) {
	if (prompt!="none") {
	  if (prompt == "def") {
	    cout << "enter " << size << "char values : ";
	  } else {
	    cout << prompt;
	  }
	}
	
	for (int i{0};i<size;i++) {
		cin >> toInput[i];
	}
}
