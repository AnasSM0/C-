#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

// Function to generate a random prime number
int generateRandomPrime() {
    int num;
    do {
        num = rand() % 100 + 50; // Adjust the range as needed
    } while (!isPrime(num));
    return num;
}

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
    for (size_t i = 0; i < message.length(); i++) {
        char c = message[i];
        int m = static_cast<int>(c);
        int cipher = 1;
        for (int j = 0; j < e; ++j) {
            cipher = (cipher * m) % n;
        }
        cout << cipher << " ";
    }
    cout << endl;
}

// Function to decrypt a ciphertext using RSA
string decrypt(const string& cipher, int d, int n) {
    string decryptedMessage = "";
    istringstream iss(cipher);
    int c;
    while (iss >> c) {
        int m = 1;
        for (int i = 0; i < d; ++i) {
            m = (m * c) % n;
        }
        decryptedMessage += static_cast<char>(m);
    }
    return decryptedMessage;
}

int main() {
    srand(static_cast<unsigned>(time(0))); // Seed for random number generation

    int p, q, e, d, n;

    // Generate random prime numbers
    p = generateRandomPrime();
    q = generateRandomPrime();

    n = p * q;
    int phi = (p - 1) * (q - 1);

    // Choose a suitable public exponent e
    e = 65537; // Common choice for e in practice

    // Calculate private exponent d
    d = modInverse(e, phi);

    cout << "Public key (e, n): (" << e << ", " << n << ")\n";
    cout << "Private key (d, n): (" << d << ", " << n << ")\n";

    // Example message
    string message = "HELLO";
    
    encrypt(message, e, n);

    // Example ciphertext
    string ciphertext = "475 354 648 803 648";
    string decryptedMessage = decrypt(ciphertext, d, n);
    cout << "Decrypted message: " << decryptedMessage << endl;

    return 0;
}

