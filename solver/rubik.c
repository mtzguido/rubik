#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "data.h"
#include "method.h"
#include "post.h"
#include "goals.h"
#include "common.h"

#define CANTFASES (sizeof(GOALS)/sizeof(int(*)(cube*)))

cube* resolver(cube* C,char* solp)
{
	cube* Cviejo;
	unsigned int i;

	for(i=0;i<CANTFASES;++i)
	{
		
		Cviejo = C;
		C = IDDFS(C,GOALS[i],MOVS[i],solp); /* mi algoritmo anda como el orco */
		free(Cviejo);

		while(*solp != 0) {solp++;}
	}

	return C;
}


int main()
{
	cube* C;
	char sol[3000];
	
	while(1) {
		C = readCube();

		if(C == NULL) return 0;
		
		C = resolver(C,sol);
		simplify(sol);

		printf("%s\n",sol);
		fflush(stdout);
		free(C);
		C = NULL;
	}
	
	return 0;
}
