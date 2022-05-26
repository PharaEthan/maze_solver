/*
** EPITECH PROJECT, 2022
** Solver
** File description:
** Init the solver struct
*/

#include "solver.h"
#include <string.h>
#include <stdlib.h>

//////////////////////////////////
// Initialize the solver struct //
//////////////////////////////////
solver_t init_struct_solver(char const *filepath)
{
    solver_t solver;
    
    if (!filepath)
        exit(84);
    solver.map = open_file(&solver, filepath);
    if (!solver.map)
        exit(84);
    for (size_t i = 0; solver.map[i]; i++)
        verif_map(solver.map[i]);
    solver.weight = strlen(solver.map[0]);
    if (solver.weight < 2)
        exit(84);
    return solver;
}
