#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

// Fungsi untuk menampilkan array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(arr[min_idx], arr[i]);
    }
}

// Merge Sort
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Fungsi untuk mengukur waktu eksekusi
void testSort(void (*sortFunc)(int[], int), int arr[], int n, const string &sortName) {
    int *arrCopy = new int[n];
    copy(arr, arr + n, arrCopy);
    auto start = high_resolution_clock::now();
    sortFunc(arrCopy, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << sortName << " : " << duration.count() << " µs" << endl;
    delete[] arrCopy;
}

void testSort(void (*sortFunc)(int[], int, int), int arr[], int n, const string &sortName) {
    int *arrCopy = new int[n];
    copy(arr, arr + n, arrCopy);
    auto start = high_resolution_clock::now();
    sortFunc(arrCopy, 0, n - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << sortName << " : " << duration.count() << " µs" << endl;
    delete[] arrCopy;
}

int main() {
    vector<int> sizes = {10, 100, 500, 1000, 10000};

    for (int n : sizes) {
        cout << "Ukuran N: " << n << endl;

        int *arr = new int[n];

        // Test dengan data acak
        cout << "Data Acak:" << endl;
        for (int i = 0; i < n; i++) arr[i] = rand() % 10000;
        testSort(bubbleSort, arr, n, "Bubble Sort");
        testSort(insertionSort, arr, n, "Insertion Sort");
        testSort(selectionSort, arr, n, "Selection Sort");
        testSort(mergeSort, arr, n, "Merge Sort");
        testSort(quickSort, arr, n, "Quick Sort");

        // Test dengan data terurut terbalik
        cout << "Data terurut terbalik:" << endl;
        for (int i = 0; i < n; i++) arr[i] = n - i;
        testSort(bubbleSort, arr, n, "Bubble Sort");
        testSort(insertionSort, arr, n, "Insertion Sort");
        testSort(selectionSort, arr, n, "Selection Sort");
        testSort(mergeSort, arr, n, "Merge Sort");
        testSort(quickSort, arr, n, "Quick Sort");

        // Test dengan data yang sudah terurut
        cout << "Data yang sudah terurut:" << endl;
        for (int i = 0; i < n; i++) arr[i] = i;
        testSort(bubbleSort, arr, n, "Bubble Sort");
        testSort(insertionSort, arr, n, "Insertion Sort");
        testSort(selectionSort, arr, n, "Selection Sort");
        testSort(mergeSort, arr, n, "Merge Sort");
        testSort(quickSort, arr, n, "Quick Sort");

        delete[] arr;
        cout << endl;
    }

    return 0;
}
