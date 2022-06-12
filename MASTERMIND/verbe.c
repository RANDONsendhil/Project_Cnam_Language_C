#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

    char verbe[] = "avancer";
    int length = strlen(verbe) - 2;
    char prepar_ver[length];
    int bool = 0;

    char *voyelle[] = {"a", "e", "i", "o", "u"};
    char *pronom[] = {"Je", "tu", "il","elle", "Nous", "Vous", "Ils", "Elles"};
    char *conj[] = {"e", "es", "e","e", "ons", "ez", "ent", "ent"};
    char *verbis[sizeof(pronom)];
    int voye_tab_size = sizeof(voyelle) / sizeof(voyelle[0]);
    int k = 0;
    unsigned int entier = 4294967294;

    printf("ENTIER %d\n", entier);




    for (int i = 0; i < length; i++)
    {
        prepar_ver[i] = verbe[i];
        verbis[k] = &prepar_ver[i];
        k++;
    }
    printf("VOYELLE TAB SIZE %d\n", voye_tab_size);

    for (int i = 0; i < voye_tab_size; i++)
    {
        if (strncmp(&verbe[0], voyelle[i], 1) == 0)
        {
            bool = 1;
            break;
        }
        else
        {
            bool = 0;
        }
    }

    for (int i = 0; i < 8; i++)
    {
        if (bool == 0)
        {

            printf("\n%s %s%s", pronom[i], verbis[0], conj[i]);
        }
        else
        {
            pronom[0] = "J'";
            printf("\n%s %s%s", pronom[i], verbis[0], conj[i]);
        }
    }

    return 0;
}