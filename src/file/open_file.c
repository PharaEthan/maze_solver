/*
** EPITECH PROJECT, 2022
** Solver
** File description:
** File gestion
*/

#include "solver.h"

///////////////////////////////////////////
// Return the number of line in the file //
///////////////////////////////////////////
static size_t nb_line(char const *filepath)
{
    FILE *file = fopen(filepath, "r");
    char *line = NULL;
    size_t len = 0;
    size_t compt = 0;

    if (!file)
        exit(84);
    for (; getline(&line, &len, file) != -1; compt++);
    free(line);
    fclose(file);
    return compt;
}

////////////////////////////////////////////////////////////////
// Open the maze file and put the maze into the solver struct //
////////////////////////////////////////////////////////////////
char **open_file(solver_t *solver, char const *filepath)
{
    char **buff = NULL;
    FILE *file = fopen(filepath, "r");
    char *line = NULL;
    size_t len = 0;
    size_t i = 0;

    if (!file)
        return NULL;
    solver->height = nb_line(filepath);
    if (solver->height < 2)
        return NULL;
    buff = malloc(sizeof(char *) * (solver->height + 1));
    if (!buff) {
        fclose(file);
        return NULL;
    }
    for (; getline(&line, &len, file) != -1; i++) {
        buff[i] = line;
        line = NULL;
    }
    free(line);
    buff[i] = NULL;
    fclose(file);
    return buff;
}
