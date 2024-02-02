#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

// Function to calculate gcd using Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate modular inverse using Extended Euclidean Algorithm
int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;  // No modular inverse found
}

// Function to encrypt a message using RSA
void encrypt(const string& message, int e, int n) {
    cout << "Encrypted message: ";
    for (int i = 0; i < message.length(); i++) {
        char c = message[i];
        int m = static_cast<int>(c);
        int cipher = static_cast<int>(pow(m, e)) % n;
        cout << cipher << " ";
    }
    cout << endl;
}

// Function to decrypt a ciphertext using RSA
string decrypt(const string& cipher, int d, int n) {
    string message = "";
    stringstream ss(cipher);
    int c;
    while (ss >> c) {
        int m = static_cast<int>(pow(c, d)) % n;
        char ch = static_cast<char>(m);
        message += ch;
    }
    return message;
}

int main() {
    int p, q, e, d, n, phi;
    string message, cipher;
    char choice;

    cout << "Enter prime number p: ";
    cin >> p;

    cout << "Enter prime number q (not equal to p): ";
    cin >> q;

    n = p * q;
    phi = (p - 1) * (q - 1);

    cout << "Enter public exponent e (1 < e < " << phi << " and gcd(e, " << phi << ") = 1): ";
    cin >> e;

    while (gcd(e, phi) != 1) {
        cout << "Invalid e. Enter a value for e such that 1 < e < " << phi << " and gcd(e, " << phi << ") = 1: ";
        cin >> e;
    }

    d = modInverse(e, phi);

    cout << "Public key (e, n): (" << e << ", " << n << ")\n";
    cout << "Private key (d, n): (" << d << ", " << n << ")\n";
    cout << "phi(n): " << phi << endl;

    cout << "Do you want to encrypt (e) or decrypt (d) a message? ";
    cin >> choice;

    if (choice == 'e') {
        cout << "Enter the message to encrypt: ";
        cin.ignore();
        getline(cin, message);

        encrypt(message, e, n);
    } else if (choice == 'd') {
        cout << "Enter the ciphertext (space-separated integers): ";
        cin.ignore();
        getline(cin, cipher);

        string decryptedMessage = decrypt(cipher, d, n);
        cout << "Decrypted message: " << decryptedMessage << endl;
    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}

