#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

// Function to perform XOR operation on message with key
string encrypted_cipher(string &message, string &key)
{
    string encrypted_1 = "";
    int keyInd = 0;
    for (char c : message)
    {
        encrypted_1 += c ^ key[keyInd % key.length()];
        keyInd++;
    }
    return encrypted_1;
}

// Function to convert string to hexadecimal
string str_to_hex(const string &input)
{
    stringstream ss;
    for (char c : input)
    {
        ss << hex << setw(2) << setfill('0') << static_cast<int>(c) << " ";
    }
    return ss.str();
}

// Function to convert hexadecimal string to ASCII
string hex_to_str(const string &hexInput)
{
    stringstream ss(hexInput);
    string result;
    int value;
    while (ss >> hex >> value)
    {
        result += static_cast<char>(value);
    }
    return result;
}

int main()
{
    while (true)
    {

        // welcome message
        cout << "welcome to XOR cipher\n\n";

        string key;
        cout << "please Enter the secret key: ";
        cin >> key;

        cin.ignore(); // Clear the newline character from the input buffer

        cout << "1. Encryption" << endl;
        cout << "2. Decryption" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter your choice: " << endl;
        string choice;
        cin >> choice;

        string message;
        cin.ignore(); // Clear the newline character from the input buffer

        if (choice == "1")
        {
            cout << "---Encryption---" << endl;
            cout << " please Enter the plaintext message: ";
            getline(cin, message);

            // Encrypt the message using XOR cipher
            string encrypted = encrypted_cipher(message, key);
            cout << "Hexadecimal: " << str_to_hex(encrypted) << endl;
        }
        else if (choice == "2")
        {
            cout << "---Decryption---" << endl;
            cout << "please Enter the ciphertext in hexadecimal: ";
            getline(cin, message);

            // Convert hexadecimal message to ASCII
            string decrypted = hex_to_str(message);

            // Decrypt the message using XOR cipher
            string originalMessage = encrypted_cipher(decrypted, key);
            cout << "Plain text: " << originalMessage << endl;
        }
        else if (choice == "3")
        {
            cout << "Thanks for using the program." << endl;
            break;
        }

        else
        {
            cout << "Invalid choice. Please choose 1, 2, or 3.\n";
        }
    }

    return 0;
}
