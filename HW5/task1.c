#include <stdio.h>
#include <stdlib.h>
int main() {
	int n;
	printf("Enter the number of elements: ");

	scanf("%d", &n);

	int* arr = (int *)malloc(n * sizeof(int));
	if(arr == NULL){
		perror("failed to allocate memory");
		return 1;
	}
	printf("Enter %d integers: ", n);
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}

	int sum=0;

	for(int i = 0; i < n; i++){
           sum = sum + arr[i];
        }

	printf("Sum of the array: %d\n", sum);
	free(arr);
	arr = NULL;
	return 0;
}

