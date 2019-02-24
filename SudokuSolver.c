#include "SudokuSolver.h"
#include "SudokuFile.h"


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


/// Vérification d'un élément sur une ligne

bool existeSurLigne(int lin, char num, sudoku *s)
{
    int i;

    for(i = 0; i < 9; i++)
    {
        if((*s).grille[lin][i] == num)
        {
            return(true);
        }
    }

    return(false);
}


/// Vérification d'un élément sur une colonne

bool existeSurColonne(int col, char num, sudoku *s)
{
    int i;

    for(i = 0; i < 9; i++)
    {
        if((*s).grille[i][col] == num)
        {
            return(true);
        }
    }

    return(false);
}


/// Vérification d'un élément sur une region (3 lignes 3 colonnes)

bool existeSurRegion(int lin, int col, char num, sudoku *s)
{
    int i = lin - (lin % 3), j = col - (col % 3), i2, j2;

    for(i2 = i; i2 < i + 3; i2++)
    {
        for(j2 = j; j2 < j + 3; j2++)
        {
            if((*s).grille[i2][j2] == num)
            {
                return(true);
            }
        }
    }

    return(false);
}


/// Donne les resultats sur une grille affichée via la console

bool afficheSolution(sudoku *s, int position)
{
    if(position == 9 * 9) /// Fin de grille
    {
        return (true);
    }

    int l;
    int i = position / 9;
    int j = position % 9;
    char k; /// Caractère de 1 à 9

    if((*s).grille[i][j] != '0')
    {
        return (afficheSolution(s, position + 1));
    }

    for(l = 1; l <= 9; l++)
    {
        k = '0' + l;

        if(!(existeSurLigne(i, k, s)) && !(existeSurColonne(j, k, s)) && !(existeSurRegion(i, j, k, s)))
        {
            (*s).grille[i][j] = k;

            if(afficheSolution(s, position + 1))
            {
                return (true);
            }
        }
    }

    (*s).grille[i][j] = '0'; /// Change en case vide

    return (false);
}


/// Rend les resultats sur plusieurs grilles avec chaque grille une solution unique enregistrée sur fichier texte

void solutionsValides(sudoku *s, int position, char namefile[])
{
    if(position == 9 * 9) /// Fin de grille
    {
        saveSudokuToFile(namefile,s);

    }else
    {
        int l;
        int i = position / 9;
        int j = position % 9;
        char k; /// Caractère de 1 à 9

        if((*s).grille[i][j] != '0')
        {
            solutionsValides(s, position + 1, namefile);

        }else
        {
            for(l = 1; l <= 9; l++)
            {
                k = '0' + l;

                if(!(existeSurLigne(i, k, s)) && !(existeSurColonne(j, k, s)) && !(existeSurRegion(i, j, k, s)))
                {
                    (*s).grille[i][j] = k;

                    solutionsValides(s, position + 1, namefile);

                        (*s).grille[i][j] = '0'; /// Change en case vide

                }
            }
        }
    }
}
