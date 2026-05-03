#include <stdio.h>
#include <stdlib.h>


//Name: Rhett Smithgall
//CourseNumber: COP 2220
//assignment: assignment 4
//last mod: 7/12/22

//PURPOSE:
//this program is like a change teller at a bank or ATM
//this program takes 1 input ("userInputDollarAmount") and this is the desired amount of money to dispense
//the program then tells the user how many 50s, 20s and 10s they will receive equal to their entered amount

//ASSUMPTIONS
//this program assumes the user will attempt to input a whole number when asked
//the program will only work with numbers divisible by 10 and greater than 0 but these
//2 possibilities have been given solutions so the program can accept any whole number
//limitations: while this program can give change in 50s, 20s, and 10s, it can't give any lower or higher
//coins, one dollars bills and 100 dollar bills are not used.
//bugs: if anything other than whole numbers are entered like decimals or letters the program is likely to act up

//setup functions
int welcomeUser();
int collectUserInput(int userInputDollarAmount);
int calculateChange(int userInputDollarAmount);
int dispenseChange(int changeFifties,int changeTwenties,int changeTens);
int credits();

//main function
int main()
{
    //setup variables
    //holds user input of desired dollars to dispense
    int userInputDollarAmount;

    //initialize variable
    userInputDollarAmount = 0;

    //calls the function "welcomeUser();" which welcomes the user
    //this function has no input or return value
    welcomeUser();


    //calls the function collectUserInput
    //this function collects the variable "userInputDollarAmount" and returns it
    //this function accepts userInputDollarAmount as a parameter
    userInputDollarAmount = collectUserInput(userInputDollarAmount);

    //calls the function calculateChange
    //this function both calculates the number of 10s,20s, and 50s required and calls the function "dispenseChange" which tells the user those values"
    //this function accepts userInputDollarAmount as a parameter
    calculateChange(userInputDollarAmount);

    //says goodbye to the user and displays the credits
    credits();

    return 0;
}


//this function welcomes the user
//it has no parameters or return values
int welcomeUser()
{
    //this print function welcomes the user
    printf("Welcome to change teller program!\n");
    return 0;
}


//this function collects the users input of their desired dollar amount to be dispensed
//this function accepts userInputDollarAmount as a parameter
int collectUserInput(int userInputDollarAmount)
{
    //this while loop doesn't let the program proceed until userInputDollarAmount is
    //divisible by 10 and greater than zero
    while (userInputDollarAmount % 10 != 0 || userInputDollarAmount <= 0)
    {
        //ask user for the amount
        printf("please enter the desired amount of money (amount must be a multiple of 10)\n");

        //collect their entry
        scanf("%i", &userInputDollarAmount);

        //display a warning message is applicable
        if (userInputDollarAmount <= 0)
        {
            printf("The amount must be greater than 0!\n");
        }

        //display a warning message is applicable
        if (userInputDollarAmount % 10 != 0)
        {
            printf("the amount must be a multitude of 10!\n");
        }
    }

//return value
return userInputDollarAmount;
}

//this function figures out how many 50s, 20s and 10s we need to dispense for the user
//this function accepts userInputDollarAmount as a parameter
int calculateChange(int userInputDollarAmount)
{
    //setup variables
    int changeFifties;
    int changeTwenties;
    int changeTens;

    //the basic idea of this block of math is we divide each dollar amount descending starting from 50
    //each time we subtract that amount from userInputDollarAmount
    //that way each division takes the greatest amount it can the most efficiently
    changeFifties = userInputDollarAmount/50;

    userInputDollarAmount = userInputDollarAmount - (changeFifties*50);

    changeTwenties = userInputDollarAmount/20;

    userInputDollarAmount = userInputDollarAmount - (changeTwenties*20);

    changeTens = userInputDollarAmount/10;

    userInputDollarAmount = userInputDollarAmount - (changeTens*10);

    //with these new values created we send them off to the dispense change function
    //this calls the function dispenseChange which essentially just prints this information we just calculated
    dispenseChange(changeFifties,changeTwenties,changeTens);

}

//this is the function dispenseChange
//the purpose of this function is to display the information calculated in "calculateChange" function
//it is called by the function calculateChange and accepts changeFifties, changeTwenties,and changeTens as parameters
//it returns no value
int dispenseChange(int changeFifties,int changeTwenties,int changeTens)
{
    //display the 3 parameters
    printf("you will receive %i fifties, %i twenties, and %i tens\n",changeFifties,changeTwenties,changeTens);
    //and by reversing the math we can use these same values to give the user a total
    //as well as the total number of bills they will receive
    printf("altogether $%i dispensed as %i bills", (changeFifties*50 +  changeTwenties*20 + changeTens*10), changeTens+changeFifties+changeTwenties);
    return 0;
}


//this function says goodbye to the user
//this function also displays the credits
//no return value, no parameters
int credits()
{
    //say goodbye to the user
    printf("\nThanks for using change teller program!\n\n");

    //author
    printf("Programmed by:\n");
    printf(" _____  _          _   _      _____           _ _   _                 _ _\n|  __ \\| |        | | | |    / ____|         (_) | | |               | | |\n| |__) | |__   ___| |_| |_  | (___  _ __ ___  _| |_| |__   __ _  __ _| | |\n|  _  /| '_ \\ / _ \\ __| __|  \\___ \\| '_ ` _ \\| | __| '_ \\ / _` |/ _` | | |\n| | \\ \\| | | |  __/ |_| |_   ____) | | | | | | | |_| | | | (_| | (_| | | |\n|_|  \\_\\_| |_|\\___|\\__|\\__| |_____/|_| |_| |_|_|\\__|_| |_|\\__, |\\__,_|_|_|\n                                                           __/ |          \n                                                          |___/           \n");
}

