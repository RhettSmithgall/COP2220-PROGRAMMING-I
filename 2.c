//RHETT ALAN SMITHGALL
//COP 2220
//1056
//MODULE 1 EXERCISES
//6/4/2022

//Purpose:
//Accepts the inputs expenses of food as variables "monday,tuesday,wednesday,thursday,friday" in
//order to calculate the average expense of the week

//assumptions
//the inputs will be numbers that can be accepted by float
//the limitations of this program is that anything other than a number will cause it to fail
//similarly if the number is too large to be held by float the program will fail

#include <stdio.h>
int main() {
//set up variables
float monday,tuesday,wednesday,thursday,friday;

//welcome the user
printf("Welcome to the \"weekday expense calculator\"\n");

//request Monday expense
printf("how much do you spend of food on: Monday?\n");
scanf("%f",&monday);

//request tuesday expense
printf("how much do you spend of food on: Tuesday?\n");
scanf("%f",&tuesday);

//request wednesday expense
printf("how much do you spend of food on: Wednesday?\n");
scanf("%f",&wednesday);

//request thursday expense
printf("how much do you spend of food on: Thursday?\n");
scanf("%f",&thursday);

//request friday expense
printf("how much do you spend of food on: Friday?\n");
scanf("%f",&friday);

//print the average of the 5 values by adding them then dividing by 5. In a more complex program 5 would probably be a variable
printf("Your average expense is: %.2f$\n\n", (monday+tuesday+wednesday+thursday+friday)/5);

//author
printf("Programmed by:\n");
printf(" _____  _          _   _      _____           _ _   _                 _ _\n|  __ \\| |        | | | |    / ____|         (_) | | |               | | |\n| |__) | |__   ___| |_| |_  | (___  _ __ ___  _| |_| |__   __ _  __ _| | |\n|  _  /| '_ \\ / _ \\ __| __|  \\___ \\| '_ ` _ \\| | __| '_ \\ / _` |/ _` | | |\n| | \\ \\| | | |  __/ |_| |_   ____) | | | | | | | |_| | | | (_| | (_| | | |\n|_|  \\_\\_| |_|\\___|\\__|\\__| |_____/|_| |_| |_|_|\\__|_| |_|\\__, |\\__,_|_|_|\n                                                           __/ |          \n                                                          |___/           \n");
return 0;
}
