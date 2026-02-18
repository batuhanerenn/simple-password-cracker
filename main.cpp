#include <iostream>
#include <string>
#include <chrono>
#include "hashing.h"   //md5() function

using namespace std;

const string CHARSET = "abcdefghijklmnopqrstuvwxyz0123456789";

void bruteForce(const string& targetHash) {
    auto start = chrono::high_resolution_clock::now();
    int numberAttempts = 0;

    string attempt;

    for (char a : CHARSET)
    for (char b : CHARSET)
    for (char c : CHARSET)
    for (char d : CHARSET) {
        attempt = {a, b, c, d};
        numberAttempts++;

        if (md5(attempt) == targetHash) {
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed = end - start;

            cout << "Password found: " << attempt << endl;
            cout << "Time taken: " << elapsed.count() << " seconds, Number of attempts: "<<numberAttempts<<endl;
            
            return;
        }
    }

    cout << "Password not found.\n";
}

int printMenu(){
    cout << "Select what you want to do"<<endl
    << "(1) Hash your 4 digit password (only upper case and numbers a-z, 0-9)"<<endl
    << "(2) Crack the hashed password"<<endl
    << "(3) Exit"<<endl;
    int choice; cin >> choice;
    while (choice<1 || choice > 3 ){
        cout << "invalid choice"<<endl;
        cin >> choice;
    }
    return choice;
}
bool checkInput (const string& passwd){
    if (passwd.size() != 4)
        return false;
    for (int i =0; i< passwd.size(); i++){
        bool found = false;
        // if char is not found in char set
        for (int j =0; j< CHARSET.size(); j++){
            if (passwd[i] == CHARSET[j]){
                found = true;
                break;
            }
        }
        if (found == false)
            return false;
    }
    return true;
    
}


int main() {
    int choice = printMenu();
    while (choice!=3){
        if (choice == 1){
            cout << "Please enter a password to encrypt:"<<endl;
            string passwd; cin >> passwd;
            while (!checkInput(passwd)){
                cout << "This password is not supported yet."<<endl
                     << "Please enter a supported password:"<<endl;
                cin >> passwd;
            }
            string yourHash = md5(passwd);
            cout << "Your hash is:"<<endl
                 << yourHash<<endl
                 << "Please copy your hash and continue with step 2."<<endl
                 << "Press Enter to display the menu again"<<endl;
                 cin.ignore();
                 cin.get();
        }
        if (choice == 2){
            cout << "Please enter your hash to crack it with bruteforce: ";
            string crackHash; cin >> crackHash;
            bruteForce(crackHash);
            cout << "Press Enter to display the menu again"<<endl;
            cin.ignore();
            cin.get();
        }



        choice = printMenu();
    }



    return 0;
}
