/*
 3. Compare the fibonacci
 Your university's DAA course requires you to distinguish between recursive and iterative code. You find the Fibonacci series fascinating. Create some C code to show the iterative and recursive processes for the aforementioned.
 you can make use of additional functions
 
 Input format:
 3
 Output format:
 0 1 1
 0 1 1
 */
#include <iostream>
#include <vector>

class Fibonacci {
public:
    void printFibonacciIterative(int n) {
        std::vector<int> ans = {0, 1};
        for (int i = 2; i < n; i++) {
            int nextFib = ans[i - 1] + ans[i - 2];
            ans.push_back(nextFib);
        }

        for (int i : ans) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    int printFibonacciRecursive(int n) {
        if (n <= 1) {
            return n;
        }
        return printFibonacciRecursive(n - 1) + printFibonacciRecursive(n - 2);
    }

    void run() {
        int n;
        std::cin >> n;
        printFibonacciIterative(n);
        std::cout << printFibonacciRecursive(n) << std::endl;
        std::cout << std::endl;
    }
};

int main() {
    Fibonacci fib;
    fib.run();

    return 0;
}

