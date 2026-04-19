# CSE-1320 Project: Fitness Tracker

## Project Title
Fitness Tracker

## Purpose
This program is designed to help a user track workout progress. The user can record workouts, view workout history, check personal records, plan workouts for the week, and optionally save and load data.

---

## Program Design

The program uses a struct called `Workout` to store workout data such as exercise name, weight, and reps. An array like `workouts[100]` is used to store multiple workout records, and an integer `count` keeps track of how many workouts are stored. A 2D array such as `weeklyPlan[7][50]` is used to store a workout plan for each day of the week.

The program runs using a menu system controlled by a loop in `main()`.

---

## Functions (In Order)

### 1. displayMenu()
This function prints the list of options for the user. It does not take input or process data. It only shows what the user can choose.

---

### 2. recordWorkout()
This function asks the user to enter an exercise name, weight, and number of reps. It stores this information into the `workouts` array at the current index. After storing the data, it increases the `count` variable by 1 so the next workout is stored in the next position.

---

### 3. viewWorkoutHistory()
This function loops through the `workouts` array from index 0 up to `count - 1`. It prints each workout in a clean format so the user can see all previously recorded workouts.

---

### 4. calculatePRs()
This function goes through all recorded workouts and checks for the highest weight for specific exercises such as Bench, Squat, and Deadlift. It uses comparisons to keep track of the maximum value for each exercise and then prints the results.

---

### 5. planWorkout()
This function allows the user to choose a day of the week (0–6) and assign a workout to that day. The workout is stored in the `weeklyPlan` array at the selected index.

---

### 6. viewWorkoutPlan()
This function loops through all 7 days of the week and prints the workout assigned to each day using the `weeklyPlan` array.

---

### 7. saveData()
This function writes all workout data from the `workouts` array into a file. It goes through each stored workout and saves the exercise name, weight, and reps. This allows the data to be used later.

---

### 8. loadData()
This function reads workout data from the file and stores it back into the `workouts` array. It resets the `count` and rebuilds the list of workouts from the file.


---

## Menu Layout
1. Record Workout
2. View Workout History
3. View Personal Records
4. Plan Weekly Workout
5. View Workout Plan
6. Save Data
7. Load Data
8. Exit

---

## Detailed Example and Explanation

Step 1: User selects option 1 (Record Workout)
Enter choice: 1
Enter exercise: Bench
Enter weight: 185
Enter reps: 5


Explanation:
The program calls `recordWorkout()`.  
- The exercise "Bench" is stored in `workouts[0].exercise`  
- The weight 185 is stored in `workouts[0].weight`  
- The reps 5 are stored in `workouts[0].reps`  
- The `count` is increased from 0 to 1  

---

Step 2: User records another workout
Enter choice: 1
Enter exercise: Squat
Enter weight: 225
Enter reps: 3


Explanation:
The program stores this in the next position:
- `workouts[1]` now holds Squat data  
- `count` is increased from 1 to 2  

---

Step 3: User views workout history
Enter choice: 2
Workout 1: Bench - 185 lbs - 5 reps
Workout 2: Squat - 225 lbs - 3 reps


Explanation:
The program calls `viewWorkoutHistory()`.  
It loops from index 0 to 1 (since count = 2) and prints each workout.

---

Step 4: User checks personal records
Enter choice: 3
Bench PR: 185
Squat PR: 225
Deadlift PR: 0

Explanation:
The program calls `calculatePRs()`.  
- It checks each workout  
- It finds the highest weight for Bench and Squat  
- No Deadlift was entered, so it stays 0  

---

Step 5: User plans a workout
Enter choice: 4
Enter day (0-6): 0
Enter workout: Chest

Explanation:
The program calls planWorkout().

It asks for a day number (0 = Monday)
It stores "Chest" in weeklyPlan[0]
If that day already had a workout, it gets replaced
This only updates the weekly plan, not the workout history

Step 6: User views weekly plan

Enter choice: 5
Mon: Chest
Tue:
Wed:
Thu:
Fri:
Sat:
Sun:

Explanation:
The program calls viewWorkoutPlan().

It loops through all 7 days

Step 7: User saves data

Enter choice: 6
Data saved successfully.

Explanation:
The program calls saveData().

It opens a file
It loops through the workouts array
It writes each workout into the file
This allows the data to be used later
Step 8: User exits

Enter choice: 8
Exiting program...

Explanation:
The program ends the loop in main().

The program stops running
If data was saved, it can be loaded later
If not saved, the data is lost
Step 9: User loads data

Enter choice: 7
Data loaded successfully.

Explanation:
The program calls loadData().

It opens the file
It reads each saved workout
It stores them back into the workouts array
It updates the count variable so the data is restored
It prints what is stored in each weeklyPlan position
Only Monday has a workout, the rest are empty
