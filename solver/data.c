#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "common.h"

/*
 * Searches starting on C, with possible moves in Movs until
 * we find a cube which matches the criterion fit().
 * *sol contains the solution.
 */
cube *IDDFS(cube *C, cubeFitnessFunc fit, char **Movs,char *sol)
{
	cube* r;
	int i;

	for (i = 0; ; i++) {
		r = DFS(C, sol, i, fit, Movs);
		if (r)
			return r;
	}

	return NULL;
}

cube *DFS(cube *C, char *sol, int max, cubeFitnessFunc fit, char **Movs)
{
	cube *new;
	cube *r;
	int i;

	if (max <= 0) {
		if (fit(C)) {
			r = malloc(sizeof (cube));
			*r = *C;

			sol[0] = 0;

			return r;
		} else {
			return NULL;
		}
	} else {
		new = malloc(sizeof (cube));
		*new = *C;

		for (i = 0; strcmp(Movs[i], ""); i++) {
			const char *sq = Movs[i];
			int len = strlen(sq);

			doSeq(new, sq);
			strcpy(sol, sq);
			r = DFS(new, sol + len, max - len, fit, Movs);

			if (r) {
				free(new);
				return r;
			} else {
				*new = *C;
			}
		}

		free(new);
		return NULL;
	}
}

bool solved(cube *C) {
	int i;

	for (i = 0; i < 8; i++) {
		if (C->U[i] != C->U[8])
			return false;
		if (C->D[i] != C->D[8])
			return false;
		if (C->B[i] != C->B[8])
			return false;
		if (C->F[i] != C->F[8])
			return false;
		if (C->L[i] != C->L[8])
			return false;
		if (C->R[i] != C->R[8])
			return false;
	}

	return true;
}

void doSeq(cube* C, const char *s)
{
	const char *p;
	for (p = s; *p; p++) {
		switch (*p) {
		case 'F':
			turnF(C);
			break;
		case 'f':
			turnf(C);
			break;
		case 'U':
			turnU(C);
			break;
		case 'u':
			turnu(C);
			break;
		case 'D':
			turnD(C);
			break;
		case 'd':
			turnd(C);
			break;
		case 'B':
			turnB(C);
			break;
		case 'b':
			turnb(C);
			break;
		case 'L':
			turnL(C);
			break;
		case 'l':
			turnl(C);
			break;
		case 'R':
			turnR(C);
			break;
		case 'r':
			turnr(C);
			break;
		default:
			assert(0);
		}
	}
}

cube* readCube() {
	int i,j;
	int ret;
	cube *C;

	C = malloc(sizeof (cube));

	ret = 1;

	for (i = 0; i < 9; i++)
		ret = ret && 0 < scanf("%i",&C->U[i]);

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			ret = ret && 0 < scanf("%i",&C->L[3*i+j]);

		for (j = 0; j < 3; j++)
			ret = ret && 0 < scanf("%i",&C->F[3*i+j]);

		for (j = 0; j < 3; j++)
			ret = ret && 0 < scanf("%i",&C->R[3*i+j]);

		for (j = 0; j < 3; j++)
			ret = ret && 0 < scanf("%i",&C->B[3*i+j]);
	}


	for (i = 0; i < 9; i++)
		ret = ret && 0 < scanf("%i",&C->D[i]);

	if (ret) {
		return C;
	} else {
		free(C);
		return NULL;
	}
}

void showCuboF(cube *C, FILE *ff)
{
	int i;

	assert(C);

	for (i = 0; i < 3; i++) {
		fprintf(ff, "      ");
		fprintf(ff, "%i %i %i\n", C->U[3*i+0], C->U[3*i+1], C->U[3*i+2]);
	}

	for(i = 0; i < 9; i = i + 3) {
		fprintf(ff, "%i %i %i ", C->L[i+0], C->L[i+1], C->L[i+2]);
		fprintf(ff, "%i %i %i ", C->F[i+0], C->F[i+1], C->F[i+2]);
		fprintf(ff, "%i %i %i ", C->R[i+0], C->R[i+1], C->R[i+2]);
		fprintf(ff, "%i %i %i\n", C->B[i+0], C->B[i+1], C->B[i+2]);
	}

	for (i = 0; i < 3; i++) {
		fprintf(ff, "      ");
		fprintf(ff, "%i %i %i\n", C->D[3*i+0], C->D[3*i+1], C->D[3*i+2]);
	}
}

void turnF(cube* C)
{
	right4(C->F+0, C->F+2, C->F+8, C->F+6);
	right4(C->F+1, C->F+5, C->F+7, C->F+3);
	right4(C->U+6, C->R+0, C->D+2, C->L+8);
	right4(C->U+7, C->R+3, C->D+1, C->L+5);
	right4(C->U+8, C->R+6, C->D+0, C->L+2);
}

void turnf(cube* C)
{
	left4(C->F+0, C->F+2, C->F+8, C->F+6);
	left4(C->F+1, C->F+5, C->F+7, C->F+3);
	left4(C->U+6, C->R+0, C->D+2, C->L+8);
	left4(C->U+7, C->R+3, C->D+1, C->L+5);
	left4(C->U+8, C->R+6, C->D+0, C->L+2);
}

void turnU(cube* C)
{
	right4(C->U+0, C->U+2, C->U+8, C->U+6);
	right4(C->U+1, C->U+5, C->U+7, C->U+3);
	right4(C->B+2, C->R+2, C->F+2, C->L+2);
	right4(C->B+1, C->R+1, C->F+1, C->L+1);
	right4(C->B+0, C->R+0, C->F+0, C->L+0);
}

void turnu(cube* C)
{
	left4(C->U+0, C->U+2, C->U+8, C->U+6);
	left4(C->U+1, C->U+5, C->U+7, C->U+3);
	left4(C->B+2, C->R+2, C->F+2, C->L+2);
	left4(C->B+1, C->R+1, C->F+1, C->L+1);
	left4(C->B+0, C->R+0, C->F+0, C->L+0);
}

void turnD(cube* C)
{
	right4(C->D+0, C->D+2, C->D+8, C->D+6);
	right4(C->D+1, C->D+5, C->D+7, C->D+3);
	right4(C->F+6, C->R+6, C->B+6, C->L+6);
	right4(C->F+7, C->R+7, C->B+7, C->L+7);
	right4(C->F+8, C->R+8, C->B+8, C->L+8);
}

void turnd(cube* C)
{
	left4(C->D+0, C->D+2, C->D+8, C->D+6);
	left4(C->D+1, C->D+5, C->D+7, C->D+3);
	left4(C->F+6, C->R+6, C->B+6, C->L+6);
	left4(C->F+7, C->R+7, C->B+7, C->L+7);
	left4(C->F+8, C->R+8, C->B+8, C->L+8);
}

void turnR(cube* C)
{
	right4(C->R+0, C->R+2, C->R+8, C->R+6);
	right4(C->R+1, C->R+5, C->R+7, C->R+3);
	right4(C->U+8, C->B+0, C->D+8, C->F+8);
	right4(C->U+5, C->B+3, C->D+5, C->F+5);
	right4(C->U+2, C->B+6, C->D+2, C->F+2);
}

void turnr(cube* C)
{
	left4(C->R+0, C->R+2, C->R+8, C->R+6);
	left4(C->R+1, C->R+5, C->R+7, C->R+3);
	left4(C->U+8, C->B+0, C->D+8, C->F+8);
	left4(C->U+5, C->B+3, C->D+5, C->F+5);
	left4(C->U+2, C->B+6, C->D+2, C->F+2);
}

void turnL(cube* C)
{
	right4(C->L+0, C->L+2, C->L+8, C->L+6);
	right4(C->L+1, C->L+5, C->L+7, C->L+3);
	right4(C->U+0, C->F+0, C->D+0, C->B+8);
	right4(C->U+3, C->F+3, C->D+3, C->B+5);
	right4(C->U+6, C->F+6, C->D+6, C->B+2);
}

void turnl(cube* C)
{
	left4(C->L+0, C->L+2, C->L+8, C->L+6);
	left4(C->L+1, C->L+5, C->L+7, C->L+3);
	left4(C->U+0, C->F+0, C->D+0, C->B+8);
	left4(C->U+3, C->F+3, C->D+3, C->B+5);
	left4(C->U+6, C->F+6, C->D+6, C->B+2);
}

void turnB(cube* C)
{
	right4(C->B+0, C->B+2, C->B+8, C->B+6);
	right4(C->B+1, C->B+5, C->B+7, C->B+3);
	right4(C->U+0, C->L+6, C->D+8, C->R+2);
	right4(C->U+1, C->L+3, C->D+7, C->R+5);
	right4(C->U+2, C->L+0, C->D+6, C->R+8);
}

void turnb(cube* C)
{
	left4(C->B+0, C->B+2, C->B+8, C->B+6);
	left4(C->B+1, C->B+5, C->B+7, C->B+3);
	left4(C->U+0, C->L+6, C->D+8, C->R+2);
	left4(C->U+1, C->L+3, C->D+7, C->R+5);
	left4(C->U+2, C->L+0, C->D+6, C->R+8);
}
