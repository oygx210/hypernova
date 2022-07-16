#ifndef SOLVER_CONSTANTS_H
#define SOLVER_CONSTANTS_H

#define VEC_SIZE 6
#define MAX_BUTCHER_TABLEAU_SIZE 25

typedef struct SolverSolution
{
    double *t;             // mission elapsed time in seconds
    double *jd;            // absolute mission time in jd
    double (*y)[VEC_SIZE]; // position and velocity of spacecraft
    size_t n;              // number of steps taken
} SolverSolution;

typedef struct ButcherTableau
{
    double A[MAX_BUTCHER_TABLEAU_SIZE][MAX_BUTCHER_TABLEAU_SIZE];
    double b[MAX_BUTCHER_TABLEAU_SIZE];
    double c[MAX_BUTCHER_TABLEAU_SIZE];
} ButcherTableau;
typedef struct RKSolver
{
    ButcherTableau *weights;
    size_t num_stages;
} RKSolver;

// typedef for ode function
typedef void (*ODEFunction)(double t, double y[VEC_SIZE], double dydt[VEC_SIZE]);

#endif