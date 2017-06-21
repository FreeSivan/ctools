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

void quickselect(int *arr, int left, int right, int k) {
    if (left >= right) {
        return;
    }
    int pos = partition (arr, left, right);
    if (pos == k) {
        return;
    }
    if (pos > k) {
        quickselect(arr, left, pos - 1, k);
    }
    else {
        quickselect(arr, pos - 1, right, k);
    }
}

void select(int *arr, int len, int k) {
    quickselect(arr, 0, len - 1, k);
}

void printArr (int *arr, int len) {
    int i;
    for (i = 0; i < len; ++i) {
        printf ("%d ", arr[i]);
    }
    printf ("\n");
}

int main() {
    int arr[] = {5, 1, 2, 6, 3, 9, 7, 8};
    int len = sizeof(arr) / sizeof(int);
    printArr (arr, len);
    select (arr, len, 3);
    printArr (arr, len);
    return 0;
}
