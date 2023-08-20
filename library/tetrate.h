#include <math.h>

long double tetrate (long double foo, long double exp)
{
	long double org = foo;
	for (int i = 0; i < (int)exp; i++) foo = powl(org, foo);
	foo = powl(foo, powl(org, exp - (int)exp));
	return foo;
}

