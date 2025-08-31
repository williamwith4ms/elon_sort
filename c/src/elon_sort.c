#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/elon_sort.h"

int sort(void *varr, int size, int datatype_size) {
	// Don't do this.
	char *arr = (char *) varr;

	// something a little odd/unintuitive about this function is that one has to
	// set the *new length* to the output, and have the pointer be the input
	
	srand(time(NULL));

	int newsize = size;
	for (int i = 0; i < size; i++) {
		// RAND_MAX probably is set to someting ≠ 1, so use modulus instead
		
		int random = rand();

		if (random % 2 == 0) {
			for (int j = i; j < size - 1; j++) {
				for (int k = 0; k < datatype_size; k++) {
					arr[(j * datatype_size) + k] = arr[((j + 1) * datatype_size) + k];
				}
			}

			for (int j = 0; j < datatype_size; j++) {
				arr[((newsize - 1) * datatype_size) + j] = 0;
			}
			
			newsize = newsize - 1;
		}
	}

	return newsize;
}

void main() {
	int oldsize = 0;
	
	printf("Enter size for array:\n");
	scanf("%d", &oldsize);
	int *arr = malloc(sizeof(int) * oldsize);

	for (int i = 0; i < oldsize; i++) {
		arr[i] = i;
	}

	printf("Old array:");
	for (int i = 0; i < oldsize; i++) {
		printf(" %d", arr[i]);
	}
	printf("\n");

	int newsize = sort(arr, oldsize, sizeof(int));

	printf("New array:");
	for (int i = 0; i < newsize; i++) {
		printf(" %d", arr[i]);
	}
	printf("\n");

	free(arr);
}
