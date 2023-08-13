#ifndef _STDBOOL_H
#define _STDBOOL_H
#ifndef __cplusplus
#define bool	_Bool
#define true	1
#define false	0
#else 
#define _Bool	bool
#define bool	bool
#define false	false
#define true	true
#endif 
#define __bool_true_false_are_defined	1
#endif
bool readbit(unsigned long long foo,unsigned char index){return(foo&(1<<index));}
unsigned long long writebit(unsigned long long foo,unsigned char index,bool boo){if(boo&&!(foo&(1<<index)))foo+=1<<index;if(!boo&&(foo&(1<<index)))foo-=1<<index;return foo;}
unsigned long long readbits(unsigned long long foo,unsigned char start,unsigned char end){unsigned long long one=0;for(int i=start;i<end;i++)if (foo&(1<<i))one+=1<<i;return one;}
unsigned long long writebits(unsigned long long foo,unsigned char start,unsigned char end,bool boo){for(int i=start;i<end;i++){if(boo&&!(foo&(1<<i)))foo+=1<<i;if(!boo&&(foo&(1<<i)))foo-=1<<i;}return foo;}
