#include <stdio.h>

int validateemail(char address []){
    int count=0;
 for(int i=0;address[i]!='\0';i++){
    if(address[i]=='@'){
        count++;}
        if(address[i]=='.'){
            count++;}
     
}
  if (count == 2) {
        return 1;
    } else {
        return 0; 
}}

int main()
{
    char address[100];
    printf("Enter Email Address : ");
    scanf("%s",address);
    
      if (validateemail(address)) {
        printf("\nThe email address '%s' is valid.\n", address);
    } else {
        printf("\nThe email address '%s' is invalid.\n", address);
    }
    return 0;
}
