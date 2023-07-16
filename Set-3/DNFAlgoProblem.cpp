/*
 Q1.
 Given an array nums with n objects coloured red, white, or blue, sort them in place so that objects of the same colour are adjacent, with the colours in the order red, white, and blue.We will use the integers 0, 1 and 2 to represent the colours red, white and blue respectively.
 
 Sample Input:
 6 //Length of Array
 2 0 2 1 1 0 //Input Array
 
 Sample Output:
 001122
 */
#include <iostream>
#include <vector>

class FlagSorter {
public:
    void sortColors(std::vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                std::swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                std::swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

int main() {
    
    int n;
    std::cin>>n;
    std::vector<int> nums(n);

    for (int i = 0 ; i < n ;i++){
        std::cin>>nums[i];
    }
    
    FlagSorter fs;
    fs.sortColors(nums);

    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

