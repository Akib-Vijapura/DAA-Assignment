/*
 2. Excel column label
 You are working to arrange the labels for your college in the excel sheet. You can't recall the title; you only recall the column number. Create a C programme in which the same is converted. Output a string.
 
 Input format:
 28
 Output format:
 AB
 */
#include <iostream>
#include <string>

class ExcelColumnTitle {
public:
    void excel_column_title(int columnNumber) {
        std::string label;

        while (columnNumber > 0) {
            int remainder = (columnNumber - 1) % 26;
            char ch = 'A' + remainder;
            label = ch + label;
            columnNumber = (columnNumber - 1) / 26;
        }

        std::cout << label << std::endl;
    }

    void run() {
        int columnNumber;
        std::cin >> columnNumber;

        excel_column_title(columnNumber);
    }
};

int main() {
    ExcelColumnTitle ect;
    ect.run();

    return 0;
}

