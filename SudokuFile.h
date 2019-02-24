#ifndef SUDOKUFILE_H_INCLUDED
#define SUDOKUFILE_H_INCLUDED


typedef struct
{
    char ** grille;
    }sudoku;


void initializeSudoku(sudoku *s);
int openSudokuFromFile(char * filename,sudoku *s);
void printSudoku(sudoku *s);
int saveSudokuToFile(char * filename, sudoku *s);


#endif // SUDOKUFILE_H_INCLUDED
