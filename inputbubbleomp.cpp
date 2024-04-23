#include <iostream>
#include <vector>
#include <cstdlib>  // For rand()
#include <ctime>    // For clock()
#include <omp.h>    // OpenMP

// Sequential Bubble Sort
void bubbleSortSequential(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Parallel Bubble Sort using OpenMP
void bubbleSortParallel(int* arr, int size) {
    #pragma omp parallel for
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    int arr[size];
    std::cout << "Enter " << size << " integers for the array: ";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    // Measure sequential bubble sort time
    clock_t startSeqBubble = clock();
    bubbleSortSequential(arr, size);
    clock_t endSeqBubble = clock();
    double timeSeqBubble = double(endSeqBubble - startSeqBubble) / CLOCKS_PER_SEC;

    // Measure parallel bubble sort time
    clock_t startParBubble = clock();
    bubbleSortParallel(arr, size);
    clock_t endParBubble = clock();
    double timeParBubble = double(endParBubble - startParBubble) / CLOCKS_PER_SEC;

    // Display sorted array from parallel bubble sort
    std::cout << "Sorted Array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Print execution times
    std::cout << "Sequential Bubble Sort Time: " << timeSeqBubble << " seconds" << std::endl;
    std::cout << "Parallel Bubble Sort Time: " << timeParBubble << " seconds" << std::endl;

    return 0;
}
