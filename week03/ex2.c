#include<stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int a[], int n) {
    printf("N: %d\n", n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] > a[j]) {
                swap(&a[i], &a[j]);
            }
        }
    }
}

int main() {
    int a[] = {1, 4, 5, 3, 2};
    int n = sizeof(a) / sizeof(int);
    bubble_sort(a, n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", *(a + i));
    }
}