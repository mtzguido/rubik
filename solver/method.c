#include "data.h"
#include "method.h"
#include "common.h"

static int contarCruzD(cube *C);
static int contarEsqD(cube *C);
static int contarBordes(cube *C);

static int contarCruzD(cube *C)
{
	int i = 0;

	if(C->D[1] == C->D[4] && C->F[7] == C->F[4]) i++;
	if(C->D[5] == C->D[4] && C->R[7] == C->R[4]) i++;
	if(C->D[7] == C->D[4] && C->B[7] == C->B[4]) i++;
	if(C->D[3] == C->D[4] && C->L[7] == C->L[4]) i++;

	return i;
}

bool cruz2D(cube *C) { return contarCruzD(C) >= 2; }
bool cruz3D(cube *C) { return contarCruzD(C) >= 3; }
bool cruz4D(cube *C) { return contarCruzD(C) >= 4; }

static int contarEsqD(cube *C)
{
	int i = 0;

	if(!cruz4D(C)) return 0;

	if(C->D[0] == C->D[4] && C->F[6] == C->F[4] && C->L[8] == C->L[4]) i++;
	if(C->D[2] == C->D[4] && C->R[6] == C->R[4] && C->F[8] == C->F[4]) i++;
	if(C->D[8] == C->D[4] && C->B[6] == C->B[4] && C->R[8] == C->R[4]) i++;
	if(C->D[6] == C->D[4] && C->L[6] == C->L[4] && C->B[8] == C->B[4]) i++;

	return i;
}

bool esqD1(cube *C) { return contarEsqD(C) >= 1; }
bool esqD2(cube *C) { return contarEsqD(C) >= 2; }
bool esqD3(cube *C) { return contarEsqD(C) >= 3; }
bool esqD4(cube *C) { return contarEsqD(C) >= 4; }

static int contarBordes(cube *C)
{
	int i = 0;

	if(!esqD4(C)) return 0;

	if(C->F[5] == C->F[4] && C->R[3] == C->R[4]) i++;
	if(C->R[5] == C->R[4] && C->B[3] == C->B[4]) i++;
	if(C->B[5] == C->B[4] && C->L[3] == C->L[4]) i++;
	if(C->L[5] == C->L[4] && C->F[3] == C->F[4]) i++;

	return i;
}

bool bordesUD1(cube *C) { return contarBordes(C) >= 1; }
bool bordesUD2(cube *C) { return contarBordes(C) >= 2; }
bool bordesUD3(cube *C) { return contarBordes(C) >= 3; }
bool bordesUD4(cube *C) { return contarBordes(C) >= 4; }

bool caraU(cube *C)
{
	if(!bordesUD4(C)) return 0;

	if(C->U[0] != C->U[4]) return 0;
	if(C->U[1] != C->U[4]) return 0;
	if(C->U[2] != C->U[4]) return 0;
	if(C->U[3] != C->U[4]) return 0;
	if(C->U[5] != C->U[4]) return 0;
	if(C->U[6] != C->U[4]) return 0;
	if(C->U[7] != C->U[4]) return 0;
	if(C->U[8] != C->U[4]) return 0;

	return 1;
}
