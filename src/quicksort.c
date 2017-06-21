#include <stdio.h>

int partition(int *arr, int left, int right) {
    int tmp, i, j = left;
    for (i = left; i < right; ++i) {
        if (arr[i] < arr[right]) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j++] = tmp;
        }
    }
    tmp = arr[j];
    arr[j] = arr[right];
    arr[right] = tmp;
    return j;
}

void quicksort(int *arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int pos = partition(arr, left, right);
    quicksort (arr, left, pos - 1);
    quicksort (arr, pos + 1, right);
}

void quickselect(int *arr, int left, int right, int k) {
    if (left >= right) {
        return;
    }
    int pos = partition(arr, left, right);
    if (pos == k) {
        return;
    }
    if (pos > k) {
        quickselect(arr, left, pos - 1, k);
    }
    else {
        quickselect(arr, pos + 1, right, k);
    }
}

void sort(int *arr, int len) {
    quicksort(arr, 0, len-1);
}

void printArr(int *arr, int len) {
    for (int i = 0; i < len; ++i) {
        printf ("%d ", arr[i]);
    }
    printf ("\n");
}

int main() {
    int arr[] = {5, 2, 6, 1, 8, 3, 7, 9, 4};
    printArr(arr, sizeof(arr) / sizeof(int));
    //sort(arr, sizeof(arr) / sizeof(int));
    quickselect(arr, 0, sizeof(arr) / sizeof(int) - 1, 5);
    printArr(arr, sizeof(arr) / sizeof(int));
    return 0;
}

