#include "read_int.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
int read_int(int** num,int args,const char* argv[])
{
	int i;
	int a;
	int* mas=(int*)malloc(sizeof(int)*(args-1));

	for(i=1;i<args;++i)
	{
		char* ptr;
		long ret;

		errno=0;
		ret=strtol(argv[i],&ptr,10);
		a=ret;
		if(argv[i]==ptr)
		{
        free(mas);
        return 0;
		}
		//!strcmp(*(argv[i]),'\0') &&
		else if ( *ptr=='\0' && errno==0)
		{
			mas[i-1]=(int)ret;
			continue;
		}
			//printf("NORM\n%ld",ret);
		else
		{
			//printf("%ld\n,ptr=%c",ret,*ptr);
			printf("BaDDDD\n");
      free(mas);
			return 0;
		}


			//printf("%ld\n",ret);
	}
	*num=mas;
  return 1;

}
