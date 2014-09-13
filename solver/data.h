#ifndef ___DATA_H
#define ___DATA_H

#include <stdio.h>
#include "common.h"

typedef struct cube_struct {
	int F[9];
	int B[9];
	int U[9];
	int D[9];
	int R[9];
	int L[9];
} cube;

cube *readCube();
void shoeCuboF(cube *, FILE *);
void swap2(int *, int *);

/* Do a sequence of primitive moves */
void doSeq(cube *, const char *);

typedef void cubeTransformFunc(cube *);

cubeTransformFunc turnF, turnf, turnU,
		  turnu, turnD, turnd,
		  turnB, turnb, turnL,
		  turnl, turnR, turnr;

typedef bool cubeFitnessFunc(cube *);

bool solved(cube *);

cube *IDDFS(cube *C, cubeFitnessFunc fit, char **Movs, char *sol);
cube *DFS(cube *C, char * sol, int, cubeFitnessFunc, char **Movs);

static inline void left4(int *a, int *b, int *c, int *d) {
	int t;

	t = *a;
	*a = *b;
	*b = *c;
	*c = *d;
	*d = t;
}

static inline void right4(int *a, int *b, int *c, int *d) {
	left4(d, c, b, a);
}

#endif
