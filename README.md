##                          BANKING SOFTWARE
                                              
## The purpose of the Makefile : 
This Makefile is used to compile the Indian_Bank and Spain_Bank C++ programmes
## make indian_debug :  
To compile the Indian_Bank programme in debug mode, run the following command

## make indian_optimized:
             To compile the Indian_Bank programme in optimized mode, run the following command:
     
## make spain_debug:
                To compile the Spain_Bank programme in debug mode, run the following command:

## make spain_optimized : 
                     To compile the Spain_Bank programme in optimised mode, run the following command:

## make clean:
The input files for the Indian_Bank and Spain_Bank programmes are as follows:

Indian_Bank.cpp: This file contains the source code for the Indian_Bank programme.
Spain_Bank.cpp: This file contains the source code for the Spain_Bank programme.

##             STRUCTURE OF INDIAN_BANK
Declare a struct called Bank_of_India with three members: 
year, interest_rate, and inflation_rate.
## Define two functions:
getCurrentAmount() and getInvestedValue().
Read the data from the CSV file into an array of Bank_of_India structs.
Get the year of investment and the amount invested from the user.
Perform a binary search to find the index of the year of investment in the array.
If the year of investment is found, then calculate the money actually received and the invested value in the year of investment.
Otherwise, print a message saying that the year of investment is not found.

## STRUCTURE OF SPAIN_BANK

 The structure of the array in the program is as follows:

struct Bank_of_Spain {
    int year;
    
    double interest_rate;
    
    double inflation_rate;
};
The Bank_of_Spain structure has three members:

## year: The year of the data.
## interest_rate: The interest rate in that year.
## inflation_rate: The inflation rate in that year.
The array arr is of type Bank_of_Spain and has a size of 100. This means that it can store up to 100 data points.

The data in the array is read from a CSV file called spain_data.csv. The CSV file is a comma-separated file.

The binary search algorithm is used to find the index of the year of investment in the array. If the year of investment is found, then the money actually received and the value of money obtained after adding interest are calculated.

The function growthChecker_Dictatorship() and growthChecker_Monarchy() are used to calculate the growth rate of the Spanish economy during the dictatorship era (1960-1977) and the monarchy era (1977-2022).
