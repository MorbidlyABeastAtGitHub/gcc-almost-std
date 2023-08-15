#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
bool readbit(long long foo,long long index){return(foo&(1<<index));}
void writebit(long long *foo,long long index,bool boo){if(boo&&!(*foo&(1<<index)))*foo+=1<<index;if(!boo&&(*foo&(1<<index)))*foo-=1<<index;}
long long readbits(long long foo,long long start,long long end){int one=0;for(int i=start;i<end;i++)if (foo&(1<<i))one+=1<<i;return one;}
void writebits(long long *foo,long long start,long long end,bool boo){for(int i=start;i<end;i++){if(boo&&!(*foo&(1<<i)))*foo+=1<<i;if(!boo&&(*foo&(1<<i)))*foo-=1<<i;}}
bool freadbit(char foofile[],long long index){FILE* foo = fopen(foofile, "rb");unsigned char boo;if (foo == NULL) {perror("freadbit error");exit(-1);}fseek(foo, (index / 8), SEEK_SET);fread(&boo, 1, 1, foo);fclose(foo);boo = readbit(boo, (index % 8) - 1);return boo;}
