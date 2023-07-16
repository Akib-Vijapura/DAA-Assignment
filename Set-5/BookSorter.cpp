/*
 Q2. A library with a large collection of books that needs to be sorted. The library staff decides to use merge sort to sort the books, and the program performs merge sort on an array of integers representing the books. Finally, the library staff is pleased with the sorted collection and can now easily find and organize the books.
 
 Sample Input:
 5 //Number of books
 13 60 2 89 65 //Array of books
 
 Sample Output:
 After sorting:
 2 13 60 65 89
 The library is pleased with the sorted books & can now organise.
 */

#include <iostream>
#include <vector>

using namespace std;

class BookSorter {
public:
    void mergeSort(vector<int>& books) {
        if (books.size() <= 1) {
            return;
        }

        int mid = books.size() / 2;
        vector<int> left(books.begin(), books.begin() + mid);
        vector<int> right(books.begin() + mid, books.end());

        mergeSort(left);
        mergeSort(right);
        merge(books, left, right);
    }

    void merge(vector<int>& books, const vector<int>& left, const vector<int>& right) {
        int i = 0;
        int j = 0;
        int k = 0;

        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) {
                books[k++] = left[i++];
            } else {
                books[k++] = right[j++];
            }
        }

        while (i < left.size()) {
            books[k++] = left[i++];
        }

        while (j < right.size()) {
            books[k++] = right[j++];
        }
    }
};

int main() {
    
    int numBooks;
    cin >> numBooks;

    vector<int> books(numBooks);
    for (int i = 0; i < numBooks; i++) {
        cin >> books[i];
    }

    BookSorter sorter;
    sorter.mergeSort(books);

    cout << "After sorting"<<endl;
    for (int i = 0; i < numBooks; i++) {
        cout << books[i] << " ";
    }
    cout << "The library is pleased with the sorted books & can now organise." << endl;

    return 0;
}

