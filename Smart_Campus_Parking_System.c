
#include <stdio.h>
#include <string.h>

#define TOTAL_SPACES 5
//Arnav rawat part 
struct Vehicle {
    char registration[20];
    int entryTimeInMinutes;
    int occupied;
};

int main(void) {
   struct Vehicle parking[TOTAL_SPACES] = {0};
    int choice;
    int i;
    char regNumber[20];
    int entryHour, entryMinute;
    int exitHour, exitMinute;
    int entryTotalMinutes;
    int exitTotalMinutes;
    int durationMinutes;
    int actualHours;
    int actualMinutes;
    int billedHours;
    int fee;
    int found;
    int freeSpace;

  
do {

    printf("----SMART CAMPUS PARKING SYSTEM----\n");
    printf("1.Vehicle Entry\n");
    printf("2.Vehicle Exit\n");
    printf("3.Show parking status\n");
    printf("4.Exit program\n");
    printf("Enter your choice: ");
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input. Please enter a number from 1 to 4.\n");
        while (getchar() != '\n');
        continue;
    }

    if(choice==1){
        freeSpace = -1;

   printf("Enter vehicle registration number: ");
   scanf("%19s", regNumber);

   found = 0;
for (i = 0; i < TOTAL_SPACES; i++) {
if (parking[i].occupied == 1 &&
strcmp(parking[i].registration, regNumber) == 0) {
found = 1;

break;
    }
}
           
if (found == 1) {
printf("Error: This vehicle is already parked.\n");
 } else { for (i = 0; i <  TOTAL_SPACES; i++) {
 if (parking[i].occupied == 0) {
 freeSpace = i;
 break;
    }
 }

if (freeSpace == -1) {
printf("Parking area is full.\n");
 } else {
printf("Enter entry time in HH MM format: ");
 if (scanf("%d %d", &entryHour, &entryMinute) != 2) {
     printf("Invalid entry time format.\n");
     while (getchar() != '\n');
     continue;
 }

if (entryHour < 0 || entryHour > 23 ||
entryMinute < 0 || entryMinute > 59) {
printf("Invalid entry time.\n");
} else {
                  
entryTotalMinutes =
entryHour * 60 + entryMinute;

strcpy(parking[freeSpace].registration,
 regNumber);

parking[freeSpace].entryTimeInMinutes =
entryTotalMinutes;

parking[freeSpace].occupied = 1;

printf("Vehicle parked successfully.\n");
printf("Parking space number: %d\n",
freeSpace + 1);
 }
}
 }
    }

    // Piyush Thapa part
else if (choice == 2) {
 printf("Enter vehicle registration number: ");
scanf("%19s", regNumber);

found = 0;

for (i = 0; i <  TOTAL_SPACES; i++) {
if (parking[i].occupied == 1 &&
strcmp(parking[i].registration, regNumber) == 0) {

found = 1;

printf("Enter exit time in HH MM format: ");
if (scanf("%d %d", &exitHour, &exitMinute) != 2) {
    printf("Invalid exit time format.\n");
    while (getchar() != '\n');
    break;
}

if (exitHour < 0 || exitHour > 23 ||
 exitMinute < 0 || exitMinute > 59) {
printf("Invalid exit time.\n");
break;
} else {
                       
exitTotalMinutes =
 exitHour * 60 + exitMinute;

durationMinutes =
exitTotalMinutes -
parking[i].entryTimeInMinutes;

                 
if (durationMinutes < 0) {
durationMinutes = durationMinutes + 24 * 60;
}

                       
if (durationMinutes == 0) {
durationMinutes = 1;
  }

                     
actualHours = durationMinutes / 60;
actualMinutes = durationMinutes % 60;

                      
billedHours = (durationMinutes + 59) / 60;

fee = 20 + (billedHours - 1) * 10;

printf("Vehicle Status: Exited\n");
printf("Vehicle Number: %s\n", regNumber);
printf("Actual Duration: %d hour(s) and %d minute(s)\n",
actualHours, actualMinutes);
printf("Charged Duration: %d hour(s)\n",
billedHours);
printf("Parking Fee: Rs. %d\n", fee);
printf("Parking Space %d is now available.\n",
  i + 1);

                    
    parking[i].occupied = 0;
   }

    break;
  }
    }

if (found == 0) {
printf("Vehicle not found in the parking area.\n");
   }
  }
// akshat jain part 
 else if (choice == 3) {
    int available = 0;

printf("\n---- PARKING STATUS ----\n");

for (i = 0; i <  TOTAL_SPACES; i++) {
if (parking[i].occupied == 1) {
    printf("Space %d: Occupied by %s\n",
  i + 1,
parking[i].registration);

printf("Entry Time: %02d:%02d\n",
parking[i].entryTimeInMinutes / 60,
parking[i].entryTimeInMinutes % 60);
} else {
    printf("Space %d: Available\n", i + 1);
     available++;
   }
   }

printf("Available Parking Spaces: %d\n", available);
printf("Occupied Parking Spaces: %d\n",TOTAL_SPACES - available);
  }

     
else if (choice == 4) {
printf("Thank you for using the Smart Campus Parking System.\n");
 }

 else {
 printf("Invalid choice. Please try again.\n");
   }

} while (choice != 4);

    return 0;
}
