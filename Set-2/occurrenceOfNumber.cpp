/*
 Q1. Given a sorted array in non-decreasing order, apply an efficient search technique to determine the first and last occurrence of a target number given. If not found, return -1, -1. Given the code with time complexity O(n), convert it into efficient form[O(logn)].
 
 Sample Input 1
 6 8
 5 7 7 8 8 10
 
 Sample Output 1
 34
 */

#include <iostream>
#include <vector>
#include <utility>

class SearchRange {
public:
    std::pair<int, int> search(const std::vector<int>& arr, int target) {
        int first = -1, last = -1;
        int low = 0, high = arr.size() - 1;

        // Find the first occurrence
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                first = mid;
                high = mid - 1;  // Look in the left subarray for earlier occurrences
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // Reset low and high for finding the last occurrence
        low = 0;
        high = arr.size() - 1;

        // Find the last occurrence
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                last = mid;
                low = mid + 1;  // Look in the right subarray for later occurrences
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return std::make_pair(first, last);
    }
};

int main() {
    int n, target;
    std::cin >> n >> target;
    std::vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    SearchRange sr;
    std::pair<int, int> result = sr.search(arr, target);
    std::cout << result.first << " " << result.second << std::endl;

    return 0;
}

