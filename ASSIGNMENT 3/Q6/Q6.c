#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Weather {
    float temperature;
    float rainfall;
    float windSpeed;
};

struct Crop {
    char cropType[20];
    int growthStage;
    float expectedYield;
    struct Weather *weather;
};

struct Equipment {
    char equipmentName[20];
    char status[10];
    float fuelLevel;
};

struct Sensor {
    float soilNutrients;
    float pHLevel;
    float pestActivity;
};

struct Field {
    float gpsCoordinates[2];
    float soilHealth;
    float moistureLevel;
    struct Crop *crops;
    int cropCount;
    struct Equipment *equipment;
    int equipmentCount;
    struct Sensor *sensors;
    int sensorCount;
};


defineField(struct Field *field, int cropCount, int equipmentCount, int sensorCount) {
    field->crops = (struct Crop *)malloc(cropCount * sizeof(struct Crop));
    field->cropCount = cropCount;

    field->equipment = (struct Equipment *)malloc(equipmentCount * sizeof(struct Equipment));
    field->equipmentCount = equipmentCount;

    field->sensors = (struct Sensor *)malloc(sensorCount * sizeof(struct Sensor));
    field->sensorCount = sensorCount;
}


void inputCrops(struct Field *field) {
    for (int i = 0; i < field->cropCount; i++) {
        printf("Enter details for crop %d:\n", i + 1);
        printf("Crop Type: ");
        scanf("%s", field->crops[i].cropType);
        printf("Growth Stage: ");
        scanf("%d", &field->crops[i].growthStage);
        printf("Expected Yield: ");
        scanf("%f", &field->crops[i].expectedYield);

        field->crops[i].weather = (struct Weather *)malloc(sizeof(struct Weather));
        printf("Enter Weather details (Temperature Rainfall WindSpeed): ");
        scanf("%f %f %f", &field->crops[i].weather->temperature, &field->crops[i].weather->rainfall, &field->crops[i].weather->windSpeed);
    }
}


void inputEquipment(struct Field *field) {
    for (int i = 0; i < field->equipmentCount; i++) {
        printf("Enter details for equipment %d:\n", i + 1);
        printf("Equipment Name: ");
        scanf("%s", field->equipment[i].equipmentName);
        printf("Status: ");
        scanf("%s", field->equipment[i].status);
        printf("Fuel Level: ");
        scanf("%f", &field->equipment[i].fuelLevel);
    }
}


void inputSensors(struct Field *field) {
    for (int i = 0; i < field->sensorCount; i++) {
        printf("Enter details for sensor %d:\n", i + 1);
        printf("Soil Nutrients: ");
        scanf("%f", &field->sensors[i].soilNutrients);
        printf("pH Level: ");
        scanf("%f", &field->sensors[i].pHLevel);
        printf("Pest Activity: ");
        scanf("%f", &field->sensors[i].pestActivity);
    }
}


void displayField(struct Field *field) {
    printf("\nField Details:\n");
    printf("Soil Health: %.2f, Moisture Level: %.2f\n", field->soilHealth, field->moistureLevel);

    printf("\nCrops:\n");
    for (int i = 0; i < field->cropCount; i++) {
        printf("Crop %d: %s, Growth Stage: %d, Expected Yield: %.2f\n", i + 1, field->crops[i].cropType, field->crops[i].growthStage, field->crops[i].expectedYield);
        printf("  Weather - Temperature: %.2f, Rainfall: %.2f, Wind Speed: %.2f\n",
               field->crops[i].weather->temperature, field->crops[i].weather->rainfall, field->crops[i].weather->windSpeed);
    }

    printf("\nEquipment:\n");
    for (int i = 0; i < field->equipmentCount; i++) {
        printf("Equipment %d: %s, Status: %s, Fuel Level: %.2f\n", i + 1, field->equipment[i].equipmentName, field->equipment[i].status, field->equipment[i].fuelLevel);
    }

    printf("\nSensors:\n");
    for (int i = 0; i < field->sensorCount; i++) {
        printf("Sensor %d: Soil Nutrients: %.2f, pH Level: %.2f, Pest Activity: %.2f\n", i + 1, field->sensors[i].soilNutrients, field->sensors[i].pHLevel, field->sensors[i].pestActivity);
    }
}


void freeField(struct Field *field) {
    for (int i = 0; i < field->cropCount; i++) {
        free(field->crops[i].weather);
    }
    free(field->crops);
    free(field->equipment);
    free(field->sensors);
}

int main() {
    struct Field field;

    printf("Enter field details (GPS coordinates, soil health, moisture level): ");
    scanf("%f %f %f", &field.gpsCoordinates[0], &field.soilHealth, &field.moistureLevel);

    int cropCount, equipmentCount, sensorCount;
    printf("Enter number of crops, equipment, and sensors: ");
    scanf("%d %d %d", &cropCount, &equipmentCount, &sensorCount);

    defineField(&field, cropCount, equipmentCount, sensorCount);

    inputCrops(&field);
    inputEquipment(&field);
    inputSensors(&field);

    displayField(&field);

    freeField(&field);

    return 0;
}
