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
void saveData(int count, Workouts workout[]){
    FILE *fp = fopen("Workouts.txt", "a+"); 
    if(fp == NULL){
        printf("Failed to open file");
        return;
    }  
    for(int i = 0; i < count; i++){
        fprintf(fp,"%s %d %d\n", workout[i].workoutName, workout[i].reps, workout[i].weight);
    }
}

void loadData(int *count, Workouts workout[]){
    FILE *fp = fopen("Workouts.txt", "r");
    if(fp == NULL){
        printf("Failed to open file");
        return;
    }
    *count = 0;
    while(fscanf(fp,"%50s %d %d", workout[*count].workoutName, &workout[*count].reps, &workout[*count].weight) == 3){
        (*count)++;
    } 


}

int main() {
    int count=0;
    int *count1 = &count;
    Workouts workout[100];
    loadData(&count,workout);
    printf("%d\n", count);
    viewWorkoutHistory(count,workout);
    return 0;
}
