#include <stdio.h>
#include <string.h>

#define NUM_SLOGANS 3
#define ASCII_SIZE 128

int main()
{
    int i;
    char slogans[256];
   printf("Enter a Slogan : ");
   fgets(slogans,256,stdin);
   printf("%s",slogans);
   
   for(int s=0;s < NUM_SLOGANS;s++){
       printf("For \"%s\": {",slogans[s]);
   }
  
   int frequency[ASCII_SIZE] = {0};
   
   for(i=0;slogans[s][i] != '\0';i++){
       char ch = slogans[s][i];
       frequency[(int)ch]++;
   }
   int first = 1;
   for(int i =0;i < ASCII_SIZE;i++){
       if(frequency[i]>0){
           if(!first){
               printf(", ")
           }
           printf("'%c' : %d ",i,frequency[i]);
           first =0;
       }
   }
       printf(" }\n");
   }
   
   return 0;
}
