#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void initializeInventory(char*** speciesSupplies, int numSpecies) {
    for (int i = 0; i < numSpecies; i++) {
        speciesSupplies[i] = NULL; }
}


void addSupplies(char*** speciesSupplies, int speciesIndex, int numSupplies) {
    speciesSupplies[speciesIndex] = (char**)malloc(numSupplies * sizeof(char*));
    for (int i = 0; i < numSupplies; i++) {
        speciesSupplies[speciesIndex][i] = (char*)malloc(50 * sizeof(char));
        printf("Enter supply %d for species %d: ", i + 1, speciesIndex + 1);
        scanf("%s", speciesSupplies[speciesIndex][i]);
    }
}

void updateSupplies(char*** speciesSupplies, int speciesIndex, int supplyIndex) {
    printf("Enter new supply name for species %d, supply %d: ", speciesIndex + 1, supplyIndex + 1);
    scanf("%s", speciesSupplies[speciesIndex][supplyIndex]);
}


void removeSpecies(char*** speciesSupplies, int speciesIndex, int* numSupplies) {
    for (int i = 0; i < numSupplies[speciesIndex]; i++) {
        free(speciesSupplies[speciesIndex][i]);
    }
    free(speciesSupplies[speciesIndex]);
    speciesSupplies[speciesIndex] = NULL;
}


void displayInventory(char*** speciesSupplies, int* numSupplies, int numSpecies) {
    for (int i = 0; i < numSpecies; i++) {
        if (speciesSupplies[i] != NULL) {
            printf("Species %d supplies:\n", i + 1);
            for (int j = 0; j < numSupplies[i]; j++) {
                printf("  - %s\n", speciesSupplies[i][j]);
            }
        } else {
            printf("Species %d has been removed or has no supplies.\n", i + 1);
        }
    }
}

int main() {
    int numSpecies, choice, speciesIndex, supplyIndex;
    printf("Enter the number of species: ");
    scanf("%d", &numSpecies);

    char*** speciesSupplies = (char***)malloc(numSpecies * sizeof(char**));
    int* numSupplies = (int*)calloc(numSpecies, sizeof(int));

    initializeInventory(speciesSupplies, numSpecies);

    do {
        printf("\nMenu:\n");
        printf("1. Add Supplies\n");
        printf("2. Update Supplies\n");
        printf("3. Remove Species\n");
        printf("4. Display Inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter species index (1 to %d): ", numSpecies);
                scanf("%d", &speciesIndex);
                speciesIndex--; 
                printf("Enter number of supplies: ");
                scanf("%d", &numSupplies[speciesIndex]);
                addSupplies(speciesSupplies, speciesIndex, numSupplies[speciesIndex]);
                break;
            case 2:
                printf("Enter species index (1 to %d): ", numSpecies);
                scanf("%d", &speciesIndex);
                speciesIndex--;
                printf("Enter supply index to update (1 to %d): ", numSupplies[speciesIndex]);
                scanf("%d", &supplyIndex);
                supplyIndex--; 
                updateSupplies(speciesSupplies, speciesIndex, supplyIndex);
                break;
            case 3:
                printf("Enter species index (1 to %d) to remove: ", numSpecies);
                scanf("%d", &speciesIndex);
                speciesIndex--; 
                removeSpecies(speciesSupplies, speciesIndex, numSupplies);
                break;
            case 4:
                displayInventory(speciesSupplies, numSupplies, numSpecies);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

  
    for (int i = 0; i < numSpecies; i++) {
        if (speciesSupplies[i] != NULL) {
            for (int j = 0; j < numSupplies[i]; j++) {
                free(speciesSupplies[i][j]);
            }
            free(speciesSupplies[i]);
        }
    }
    free(speciesSupplies);
    free(numSupplies);

    return 0;
}
