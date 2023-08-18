// Ignore all warnings about "incompatible pointer types."
// Also, be sure to used unsigned integers when reading/writing bits
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
bool readbit(unsigned long foo, int index) 
{
	return(foo & (1 << index));
}

void writebit(unsigned long* foo, int index, bool boo)
{
	if(boo && !(*foo & (1 << index))) *foo += 1 << index;
	if(!boo && (*foo & (1 << index ))) *foo -=1 << index;
}

unsigned long readbits(unsigned long foo,int start,int end)
{
	unsigned long long one = 0; 
	for(int i = start; i < end; i++) if (foo & ( 1 << i)) one += 1 << i;
	return one;
}

void writebits(unsigned long* foo,int start,int end,bool boo)
{
	for(int i = start; i < end + 1; i++) writebit(foo, i, boo);
}

bool freadbit(char foofile[],unsigned long index)
{
	FILE* foo = fopen(foofile, "rb");
	unsigned char boo;
	
	if(foo == NULL)
	{
		perror("freadbit error");
		exit(-1);
	}
		fseek(foo, (index / 8),SEEK_SET);
		fread(&boo, 1, 1, foo);
		fclose(foo);
		boo = readbit(boo, (index % 8) - 1);
		return boo;
}

void fwritebit(char foofile[],unsigned long index,bool boo)
{
	FILE*foo=fopen(foofile, "ab");
	
	if (!ftell(foo))
	{
		for (unsigned long i = 0; i < (index / 8); i++) fputc(0,foo);
		fputc(1<<(index - ((index / 8) * 8)), foo);
	}
	
	else if (foo != NULL)
	{
		fseek(foo, 0, SEEK_END);
		unsigned long fp = ftell(foo);
		
		if (fp - 1 < (index / 8))
		{
			rewind(foo);
			for (unsigned long i = 0; i < (index / 8) - fp; i++) fputc(0,foo);
			fputc(1<<(index - ((index / 8) * 8)), foo);
		}
		
		else
		{
			foo=fopen(foofile,"rb+");
			fseek(foo, (index / 8), SEEK_SET);
			unsigned char i = fgetc(foo);
			fseek(foo, (index / 8), SEEK_SET);
			writebit(&i, index - ((index / 8) * 8), boo);
			fputc(i, foo);
		}
	}
	fclose(foo);
}


