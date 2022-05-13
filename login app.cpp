#include <iostream>
#include <istream>
#include <fstream>
#include <string>
using namespace std;
void login();
void registr();
void change();

int main()
{
    int choice;
    cout << "Welcome to Login App!" << endl;
    cout << "1-Login \n" ;
    cout << "2-Register \n";
    cout << "3-Change password \n";
    cout << "4-Exit\n";
    cout << "Enter your choice \n";

    cin>>choice;
    switch(choice)
    {
    case 1:{
        login();
        break;
    }
    case 2:{
        registr();
        break;
    }
    case 3:{
        change();
        break;
    }
    case 4:{
        cout<<"Thanks for using Login App \n";
        break;
    }
    default:
        cout<<"Wrong choice \n";
        main();
    }
    }
 void login()
 {
     string username, password;
     cout<<"Enter your username\n";
     cin>>username;
     cout<<"Enter your password \n";
     cin>>password;
     cout<<"Successful login, welcome"<<" "<<username;
     cout<<"Failed login. Try again.";


 }
 void registr()
 {
     string username, email , phoneNumber ,password , rpassword;
     cout<<"Enter the username\n";
     cin>>username;
     cout<<"Enter the password\n";
     cout<<"The password must be at least 10 characters and 5 or more unique characters use at least 3 of the lowercase\nuppercase,numeric or use special characters @#%$+_-/;:!,? No spaces allowed \n";
     cin>>password;
     cout<<"repeat the password\n";
     cin>>rpassword;
     while(password!=rpassword){
            cout<<"There is wrong on the password\n";
            cout<<"repeat the password agin\n";
            cin>>rpassword;
     }
     cout<<"Enter the number\n";
     cin>>phoneNumber;
     cout<<"Enter the email\n";
     cin>>email;



 }
void change()
{
    string oldPassword , newPassword , nPassword;
    cout<<"Enter the old password \n";
    cin>>oldPassword;
    cout<<"Enter the new password \n";
    cin>>newPassword;
    cout<<"Enter the new password agin\n";
    cin>>nPassword;
    if(newPassword==nPassword){
            //encrypt the pass and save it in file


    }else{
        cout<<"There is a wrong try again :(< ";
    }



}
