//RHETT ALAN SMITHGALL
//COP 2220
//1056
//MODULE 1 EXERCISES
//6/4/2022

//Purpose:
//Accepts the input "speed" to give the distance in miles after 2,4,6,8, and 10 hours

//assumptions
//the inputs will be numbers that can be accepted by float
//the limitations of this program is that anything other than a number will cause it to fail
//similarly if the number is too large to be held by float the program will fail

#include <stdio.h>
int main(int argc,char* argv[]) {
//set up variables
float speed;

//welcome the user
printf("Welcome to the Car Chart (tm) speedometer\n");

//request miles per hour
printf("what is the speed of the car in miles per hour?\n");
scanf("%f", &speed);

//calculate and print the "speed" multiplied by the "hours" to give us distance
printf("-----------------------------\n");
printf("         Car Chart (tm)      \n");
printf("-----------------------------\n");
printf(" time/hours | Distance/miles \n");
printf("-----------------------------\n");
printf("      2            %.0f\n", speed*2);
printf("      4            %.0f\n", speed*4);
printf("      6            %.0f\n", speed*6);
printf("      8            %.0f\n", speed*8);
printf("     10            %.0f\n", speed*10);
printf("-----------------------------\n\n");

//author
printf("Programmed by:\n");
printf(" _____  _          _   _      _____           _ _   _                 _ _\n|  __ \\| |        | | | |    / ____|         (_) | | |               | | |\n| |__) | |__   ___| |_| |_  | (___  _ __ ___  _| |_| |__   __ _  __ _| | |\n|  _  /| '_ \\ / _ \\ __| __|  \\___ \\| '_ ` _ \\| | __| '_ \\ / _` |/ _` | | |\n| | \\ \\| | | |  __/ |_| |_   ____) | | | | | | | |_| | | | (_| | (_| | | |\n|_|  \\_\\_| |_|\\___|\\__|\\__| |_____/|_| |_| |_|_|\\__|_| |_|\\__, |\\__,_|_|_|\n                                                           __/ |          \n                                                          |___/           \n");
return 0;
}


