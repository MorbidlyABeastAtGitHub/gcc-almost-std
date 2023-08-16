// Ignore all warnings about "incompatible pointer types."
unsigned long long rounddown(unsigned long long foo, unsigned long long val) { return(foo / val) * val; }
unsigned long long roundup(unsigned long long foo, unsigned long long val){ return (( foo / val) * val) + val; }
/*This all works because of integer truncation: e.g., dividing 25 by 8 results in 3.125, truncated to 3 in C.
Then multiplying the truncated value by the first step's divisor results in a rounded value. So, 25 --> 3.125 (truncated to 3) --> 24.
Rounding up is just taking the rounded-down value and adding the divisor's value to it.*/
