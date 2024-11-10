#include <stdio.h>
#include <string.h>

void compresssentence (char arr[], char cmarr[],int *count){
    int i = 0 , j = 0;
    
    while(arr[i]!='\0'&&arr[i]!='\n'){
        if(arr[i]!=arr[i+1]){
            cmarr[j++]=arr[i];
        }else{
            (*count) ++;
        }
        i++;
    }
    cmarr[j]='\0';
}


int main()
{
    char arr[100];
    char cmarr[100];
    int count;
    printf("Enter a Sentence : ");
    fgets(arr,100,stdin);
    
    compresssentence(arr,cmarr,&count); 
    printf("Compressed Sentence: %s\n", cmarr);
    printf("Characters removed: %d\n", count);
    
    return 0;
}
