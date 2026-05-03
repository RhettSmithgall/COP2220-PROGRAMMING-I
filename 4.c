//RHETT ALAN SMITHGALL
//COP 2220
//1056
//Assignment 1
//6/4/2022

//Purpose:
//this program accepts no inputs, its only purpose is to convert 5 specific amounts of US dollars to Canadian Dollars
//those amounts are 5,10,15,20 and 25

//assumptions
//no input will be required
//the program will convert the amounts from US dollars to Canadian dollars and then print the result in a chart
//the limitations of this program are that because it accepts no input there is no way to convert any other amount of US dollars to Canadian dollars
//only the set amounts listed above

#include <stdio.h>
int main() {
printf("US $ 5  ----- Can $ %.2f\n", 1.25*5);
printf("US $ 10 ----- Can $ %.2f\n", 1.25*10);
printf("US $ 15 ----- Can $ %.2f\n", 1.25*15);
printf("US $ 20 ----- Can $ %.2f\n", 1.25*20);
printf("US $ 25 ----- Can $ %.2f\n", 1.25*25);
}
