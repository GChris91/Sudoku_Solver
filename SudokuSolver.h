#ifndef SUDOKU_H_INCLUDED
#define SUDOKU_H_INCLUDED

#include "SudokuFile.h"
#include <stdbool.h>

bool existeSurLigne(int lin, char num, sudoku *s);
bool existeSurColonneColonne(int col, char num, sudoku *s);
bool existeSurColonneRegion(int lin, int col, char num, sudoku *s);
bool afficheSolution(sudoku *s, int position);
void solutionsValides(sudoku *s, int position, char filename[]);


#endif // SUDOKU_H_INCLUDED
