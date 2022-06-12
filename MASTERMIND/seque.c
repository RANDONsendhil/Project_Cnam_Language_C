#include <stdio.h>
#include <stdlib.h>

void inverse(int *a , int *b);
 
int main(void)
{
    
//   int varA;
//   int varB;

// varA = 2;
// varB = 10;

// printf("AVANT\n");
// printf("A:  %d\n", varA);
// printf("B:  %d", varB);

// inverse(&varA, &varB);

// printf("\nAPRES\n");
// printf("A:  %d\n", varA);
// printf("B:  %d\n", varB);

int NBCASES = 3;
 

    int getBienplaces = 0;
    int getMalplaces= 0;
    int missing = 0;

    int essai[3] = {1,2,3};
    int RefTmp[3] = {1,2,5};


   
 
    
  printf("ref\n");

 

      for (int i = 0; i < NBCASES; i++)
    {
      


       printf("%d ", RefTmp[i]);
    }

    printf("\nessali\n");



 for (int i = 0; i < NBCASES; i++)
    {
      
       printf("%d ", essai[i]);
    }



 printf("\n\n\n");


    for (int i = 0; i < NBCASES; i++)
    {   
           
        if (RefTmp[i] == essai[i])
        {
            getBienplaces++;
        } 

        for (int j = 0; j < NBCASES; j++)
        {
            
            if (RefTmp[i] == essai[j])
            {
              printf("RefTmp %d", RefTmp[i]);
               printf("\n");
                RefTmp[i] = 0;
                
                getMalplaces++;
                printf("%d", RefTmp[i]);
                 printf("\n");
               
            }
            
        }
    }
  
  

printf("bien place: %d\n", getBienplaces);
printf("mal place : %d\n",getMalplaces-getBienplaces);

    return 0;
}


 