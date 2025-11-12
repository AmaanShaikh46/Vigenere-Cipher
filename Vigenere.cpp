#include <iostream>
#include <limits>
#include <conio.h>
using namespace std;


string encrypt(string plaintext, string keyword, char table[26][26]) {
    string ciphertext = "";
    int keyLen = keyword.length();
    int j = 0;

    for(char c : plaintext) {
        if(c >= 'A' && c <= 'Z') {       //uppercase letters
            int row = keyword[j % keyLen] - 'A';
            int col = c - 'A';
            ciphertext += table[row][col];
            j++;
        } else if(c >= 'a' && c <= 'z') { //lowercase letters
            int row = toupper(keyword[j % keyLen]) - 'A';
            int col = toupper(c) - 'A';
            ciphertext += table[row][col];
            j++;
        } else {
            ciphertext += c;
        }
    }
    return ciphertext;
}

string getHiddenInput() {
    string pass = "";
    char ch;
    while (true) {
        ch = _getch();
        if (ch == 13) break;
        else if (ch == 8) {
            if (!pass.empty()) {
                pass.pop_back();
                cout << "\b \b";
            }
        } else {
            pass += ch;
            cout << '*';
        }
    }
    return pass;
}


string decrypt(string ciphertext, string keyword, char table[26][26]) {
    string plaintext = "";
    int keyLen = keyword.length();
    int j = 0;

    for(char c : ciphertext) {
        if(c >= 'A' && c <= 'Z') {
            int row = toupper(keyword[j % keyLen]) - 'A';
            int col;
            for(col = 0; col < 26; col++) if(table[row][col] == c) break;
            plaintext += char('A' + col);
            j++;
        } else if(c >= 'a' && c <= 'z') {
            int row = toupper(keyword[j % keyLen]) - 'A';
            int col;
            for(col = 0; col < 26; col++) if(table[row][col] == toupper(c)) break;
            plaintext += char('a' + col);
            j++;
        } else {
            plaintext += c;
        }
    }
    return plaintext;
}


void decryptMenu(string keyword, char table[26][26], string ciphertext) {
    int decryptOption;
    cout << "\nDecrypt Menu:";
    cout << "\n  1. Enter ciphertext manually";
    cout << "\n  2. Decrypt existing ciphertext in memory";
    cout << "\nEnter your choice: ";
    cin >> decryptOption;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch(decryptOption) {
        case 1: {
            string inputCipher;
            cout << "\nEnter ciphertext to decrypt: ";
            getline(cin, inputCipher);
            string decryptedText = decrypt(inputCipher, keyword, table);
            cout << "\nDecrypted plaintext: " << decryptedText;
            break;
        }
        case 2:
            if(ciphertext.empty()) {
                cout << "\nNo ciphertext available in memory! Encrypt something first.";
            } else {
                string decryptedText = decrypt(ciphertext, keyword, table);
                cout << "\nDecrypted plaintext from memory: " << decryptedText;
            }
            break;
        default:
            cout << "\nInvalid option. Returning to main menu.";
    }
}



int main(){
    int options;
string password = "";
string keyPass = "Sarkd1297";
string keyword = "Knight";
string plaintext = "";
string ciphertext = "";
string keyedAlphabet = "KNIGHTFEWRYABCDJLMOPQSUVXZ";
char vigenereTable[26][26];
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            vigenereTable[i][j] = keyedAlphabet[(i + j) % 26];
        }
    }
      cout << "\nEnter Password: ";
password = getHiddenInput();


if(password!="NightFury"){
    cout<<"\n--------------Access Denied!--------------";
    return 0;
}else{
cout<<"\n\n!--------------Access Granted--------------!";
}
cout<<"\n\nWelcome back Amaan!";
while(true) {
cout<<"\n\n==VIGENÈRE CIPHER PROGRAM==";
cout<<"\n   1. Encrypt plaintext";
cout<<"\n   2. Decrypt ciphertext";
cout<<"\n   3. Enter plaintext";
cout<<"\n   4. View plaintext";
cout<<"\n   5. Change keyword (with a key-change password)";
cout<<"\n   6. Show Vigenère table";
cout<<"\n   7. Exit\n";
cout << "\nEnter your choice: ";
cin >> options;
cin.ignore();
    switch(options) {
         case 1:
            if(plaintext.empty()) {
    cout << "\nNo plaintext entered! Please enter plaintext first.";
} else {
    ciphertext = encrypt(plaintext, keyword, vigenereTable);
    cout << "\nCiphertext: " << ciphertext;
}        break;


         case 2:
          decryptMenu(keyword, vigenereTable, ciphertext);
         break;

         case 3:
             cout << "\nEnter plaintext: ";
             getline(cin, plaintext);
         break;


         case 4:
             cout << "\nPlaintext: " << (plaintext.empty() ? "[No plaintext entered]" : plaintext);
         break;


         case 5: {
             cout << "\nEnter key-change password: ";
             string inputKeyPass;
             cin >> inputKeyPass;
                if(inputKeyPass == keyPass) {
                    cout << "\nEnter new keyword: ";
                    cin.ignore();
                    getline(cin, keyword);
                    cout << "\nKeyword updated successfully!";
                }else{
                    cout << "\nIncorrect password. Access denied.";
                }
         break;
            }


         case 6:
    cout << "\nVigenère Table:\n\n   ";
    for(int k = 0; k < 26; k++) cout << char('A' + k) << " ";
    cout << "\n";

    for(int i = 0; i < 26; i++) {
        cout << char('A' + i) << "  ";
        for(int j = 0; j < 26; j++) {
            cout << vigenereTable[i][j] << " ";
        }
        cout << "\n";
    }
         break;


         case 7:
             cout << "\nExiting program. Goodbye!";
                return 0;


         default:
             cout << "\nInvalid option. Please try again.";
        }



}
return 0;
}

