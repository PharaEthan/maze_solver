/*
** EPITECH PROJECT, 2022
** Solver
** File description:
** Error handling
*/

#include "solver.h"

////////////////////////
// check the argument //
////////////////////////
void error_handling(int ac, char **av)
{
    struct stat st;

    if (ac != 2)
        exit(84);
    if (stat(av[1], &st) != 0) // av[1] = {maze.txt}
        exit(84);
}
