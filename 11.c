#include <stdio.h>
#include <stdlib.h>
//name: Rhett Smithgall
//Assignment: Module 4 exercises
//cop 2220
//1056
//8/12/22

//purpose
//this program has 3 uses plus a menu
//in main there is a menu holding the other 3 functions
//imperial to metric uses a series of calls and 3 different functions to eventually turn feet and inches into meters and centimeters
//waiting time will, given a time and how long to wait, what time it will be after you wait
//change teller will, given an amount of change under a dollar, divide it into quarters, dimes, and pennies

//assumptions
//the menu accepts only integers but is prepared to exit for unexpected values
//imperialtometric expects integers and WILL misbehave if given something else
//waiting time can act up if the user inputs something outside the 00:00 time format and of course if its not an int
//change teller will actually catch errors for negative numbers and numbers above 100 but cannot combat error for a non integer value

//the many many function prototypes
int waitingTime();
int changeTeller();

int feetInchesInput();
int feetInchesCalculator(int userInputFeet,int userInputInches);
int feetInchesOutput(float outputMeters,float outputCentimeters);

//main function accepts a single integer input called userselection used for the menu.
//main controls the menu for choosing which function to go to
int main()
{
    int userSelection;
    int exit;

    exit = 0;

    //this loop controls a menu, exit is default so 4 or anything unexpected will close the program
    while (exit != 1)
    {
        printf("Welcome to Module 4 exercises!\n");
        printf("Please enter a number below to select an option\n");
        printf("1. imperial to metric converter\n");
        printf("2. waiting time calculator\n");
        printf("3. Change calculator\n");
        printf("4. exit\n");

        scanf("%i", &userSelection);

        switch(userSelection)
        {
            case 1:
                {
                    feetInchesInput();
                    break;
                }
            case 2:
                {
                    waitingTime();
                    break;
                }
            case 3:
                {
                    changeTeller();
                    break;
                }
            default:
                {
                    exit = 1;
                }
        }
    }
    return 0;
}

//feetinchesinput exists to collect the input from the user and pass it to feetinchescalculator
int feetInchesInput()
{
    int userInputFeet;
    int userInputInches;
    char userInputExit;
    int exit;

    printf("welcome to the imperial to metric calculator!\n");

        while (exit != 1)
        {
            printf("how many feet?\n");

            scanf("%i", &userInputFeet);

            printf("how many inches?\n");

            scanf("%i", &userInputInches);

            feetInchesCalculator(userInputFeet,userInputInches);

            printf("would you like to exit? (y/n)\n");

            scanf(" %c", &userInputExit);

                //this loop allows the user to continue inputting value if they want to
                switch (userInputExit)
                {
                    case 'y':
                    {
                        exit = 1;
                        break;
                    }
                    default:
                    {
                        exit = 0;
                        break;
                    }
                }
        }
        return 0;
}

//feetinches calculator calculates the centimeters and meters and passes that to feetinchesoutput to be displayed
int feetInchesCalculator(int userInputFeet,int userInputInches)
{
    float outputMeters;
    float outputCentimeters;

    outputMeters = userInputFeet*0.3048;
    outputCentimeters = userInputInches*2.54;

    feetInchesOutput(outputMeters,outputCentimeters);
    return 0;
}


//feetinchesoutput contains a print statment which prints the information calculated in feetinchescalculator
int feetInchesOutput(float outputMeters,float outputCentimeters)
{
    printf("thats %f meters and %f centimeters!\n", outputMeters, outputCentimeters);
    return 0;
}


//waiting time takes what time it is and how long to wait and tells you the calculated time after your wait
int waitingTime()
{
    char exit;
    exit = 'y';

    //making a program calculate in 00:00 format was a small challenge, the solution was to have
    //many variables to break down the math step by step
    int userInputCurrentMinutes;
    int userInputCurrentHours;
    int userInputWaitMinutes;
    int userInputWaitHours;
    int hourFinal;
    int minuteFinal;

    printf("welcome to waiting time!\n");

        while(exit != 'n')
        {
            printf("what time is it? (24-hour notation)\n");
            scanf("%i:%i", &userInputCurrentHours,&userInputCurrentMinutes);

            printf("how long would you like to wait?\n");
            scanf("%i:%i", &userInputWaitHours,&userInputWaitMinutes);

            //this small series of if/then statements add to the time unless it hits a break point, 23 in hours, 60 in minutes
            //basically they just make time the base 24 and base 60 systems they are.
            if ((userInputCurrentHours + userInputWaitHours) > 23)
            {
                hourFinal = (userInputCurrentHours + userInputWaitHours) - 24;
            }
            else
            {
                hourFinal = (userInputCurrentHours + userInputWaitHours);
            }

            if ((userInputCurrentMinutes + userInputWaitMinutes) >= 60)
            {
                hourFinal++;

                minuteFinal = userInputCurrentMinutes + userInputWaitMinutes - 60;
            }
            else
            {
                minuteFinal = (userInputCurrentMinutes + userInputWaitMinutes);
            }

            printf("It will be %02i:%02i at the end of your wait\n",hourFinal, minuteFinal);

            //this lets the user input more times if they wish
            printf("would you like to try another time?\nyes: enter 'y'\nno: enter 'n'\n");
            scanf(" %c",&exit);
        }
    return 0;
}

//change teller accepts a value under 100 and tells you how many quarters, dimes, and pennies that makes
int changeTeller()
{
    int userInputTotalMoney;

    userInputTotalMoney = 0;

    int changeQuarters;
    int changeDimes;
    int changePennies;

    printf("welcome to change teller\n");
    printf("please enter the amount of money you have\n");

    while (userInputTotalMoney>=100||userInputTotalMoney<=0)
    {
        scanf("%i", &userInputTotalMoney);

        if (userInputTotalMoney >= 100)
        {
            printf("Value must be lower than 100!\n");
        }

        if (userInputTotalMoney <= 0)
        {
            printf("Value must be greater than zero!\n");
        }
    }

    //the math here is essentially to divide by each value descending to pennies
    changeQuarters = userInputTotalMoney/25;

    userInputTotalMoney = userInputTotalMoney-(changeQuarters*25);

    changeDimes = userInputTotalMoney/10;

    userInputTotalMoney = userInputTotalMoney-(changeDimes*10);

    changePennies = userInputTotalMoney;

    printf("That gives you %i quarters, %i dimes, %i pennies.\n",changeQuarters, changeDimes, changePennies);
}
