/*
 Q2. Given two strings ransom note and magazine, return true if ransom note can be constructed by using the letters from the magazine and false otherwise.Each letter in the magazine can only be used once in ransom note.
 
 Sample Input:
 aab //Ransom Note
 ab //Magazine
 
 Sample Output:
 false
 
 Sample Input:
 aa
 aab
 Sample Output:
 true
 */
#include <iostream>
#include <unordered_map>

class RansomNoteChecker {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        std::unordered_map<char, int> charCount;

        // Count the frequency of characters in the magazine
        for (char ch : magazine) {
            charCount[ch]++;
        }

        // Check if the ransom note can be constructed
        for (char ch : ransomNote) {
            if (charCount[ch] > 0) {
                charCount[ch]--;
            } else {
                return false;
            }
        }

        return true;
    }
};

int main() {
    std::string ransomNote;
    std::string magazine;

    // Get input from the user
    std::cin>>ransomNote;
    std::cin>>magazine;

    RansomNoteChecker rnc;
    bool result = rnc.canConstruct(ransomNote, magazine);

    std::cout << (result ? "true" : "false") << std::endl;

    return 0;
}

