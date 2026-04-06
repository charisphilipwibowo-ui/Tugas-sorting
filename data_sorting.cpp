#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Fungsi pembantu untuk mencetak array
void printArray(const vector<int>& arr) {
    for (int i : arr) cout << i << " ";
    cout << endl;
}

// 1. BUBBLE SORT
void bubbleSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
        cout << "Iterasi " << i + 1 << ": ";
        printArray(arr);
    }
}

// 2. SELECTION SORT
void selectionSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx]) min_idx = j;
        swap(arr[i], arr[min_idx]);
        cout << "Iterasi " << i + 1 << ": ";
        printArray(arr);
    }
}

// 3. INSERTION SORT
void insertionSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        cout << "Iterasi " << i << ": ";
        printArray(arr);
    }
}

// Quick Sort & Merge Sort (Logika Rekursif - Tampilan hasil akhir saja agar tidak membingungkan)
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n, choice, val;
    cout << "Masukkan jumlah data: "; cin >> n;
    vector<int> data;
    for(int i=0; i<n; i++) {
        cout << "Data ke-" << i+1 << ": "; cin >> val;
        data.push_back(val);
    }

    cout << "\nPilih Algoritma:\n1. Bubble\n2. Selection\n3. Insertion\n4. Quick\nMasukkan pilihan: ";
    cin >> choice;

    switch(choice) {
        case 1: bubbleSort(data); break;
        case 2: selectionSort(data); break;
        case 3: insertionSort(data); break;
        case 4: quickSort(data, 0, n-1); printArray(data); break;
        default: cout << "Pilihan tidak ada.";
    }
    return 0;
}