#include <stdio.h>
#include <string.h>


#define NUM_USERS 5
#define NUM_CATEGORIES 3
#define NUM_DEVICES 3

// Structures
typedef struct {
    int resolution;      
    double playbackTime; 
    double bandwidth;   
} DevicePreferences;

typedef struct {
    char title[50];
    double rating;    
    int runtime;      
    char encoding[20]; 
} ContentMetadata;


double engagementMatrix[NUM_USERS][NUM_CATEGORIES]; 
DevicePreferences deviceMatrix[NUM_USERS][NUM_DEVICES]; 
ContentMetadata contentMatrix[NUM_CATEGORIES]; 


void initializeEngagementMatrix();
void initializeDevicePreferences();
void initializeContentMetadata();
void printEngagementMatrix();
void printDevicePreferences();
void printContentMetadata();

int main() {
    initializeEngagementMatrix();
    initializeDevicePreferences();
    initializeContentMetadata();

    printf("### User Engagement Matrix ###\n");
    printEngagementMatrix();

    printf("\n### Device Preferences ###\n");
    printDevicePreferences();

    printf("\n### Content Metadata ###\n");
    printContentMetadata();

    return 0;
}

void initializeEngagementMatrix() {
    for (int user = 0; user < NUM_USERS; ++user) {
        for (int category = 0; category < NUM_CATEGORIES; ++category) {
            engagementMatrix[user][category] = (user + 1) * (category + 1) * 1.2; 
        }
    }
}

void initializeDevicePreferences() {
    for (int user = 0; user < NUM_USERS; ++user) {
        for (int device = 0; device < NUM_DEVICES; ++device) {
            deviceMatrix[user][device].resolution = 1080;
            deviceMatrix[user][device].playbackTime = (user + 1) * 5.0 + device;
            deviceMatrix[user][device].bandwidth = (device + 1) * 2.5;
        }
    }
}

void initializeContentMetadata() {
    strcpy(contentMatrix[0].title, "Action Movie");
    contentMatrix[0].rating = 8.5;
    contentMatrix[0].runtime = 120;
    strcpy(contentMatrix[0].encoding, "H.294");

    strcpy(contentMatrix[1].title, "Drama Movie");
    contentMatrix[1].rating = 7.8;
    contentMatrix[1].runtime = 140;
    strcpy(contentMatrix[1].encoding, "H.165");

    strcpy(contentMatrix[2].title, "Comedy Show");
    contentMatrix[2].rating = 9.2;
    contentMatrix[2].runtime = 30;
    strcpy(contentMatrix[2].encoding, "GP4");
}

void printEngagementMatrix() {
    for (int user = 0; user < NUM_USERS; ++user) {
        printf("User %d: ", user + 1);
        for (int category = 0; category < NUM_CATEGORIES; ++category) {
            printf("%.2f\t", engagementMatrix[user][category]);
        }
        printf("\n");
    }
}

void printDevicePreferences() {
    for (int user = 0; user < NUM_USERS; ++user) {
        printf("User %d:\n", user + 1);
        for (int device = 0; device < NUM_DEVICES; ++device) {
            printf("  Device %d -> Resolution: %d, Playback Time: %.2f, Bandwidth: %.2f\n",
                   device + 1,
                   deviceMatrix[user][device].resolution,
                   deviceMatrix[user][device].playbackTime,
                   deviceMatrix[user][device].bandwidth);
        }
    }
}

void printContentMetadata() {
    for (int category = 0; category < NUM_CATEGORIES; ++category) {
        printf("Category %d -> Title: %s, Rating: %.1f, Runtime: %d, Encoding: %s\n",
               category + 1,
               contentMatrix[category].title,
               contentMatrix[category].rating,
               contentMatrix[category].runtime,
               contentMatrix[category].encoding);
    }
}
