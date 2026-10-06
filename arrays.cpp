#include <iostream>

int main() {
    int arr[5] = {1, 2, 3};
    int arr2[5] = {0};
    int arr3[] = {1,2,3};

    // print all elements of the arrays
    std::cout << "arr: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    std::cout << "arr2: ";
    for (int x : arr2) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    std::cout << "arr3: ";
    for (int x : arr3) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    int length = sizeof(arr) / sizeof(arr[0]);

    return 0;
}