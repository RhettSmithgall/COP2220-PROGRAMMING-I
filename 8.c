#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ABCSort(char studentNames[10][10],float studentGrades[10]);

int numberSort(char studentNames[10][10],float studentGrades[10]);

int main()
{
                                //The commented lines below and be attached to the array declarations to populate them with generic names and gpas for testing purposes
                                //remember to comment out the array entry loop if you do this
    char studentNames[10][10]  = {"Clara","Ella","Billy","Johnnie","Jill","Cameron","Willis","Betty","Irving","Martin"};
    float studentGrades[10]  = {2.0,2.2,3.4,4.0,1.1,1,2.6,3.8,3.6,3.7};
    int i,userInputMenu;

    printf("welcome to class sorter!\n");
    printf("please enter a students name and gpa\n");
    /*
    //this loop lets the user enter the students names and grades into the arrays
    for(i=0;i<10;i++)
    {
            printf("Name %i: ",i+1);
            scanf("%10s",studentNames[i]);

            printf("GPA: ");
            scanf("%f",&studentGrades[i]);
    }
    */

    //this prints the results, a loop is required to go through the array
    printf("\n -----------------------\n");
    printf(" | #| Name       | GPA |\n");
    printf(" -----------------------\n");
    for(i=0;i<10;i++)
    {
        printf(" |%2i| %-10s | %2.1f |\n",i+1,studentNames[i],studentGrades[i]);
    }
    printf(" -----------------------\n");

    //this prompts the user on how they want to sort the list they made and collects the result
    printf("Would you like to sort alphabetically by name or numerically by GPA?\n1. Name\n2. GPA\n3. Exit Program\n");
    scanf("%i",&userInputMenu);

    if(userInputMenu == 1)
    {
        //this calls ABCSort which sorts the list alphabetically
        ABCSort(studentNames,studentGrades);
    }
    if(userInputMenu == 2)
    {
        //this calls numberSort which sorts the list numerically
        numberSort(studentNames,studentGrades);
    }

    //author
    printf("Programmed by:\n");
    printf(" _____  _          _   _      _____           _ _   _                 _ _\n|  __ \\| |        | | | |    / ____|         (_) | | |               | | |\n| |__) | |__   ___| |_| |_  | (___  _ __ ___  _| |_| |__   __ _  __ _| | |\n|  _  /| '_ \\ / _ \\ __| __|  \\___ \\| '_ ` _ \\| | __| '_ \\ / _` |/ _` | | |\n| | \\ \\| | | |  __/ |_| |_   ____) | | | | | | | |_| | | | (_| | (_| | | |\n|_|  \\_\\_| |_|\\___|\\__|\\__| |_____/|_| |_| |_|_|\\__|_| |_|\\__, |\\__,_|_|_|\n                                                           __/ |          \n                                                          |___/           \n");

}


//this is ABCSort, it takes an array of names and grades and sorts them alphabetically by name
int ABCSort(char studentNames[10][10],float studentGrades[10])
{
    int i,j;
    char nameCopy[10];
    float numberCopy;


    //these 2 nested loops control the sorting process
    //ever step is mirrored by the array with grades so the 2 stay in sync

    for(i=0;i<10;i++)
    {
    //first we make a copy of a studentNames entry starting with the first
    strcpy(nameCopy,studentNames[i]);
    numberCopy = studentGrades[i];

        for(j=0;j<10;j++)
        {
            //the in the 2nd loop this entry is compared against every other entry 1 by 1 until it hit one before it in the alphabet
            if(strcmp(nameCopy,studentNames[j]) < 0)
            {
                //we then replace our entry we're using to compare with the superior
                strcpy(studentNames[i],studentNames[j]);
                studentGrades[i] = studentGrades[j];

                //then we place our copy we made into the spot left open by the one we moved
                strcpy(studentNames[j],nameCopy);
                studentGrades[j] = numberCopy;

                //then we replace our copy and use the new, higher in the alphabet name, to compare with
                strcpy(nameCopy,studentNames[i]);
                numberCopy = studentGrades[i];
            }

        }
    }
    //this prints the results, a loop is required to go through the array
    printf("\n -----------------------\n");
    printf(" | #| Name       | GPA |\n");
    printf(" -----------------------\n");

    for(i=0;i<10;i++)
    {
            printf(" |%2i| %-10s | %2.1f |\n",i+1,studentNames[i],studentGrades[i]);
    }
    printf(" -----------------------\n");

    return 0;

}


//this is numberSort, it takes an array of names and grades and sorts them numerically by grade
int numberSort(char studentNames[10][10],float studentGrades[10])
{
    int i,j;
    char nameCopy[10];
    float numberCopy;


    //these 2 nested loops control the sorting process
    //ever step is mirrored by the array with names so the 2 stay in sync

    for(i=0;i<10;i++)
    {
    //first we make a copy of a studentGrades entry starting with the first
    numberCopy = studentGrades[i];
    strcpy(nameCopy,studentNames[i]);


        for(j=0;j<10;j++)
        {
            //the in the 2nd loop this entry is compared against every other entry 1 by 1 until it hit a higher number
            if(numberCopy > studentGrades[j])
            {
                //we then replace our entry we're using to compare with the superior
                strcpy(studentNames[i],studentNames[j]);
                studentGrades[i] = studentGrades[j];

                //then we place our copy we made into the spot left open by the one we moved
                strcpy(studentNames[j],nameCopy);
                studentGrades[j] = numberCopy;

                //then we replace our copy and use the new, higher number, to compare with
                strcpy(nameCopy,studentNames[i]);
                numberCopy = studentGrades[i];
            }

        }
    }

    //this prints the results, a loop is required to go through the array
    printf("\n -----------------------\n");
    printf(" | #| Name       | GPA |\n");
    printf(" -----------------------\n");

    for(i=0;i<10;i++)
    {
            printf(" |%2i| %-10s | %2.1f |\n",i+1,studentNames[i],studentGrades[i]);
    }
    printf(" -----------------------\n");

    return 0;

}




