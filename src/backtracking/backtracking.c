/*
** EPITECH PROJECT, 2022
** Solver
** File description:
** Backtracking algorithm
*/

#include "solver.h"

////////////////////////
// put the maze start //
////////////////////////
void set_maze_start_end(solver_t *solver)
{
    if (solver->map[0][0] == WALL)
        exit(84);
    solver->map[0][0] = START; // You can change the start coordonates
    solver->map[solver->height - 1][solver->weight - 2] = END;
    solver->map[solver->height - 1][solver->weight - 1] = '\0';
}

////////////////////////////
// Backtracking algorithm //
////////////////////////////
int backtracking(solver_t *solver, int x, int y)
{
    if (y < 0 || (y > solver->height - 1) || x < 0 || (x > solver->weight - 1))
        return (0);
    if (solver->map[y][x] == END)
        return (1);
    if (solver->map[y][x] != VOID && solver->map[y][x] != START)
        return (0);
    solver->map[y][x] = PATH;
    if (backtracking(solver, x + 1, y) == 1)
        return (1);
    if (backtracking(solver, x, y + 1) == 1)
        return (1);
    if (backtracking(solver, x - 1, y) == 1)
        return (1);
    if (backtracking(solver, x, y - 1) == 1)
        return (1);
    solver->map[y][x] = BADPATH; // If you delete this line you'll see all the path of the algoritm
    return (0);
}

void edit_maze(solver_t *solver)
{
    for (size_t y = 0; solver->map[y]; y++) {
        for (size_t x = 0; solver->map[y][x]; x++) {
        if (solver->map[y][x] == BADPATH)
            solver->map[y][x] = VOID;
        if (solver->map[y][x] == END)
            solver->map[y][x] = PATH;
        }
    }
}
