#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#include "SudokuFile.h"
#include "SudokuSolver.h"



int main()
{

    int i, done = 0;
    char filename[256];
    char solution;

    sudoku *s;

    printf("Nom de votre grille Sudoku ?\n");
    scanf("%s", filename);

    s = malloc(sizeof(sudoku));
    i = openSudokuFromFile(filename, s);

    if(i == -1) /// Erreur en cas de fichier corrompu ou inexistant
    {
        printf("Erreur, Sudoku mal remplis ou inexistant\n" );
        return(0);
    }

    printSudoku(s);

    printf("Souhaitez-vous:\nAfficher la solution? (A)\nL\'enregistrer dans un fichier? (E)\n");

    do
    {
        solution = getch();
        switch(solution){

            case 'A' :
                afficheSolution(s, 0);
                for(i = 0; i < 9 * 9; i++)
                {
                    if((*s).grille[i / 9][i % 9]== '0')
                    {
                        printf("Il n\'existe pas de solution pour cette grille\n");
                        return(0);
                    }
                }
                printSudoku(s);

            done = 1; /// Permet de sortir de la boucle
            break;

            case 'a' :
                afficheSolution(s, 0);
                for(i = 0; i < 9 * 9; i++)
                {
                    if((*s).grille[i / 9][i % 9]== '0')
                    {
                        printf("Il n\'existe pas de solution pour cette grille\n");
                        return(0);
                    }
                }
                printSudoku(s);

            done = 1; /// Permet de sortir de la boucle
            break;


            case 'E' :
                printf("Donner le nom ou l\'emplacement du fichier de sauvegarde\n");
                scanf("%s", filename);
                solutionsValides(s, 0, filename);

            done = 1; /// Permet de sortir de la boucle
            break;

            case 'e' :
                printf("Donner le nom ou l\'emplacement du fichier de sauvegarde\n");
                scanf("%s", filename);
                solutionsValides(s, 0, filename);

            done = 1; /// Permet de sortir de la boucle
            break;


            default :
                continue; /// Boucle permettant de s'assurer qu'une option est choisie
            break;
        }

    } while (!done);

    return (0);
}
