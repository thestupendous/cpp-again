//in this program, we have to find call stack on line number , marked with `//here`

#if 1
#include <iostream>

void d()
{ // here
}
/* solution: after debugging, this is the call stack
    d()
    b()
    a()
    main()
*/
void c()
{
}

void b()
{
	c();
	d();
}

void a()
{
	b();
}

int main()
{
	a();

	return 0;
}


#endif