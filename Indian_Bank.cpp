#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip> // Include the header for setprecision and fixed
#include <math.h>

using namespace std;

// Define a structure to hold the bank data
struct Bank_of_India {
    int year;
    double interest_rate;
    double inflation_rate;
};

double temp = 0.0; // Temporary variable to hold processed amount

// Function to calculate and return the money actually received after adding interest
double getCurrentAmount(Bank_of_India arr[], int year_invested, double amount_invested, int index) {
    double processed_amount = amount_invested;
    for (int i = year_invested; i < index; i++) {
        double interest = arr[i].interest_rate;
        processed_amount = processed_amount * (1.0 + (interest/100.0) );
    }
    temp = processed_amount; // Store processed amount in temp
    return processed_amount;
}

// Function to calculate and return the invested value after considering inflation
double getInvestedValue(Bank_of_India arr[], int year_invested, double amount_invested, int index) {
    double invested_Value = temp;
    double inflation = 0.0;
    for (int i = index - 1; i >= year_invested; i--) {
        inflation = arr[i].inflation_rate; // Update inflation rate
        invested_Value = invested_Value * (1.0 - (inflation/100));
    }
    return invested_Value;
}

int main() {
    Bank_of_India arr[100];
    ifstream mycsvfile("india.csv.csv");

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

    // Use std::fixed and std::setprecision to round off values to 2 decimal places
    cout << fixed << setprecision(2);
    cout << "Money Actually Received :  " << getCurrentAmount(arr, mid, amount_invested, index) << " INR "<<endl;
    cout << "Invested Value in Year of Investment: " << getInvestedValue(arr, mid, amount_invested, index) << " INR";

    return 0;
}
