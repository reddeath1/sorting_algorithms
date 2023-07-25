#include "sort.h"

/**
* _swap - Main function that swap
* @a: The array
* @b: The array
*/ 
void _swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
* hoare_partition - Main function for hoare partition
* @array: The array
* @low: The lower
* @high: The higher
*/

int hoare_partition(int *array, int low, int high) {
    int pivot = array[high];
    int i = low - 1;
    int j = high + 1;

    while (1) {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        swap(&array[i], &array[j]);
        // Print the array after each swap
        for (int k = low; k <= high; k++) {
            printf("%d ", array[k]);
        }
        printf("\n");
    }
}

/**
* quick_sort_helper - Main helper function
* @array: The array
* @low: The lower
* @high: The hinger
*/

void quick_sort_helper(int *array, int low, int high) {
    if (low < high) {
        int pivot_index = hoare_partition(array, low, high);
        quick_sort_helper(array, low, pivot_index);
        quick_sort_helper(array, pivot_index + 1, high);
    }
}

/**
* quick_sort_hoare - Main function to sort hoare
* @array: The array
* @size: The size
*/
void quick_sort_hoare(int *array, size_t size) {
    quick_sort_helper(array, 0, size - 1);
}
