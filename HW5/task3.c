#include <stdio.h>
#include <stdlib.h>

int main(){
	int* arr = (int*)malloc(10 * sizeof(int));
	if(arr == NULL){
                perror("failed to allocate memory");
                return 1;
        }

        printf("Enter 10 integers: ");
        for(int i = 0; i < 10; i++){
                scanf("%d", &arr[i]);
        }

	int* temp  = (int *)realloc(arr, 5 * sizeof(int));
    	if (temp == NULL) {
        	perror("failed to reallocate memory");
        	free(arr);
        	return 1;
       	}
	arr = temp;

	printf("Array after resizing ");
	       for(int i = 0; i < 5; i++){
                printf("%d ", arr[i]);
        }
	free(arr);
	arr = NULL;



}	
