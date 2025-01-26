#include<iostream>

struct pair{
	int32_t x;
	int32_t y;
};


int main(){
	pair number{3,4};
	pair * p = nullptr;
	p = &number;
	p->x = 3;
	p->y= 1000;

	std::cout<< number.x <<',' << number.y << '\n';

	return 0;
}
