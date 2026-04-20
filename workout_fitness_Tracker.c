#include <stdio.h>
typedef struct 
{
    char workoutName[50];
    int weight;
    int reps;

}Workouts;



void displaymenu(){
    printf("1. Record Workout\n2. View Workout History\n3. View Personal Records\n4. Plan Weekly Workout\n5. View Workout Plan\n6. Save Data\n7. Load Data\n8. Exit\n");
    printf("\n");
}
void RecordWorkout(int *count,Workouts workout[]){

    printf("Enter Workout name ");
    scanf("%s", workout[*count].workoutName);
    printf("Enter number of Reps ");
    scanf("%s", workout[*count].reps);
    printf("Enter Weight ");
    scanf("%s", workout[*count].weight);
    (*count)++;
}
void viewWorkoutHistory(int count, Workouts workout[]){
    for int
}




int main() {
    int count=0;
    int *count1 = &count;
    Workouts workout[2];
    RecordWorkout(count1,workout);
    printf("%d\n%s", count,workout[0].workoutName);
    displaymenu();
    return 0;
}
