/*
 Q3. Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1. Assume all the inputs are lowercase.
 
 Sample Input:
 elephant
 
 Sample Output:
 The first unique character is l
 
 Sample Input:
 aabbcc
 
 Sample Output:
 -1
 */

#include <iostream>
#include <string>
#include <unordered_map>
using namespace::std;

class FirstUniqueCharacterFinder {
public:
    int findFirstUniqueCharacter(const std::string& s) {
        std::unordered_map<char, int> charCount;

        // Count the frequency of characters
        for (char ch : s) {
            charCount[ch]++;
        }

        // Find the first non-repeating character
        for (int i = 0; i < s.length(); i++) {
            if (charCount[s[i]] == 1) {
                return i;
            }
        }

        return -1;  // No non-repeating character found
    }
};

int main() {
    
    string s;
    cin>>s;

    FirstUniqueCharacterFinder finder;
    int index = finder.findFirstUniqueCharacter(s);

    if (index != -1) {
        std::cout << "The first unique character is " << s[index] << std::endl;
    } else {
        cout<<-1<<endl;
    }

    return 0;
}

