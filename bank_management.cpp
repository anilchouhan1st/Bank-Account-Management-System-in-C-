#include <iostream>
#include <string>
#include<vector>
using namespace std;
class bank_account
{
private:
    string account_name;
    string account_number;
    string account_type;
    double Balance;
    string Saving;
    string Current;

public:
    
    void initialize()
    {

        cout << "Enter the Account holder's Name :" << endl;
        getline(cin,account_name);
        cout << "Enter the Account number :" << endl;
        cin >> account_number;
        cout << "Enter the Account Type (Saving/Current) :" << endl;
        cin >> account_type;
        if (account_type == "Saving" || account_type == "Current")
        {

        }
        else
        {
            cout << "\nIncorrect input \n Try again"<<endl;
           
        }
        cout << "Enter the Balance :" << endl;
        cin >> Balance;
    }

public:
    void deposit()
    {
        int amount;
        cout << "Enter the deposit amount" << endl;
        cin >> amount;
        if (amount > 0)
        {
            Balance += amount;
            cout << "Total balance is " << Balance << endl;
        }
    }

public:
    void Withdraw()
    {
        int amount;
        cout << "Enter the Withdraw amount" << endl;
        cin >> amount;
        if (amount > 0 && Balance > amount)
        {
            Balance -=amount;
            cout << "Total remaining balance is " << Balance << endl;
        }
        else{
            cout<<"Not enought money"<<endl;
        }
    }

public:
    void Display()
    {
        cout << "Account holder's Name :" << account_name << endl;
        cout << "Account number :" << account_number << endl;
        cout << "Account Type (Saving/Current) :" << account_type << endl;
        cout << "Balance :" << Balance << endl;
    }

string getAccountNumber(){
        return account_number;
    }
};

vector<bank_account> Naccount;
int main()
{
    int choice;
    class bank_account mybank;
    // mybank.initialize();

    do
    {
        cout << "\n<*****MENU*****>" << endl;
        cout<<"1.Create New Account"<<endl;
        cout << "2.Deposit" << endl;
        cout << "3.Withdraw" << endl;
        cout << "4.Display" << endl;
        cout << "5.Exit" << endl;
        cout << "Enter your choice" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            bank_account obj1;
            cin.ignore();
            obj1.initialize();
            Naccount.push_back(obj1);
            cout << "Account created successfully\n";
            break;

        }
        case 2:
        {
            mybank.deposit();
            break;
        }
        case 3:
        {
            mybank.Withdraw();
            break;
        }
        case 4:
        {
            if(Naccount.empty()){
                cout<<"There is no account present in database"<<endl;
                break;
            }
           string accN;
           cout<<"Enter Account number: "<<endl;
           cin>>accN;
           bool found = false;
           for(auto acc:Naccount){
            if(acc.getAccountNumber()==accN){
                acc.Display();
                found = true;
                break;
            }
           }
           if(!found){
            cout<<"*****NO ACCOUNT FOUND*****"<<endl;
           }
            
            break;
        }
        case 5:
        {
            cout << "Exit...Thank you!!" << endl;
            break;
        }
        default:
        {
            cout << "Invalid";
            break;
        }
        }
    } while (choice != 4);

    return 0;
}