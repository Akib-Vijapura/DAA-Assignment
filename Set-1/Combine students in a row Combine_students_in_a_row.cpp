/*
 1. Combine students in a row
 Two rows of students are seated in a class, a teacher notices. She also observes that there might be room for the second-row's students to take seats in the first row. She needs your assistance to force every student to sit in the front row. Help her to do the same by providing a C program given the number of students in each row followed by the students.

 Input format:
 3
 1 2 3
 3
 2 5 6
 Output format:
 1 2 3 2 5 6

 */

#include <iostream>
#include <vector>

class CombineStudents {
public:
    void combineStudents(vector<int>& v1, vector<int>& v2) {
        for (int i = 0; i < v2.size(); i++) {
            v1.push_back(v2[i]);
        }
        // v1.insert(v1.end(),  make_move_iterator(v2.begin()) , make_move_iterator(v2.end()));
    }

    void run() {
        vector<int> row1;
        vector<int> row2;

        // Taking first row input
        int n;
        cin >> n;

        while (n--) {
            int x;
            cin >> x;
            row1.push_back(x);
        }

        // Taking second row input
        int m;
        cin >> m;

        while (m--) {
            int x;
            cin >> x;
            row2.push_back(x);
        }

        combineStudents(row1, row2);

        // Printing row1
        for (auto index : row1)
            cout << index << " ";

        cout << endl;
    }
};

int main() {
    CombineStudents cs;
    cs.run();

    return 0;
}

