#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
bool readbit(size_t foo,size_t index){return(foo&(1<<index));}
void writebit(size_t *foo,size_t index,bool boo){if(boo&&!(*foo&(1<<index)))*foo+=1<<index;if(!boo&&(*foo&(1<<index)))*foo-=1<<index;}
size_t readbits(size_t foo,size_t start,size_t end){int one=0;for(int i=start;i<end;i++)if (foo&(1<<i))one+=1<<i;return one;}
void writebits(size_t *foo,size_t start,size_t end,bool boo){for(int i=start;i<end;i++){if(boo&&!(*foo&(1<<i)))*foo+=1<<i;if(!boo&&(*foo&(1<<i)))*foo-=1<<i;}}
bool freadbit(char foofile[],size_t index){FILE* foo = fopen(foofile, "rb");int boo;if (foo == NULL) {perror("freadbit error");exit(-1);}fseek(foo, (index / 8), SEEK_SET);fread(&boo, 1, 1, foo);fclose(foo);boo = readbit(boo, (index % 8) - 1);return boo;}
