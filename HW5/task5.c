#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
        printf("Enter the number of students: ");

        scanf("%d", &n);
	if (n <= 0) {
                printf("Can't be negative\n");
                return 1;
        }

	int* arr = (int *)malloc(n*sizeof(int));
        if(arr == NULL){
                perror("failed to allocate memory");
                return 1;
        }
	printf("Enter the grades: ");
        for(int i =0; i<n; i++){
                scanf("%d", &arr[i]);
        }
	int min = arr[0];
   	int max = arr[0];

    	for(int i =0; i<n; i++){
        	if(min > arr[i]) {
		       	min = arr[i];
       		}
           
        	if(max < arr[i]) {
			max = arr[i];
        	}
    	}
    	printf("Highest Grade: %d\n", max);
    	printf("Lowest Grade: %d\n", min);
    	
	free(arr);
    	arr=NULL;
    	
	return 0;
}
