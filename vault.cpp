#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Simple XOR encryption/decryption function
void xorEncryptDecrypt(string &data, char key) {
    for (size_t i = 0; i < data.size(); i++) {
        data[i] ^= key;
    }
}

int main() {
    string inputFile, encryptedFile = "encrypted.dat";
    char key = 'K';

    cout << "Enter input filename to encrypt: ";
    getline(cin, inputFile);

    ifstream fin(inputFile, ios::binary);
    if (!fin) {
        cout << "Error opening input file!" << endl;
        return 1;
    }

    // Read entire file content into a string
    string fileData((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
    fin.close();

    // Encrypt the file data
    xorEncryptDecrypt(fileData, key);

    // Write encrypted data to output file
    ofstream fout(encryptedFile, ios::binary);
    fout.write(fileData.c_str(), fileData.size());
    fout.close();

    cout << "File encrypted successfully into '" << encryptedFile << "'." << endl;

    // For verification, decrypt the file again and show preview
    ifstream fin2(encryptedFile, ios::binary);
    string encryptedData((istreambuf_iterator<char>(fin2)), istreambuf_iterator<char>());
    fin2.close();

    xorEncryptDecrypt(encryptedData, key);

    cout << "Decrypted content preview (first 100 chars):" << endl;
    cout << encryptedData.substr(0, 100) << endl;

    return 0;
}
