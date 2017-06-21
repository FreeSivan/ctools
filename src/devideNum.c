#include <stdio.h>

void printArr(int *arr, int length) {
    int i;
    for (i = length - 1; i > 0; i -= arr[i]) {
        printf ("%d ", arr[i]);
    }
    printf ("\n");
}

void devideNum(int s, int t, int *arr, int length) {
    int i;
    if (s <= 0) {
        printArr(arr, length);
        return;
    }
    if (t > s) {
        t = s;
    }
    for (i = 1; i <= t; ++i) {
        arr[s] = i;
        devideNum(s-i, i, arr, length);
    }
}

int main() {
    int arr[7] = {0};
    devideNum(6, 6, arr, sizeof(arr)/sizeof(int));
    return 0;
}

