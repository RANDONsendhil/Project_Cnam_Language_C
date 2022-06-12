#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NBCASES 3
#define NBESSAIS 10

/* prototypes à définir */

void tirage(int tab[], int dim);
void print_tab(int[], int dim);
void analyse(int ref[], int essai[], int *BienPlaces, int *MalPlaces);
int entree(int essai[], int *combEntree);
void depiler(int essai[]);

int MasterMind()
{
    int *ref, *essai;
    int BienPlaces, MalPlaces, dim, combEntree;

    printf("Donnez le nombre de cases : ");
    scanf("%d", &dim);

    ref = (int *)malloc(dim * sizeof(int));
    essai = (int *)malloc(dim * sizeof(int));

    if (ref == NULL || essai == NULL)
    {
        printf("pas assez de memoire\n");
        exit(-1);
    }

    tirage(ref, dim);
    printf("ref = ");
    print_tab(ref, dim);

    for (int j = 0; j < NBESSAIS; j++)
    {
        printf("\nEntrez votre combinaison de %d chiffres: ", NBCASES);
        entree(essai, &combEntree);
        if (combEntree < dim)
        {
            printf("Nombre de chiffres trop petit, recommencez");
            j--;
        }
        else if (combEntree > dim)
        {
            printf("Nombre de chiffres trop grand, recommencez");
            j--;
        }
        else
        {
            depiler(essai);
            BienPlaces = 0;
            MalPlaces = 0;

            analyse(ref, essai, &BienPlaces, &MalPlaces);

            if (BienPlaces == combEntree)
            {
                printf("Bravo ! Vous avez trouvee en %d coup", (j + 1));
                break;
            }
            else if (BienPlaces != combEntree )
            {
                printf("============== TENTATIVE RESTANTE %d ===============\n", (NBESSAIS - (j + 1)));
                printf("| Nombre de couleur bien place est           : %d  |\n", BienPlaces);
                printf("| Nombre de couleur trouver et malplacer     : %d  |\n", (MalPlaces));
                printf("---------------------------------------------------\n");

                 if(j+1 >9 ){

                     printf(" Le nombre maximum de tentatives est atteint! Veuillez recommencer le programme.");
                 }
            }
        }
    }

    free(ref);
    free(essai);
    return 0;
}

void print_tab(int tab[], int dim)
{
    int i;
    for (i = 0; i < dim; ++i)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

void tirage(int tab[], int dim)
{
    int NbSec, vali, i;
    double valf;

    NbSec = time(NULL); /* nombre de secondes écoulées depuis le 1/1/70 */
    srand(NbSec);       /* initialisation du générateur pseudo-aléatoire */
    vali = rand();      /* un coup pour rien. Le premier n'est pas aléatoire */

    for (i = 0; i < dim; i++)
    {
        valf = rand() / (RAND_MAX + 1.0); /* nombre flottant compris entre 0.0
                et 0.9999999 */
        vali = (int)(valf * NBCASES) + 1; /* nombre entier compris entre 1 et NBCOULEURS */
        tab[i] = vali;
    }
}

int entree(int essai[], int *combEntree)
{
    unsigned int x;

    scanf("%d", &x);

    int i = 0;
    long temp = 1;
    int y = 0;

    while (temp <= x)
    {
        y = x % 10;
        x = x / 10;
        essai[i] = y;
        i++;
    }
    *combEntree = i;
    return i;
}

void depiler(int essai[])
{
    int k = NBCASES - 1;
    int j = 0;

    int tabBis[NBCASES];
    for (int i = 0; i < NBCASES; i++)
    {
        tabBis[j] = essai[k];
        j++;
        k--;
    }
    for (int i = 0; i < NBCASES; i++)
    {
        essai[i] = tabBis[i];
    }
}

void analyse(int ref[], int essai[], int *BienPlaces, int *MalPlaces)
{
    int RefTmp[NBCASES];
    int RefTmpbis [NBCASES];
    int getBienplaces = 0;
    int getMalplaces = 0;

 for (int i = 0; i < NBCASES; i++)
    {
        RefTmpbis[i] = ref[i];
    }


    for (int i = 0; i < NBCASES; i++)
    {
              RefTmp[i] = ref[i];
    }

    for (int i = 0; i < NBCASES; i++)
    {
        for (int j = 0; j < NBCASES; j++)
        {
            if (essai[i] == RefTmp[j] && i == j)
            {
                getBienplaces++;
                essai[i] = -1;
                RefTmp[j] = -1;
            }
        }
    }

    for (int i = 0; i < NBCASES; i++)
    {
        for (int j = 0; j < NBCASES; j++)
        {
            if (essai[i] != -1)
            {
                if (essai[i] == RefTmp[j] && i != j)
                {
                    getMalplaces++;
                    essai[i] = -1;
                    RefTmp[j] = -1;
                }
            }
        }
    }


 for (int i = 0; i < NBCASES; i++)
    {
        ref[i] =   RefTmpbis[i];
    }

    *BienPlaces = getBienplaces;
    *MalPlaces = getMalplaces;
}

