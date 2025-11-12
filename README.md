# 🔐 Vigenère Cipher Encryption/Decryption (C++)

**Author:** Amaan Shaikh  
**Language:** C++  
**Type:** Personal Project  

---

## 🧠 Description
This project implements the **Vigenère cipher** in C++.  
It’s a console-based program designed to **encrypt** and **decrypt** messages using a **custom 26×26 Vigenère table** generated from a **keyed alphabet**.

> **Keyed Alphabet:** `KNIGHTFEWRYABCDJLMOPQSUVXZ`

---

## ✨ Features
- 🧩 Uses a **custom 26×26 Vigenère table**  
- 🔐 **Password-protected access**  
  - Main password to start the program  
  - Secondary password to change the encryption keyword  
- 📜 **Menu-driven interface** with options to:
  - Encrypt plaintext  
  - Decrypt ciphertext  
  - Enter and view plaintext  
  - Change encryption keyword  
  - Display the Vigenère table  
- 💾 *(Optional)* File I/O for saving and loading plaintext, ciphertext, and keywords

---

## 🎯 Purpose
The purpose of this project is to:

- Strengthen understanding of **C++ fundamentals** such as:
  - Classes, functions, loops, conditionals, and file I/O  
- Implement a **classical encryption algorithm** in a professional, structured way  
- Explore secure console input (using `_getch()`) and string handling techniques  

---

## ⚙️ How to Compile and Run
Make sure you have **MinGW** or another C++ compiler installed.

```bash
g++ Vigenere.cpp -o vigenere
.\vigenere
