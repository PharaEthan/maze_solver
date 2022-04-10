/*
** EPITECH PROJECT, 2022
** Solver
** File description:
** Init the solver struct
*/

#include "solver.h"

//////////////////////////////////
// Initialize the solver struct //
//////////////////////////////////
solver_t *init_struct_solver(char const *filepath)
{
    solver_t *solver = NULL;
    
    if (!filepath)
        return NULL;
    solver = malloc(sizeof(solver_t));
    if (!solver)
        return NULL;
    solver->map = open_file(solver, filepath);
    if (!solver->map)
        return NULL;
    for (size_t i = 0; solver->map[i]; i++)
        verif_map(solver->map[i]);
    solver->weight = strlen(solver->map[0]);
    if (solver->weight < 2)
        exit(84);
    return solver;
}
