#include <stdio.h>
#include <stdlib.h>

//Struct that holds each workout info
typedef struct 
{
    char workoutName[50];
    int weight;
    int reps;

}Workouts;


//Displays The menu so the user can then select what they would like to do
void displaymenu(){
    printf("1. Record Workout\n2. View Workout History\n3. View Personal Records\n4. Plan Weekly Workout\n5. View Workout Plan\n6. Save Data\n7. Load Data\n8. Exit\n");
    printf("\n");
}

//Asks for user input then stores that info into a struct in a struct array at position count
//count increments one each time ran so workouts are in order
void RecordWorkout(int *count,Workouts workout[]){

    printf("Enter Workout name ");
    scanf("%s", &workout[*count].workoutName);
    printf("Enter number of Reps ");
    scanf("%d", &workout[*count].reps);
    printf("Enter Weight ");
    scanf("%d", &workout[*count].weight);
    (*count)++;
}

//goes through our struct array and prints out each workout and its information
void viewWorkoutHistory(int count, Workouts workout[]){
    for (int i = 0; i < count;i++){
        printf("Workout name: %s\nNumber of reps: %d\nWeight: %d\n",workout[i].workoutName,workout[i].reps,workout[i].weight);
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
