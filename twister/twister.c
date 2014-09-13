#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int F[9];
	int B[9];
	int U[9];
	int D[9];
	int R[9];
	int L[9];
} cubo;

void left4(int* a, int* b, int* c, int* d)
{
	int t;
	
	t = *a;
	*a = *b;
	*b = *c;
	*c = *d;
	*d = t;
}

void right4(int* a, int* b, int* c, int* d)
{
	left4(d,c,b,a);
}

void girarF(cubo* C)
{
	right4(C->F+0, C->F+2, C->F+8, C->F+6);
	right4(C->F+1, C->F+5, C->F+7, C->F+3);
	right4(C->U+6, C->R+0, C->D+2, C->L+8);
	right4(C->U+7, C->R+3, C->D+1, C->L+5);
	right4(C->U+8, C->R+6, C->D+0, C->L+2);
}

void girarf(cubo* C)
{
	left4(C->F+0, C->F+2, C->F+8, C->F+6);
	left4(C->F+1, C->F+5, C->F+7, C->F+3);
	left4(C->U+6, C->R+0, C->D+2, C->L+8);
	left4(C->U+7, C->R+3, C->D+1, C->L+5);
	left4(C->U+8, C->R+6, C->D+0, C->L+2);
}

void girarU(cubo* C)
{
	right4(C->U+0, C->U+2, C->U+8, C->U+6);
	right4(C->U+1, C->U+5, C->U+7, C->U+3);
	right4(C->B+2, C->R+2, C->F+2, C->L+2);
	right4(C->B+1, C->R+1, C->F+1, C->L+1);
	right4(C->B+0, C->R+0, C->F+0, C->L+0);
}

void giraru(cubo* C)
{
	left4(C->U+0, C->U+2, C->U+8, C->U+6);
	left4(C->U+1, C->U+5, C->U+7, C->U+3);
	left4(C->B+2, C->R+2, C->F+2, C->L+2);
	left4(C->B+1, C->R+1, C->F+1, C->L+1);
	left4(C->B+0, C->R+0, C->F+0, C->L+0);
}
	 
void girarD(cubo* C)
{
	right4(C->D+0, C->D+2, C->D+8, C->D+6);
	right4(C->D+1, C->D+5, C->D+7, C->D+3);
	right4(C->F+6, C->R+6, C->B+6, C->L+6);
	right4(C->F+7, C->R+7, C->B+7, C->L+7);
	right4(C->F+8, C->R+8, C->B+8, C->L+8);
}

void girard(cubo* C)
{
	left4(C->D+0, C->D+2, C->D+8, C->D+6);
	left4(C->D+1, C->D+5, C->D+7, C->D+3);
	left4(C->F+6, C->R+6, C->B+6, C->L+6);
	left4(C->F+7, C->R+7, C->B+7, C->L+7);
	left4(C->F+8, C->R+8, C->B+8, C->L+8);
}

void girarR(cubo* C)
{
	right4(C->R+0, C->R+2, C->R+8, C->R+6);
	right4(C->R+1, C->R+5, C->R+7, C->R+3);
	right4(C->U+8, C->B+0, C->D+8, C->F+8);
	right4(C->U+5, C->B+3, C->D+5, C->F+5);
	right4(C->U+2, C->B+6, C->D+2, C->F+2);
}

void girarr(cubo* C)
{
	left4(C->R+0, C->R+2, C->R+8, C->R+6);
	left4(C->R+1, C->R+5, C->R+7, C->R+3);
	left4(C->U+8, C->B+0, C->D+8, C->F+8);
	left4(C->U+5, C->B+3, C->D+5, C->F+5);
	left4(C->U+2, C->B+6, C->D+2, C->F+2);
}

void girarL(cubo* C)
{
	right4(C->L+0, C->L+2, C->L+8, C->L+6);
	right4(C->L+1, C->L+5, C->L+7, C->L+3);
	right4(C->U+0, C->F+0, C->D+0, C->B+8);
	right4(C->U+3, C->F+3, C->D+3, C->B+5);
	right4(C->U+6, C->F+6, C->D+6, C->B+2);
}

void girarl(cubo* C)
{
	left4(C->L+0, C->L+2, C->L+8, C->L+6);
	left4(C->L+1, C->L+5, C->L+7, C->L+3);
	left4(C->U+0, C->F+0, C->D+0, C->B+8);
	left4(C->U+3, C->F+3, C->D+3, C->B+5);
	left4(C->U+6, C->F+6, C->D+6, C->B+2);
}

void girarB(cubo* C)
{
	right4(C->B+0, C->B+2, C->B+8, C->B+6);
	right4(C->B+1, C->B+5, C->B+7, C->B+3);
	right4(C->U+0, C->L+6, C->D+8, C->R+2);
	right4(C->U+1, C->L+3, C->D+7, C->R+5);
	right4(C->U+2, C->L+0, C->D+6, C->R+8);
}

void girarb(cubo* C)
{
	left4(C->B+0, C->B+2, C->B+8, C->B+6);
	left4(C->B+1, C->B+5, C->B+7, C->B+3);
	left4(C->U+0, C->L+6, C->D+8, C->R+2);
	left4(C->U+1, C->L+3, C->D+7, C->R+5);
	left4(C->U+2, C->L+0, C->D+6, C->R+8);
}

void mostrarCubo(cubo* C)
{
	int i;
	
	if (C == NULL)
	{
		printf("mostrarCubo recibió argumento nulo\n");
		return;
	}
	
	for(i=0;i<3;++i)
	{
		printf("      ");
		printf("%i %i %i\n",C->U[3*i+0],C->U[3*i+1],C->U[3*i+2]);
	}
	
	for(i=0;i<9;i=i+3)
	{
		printf("%i %i %i ",C->L[i+0],C->L[i+1],C->L[i+2]);
		printf("%i %i %i ",C->F[i+0],C->F[i+1],C->F[i+2]);
		printf("%i %i %i ",C->R[i+0],C->R[i+1],C->R[i+2]);
		printf("%i %i %i\n",C->B[i+0],C->B[i+1],C->B[i+2]);
	}
	
	for(i=0;i<3;++i)
	{
		printf("      ");
		printf("%i %i %i\n",C->D[3*i+0],C->D[3*i+1],C->D[3*i+2]);
	}
}

int solved(cubo* C)
{
	int i;
	
	for(i=0;i<8;++i)
	{
		if(C->U[i] != C->U[8]) return 0;
		if(C->D[i] != C->D[8]) return 0;
		if(C->B[i] != C->B[8]) return 0;
		if(C->F[i] != C->F[8]) return 0;
		if(C->L[i] != C->L[8]) return 0;
		if(C->R[i] != C->R[8]) return 0;
	}
	
	return 1;
}

void hacerReceta(cubo* C, char* s)
{
	char c;
	while((c = *s++)) /*doble parentesis asi mi compilador no llora*/
	{
		if(c == 'F')
			girarF(C);
		else if(c == 'f')
			girarf(C);
		else if(c == 'U')
			girarU(C);
		else if(c == 'u')
			giraru(C);
		else if(c == 'B')
			girarB(C);
		else if(c == 'b')
			girarb(C);
		else if(c == 'D')
			girarD(C);
		else if(c == 'd')
			girard(C);
		else if(c == 'L')
			girarL(C);
		else if(c == 'l')
			girarl(C);
		else if(c == 'R')
			girarR(C);
		else if(c == 'r')
			girarr(C);
		else if(c == ' ')
			;
		else
		{
			printf("Argumento invalido a hacerReceta. Caracter: %c (%i)\n",c,c);
			abort();
		}
	}
}

void aleatorio(cubo* C)
{
	int i;
	void (*funcs[])(cubo*) = { girarF, girarf, girarU, giraru,
	                           girarD, girard, girarR, girarr,
	                           girarL, girarl, girarB, girarb };
	
	i = rand() % (sizeof funcs / sizeof (funcs[0]));
	(funcs[i])(C);
}

cubo* leerCubo()
{
	int i,j;
	cubo* C;
	int ret;

	C = (cubo*) malloc(sizeof(cubo));
	ret = 1;

	for(i=0;i<9;++i)
		ret = ret && 0 < scanf("%i",&C->U[i]); /*leo U*/

	for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
			ret = ret && 0 < scanf("%i",&C->L[3*i+j]);

		for(j=0;j<3;++j)
			ret = ret && 0 < scanf("%i",&C->F[3*i+j]);

		for(j=0;j<3;++j)
			ret = ret && 0 < scanf("%i",&C->R[3*i+j]);

		for(j=0;j<3;++j)
			ret = ret && 0 < scanf("%i",&C->B[3*i+j]);
	}


	for(i=0;i<9;++i)
		ret = ret && 0 < scanf("%i",&C->D[i]); /*leo D*/

	if(ret)
		return C;
	else {
		free(C);
		return NULL;
	}
}

void mostrarCuboS(cubo* C, char *s)
{
	int o=0;
	int i;
	
	if (C == NULL)
	{
		fprintf(stderr ,"mostrarCubo recibió argumento nulo\n");
		return;
	}
	
	for(i=0;i<3;++i)
	{
		o += sprintf(s+o, "%i %i %i ",C->U[3*i+0],C->U[3*i+1],C->U[3*i+2]);
	}
	
	for(i=0;i<9;i=i+3)
	{
		o += sprintf(s+o, "%i %i %i ",C->L[i+0],C->L[i+1],C->L[i+2]);
		o += sprintf(s+o, "%i %i %i ",C->F[i+0],C->F[i+1],C->F[i+2]);
		o += sprintf(s+o, "%i %i %i ",C->R[i+0],C->R[i+1],C->R[i+2]);
		o += sprintf(s+o, "%i %i %i ",C->B[i+0],C->B[i+1],C->B[i+2]);
	}
	
	for(i=0;i<3;++i)
	{
		o += sprintf(s+o, "%i %i %i ",C->D[3*i+0],C->D[3*i+1],C->D[3*i+2]);
	}

	s[o] = '\n';
	s[o+1] = 0;
}

int main(int argc, char** argv)
{
	assert(argc == 2);
	cubo *in;
	
	in = leerCubo();

	if(in == NULL) {
		printf("Entrada mal formada. Abortando\n");
		exit(1);
	}

	hacerReceta(in, argv[1]);
	mostrarCubo(in);

	return 0;
}

