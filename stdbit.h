#include <stdbool.h>
bool readbit(unsigned long long foo,int i index){return(foo&(1<<index));}
unsigned long long writebit(unsigned long long foo,int index,bool boo){if(boo&&!(foo&(1<<index)))foo+=1<<index;if(!boo&&(foo&(1<<index)))foo-=1<<index;return foo;}
unsigned long long readbits(unsigned long long foo,int start,int end){unsigned long long one=0;for(int i=start;i<end;i++)if (foo&(1<<i))one+=1<<i;return one;}
unsigned long long writebits(unsigned long long foo,int start,int end,bool boo){for(int i=start;i<end;i++){if(boo&&!(foo&(1<<i)))foo+=1<<i;if(!boo&&(foo&(1<<i)))foo-=1<<i;}return foo;}
