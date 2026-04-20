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

void calculatePRs(){
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


