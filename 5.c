#include <stdio.h>

int main() {
//create variables
float Weight;
char Zone;

//welcome the user
printf("Welcome to Shipping Company International!\n");

//ask user for the weight and then collect it from them
printf("How much does [ITEM] weigh in pounds?\n");
scanf("%f", &Weight);

//explain the location and pricing to the user
printf("Our pricing changes based on shipping location, what zone will you ship to today?\n");
printf("Zone A: Within the continental US [$5 per pound]\n");
printf("Zone B: within North or Central America, but outside the US [$10 per pound]\n");
printf("Zone C: South America, Europe [$20 per pound]\n");

//scanf to collect the user response, the response is held as a single character so a string array is unnecessary
//however the lingering new line character from the previous response must be dealt with
//so the \n in front of the %c is vital to this line
scanf("\n%c", &Zone);

//the series of 'if else' statements here compare the letter held in "Zone" one by one to each viable option until it meets one
// if none are met it displays a generic message of failure
//additionally the math for the pound*zone price is done within the display message
if(Zone == 'A')
    printf("Your price will be %f\n", Weight * 5);
    else if (Zone == 'B')
        printf("Your price will be %f\n", Weight * 10);
            else if (Zone == 'C')
            printf("Your price will be %f\n", Weight * 20);
                else
                printf("you must enter A, B, or C!\n");


//say goodbye to the user
printf("Thank you for using Shipping Company International!\n\n");

//author
printf("Programmed by:\n");
printf(" _____  _          _   _      _____           _ _   _                 _ _\n|  __ \\| |        | | | |    / ____|         (_) | | |               | | |\n| |__) | |__   ___| |_| |_  | (___  _ __ ___  _| |_| |__   __ _  __ _| | |\n|  _  /| '_ \\ / _ \\ __| __|  \\___ \\| '_ ` _ \\| | __| '_ \\ / _` |/ _` | | |\n| | \\ \\| | | |  __/ |_| |_   ____) | | | | | | | |_| | | | (_| | (_| | | |\n|_|  \\_\\_| |_|\\___|\\__|\\__| |_____/|_| |_| |_|_|\\__|_| |_|\\__, |\\__,_|_|_|\n                                                           __/ |          \n                                                          |___/           \n");
return 0;
}
