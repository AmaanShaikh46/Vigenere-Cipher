Vigenere Cipher (C++)

This project is a console-based implementation of the Vigenere cipher in C++.
It uses a custom keyed alphabet to generate a 26x26 cipher table and provides
menu options for encryption, decryption, viewing plaintext, changing the keyword,
and displaying the Vigenere table.

Keyed Alphabet:
KNIGHTFEWRYABCDJLMOPQSUVXZ

Features:
- Custom 26x26 Vigenere table
- Password required to start the program
- Secondary password required to change the encryption keyword
- Menu-driven interface
- Encrypt and decrypt text (supports uppercase and lowercase)
- Enter and view plaintext
- Display the full Vigenere table
- Hidden password input using _getch()
- Passwords are not stored in the code and are read from environment variables

How it works:
The program generates a 26x26 table based on the keyed alphabet and applies the
Vigenere cipher rules for both encryption and decryption. Passwords are read from
environment variables instead of being stored in the source code.

Requirements:
- A C++ compiler (MinGW, MSYS2 gcc, or any recent compiler)
- Windows PowerShell or CMD (Linux/macOS also supported)

Setting Environment Variables (Required):

Windows PowerShell (temporary for the current session):
    $env:VIGENERE_PASS="YOUR_PASSWORD"
    $env:VIGENERE_KEYPASS="YOUR_KEYCHANGE_PASSWORD"

Windows CMD (permanent until changed):
    setx VIGENERE_PASS YOUR_PASSWORD
    setx VIGENERE_KEYPASS YOUR_KEYCHANGE_PASSWORD

Linux/macOS (shell session):
    export VIGENERE_PASS="YOUR_PASSWORD"
    export VIGENERE_KEYPASS="YOUR_KEYCHANGE_PASSWORD"

Note:
After using setx on Windows CMD, close and reopen the terminal so the environment
variables load correctly.

Compiling the Program:
    g++ Vigenere.cpp -o vigenere

Running the Program:

PowerShell:
    .\vigenere

CMD:
    vigenere.exe

Project Purpose:
This project was built to practice classical encryption algorithms, character-
based table manipulation, secure input handling, and to improve C++ fundamentals.

License:
MIT License
