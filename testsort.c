#include <stdio.h>

void SelectionSort(int *, int);

int main() {
    int a[] = {8, 6, 10, 3, 1, 2, 5, 4};
    int array_size = 8;
    
    SelectionSort(&a[0], array_size);
} /* main */

void SelectionSort(int a[], int array_size) {
/*     int i;

    for (i = 0; i < array_size - 1; ++i) {
        int j, k, min, temp;
        
        min = i;
        
        for (j = i + 1; j < array_size; ++j) {
           if (a[j] < a[min]) min = j;
        }
        
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;

        printf("[ ");
        for (k = 0; k < array_size; ++k) {
            printf("%d", a[k]);
            if (k != array_size - 1) printf(", ");
        }
        printf(" ]\n");
    }
/**/
    int x, index_of_min, y, temp, k;
    
	for (x = 0; x < array_size; x++) {
		int index_of_min = x;

		for(y = x; y < array_size; y++) {
            if (a[index_of_min] > a[y]) index_of_min = y;
		}

		int temp = a[x];
        a[x] = a[index_of_min];
        a[index_of_min] = temp;

        printf("[ ");
        for (k = 0; k < array_size; ++k) {
            printf("%d", a[k]);
            if (k != array_size - 1) printf(", ");
        }
        printf(" ]\n");
	}
/**/
}