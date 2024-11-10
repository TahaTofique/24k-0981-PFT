#include <stdio.h>
#include <string.h>

void sortWord(char *word) {
    int len = strlen(word);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (word[i] > word[j]) {
                char temp = word[i];
                word[i] = word[j];
                word[j] = temp;
            }
        }
    }
}

int main() {
    char arr[99][99];   
    char sortedArr[99][99];
    int used[99] = {0};    
    int n;


    printf("Enter Number of Words: ");
    scanf("%d", &n);


    for (int i = 0; i < n; i++) {
        printf("Word %d: ", i + 1);
        scanf("%s", arr[i]);
        strcpy(sortedArr[i], arr[i]);
        sortWord(sortedArr[i]); 
    }

    
    printf("[");
    int firstGroup = 1;
    for (int i = 0; i < n; i++) {
        if (used[i] == 0) { 
            if (!firstGroup) {
                printf(", ");
            }
            firstGroup = 0;
            printf("[");

            int firstInGroup = 1;
            for (int j = i; j < n; j++) {
                if (used[j] == 0 && strcmp(sortedArr[i], sortedArr[j]) == 0) {
                    if (!firstInGroup) {
                        printf(", ");
                    }
                    firstInGroup = 0;
                    printf("%s", arr[j]);
                    used[j] = 1; 
                }
            }
            printf("]");
        }
    }
    printf("]\n");

    return 0;
}

