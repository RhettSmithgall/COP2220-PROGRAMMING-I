#include <stdio.h>
int main()
{
    //set up variables
    int inputOne,inputTwo,inputThree;

    //Welcome User
    printf("Welcome to Ascending Number Program!\n");

    //Ask user for 3 inputs and then collect 3 inputs with scanf
    printf("please enter 3 numbers!\n\n");

    scanf("%i %i %i", &inputOne, &inputTwo, &inputThree);

    //this text mostly serves to separate the user-entered numbers from the computer-sorted numbers
    printf("Your numbers in ascending order are:\n");

    /*
    the series of if else statements is a little complicated but essentially the math works by first establishing that
    there are only 6 possibilities no matter what the user enters. one number will be the highest "high", one will be lowest "low"
    and one will be in the middle "mid"
    these 6 options are as follows
    1. high low mid
    2. high mid low
    3. mid low high
    4. low mid high
    5. low high mid
    6. mid high low
    by thinking about each possibility individually it was easier to make an if else statement to get the information required
    I will explain the first option here and the rest should be explained through that
    if inputOne is greater than inputTwo and inputTwo is greater than inputThree that ensures one is highest, making three lowest, leaving two in the middle.
    */
    if (inputOne > inputTwo)
    {
        if (inputTwo > inputThree)
        {
            //printf("high mid low")
            printf("%i %i %i", inputThree, inputTwo, inputOne);
        }
        else
        {
            if (inputOne > inputThree)
            {
                //printf("high low mid")
                printf("%i %i %i", inputTwo, inputThree, inputOne);
            }
            else
            {
                //printf("mid low high")
                printf("%i %i %i", inputTwo, inputOne, inputThree);
            }
        }
    }
    else
    {
        if (inputOne > inputThree)
        {
            //printf("mid high low")
            printf("%i %i %i", inputThree, inputOne, inputTwo);
        }
        else
        {
            if (inputTwo > inputThree)
            {
                //printf("low high mid")
                printf("%i %i %i", inputOne, inputThree, inputTwo);
            }
            else
            {
                //printf("low mid high")
                printf("%i %i %i", inputOne, inputTwo, inputThree);
            }
        }
    }

    //say goodbye to the user
    printf("\nThank you for using Ascending Number Program!\n\n");

    //author
    printf("Programmed by:\n");
    printf(" _____  _          _   _      _____           _ _   _                 _ _\n|  __ \\| |        | | | |    / ____|         (_) | | |               | | |\n| |__) | |__   ___| |_| |_  | (___  _ __ ___  _| |_| |__   __ _  __ _| | |\n|  _  /| '_ \\ / _ \\ __| __|  \\___ \\| '_ ` _ \\| | __| '_ \\ / _` |/ _` | | |\n| | \\ \\| | | |  __/ |_| |_   ____) | | | | | | | |_| | | | (_| | (_| | | |\n|_|  \\_\\_| |_|\\___|\\__|\\__| |_____/|_| |_| |_|_|\\__|_| |_|\\__, |\\__,_|_|_|\n                                                           __/ |          \n                                                          |___/           \n");

return 0;
}

