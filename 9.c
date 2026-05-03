#include <stdio.h>
#include <stdlib.h>
//Rhett Smithgall
//Assignment 7
//cop 2220
//1056
//8/15/22

//purpose
//the purpose of this program is to open 2 text files
//and combine the information within into a 3rd text file the program should create

//assumptions
//the files will be formatted correctly, in this case the first file for "customers"
//should have each line formatted as such "customerID customerFirstName customerLastName customerBalance\n"
//the 2nd file "transactions" should be formatted "customerID transaction\n"
//any deviation from these formatting restraints causes differing data types to be stored incorrectly
//ensuring bad data and often misbehavior from the code

//this is a structure created to store customer information
//it stores ID numbers
//first names
//last names
//and their balance from the previous month
struct customerInfo
{
    int customerIds[10];
    char customerFirstNames[10][20];
    char customerLastNames[10][20];
    int cutomerBalance[10];

};

//this is a structure to hold transactions
//it the IDs of the customer making the transaction
//and the amount of the transaction
struct transactions
{
    int customerIds[10];
    int transactionAmount[10];
};

int main()
{
    //initializing all the variables and structures
    int i,j,numberOfTransactions,numberOfCustomers;
    struct customerInfo customerInfoAugust;
    struct transactions customerTransactionsAugust;

    //keeping track of the number of entries in both files will be important later
    //so these values are initialized here
    numberOfTransactions = 0;
    numberOfCustomers = 0;

    //this prepares the 3 files we will use in this program
    //customerFileInput is everything in the customerInfo structure
    //transaction file is everything in the transactions structure
    //and customerFileOutput is the out file we will generate using the information from the previous two
    FILE *customerFileInput,*transactionFile,*customerFileOutput;

    //reading from the customers file
    //this rule applies to all the file paths within this code
    // "\" is a special character and for some reason you need 2 of them to get the point across, double slash in file paths
    // also, you will have to change this file path every time you move this, it should just grab it off "customers.txt" because theyre in the same folder but it doesnt
    customerFileInput = fopen("customers.txt","r");
    //this loop loads data from the customers file into the relevant arrays
    //all the arrays here are part of the customersInfo structure
    for(i=0;feof(customerFileInput)==0;i++)
    {
    fscanf(customerFileInput,"%i %s %s %i \n",&customerInfoAugust.customerIds[i],customerInfoAugust.customerFirstNames[i],customerInfoAugust.customerLastNames[i],&customerInfoAugust.cutomerBalance[i]);
    numberOfCustomers++;
    }
    //clear file memory to open the next one
    fclose(customerFileInput);

    //reading from the transactions file
    transactionFile = fopen("transactions.txt","r");

    //this loop reads the contents of the transactions file line by line, each line is loaded into the relevant array
    //all the arrays here are part of the transactions stucture
    for(i=0;feof(transactionFile)==0;i++)
    {
    fscanf(transactionFile,"%i %i\n",&customerTransactionsAugust.customerIds[i],&customerTransactionsAugust.transactionAmount[i]);
    numberOfTransactions++;
    }
    //clear file memory to open the next one
    fclose(transactionFile);

    //these nested loops compare a transaction number to each customer to find a matching ID
    //when a matching ID is found their new transaction is added to their balance
    for(i=0;i<numberOfTransactions;i++)
    {
        for(j=0;j<numberOfCustomers;j++)
        {
            if(customerTransactionsAugust.customerIds[i] == customerInfoAugust.customerIds[j])
            {
                customerInfoAugust.cutomerBalance[j] += customerTransactionsAugust.transactionAmount[i];
            }

        }
    }

    //this fopen either opens an existing file of the same name or creates the needed file
    //then this file is written too
    customerFileOutput = fopen("customersOutput.txt","w");
    for(i=0;i<numberOfCustomers;i++)
    {
    fprintf(customerFileOutput,"%i %i\n",customerInfoAugust.customerIds[i],customerInfoAugust.cutomerBalance[i]);
    }
    fclose(customerFileOutput);

    //author
    printf("Programmed by:\n");
    printf(" _____  _          _   _      _____           _ _   _                 _ _\n|  __ \\| |        | | | |    / ____|         (_) | | |               | | |\n| |__) | |__   ___| |_| |_  | (___  _ __ ___  _| |_| |__   __ _  __ _| | |\n|  _  /| '_ \\ / _ \\ __| __|  \\___ \\| '_ ` _ \\| | __| '_ \\ / _` |/ _` | | |\n| | \\ \\| | | |  __/ |_| |_   ____) | | | | | | | |_| | | | (_| | (_| | | |\n|_|  \\_\\_| |_|\\___|\\__|\\__| |_____/|_| |_| |_|_|\\__|_| |_|\\__, |\\__,_|_|_|\n                                                           __/ |          \n                                                          |___/           \n");

    return 0;
}
