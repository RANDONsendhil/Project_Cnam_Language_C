#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NBCASES 5
#define NBESSAIS 10

/*  prototype de la fonc. tirage() prend 2 params:  [1] un tableau qui stock les entiers, [2] la dimension du tableau  */
void tirage(int tab[], int dim);

/*  prototype de la fonc. print_tab() 2 params:  [1] un tableau d'entier à afficher, [2] la dimension du tableau */
void print_tab(int tab[], int dim);

/** prototype de la fonc. analyse() prend 4 params:  [1] tab ref[], [2] tab essai[], [3] dimension du tableau ref et essai [3], pointeur nb entier bien
 *  place, [4] pointeur nb entier trouvés et malplacés 
*/
void analyse(int ref[], int essai[], int dim, int *BienPlaces, int *MalPlaces);

/*  prototype de la fonc. entree() prend [1] param:  pour recupère les entiers de l'utilisateur et stock dans le tableau essai */
int entree(int essai[]);

/*  prototype de la fonc. depiler() prend [1] param: pour depiler le tab essai  */
void depiler(int essai[], int dim);

/********************************************************************************************************************************************************************************
 * La synthèse
 * 
 * La méthode main() exécute le programme Mastermind.
 * 
 * 
 * --------------------------------------------------------------------------------------------------------
 * Les variables:
 * 
 * 1. #define NBCASES définit le nb max du tableau
 * 2. #define NBESSAIS défint le nb max de tentative.
 * 3. *ref       : pointeur de type entier qui utilise pour allouer un bloc mémoire pour le tirage selon
 *     la dimension fourni par l'utilisateur. 
 * 4. *essai     : pointeur de type entier qui utilise pour allouer un bloc mémoire pour pour stocker les
 *      entiers saisis par l'utilisateur et qui prend la meme taille que le tab ref. 
 * 5. BienPlaces : de type int ( entier ) stock et affiche les nb entiers bienplacés
 * 6. MalPlaces  : de type int ( entier ) stock et affiche les nb entiers malplacés
 * 7. dim        : de type int ( entier ) stock et affiche les nb entiers malplacés
 * 8. combEntree : de type int ( entier ) recupère la taille du tableau essai saisi par l'utilisateur
 *    puis compare avec la taille du tab ref.
 * ------------------------------------------------------------------------------------------------------------
 * 

 * -------------------------------------------------------------------------------------------------------------
 * Les étapes de la methode main():
 * 
 * Etape [1]:
 * Le taille du tableau est défini par l'utilisteur, puis une boucle do while traite la demande, la
 *  boucle ne permet pas de passer à l'étape suivante [2] si la valeur saisie par l'utilsateur est > NBCASES.
 * 
 * Etape [2]:
 * Après le contrôle de saisie de l'utilisateur, la fonction malloc réserve dimension*octet pour
 * stocker les valeurs dans la mémoire dynamiquement, l'adresse du début de la zone de stockage étant copié
 * dans le pointeur essai et ref. Le programme se termine si la fonction malloc n’a pas réussi à allouer
 * une zone mémoire pour ref et essai.
 * 
 * Etape [3]: 
 * Le programme génère le tirage à l'aide de la fonction tirage() qui prend deux params [1] un tableau
 * qui stock les entiers, [2] la dimension du tableau.
 * 
 * Etape [4]:
 * La fonction affiche print_tab() le tirage généré qui prend  2 params [1] un tableau d'entier à afficher,
 * [2] la dimension du tableau 
 * 
 * 
 * Etape [5]:
 * Le programme demande de saisir une combinaison x chiffres (nb chiffres = nb cases) . Si le nb saisie
 * est inférieur ou  supérieur à nb cases, un message d'erreur s'affiche à chaque essai tant l'utilisateur
 *  fournit une combinaison valide.
 * 
 *  
 * Etape [6]: Le programe rend la main à l'utilsateur, il repete NBESSAIS fois max définit dans #define par une boucle for
 * tant que l'utilisateur tente de touver les bons chiffres. Le programme se termine soit l'utilisateur a trouvé le bons
 * chiffres ou soit il a dépassé les nb max tenetaives défini.
 * 
 * 
 * Etape [7]:
 *  La fonction entree():
 * La fonction entree() récupère les valeurs saisies et stock dans le tab essai[]. A la sortie de la fonction entree().
 * le tab essai[] contient le dernier élément saisi est aussi le premier sortie:
 * Ex: La fonction entrée récupère des entiers [1,2,3,4,5], puis rangé les données dans l'ordre suivant: [5,4,3,2,1]
 * 
 * 
 * Etape [8]:
 * 
 * La fonction depiler():
 * La fonction depiler() prend 2 params, [1] tab essai[] et [2] dim, cette fonction fait une copie de tab essai[] en inversant
 * l'ordre en prenant en compte de récupérer les données une à une, en commençant par la dernière qui vient d'être posée tout
 * en haut de la pile. On enlève les données au fur et à mesure, jusqu'à la dernière tout en bas de la pile puis et copie dans
 * le tableau tabBis[]. En sortant de cette fonction, le tab tabBis recopie  de nouveau  les données  dans le tab essai[].
 * Le tab essai[] se retrouve les données dans l'ordre saisi par l'utilisateur.
 * 
 * 
 * Etape [9]:
 * 
 * La fonction analyse():
 * 
 * La fonction analyse() prend en relai avec ses 5 params: [1] tab ref[], [2] tab essai[], [3] dimension, [4] pointeur *Bienplace,
 * pointeur *Malplacee.Cette fonction détermine et affiche les nb valeurs bienplacés ou malplacés à chaque tentative. Si les chiffres
 * fourni par l'utilisateur ne touve dans le tab ref[] les valeurs de l'addresses des pointeurs malplacés et bienplacés affiche 0.
 * 
 *  a) La fonction contient 2 tabs RefTmp[] et RefTmpbis[], la dimension est même que le tab ref[] avec deux variables locales getBienplaces
 *  et getMalplaces de types int
 * 
 *  b) Dans un premier temps, la fonction fait une copie de tab ref[] dans le tab RefTmpbis[] et RefTmp[] à l'intérieur de la fonction analyser().
 * 
 *  c) Pour Bien Place:
 *  La methode parcours dans les tableaux par une boucle  for [i] pour le tab essai[] et une boucle for [j] pour le tab ref[] pour comparer ces deux 
 *  tabs avec une condition précise si un ou plusieurs chiffire saisie(s) par l'utilisatuer se trouve dans le tab ref[] et surtout se trouve
 *  à la même posisiton que le tab ref[], si la condition est remplie la variable Bienplacee incremente et puis les valeurs trouves seront remplacée(s)
 *  par -1 dans le tab re[] et dans le tab eesai[]
 * 
 *  d) Pour les chiffres trouvés mais malplacés.
 *  Après avoir fini de chercher les  chiffres bien placeess, methode passe à la  deuxime boucle de la methode  en tenant en comte de traiter uniquemet
 *  les entiers different de -1 qui la premiere condition avant d'entrer pour chercher les chiffres trouvés et malplacés. Puis la deuxieme condition
 *  vérifie que la tab essai[i] et tab ref[i] sont égals et position est de i est différent de j,  si la condition est remplie, la variable malplacées
 *  incremenete en remplacant les valeurs ciblées des tab essai[i] et ref[j] à -1 çela empeche de ne pas parcourir sur les chiffres sont déclaré touvés et malplacés.
 *   
 *   Prenons un exemple:
 * 
 *   tableau ref []  = {2, 2, 3 }
 *   tableau essai[] = {3, 2, 2 }
 *   
 *   Dans cet exemple le resultat attendu est 1 BienPlacé et 2 malplaces.
 * 
 *   Boucle Bienplacee:
 *   La 1ère boucle  incremente la valeur Bienplacee si la condition est remplie si le tab essai est égale à ref ainsi que ses positions de i et j sont égales:
 *    
 *   POSITION ESSAI i => [1] TAB ESSAi VALEUR [2]  POSITION REF j => [1] TAB REF VALEUR  [2]    ==> Condition repmpli, Bienplace increment pour la position [i], donc Bienplacee egale à 1.
 *   POSITION ESSAI i => [1] TAB ESSAi VALEUR [-1]  POSITION REF j => [1] TAB REF VALEUR [-1]   ==> Après avoir incrementé pour la valeur concerné est remplacé par -1 pour éviter les doublons.
 * 
 *   à la sortie de la première boucle de la methode analsyer()
 *   les deux tableux se trouvent comme ci-dessous:
 *   tableau ref []    3 -1 2 
 *   tableau essai[]   2 -1 3 
 *   
 *   Boucle Malplacee
 *   Dans la deuxième boucle, la première condition traite uniquement les valeurs si elle est different de -1, si oui, la 2me condition verifie que,
 *   le tableau essai [i], ref[j] sont égaux mais leurs position sont bien différentes dans ce cas là, la valeur Malplacee incremente et de nouveau en remplacent les
 *   les valeur malplaceés à -1 qui evite de parcourir sur les chiffres sont déclaré touvés et malplacés.
 * 
 *   POSITION ESSAI i => [0] TAB ESSAi VALEUR [3]  POSITION REF j => [2] TAB REF [3]   ==> La valeur 3 se trouve dans les deux tab mais leur poisition sont differents par i etj // increment =1 
 *   POSITION ESSAI i => [2] TAB ESSAi VALEUR [2]  POSITION REF j => [0] TAB REF [2]   ==> La valeur 2 se trouve dans les deux tab mais leur poisition sont differents par i etj // increment =2 
 *    
 *   A la sortie de la 2ème boucle de la methode analsyer() 
 *   les deux tableux se trouvent comme ci-dessous:
 *   tableau ref []    -1 -1 -1 
 *   tableau essai[]   -1 -1 -1
 * 
 *   En affichant le resultat: Bienplacee = 1 et Malplacee  = 2.
 *  
 *   IMPORTANT:
 * 
 *   Après avoir parcouru de chaque boucle, à la sortie de 2ème boucle, le tableau RefTmpbis[] recopie ses valeurs  dans le tab ref[]
 *   pour que le tab ref[] retrouve ses valeurs d'origine du programme pendant la fonction tirage est appelé,car ces deux boucles ecrasent chaque fois les
 *   tab ref  quand l'utilisateur verifie ses combinaision  à chaque tentative.
 *   ************************************************************************************************************************************************************************************************
 * */

int main()
{
    int *ref, *essai;
    int BienPlaces, MalPlaces, dim, combEntree;

    printf(" [ JEU MASTERMIND ] \n");
    do
    {
        printf("Donnez le nombre de cases : ");
        scanf("%d", &dim);

        if (dim > NBCASES)
        {
            printf("--------------------------------------------------------------- ");
            printf("\n|  Le nombre de case saisi est bien superieur que le tirage.  |\n|    Veuillez entrer une valeur inferieur ou egale a => %d     |\n", NBCASES);
            printf("---------------------------------------------------------------\n");
        }

    } while (dim > NBCASES);

    ref = (int *)malloc(dim * sizeof(int));   // allocation dynamique qui utilise pour le tirage qui contient des entiers et stock dans un tableau essai
    essai = (int *)malloc(dim * sizeof(int)); // allocation dynamique de tableau essai dans le quel les entiers sera stockes saisi par l'utilisateur

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
        printf("\nEntrez votre combinaison de %d chiffres: ", dim);
        combEntree = entree(essai);

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
            depiler(essai, dim);
            BienPlaces = 0;
            MalPlaces = 0;

            analyse(ref, essai, dim, &BienPlaces, &MalPlaces);

            if (BienPlaces == combEntree)
            {
                printf("Bravo ! Vous avez trouvee en %d coup", (j + 1));
                break;
            }
            else if (BienPlaces != combEntree)
            {
                printf("============== TENTATIVE RESTANTE %d ===============\n", (NBESSAIS - (j + 1)));
                printf("| Nombre de couleur bien place est           : %d  |\n", BienPlaces);
                printf("| Nombre de couleur trouver et malplacer     : %d  |\n", (MalPlaces));
                printf("---------------------------------------------------\n");

                if (j + 1 > 9)
                {

                    printf(" Le nombre maximum de tentatives est atteint! Veuillez recommencer le programme.");
                }
            }
        }
    }

    free(ref);
    free(essai);

    return 0;
}

// affchiche le tableau // Expliqué dans l'étape [4] de la synthèse//

void print_tab(int tab[], int dim)
{
    int i;
    for (i = 0; i < dim; ++i)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

/**
 * La fonction génère une combinaison de nb chiffres,
 * et stock les valeurs dans tableau. 
 * */

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

/**
 * La fonction recupère les valeurs entrées par un untilisatuer et stock dans un tableau essai[]
 * Le détail de la fonction est expliqué à l'Etape [7] de la synthèse/
 * 
* */

int entree(int essai[])
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
    return i;
}

/**
 * La fonction range de nouveau les données dans le tab essai dans l'ordre d'utilisateur qui était inversé à la sortie de la fonction entree()  
 * Le détail de la fonction est expliqué à l'Etape [8] de la synthèse/
 * 
* */
void depiler(int essai[], int dim)
{
    int k = dim - 1;
    int j = 0;
    int tabBis[dim];

    for (int i = 0; i < dim; i++)
    {
        tabBis[j] = essai[k];
        j++;
        k--;
    }
    for (int i = 0; i < dim; i++)
    {
        essai[i] = tabBis[i];
    }
}

/**
 * La fonction analyse() verifie les données founit par l' d'utilisateur à chaque essai.
 * Le détail de la fonction est expliqué à l'Etape [9] de la synthèse/
 * 
*/
void analyse(int ref[], int essai[], int dim, int *BienPlaces, int *MalPlaces)
{
    int RefTmp[dim];
    int RefTmpbis[dim];
    int getBienplaces = 0;
    int getMalplaces = 0;

    for (int i = 0; i < dim; i++)
    {
        RefTmpbis[i] = ref[i];
    }

    for (int i = 0; i < dim; i++)
    {
        RefTmp[i] = ref[i];
    }

    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            if (essai[i] == RefTmp[j] && i == j)
            {
                getBienplaces++;
                essai[i] = -1;
                RefTmp[j] = -1;
            }
        }
    }

    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
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

    for (int i = 0; i < dim; i++)
    {
        ref[i] = RefTmpbis[i];
    }

    *BienPlaces = getBienplaces;
    *MalPlaces = getMalplaces;
}
