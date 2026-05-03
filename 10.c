//Rhett Smithgall
//COP2220
//module 3 exercises
//8/12/22

//Purpose
//this program has 4 primary goals called "countdown","multiplication table","tree structure" and the menu within main
//countdown starts at 100 (a set value, not an input) and counts down by 5 printing the result along the way. e.g. 100,95,90,85,ect.
//multiplication table accepts an input from the user and prints a multiplication table from 0-12 including the answer
//tree structure makes a little pyramid structure with asterisks

//assumptions
//within the menu the user will use the guide and enter a integer to navigate. a default is prepared but entering too much and letters can confuse the program
//within multiplication table the user will only enter an integer, this function has no default or backup so if the user enters anything other than an integer the program breaks
//tree structure and countdown have no inputs so they seem indestructible.

#include <stdio.h>
#include <stdlib.h>

//function prototypes
int countdown();
int multiplicationTable();
int treeStructure();

//main function
//holds a menu for all the other functions
//welcomes and goodbyes the user
int main()
{
    //setting up variables
    //user selection is used as a user input
    int userSelection;
    //exit is used to escape the switch statement when needed
    int exit;

    //setting up exit so it won't start with an unexpected value
    exit = 0;

    //this while loop ensures the user can select each option and return multiple times
    //the user can't leave until they select exit (or any unexpected value)
    while (exit != 1)
    {
        //printing the menu options
        printf("Welcome to Module 3 exercises!\n");
        printf("Please enter a number below to select an option\n");
        printf("1. Count down from 100\n");
        printf("2. multiplication table\n");
        printf("3. tree structure\n");
        printf("4. exit\n");

        scanf("%i", &userSelection);

        switch(userSelection)
        {
            case 1:
                {
                    countdown();
                    break;
                }
            case 2:
                {
                    multiplicationTable();
                    break;
                }
            case 3:
                {
                    treeStructure();
                    break;
                }
                //exit is set as the default because it's safer for the program to exit by accident and end then to be trapped
                //running tree structure over and over again or something
            default:
                {
                    exit = 1;
                }
        }
    }
    printf("thanks for using module 3 exercises!!");
    return 0;
}


//function countdown
//doesn't take any inputs or anything, just counts down by 5 from 100
//100,95,80,85...
int countdown()
{
    int counter;
    counter = 100;

    printf("welcome to countdown\n");

    while (counter != 0)
    {
        //the % sign here is basically doing all the work, without it the loop would
        //print everything, instead it only counts down by 5 because of the %  sign
        if (counter %5 == 0)
        {
            printf("%i\n", counter);
        }
        counter--;
    }
}

//multiplication function
//this function takes one input and builds a multiplication table from 0-12
int multiplicationTable()
{
    int userInput,i;

    printf("welcome to multiplication table\n");
    printf("what number do you want a multiplication table for?\n");

    scanf("%i", &userInput);

    //if I put <= instead of < i could use 12 to make this slightly more readable but I didn't so here we are
    //this table only goes to 12 but theres a 13 here, it gets eaten before running by the loop.
    for (i=0;i<13;i++)
    {
        printf("%i X %i = %i\n",i,userInput,i*userInput);
    }
}

//tree structure function
//tree structure makes a pyramid shape from asterisk
int treeStructure()
{
    int i,j,x;

    printf("welcome to treestructure!\n");

    //this whole loop is really complicated but basically we need to start with 1
    //asterisk and end with 15, so each loop we need 1 more asterisk on the row from the last time
    //but it also has to be centered, so we need some spaces to push the asterisks to the middle, 1 less each time
    //because of this we have 3 total loops here, this main one to hold everything then one for spaces and one for asterisks
    for (i=0;i<16;i++)
    {
        //the pyramid is twice as wide as it is tall, the number of i here is important to both so here we
        //make sure the pyramid is only half as tall
        if (i%2 != 0)
        {

            //this loop controls the spaces with the x<8-i/2 thing in the middle, this ensures it adds less
            //spaces as the loop progresses but still adds the right amount at the begining
            for(x=0;x< 8-i/2;x++)
            {
                printf("  ");
            }

            //this loop is a lot more simple, it puts the right amount of asterisks each level
            //by using the number of loops
            for(j=0;j<i;j++)
            {
                printf(" *");
            }
            printf("\n");
        }
    }
}


