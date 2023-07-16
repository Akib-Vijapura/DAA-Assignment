/*
 Q2. An art student requires to enter the colours in hexadecimal. The computer gives the colours as a binary string. Write a C/CPP program to assist her to convert the binary string into a hexadecimal string for her assignment.
 
 Sample Input:
 00010000
 Sample Output:
 10
 
 Sample Input:
 00001111
 Sample Output:
 F

 */
#include <iostream>
#include <bitset>
#include <sstream>

class BinaryToHexConverter {
public:
    std::string binaryToHexadecimal(const std::string& binary) {
        // Convert binary to decimal
        std::bitset<8> bit(binary);
        int decimal = bit.to_ulong();

        // Convert decimal to hexadecimal
        std::stringstream stream;
        stream << std::hex << decimal;
        std::string hexadecimal = stream.str();

        return hexadecimal;
    }
};

int main() {
    
    std::string binary;
    std::cin >> binary;

    BinaryToHexConverter converter;
    std::string hexadecimal = converter.binaryToHexadecimal(binary);

    std::cout<< hexadecimal << std::endl;

    return 0;
}

