/*
 Q1. An adventurer returning from a long journey with a bag of treasure. The adventurer wants to sort the treasure to see what they have, so they decide to use quick sort to sort the items in their bag. The program then performs quick sort on an array of integers representing the treasure and prints out the sorted array. Finally, the adventurer is pleased with the sorted treasure and can now count their wealth.
 
 Sample Input:
 5 // Length of the array treasure
 10 5 40 2 40 // Treasure
 
 Sample Output:
 After sorting:
 2 5 10 40 40
 The adventurer is pleased with the sorted treasure and can now count their wealth.

 */

#include <iostream>
#include <vector>
using namespace std;

class TreasureSorter {
public:
    void quickSort(vector<int>& treasure, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(treasure, low, high);
            quickSort(treasure, low, pivotIndex - 1);
            quickSort(treasure, pivotIndex + 1, high);
        }
    }

    int partition(vector<int>& treasure, int low, int high) {
        int pivot = treasure[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (treasure[j] < pivot) {
                i++;
                swap(treasure[i], treasure[j]);
            }
        }
        swap(treasure[i + 1], treasure[high]);
        return i + 1;
    }
};

int main() {
    
    int length;
    cin >> length;

    vector<int> treasure(length);
    for (int i = 0; i < length; i++) {
        cin >> treasure[i];
    }

    TreasureSorter sorter;
    sorter.quickSort(treasure, 0, length - 1);

    cout<<" After sorting: "<<endl;
    for (int i = 0; i < length; i++) {
        cout << treasure[i] << " ";
    }
    cout << "\nThe adventurer is pleased with the sorted treasure and can now count their wealth." << ::endl;

    return 0;
}
