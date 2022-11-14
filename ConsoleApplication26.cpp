#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
using namespace std;

void SayilariDiziyeAktar(int arr[], int n);
void RastgeleSayiUret();
void diziyiYazdir(int arr[], int n);
void heapSort(int arr[], int n);
void heapify(int arr[], int n, int i);
void pancakeSort(int* arr, int n);
void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);
void swap(int* a, int* b);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void mergeSort(int array[], int const begin, int const end);
void merge(int array[], int const left, int const mid, int const right);
void swap1(int* a, int* b);
int main()
{
    clock_t baslangic = clock(), bitis;
    //RastgeleSayiUret();

    // Binlik Dizi
    /*
    int BinEleman_Array[1000];
    SayilariDiziyeAktar(BinEleman_Array, 1000);
    int n = sizeof(BinEleman_Array) / sizeof(BinEleman_Array[0]);
    selectionSort(BinEleman_Array, n);
    diziyiYazdir(BinEleman_Array, n);
    */

    // Onbinlik Dizi
    /*
    int Onbinlik_Array[10000];
    SayilariDiziyeAktar(Onbinlik_Array, 10000);
    int n = sizeof(Onbinlik_Array) / sizeof(Onbinlik_Array[0]);
    pancakeSort(Onbinlik_Array, n);
    diziyiYazdir(Onbinlik_Array, n);
    */

    //Yuzbinlik Dizi
    /*
    int Yuzbinlik_Array[100000];
    SayilariDiziyeAktar(Yuzbinlik_Array,100000);
    int n = sizeof(Yuzbinlik_Array) / sizeof(Yuzbinlik_Array[0]);
    heapSort(Yuzbinlik_Array, n);
    diziyiYazdir(Yuzbinlik_Array, n);
    */

    // Bir Milyonluk Dizi
    /*
    int* BirMilyon_Array = new int[1000000];
    SayilariDiziyeAktar(BirMilyon_Array, 1000000);
    int n = 1000000;
    heapSort(BirMilyon_Array, n);
    diziyiYazdir(BirMilyon_Array, n);
    */


    bitis = clock();
    cout << "\n\nKodun calisma suresi:" << float(bitis - baslangic) / CLOCKS_PER_SEC;
    return 0;
}

void heapify(int arr[], int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);

        // Heapify root element to get highest element at root again
        heapify(arr, i, 0);
    }
}

/* Reverses arr[0..i] */
void flip(int arr[], int i)
{
    int temp, start = 0;
    while (start < i)
    {
        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
        start++;
        i--;
    }
}

// Returns index of the 
// maximum element in 
// arr[0..n-1] 
int findMax(int arr[], int n)
{
    int mi, i;
    for (mi = 0, i = 0; i < n; ++i)
        if (arr[i] > arr[mi])
            mi = i;
    return mi;
}

// The main function that 
// sorts given array using 
// flip operations 
void pancakeSort(int* arr, int n)
{
    // Start from the complete 
    // array and one by one 
    // reduce current size 
    // by one 
    for (int curr_size = n; curr_size > 1;
        --curr_size)
    {
        // Find index of the 
        // maximum element in 
        // arr[0..curr_size-1] 
        int mi = findMax(arr, curr_size);

        // Move the maximum 
        // element to end of 
        // current array if 
        // it's not already 
        // at the end 
        if (mi != curr_size - 1)
        {
            // To move at the end, 
            // first move maximum 
            // number to beginning 
            flip(arr, mi);

            // Now move the maximum 
            // number to end by 
            // reversing current array 
            flip(arr, curr_size - 1);
        }
    }
}
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void merge(int array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays
    auto* leftArray = new int[subArrayOne],
        * rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne
        = 0, // Initial index of first sub-array
        indexOfSubArrayTwo
        = 0; // Initial index of second sub-array
    int indexOfMergedArray
        = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
        && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
void swap1(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] <= pivot)
        {
            i++;
            swap1(&arr[i], &arr[j]);
        }
    }
    swap1(&arr[i + 1], &arr[high]);

    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


void selectionSort(int arr[], int n)
{
    int i, j, min_idx;


    for (i = 0; i < n - 1; i++)
    {


        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        if (min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}
void diziyiYazdir(int arr[], int n) {

    for (int i = 0; i < n; i++) {

        cout << arr[i] << " ";
        if (i % 20 == 0 && i != 0)
            cout << endl;
    }

}

void SayilariDiziyeAktar(int arr[], int n) {

    ifstream readFile("sayilar.txt");
    string sayi;
    for (int i = 0; i < n; i++) {
        getline(readFile, sayi);
        stringstream deneme(sayi);
        deneme >> arr[i];
        //cout << arr[i] << endl;
    }
}

void RastgeleSayiUret() {
    ofstream file("sayilar.txt", ios::in);

    file.open("sayilar.txt");
    srand((unsigned)time(NULL));

    for (int i = 0; i < 1000000; i++) {
        int random = rand() % 101; // 0 ile 100 arası sayı oluşturur.
        file << random << endl;
    }

    file.close();
    cout << "Rastgele bir milyon sayi uretildi ve .txt dosyasına kaydedildi.";
}
