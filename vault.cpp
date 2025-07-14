#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void encryptDecrypt(string& data, char key) {
    for (int i = 0; i < data.size(); i++) {
        data[i] ^= key; // simple XOR encryption/decryption
    }
}

int main() {
    string filename = "secret.txt";
    string data;

    cout << "Enter data to encrypt: ";
    getline(cin, data);

    encryptDecrypt(data, 'K'); // 'K' is the encryption key

    // Write encrypted data to file
    ofstream outFile(filename, ios::binary);
    outFile << data;
    outFile.close();

    cout << "Data encrypted and saved to " << filename << endl;

    // Now read and decrypt
    ifstream inFile(filename, ios::binary);
    string encryptedData((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
    inFile.close();

    encryptDecrypt(encryptedData, 'K'); // decrypt

    cout << "Decrypted data: " << encryptedData << endl;

    return 0;
}
