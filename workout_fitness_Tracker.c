#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Workout {
    char exercise[30];
    int weight;
    int reps;
};

struct Workout workouts[100];
char weeklyPlan[7][50];
int count = 0;

void calculatePRs(struct Workout workouts[], int count){
int prB = 0;
int prS = 0;
int prD = 0;

    for(int i = 0; i < count; i++){
        if(strcmp(workouts[i].exercise,"bench") == 0){
            if(workouts[i].weight > prB){
            prB = workouts[i].weight;
            }
        }
        else if(strcmp(workouts[i].exercise,"squat") == 0){
            if(workouts[i].weight > prS){
            prS = workouts[i].weight;
            }
        }
        else if(strcmp(workouts[i].exercise,"deadlift") == 0){
            if(workouts[i].weight > prD){
            prD = workouts[i].weight;
            }
        }

       
    }
    printf("Your bench pr is %d\n", prB);
    printf("Your squat pr is %d\n", prS);
    printf("Your deadlift pr is %d\n", prD);
}

void planWorkout(char weeklyPlan[7][50]) {
    int day;

    printf("Enter a day - 0 = Mon, 1 = Tue, 2 = Wed, 3 = Thu, 4 = Fri, 5 = Sat, 6 = Sun: ");
    scanf("%d", &day);

    if (day >= 0 && day <= 6) {

        printf("Enter workout for that day: ");
        scanf(" %s", weeklyPlan[day]);

        printf("Workout plan saved for that day.\n");
    }
    else {
        printf("Invalid day.\n");
    }
    void viewWorkoutPlan(char weeklyPlan[7][50]) {
        char days[7][10] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

        printf("\nWeekly Workout Plan:\n");

        for (int i = 0; i < 7; i++) {
            printf("%s: %s\n", days[i], weeklyPlan[i]);
        }
    }
}
