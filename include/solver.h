/*
** EPITECH PROJECT, 2022
** Solver
** File description:
** include for solver
*/

#ifndef SOLVER_H_
    #define SOLVER_H_

    #include <stdbool.h>
    #include <sys/stat.h>
    #include <sys/resource.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdio.h>

////////////////////////////////
// Macro for solver algorithm //
////////////////////////////////
enum maze {
    WALL = 'X',
    START = 'S',
    END = 'E',
    VOID = '*',
    PATH = 'o',
    BADPATH = 'C'
};

/////////////////////////////////
// Struct for solver algorithm //
/////////////////////////////////
typedef struct solver {
    char **map;
    int weight;
    int height;
} solver_t;

///////////////////
// Error gestion //
///////////////////
void error_handling(int ac, char **av);
bool verif_map(char const *map);

/////////////////////
// Struct function //
/////////////////////
char **open_file(solver_t *solver, char const *filepath);
solver_t init_struct_solver(char const *filepath);

//////////////////////
// Solving function //
//////////////////////
void edit_maze(solver_t *solver);
int backtracking(solver_t *solver, int x, int y);
void set_maze_start_end(solver_t *solver);

#endif/* SOLVER */
