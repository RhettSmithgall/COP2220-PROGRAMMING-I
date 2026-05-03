#include <stdio.h>
int main()
{
    //initialize variables
    //int was selected as years cannot be decimals
    int userYear;

    //welcome the user
    printf("welcome to Leap Year Figure-out-er!\n");

    //ask the user for their year they want to input and collect it with scanf
    printf("please enter a year and this program will tell you whether or not it was a leap year\ninput:");

    scanf("%i", &userYear);

    //the following series of if/else statements need to ask 4 questions in order to determine a leap year.
    //because these need to be done in order if/else was selected over switch/case
    //the 4 questions are as follows
    //1. does the year come before 1752? there are no leap years before 1752
    //2. does  the number divide by 400 without remainder? a leap year is divisible by 400
    //3. does the year divide by 100? years divisible by 100 are not leap years
    //4. does the year divide by 4? years divisible by 4 are leap years
    //as you can see these rules would overlap is done simultaneously like in switch. years are only leap years if they are divisible by 4
    //AFTER being checked to see if they are divisible by 100 for example. These steps must be done one after the other in order from 1 to 4
    if (userYear < 1752)
    {
        printf("Your year is not a leap year because there were no leap years before 1752");
    }
    else
    {
        if (userYear % 400 == 0)
        {
            printf("Your year is a leap year!");
        }
        else
        {
            if (userYear % 100 == 0)
            {
                printf("Your year is not a leap year :(");
            }
            else
            {
                if (userYear % 4 == 0)
                {
                    printf("Your year is a leap year!");
                }
                else
                {
                    printf("Your year is not a leap year :(");
                }
            }
        }
    }



    //say goodbye to the user
    printf("\nThank you for using Leap Year Figure-out-er!\n\n");

    //author
    printf("Programmed by:\n");
    printf(" _____  _          _   _      _____           _ _   _                 _ _\n|  __ \\| |        | | | |    / ____|         (_) | | |               | | |\n| |__) | |__   ___| |_| |_  | (___  _ __ ___  _| |_| |__   __ _  __ _| | |\n|  _  /| '_ \\ / _ \\ __| __|  \\___ \\| '_ ` _ \\| | __| '_ \\ / _` |/ _` | | |\n| | \\ \\| | | |  __/ |_| |_   ____) | | | | | | | |_| | | | (_| | (_| | | |\n|_|  \\_\\_| |_|\\___|\\__|\\__| |_____/|_| |_| |_|_|\\__|_| |_|\\__, |\\__,_|_|_|\n                                                           __/ |          \n                                                          |___/           \n");
return 0;
}
