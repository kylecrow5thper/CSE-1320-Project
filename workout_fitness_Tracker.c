#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct that holds each workout info
typedef struct 
{
    char workoutName[50];
    int weight;
    int reps;

} Workouts;

// Displays the menu
void displaymenu(){
    printf("1. Record Workout\n2. View Workout History\n3. View Personal Records\n4. Plan Weekly Workout\n5. View Workout Plan\n6. Exit\n\n");
}

// Record workout
void RecordWorkout(int *count, Workouts workout[]){
    printf("Enter Workout name: ");
    scanf(" %49[^\n]", workout[*count].workoutName);

    printf("Enter number of Reps: ");
    scanf("%d", &workout[*count].reps);

    printf("Enter Weight: ");
    scanf("%d", &workout[*count].weight);

    (*count)++;
}

// View workout history
void viewWorkoutHistory(int count, Workouts workout[]){
    for (int i = 0; i < count; i++){
        printf("Workout %d\n", i + 1);
        printf("Workout name: %s\n", workout[i].workoutName);
        printf("Number of reps: %d\n", workout[i].reps);
        printf("Weight: %d\n\n", workout[i].weight);
    }
}

// Calculate PRs
void calculatePRs(int count, Workouts workout[]){
    int prB = 0;
    int prS = 0;
    int prD = 0;

    for(int i = 0; i < count; i++){
        if(strcmp(workout[i].workoutName,"bench") == 0){
            if(workout[i].weight > prB){
                prB = workout[i].weight;
            }
        }
        else if(strcmp(workout[i].workoutName,"squat") == 0){
            if(workout[i].weight > prS){
                prS = workout[i].weight;
            }
        }
        else if(strcmp(workout[i].workoutName,"deadlift") == 0){
            if(workout[i].weight > prD){
                prD = workout[i].weight;
            }
        }
    }

    printf("Your bench PR is %d\n", prB);
    printf("Your squat PR is %d\n", prS);
    printf("Your deadlift PR is %d\n", prD);
}

// Plan workout
void planWorkout(char weeklyPlan[7][50]) {
    int day;

    printf("Enter a day - 0 = Mon, 1 = Tue, 2 = Wed, 3 = Thu, 4 = Fri, 5 = Sat, 6 = Sun: ");
    scanf("%d", &day);

    if (day >= 0 && day <= 6) {
        printf("Enter workout for that day: ");
        scanf(" %49[^\n]", weeklyPlan[day]);

        printf("Workout plan saved for that day.\n");
    }
    else {
        printf("Invalid day.\n");
    }
}

// View weekly plan
void viewWorkoutPlan(char weeklyPlan[7][50]) {
    char days[7][10] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

    printf("\nWeekly Workout Plan:\n");

    for (int i = 0; i < 7; i++) {
        printf("%s: %s\n", days[i], weeklyPlan[i]);
    }
}

int main() {
    int count = 0;
    Workouts workout[100];
    char weeklyPlan[7][50] = {""};
    int choice;

    do {
        displaymenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                RecordWorkout(&count, workout);
                break;

            case 2:
                viewWorkoutHistory(count, workout);
                break;

            case 3:
                calculatePRs(count, workout);
                break;

            case 4:
                planWorkout(weeklyPlan);
                break;

            case 5:
                viewWorkoutPlan(weeklyPlan);
                break;

            case 6:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

        printf("\n");

    } while (choice != 6);

    return 0;
}
