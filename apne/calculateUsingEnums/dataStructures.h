#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

enum Error {
	SUCCESS, DIVISIONBYZERO, INVALIDOPERATION
};

struct Out {
	double res;
	Error err;
};



#endif
