#include <iostream>
using namespace std;

double bayesTheorem(double bOverA, double a, double b)
{
    return (bOverA)*a / b;
}

int main()
{
    cout << "Enter number of Test Cases: ";
    int t;
    cin >> t;
    while (t--)
    {
        double p_ba, pb, pa, p_ab;
        cout << "Enter Probability of B over A - P(B|A): ";
        cin >> p_ba;
        cout << "Enter Probability of A - P(A): ";
        cin >> pa;
        cout << "Enter Probability of B - P(B): ";
        cin >> pb;
        if(p_ba > 1 || pa > 1 || pb > 1) {
            cout<<"One or more values entered are incorrect"<<endl;
            continue;
        }
        p_ab = bayesTheorem(p_ba, pa, pb);
        p_ab > 1 ? cout << "Answer not feasible" << endl : cout << "Probability of A over B - P(B|A): " << p_ab << endl;
    }

    return 0;
}