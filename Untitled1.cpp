#include <iostream>
#include <iomanip>
using namespace std;

//Function prototypes
double calculateCharge(double, int);

const double                      //Rates per 500 miles shipped
RATE1 = 3.10,                     //For pkgs weighing <= 2kg
RATE2 = 4.20,                     //For pkgs > 2kg but  <= 6kg
RATE3 = 5.30,                     //For pkgs > 6kg but <= 10kg
RATE4 = 6.40;                     //For pkgs > 10kg

int main()
{
    double weight, cost;
    int miles;
    cout << fixed << showpoint << setprecision(2);
    cout << "Fast Freight Shipping Company \n" << "Pakage Shipping Charges Calculator\n\n";
    cout << "Enter Package weight in kg (or 0 to exit) :";
    cin >> weight;

    while(weight>0)
    {
        cout << "Enter shipping distance in miles:";
        cin >> miles;
        cost = calculateCharge(weight, miles);
        cout << "\nShipping cost : $" << cost << endl << endl;
        cout << "Enter Package weight in kg (or 0 to exit) :";
        cin >> weight;
    }

    return 0;
}//end of main function

double calculateCharge(double wt, int mi)
{
    double RatePer500 = 0,            //Rate per 500 mi. shipped
        shippingCharge;

    if (wt <= 2.0)
        RatePer500 = RATE1;
    else if (wt <= 6.0)
        RatePer500 = RATE2;
    else if (wt <= 10.0)
        RatePer500 = RATE3;
    else
        RatePer500 = RATE4;

    shippingCharge = RatePer500 * (mi / 500.0);
    return shippingCharge;

}//end of calculateCharge function
