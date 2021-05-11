#include <iostream>
#include <string.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;

enum TYPEOFACCOUNT
{
    currentAccount,
    savingAccount
};

class SavAccount;
class CurrAccount;

class Account
{
protected:
    string accNumber;
    TYPEOFACCOUNT typeOfAcc;
    string holderName;
    double accBalance;
public:
    void getDetails()
    {
        string aNum, hName;
        char temp;
        cout << "Please enter your account number: ";
        getline(cin, aNum);
        cout << "Please choose an account type" << endl
             << "Savings Account[s]"
             << "\nCurrent Account[c]"
             << "\nYour choice[s/c]: ";
        cin >> temp;
        cout << "Please enter your name: ";
        getline(cin, hName);
        temp == 's' ? setDetails(aNum, TYPEOFACCOUNT::savingAccount, hName) : setDetails(aNum, TYPEOFACCOUNT::savingAccount, hName);
    }
    void setDetails(string aNum, TYPEOFACCOUNT t, string hName)
    {
        accNumber = aNum;
        typeOfAcc = t;
        holderName = hName;
    }
    TYPEOFACCOUNT getType()
    {
        return typeOfAcc;
    }
    string getAccNumber()
    {
        return accNumber;
    }
    string getName()
    {
        return holderName;
    }
    void printDetails()
    {
        cout << endl
             << "Account Details:" << endl;
        cout << "Holder Name: " << holderName;
        cout << "Account Number: " << accNumber;
        cout << "Account Balance: " << accBalance;
        typeOfAcc == TYPEOFACCOUNT::currentAccount ? cout<<"Current Account" : cout<<"Savings Account";
    }
    Account()
    {
        getDetails();
    }
    ~Account() {}
};

class SavAccount : public Account
{
public:
    void addDeposit(double amount)
    {
        accBalance += amount;
    }
    void displayBalance() const
    {
        cout << "Balance = " << accBalance << endl;
    }
    
};

class CurrAccount : public Account
{

public:
    void addDeposit(double amount)
    {
        accBalance += amount;
    }
    void displayBalance() const
    {
        cout << "Balance = " << accBalance << endl;
    }
    void printDetails()
    {
        cout << endl
             << "Account Details:" << endl;
        cout << "Holder Name: " << holderName;
        cout << "Account Number: " << accNumber;
        cout << "Account Balance: " << accBalance;
        cout << "Type of account: Current Account";
    }
};

int main()
{
}