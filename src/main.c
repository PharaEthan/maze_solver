/*
** EPITECH PROJECT, 2022
** Solver
** File description:
** Main of maze's solver
*/

#include "solver.h"

////////////////////////////////////
// Resize your memory stack       //
// Useful in recursive algorithms //
////////////////////////////////////
static void resize_stack(void)
{
    struct rlimit stack;

    if (getrlimit(RLIMIT_STACK, &stack))
        return;
    stack.rlim_cur = stack.rlim_max;
    if (setrlimit(RLIMIT_STACK, &stack))
        return;
}

/////////////////////
// Free the memory //
/////////////////////
static void free_struct(solver_t *solver)
{
    for (size_t i = 0; solver->map[i]; i++)
        free(solver->map[i]);
    free(solver->map);
}

/////////////////////////
// Main of the project //
/////////////////////////
int main(int ac, char **av)
{
    solver_t solver;

    error_handling(ac, av);
    solver = init_struct_solver(av[1]);
    resize_stack();
    set_maze_start_end(&solver);
    if (backtracking(&solver, 0, 0) == 0) {
        printf("no solution found");
        return (0);
    }
    edit_maze(&solver);
    for (size_t i = 0; solver.map[i]; i++)
        printf("%s", solver.map[i]);
    free_struct(&solver);
    return EXIT_SUCCESS;
}
