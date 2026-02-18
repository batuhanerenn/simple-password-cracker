# simple-password-cracker
# Simple Password Cracker (Brute Force)

This project demonstrates brute force password cracking in C++.

- Uses OpenSSL EVP for hashing (MD5)
- Tries all possible 4-character passwords
- Prints the time taken to crack

## Build
g++ main.cpp -lcrypto -o cracker

## Run
./cracker
