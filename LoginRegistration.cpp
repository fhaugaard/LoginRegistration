#include <iostream>
#include <cctype> 
#include <fstream>

using namespace std;

void registration(string user, string pwd){
    fstream file;
    file.open("Accounts.csv", ios::app);

    file << user + "," + pwd << endl;
    cout << "User has been registered!" << endl;
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
    string user = "Forrest";
    string pwd = "Password";
    login(user, pwd);
    return 0;
}