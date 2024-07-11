#include <iostream>
#include <cctype> 
#include <fstream>

using namespace std;

void registration(){
    string user, pwd;
    string pwd1 = " ";
    cout << "Please enter a username you will remember: ";
    cin >> user;
    

    while(pwd != pwd1){
        cout << "Please enter a password: ";
        cin >> pwd;
        

        cout << "Please confirm your password: ";
        cin >> pwd1;
  

        if(pwd != pwd1){
            cout << "The password does not match! Please try again." << endl;
        }
    }

    fstream file;
    file.open("Accounts.csv", ios::app);

    file << user + "," + pwd << endl;
    cout << user <<" has been registered!" << endl;
    file.close();
}

bool login(string user, string pwd){
    fstream file;
    file.open("Accounts.csv");
    string line;

    string accountInfo = user + "," + pwd;

    if(file.is_open()){
        while(getline(file, line)){
            if(line == accountInfo){
                cout << "Login successful!" << endl;
                return true;
            }
        }
        file.close();
    }
    return false;
}

int main(){
    bool init = true;
    int x;
    string user, pwd;
    while(init){
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "Please enter either 1 or 2: ";
        cin >> x;
        cout << endl;


        if(x == 1){
            cout << "Please enter your username: ";
            cin >> user;
            cout << "Please enter your password: ";
            cin >> pwd;
            if(login(user, pwd)){
                init = false;
            }
            else{
                cout << "User does not exist! Please register a new account!" << endl;
                registration();
                init = false;
            }
        }
        else if(x == 2){
            registration();
            init = false;
        }
    }

    return 0;
}