/*
** EPITECH PROJECT, 2022
** Solver
** File description:
** Check the map characters.
*/

#include "solver.h"
#include <stddef.h>

///////////////////////////////
// Verif if the map is valid //
///////////////////////////////
bool verif_map(char const *map)
{
    for (size_t i = 0; map[i]; i++)
        if (map[i] != WALL && map[i] != VOID && map[i] != '\n')
            return false;
    return true;
}
