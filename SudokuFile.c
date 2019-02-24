#include "SudokuFile.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>



/// Procédure d'initialisation
/// Rend une grille vide

void initializeSudoku(sudoku *s)
{
    int i;

    (*s).grille = malloc(9 * sizeof(char*));

    for (i = 0 ; i < 9 ; i++)
    {
        (*s).grille[i] = malloc(9 * sizeof(char));
    }
}


/// Ouverture via fichier

int openSudokuFromFile(char * filename, sudoku *s)
{
    int i,j,k;
    char ligne[256];
    char *pointeur;

    FILE *fichier;
    fichier = fopen(filename, "r"); /// Mode read
    initializeSudoku(s);

    for(i = 0; i < 9; i++)
    {
        pointeur = fgets(ligne, 18, fichier);

        if (pointeur == NULL)
        {
            return(-1);
        }

        k = 0; /// Case manquante du Sudoku à compléter

        for(j = 0; j < 18; j++)
        {
            if(pointeur[j] != ' ')
            {
                (*s).grille[i][k] = pointeur[j];
                k++;
            }
        }

        pointeur = fgets(ligne, 18, fichier);
        pointeur = NULL;

    }
    return(0);
}


/// Affichage du Sudoku

void printSudoku(sudoku *s)
{
    int i,j;

    printf("------------------\n"); /// Facilite l'affichage de la grille sur console

    for(i = 0 ; i < 9 ; i++)
    {
        printf("|");

        for(j = 0 ; j < 8 ; j++)
        {
            if((*s).grille[i][j] == '0')
            {
                printf(" |");
            }else
            {
                printf("%c|",(*s).grille[i][j]);
            }
        }

        if((*s).grille[i][j] == '0') /// Le caractère 0 représente un espace vide à compléter
        {
            printf(" |\n");
        }else
        {
                printf("%c|\n",(*s).grille[i][j]);
        }

        if((i == 2) || (i == 5) || (i == 8))
        {
            puts("------------------"); /// Facilite l'affichage de la grille sur console
        }else
        {
            printf("\n");
        }

    }
    printf("\n");
}


/// Enregistrement du Sudoku

int saveSudokuToFile(char * filename, sudoku *s)
{
    int i,j,k;
    char ligne[256];

    FILE *fichier;
    fichier = fopen(filename, "a");  /// Mode appending

    for(i = 0; i < 9; i++)
    {
        k = 0; /// Case manquante du Sudoku à completer
        for(j = 0; j < 9; j++)
        {
            ligne[k] = (*s).grille[i][j];
            k++;
            ligne[k] = ' ';
            k++;
        }

        fprintf(fichier, ligne);
        fprintf(fichier, "\n" );
    }

    fprintf(fichier, "\n\n"); /// Espaces au cas où une nouvelle grille est ajoutée au fichier

    return(0);
}
