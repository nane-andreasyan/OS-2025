#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
        printf("Enter the number of elements: ");

        scanf("%d", &n);
	int* arr = (int *)calloc(n,sizeof(int));
        if(arr == NULL){
                perror("failed to allocate memory");
                return 1;
        }
	printf("Array after calloc: ");
	for(int i =0; i<n; i++){
                printf("%d ", arr[i]);
        }

	printf("\nEnter %d integers:", n);
        for(int i =0; i<n; i++){
                scanf("%d", &arr[i]);
        }

	printf("Updated array:  ");
	for(int i =0; i<n; i++){
                printf("%d ", arr[i]);
        }
	int sum=0;

        for(int i =0; i<n; i++){
           sum = sum + arr[i];
        }

	int avg = sum/n;
	printf("\nAvg of the array: %d\n", avg);
	free(arr);
	arr=NULL;
        return 0;
}
