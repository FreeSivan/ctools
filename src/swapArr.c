#include <stdio.h>


void printArr(int *arr, int len) {
    int i;
    for (i = 0; i < len; ++i) {
        printf ("%d ", arr[i]);
    }
    printf ("\n");
}

int main() {
    int arr1[] = {2, 3, 12, 77, 39, 4};
    int arr2[] = {235, 4, 29, 7};
    int len1 = sizeof(arr1) / sizeof(int);
    int len2 = sizeof(arr2) / sizeof(int);
    int *result = new int[len2];
    int *tmp = new int[len1 + len2];
    for (int i = 0; i < len1; ++i) {
        tmp[i] = arr1[i];
    }
    for (int i = 0; i < len2; ++i) {
        tmp[len1 + i] = arr2[i];
    }
    printArr(arr1, len1);
    printArr(arr2, len2);
    printArr(tmp, len1 + len2);
    return 0;
}
