#include <iostream>
#include <vector>
using namespace std;

// 1. Print 1 to N
void print1ToN(int n) {
    if (n == 0) return;
    print1ToN(n - 1);
    cout << n << " ";
}

// 2. Print N to 1
void printNTo1(int n) {
    if (n == 0) return;
    cout << n << " ";
    printNTo1(n - 1);
}

// 3. Factorial
int factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

// 4. Sum of first N numbers
int sumN(int n) {
    if (n == 0) return 0;
    return n + sumN(n - 1);
}

// 5. Fibonacci
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// 6. Generate all subsets (Backtracking)
void generateSubsets(int index, vector<int>& arr, vector<int>& current) {
    if (index == arr.size()) {
        for (int x : current) cout << x << " ";
        cout << endl;
        return;
    }

    // Include
    current.push_back(arr[index]);
    generateSubsets(index + 1, arr, current);

    // Exclude
    current.pop_back();
    generateSubsets(index + 1, arr, current);
}

// 7. Permutations (Backtracking)
void permutations(vector<int>& arr, int index) {
    if (index == arr.size()) {
        for (int x : arr) cout << x << " ";
        cout << endl;
        return;
    }

    for (int i = index; i < arr.size(); i++) {
        swap(arr[index], arr[i]);
        permutations(arr, index + 1);
        swap(arr[index], arr[i]); // backtrack
    }
}

int main() {
    int n = 5;

    cout << "Print 1 to N: ";
    print1ToN(n);

    cout << "\nPrint N to 1: ";
    printNTo1(n);

    cout << "\nFactorial: " << factorial(n);

    cout << "\nSum of N: " << sumN(n);

    cout << "\nFibonacci (n=6): " << fibonacci(6);

    cout << "\n\nSubsets:\n";
    vector<int> arr = {1, 2, 3};
    vector<int> current;
    generateSubsets(0, arr, current);

    cout << "\nPermutations:\n";
    permutations(arr, 0);

    return 0;
}
