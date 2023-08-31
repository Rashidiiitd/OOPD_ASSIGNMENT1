#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip> // Include the header for setprecision and fixed
#include <math.h>
using namespace std;

// Define a structure to hold the bank data
struct Bank_of_Spain {
    int year;
    double interest_rate;
    double inflation_rate;
};

double temp = 0.0; // Temporary variable to hold processed amount

// Function to calculate and print the money actually received
void getCurrentAmount(Bank_of_Spain arr[], int invested_year, double amount_invested, int index) {
    double processed_amount = amount_invested;
    int i = invested_year;
    
    // Calculate money till 2002
    for (; arr[i].year < 2002; i++) { 
        double interest = arr[i].interest_rate;
        processed_amount = processed_amount * (1.0 + interest / 100.0);
    }
    if (arr[i].year == 2002)
        processed_amount = processed_amount / 166.0; // Conversion to Euro

    // Calculate money from 2002 to 2023
    for (; arr[i].year < 2023; i++) {
        double interest = arr[i].interest_rate;
        processed_amount = processed_amount * (1.0 + interest / 100.0);
    }
    temp = processed_amount;
    
    // Print the result with 2 decimal places
    cout << fixed << setprecision(2);
    cout << "Money Actually Received : EURO  " << processed_amount << endl;
    return;
}

// Function to calculate and print the invested value after inflation
void printInvestedValue(Bank_of_Spain arr[], int invested_year, int index) {
    double invested_Value = temp;
    double inflation = 0.0;

    // Adjust invested value if invested year is before 2002
    if (invested_year < 2002) {
        invested_Value = 166.0 * invested_Value;
    }
    
    // Calculate invested value after inflation
    for (int i = 2022; i >= invested_year; i--) {
        double inflation = arr[index].inflation_rate;
        invested_Value = invested_Value * (1.0 - (inflation / 100.0));
        index--;
    }

    // Print the result with 2 decimal places
    cout << fixed << setprecision(2);
    cout << "Value of money  in the year it was invested (Pesseta): " << invested_Value << endl;
}
double  growthChecker_Dictatorship(Bank_of_Spain arr[]){
    double temp = 1999;
    double  growth_rate = 1.0;
    // 1960 ---> 1977 Dictatorship 
    for(int i = 0;i<18;i++){
        temp = temp * (1.0 + (arr[i].inflation_rate/100.0));
        // dictatorship era growth percentage
        double growth_rate = (temp - 1999)/100;
    }
    return growth_rate;
}
double growthChecker_Monarchy(Bank_of_Spain arr[]){
    double temp = 1999;
    // 1977 ---> 2022 Monarchy
    double  growth_rate = 1.0;
    for(int i = 19;i<37;i++){
        temp = temp * (1.0 + (arr[i].inflation_rate/100.0));
        // dictatorship era growth percentage
         growth_rate = (temp - 1999)/100;
    }
   return growth_rate;
}
int main() {
    Bank_of_Spain arr[100];
    ifstream mycsvfile("spain_data.csv");

    if (!mycsvfile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    string starter;
    getline(mycsvfile, starter);
    string file_iterator;
    int index = 0;

    // Read data from CSV file and store in the structure
    while (getline(mycsvfile, file_iterator)) {
        istringstream ss(file_iterator);
        double interest_rate, inflation_rate;
        int invest_year, serial_index;

        char comma; // Use a comma to skip delimiters

        ss >> serial_index >> comma >> invest_year >> comma >> interest_rate >> comma >> inflation_rate;

        arr[index].year = invest_year;
        arr[index].interest_rate = interest_rate;
        arr[index].inflation_rate = inflation_rate;

        index++; // Increment the index for each iteration
    }

    mycsvfile.close();

    // Input the year of investment and amount
    int year_invested;
    double amount_invested;
    cout << "enter year of investment :  ";
    cin >> year_invested;
    cout << "enter amount of investment :  ";
    cin >> amount_invested;

    int low = 0;
    int high = index - 1;
    int mid;
    bool flag = false;

    // Binary search to find the index for the input year
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid].year == year_invested) {
            flag = true;
            break;
        } else if (arr[mid].year > year_invested) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if (!flag) {
        cout << "invested_year is not found";
        return 0;
    }

    // Calculate and print money actually received
    getCurrentAmount(arr, mid, amount_invested, index);
    
    // Call the printInvestedValue function to print the value of money obtained after adding interest
    printInvestedValue(arr, arr[mid].year, index - 1);
    if(growthChecker_Dictatorship(arr)>growthChecker_Monarchy(arr))
    {
    cout<<"GROWTH RATE OF DICTATORSHIP IS FASTER ";
    }
else{
    cout<<"GROWTH RATE OF MONARCHY IS FASTER";
}

    return 0;
}

