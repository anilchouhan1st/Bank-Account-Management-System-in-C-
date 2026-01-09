#include <iostream>
#include <string>
#include<vector>
#include<ctype.h>
#include<algorithm>
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
    string Pin;

public:
    
    void initialize()
    {

        cout << "Enter the Account holder's Name : " << endl;
        getline(cin,account_name);
        cout << "Enter the Account number : " << endl;
        cin >> account_number;
        cout << "Enter the Account Type (Saving/Current) : " << endl;
        cin >> account_type;
        transform(account_type.begin(),account_type.end(),account_type.begin(),::tolower);
        while(account_type != "saving" &&  account_type != "current"){
            cout << "\nIncorrect input .Try again\n"<<endl;
            cout << "Enter the Account Type (Saving/Current) :" << endl;
            cin >> account_type;
        transform(account_type.begin(),account_type.end(),account_type.begin(),::tolower);
        }
        cout<<"Set 4-Digit PIN : "<< endl;
        cin>>Pin;
        while(Pin.size()!=4){
            cout<<"PIN must be 4-Digit. Try again"<<endl;
            cin>>Pin;
        }
        cout << "Enter the Balance : " << endl;
        cin >> Balance;
    }

public:
    void Deposit()
    {
        int amount;
        cout << "Enter the Deposit amount" << endl;
        cin >> amount;
        if (amount > 0)
        {
            Balance += amount;
            cout<<"Rs."<<amount<<" is Deposit into your account Successfull "<<endl;
            cout << "Total balance is Rs. " << Balance << endl;
        }
    }

public:
    void Withdraw()
    {
        int amount;
        cout << "Enter the Withdraw amount" << endl;
        cin >> amount;
        if (amount > 0 && Balance >= amount)
        {
            Balance -=amount;
            cout<<"Rs."<<Balance<<" is Withdraw from your account Successfull "<<endl;
            cout << "Total remaining balance is Rs." << Balance << endl;
        }
        else{
            cout<<"Not enought money"<<endl;
        }
    }

public:
    void Display()
    {
        cout << "Account holder's Name : " << account_name << endl;
        cout << "Account number : " << account_number << endl;
        cout << "Account Type (Saving/Current) : " << account_type << endl;
        cout << "Balance : Rs. " << Balance << endl;
    }

    string getAccountNumber(){
        return account_number;
    }
public:
    string getPIN(){
        return Pin;
    }
    
};
int FindAccountIndex(vector<bank_account> &account,string accN){
        int found = -1;
     for(int i =0;i<account.size();i++){
         
         
            if(account[i].getAccountNumber()==accN){
                found = 1;
               return i;
            }
           }
           if(found==-1){
            cout<<"*****NO ACCOUNT FOUND*****"<<endl;
           }
        return found;    
    }

    int getIntputFromUser(vector<bank_account> &account){
          if(account.empty()){
                cout<<"There is no account present in database"<<endl;
                return -1;
            }
           string accN;
           cout<<"Enter Account number: "<<endl;
           cin>>accN;
           int IDex = FindAccountIndex(account,accN);
    return IDex; 
}
bool verifingPin(bank_account &acc){
    string entered;
    int tries = 3;
    while(tries--){
        cout<<"Enter 4-Digit PIN "<<endl;
        cin>>entered;
        if(entered==acc.getPIN()){
            return true;
        }
        else{
            cout<<"Wrong PIN."<<endl;
            cout<<tries<<" Tries remaining"<<endl;
        }
    }
    cout<<"Account got locked "<<endl;

    return false;
}
int main()
{
    vector<bank_account> Naccount;
    int choice;
    class bank_account mybank;
    // mybank.initialize();

    do
        {
        
        cout<<"\n******* WELCOME TO AC INTERNATIONAL BANK *******"<<endl;
        cout << "\n<***** MENU *****>" << endl;
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
           int IDex = getIntputFromUser(Naccount);
           if(!verifingPin(Naccount[IDex])){
            break;
           }
           if(IDex!=-1) {
            Naccount[IDex].Deposit();
           }
            break;
        }
        case 3:
        {
           int IDex = getIntputFromUser(Naccount);
           if(!verifingPin(Naccount[IDex])){
            break;
           }
           if(IDex!=-1) {
            Naccount[IDex].Withdraw();
           }
            break;
        }
        case 4:
        {
            int IDex = getIntputFromUser(Naccount);
            if(!verifingPin(Naccount[IDex])){
            break;
           }
           if(IDex!=-1) {
            Naccount[IDex].Display();
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
    } while (choice != 5);

    return 0;
}