#include <stdio.h>
#include <stdlib.h>

int main() {
        char** str = (char**)malloc(3*sizeof(char*));
        if(str == NULL){
                perror("failed to allocate memory");
                return 1;
        }
        for(int i = 0; i < 3; i++){
                str[i] = (char*)malloc(50*sizeof(char));
                if (str[i] == NULL) {
                        perror("failed to allocate memory to char pointer");
                 for (int j = 0; j < i; j++){
                         free(str[j]);
                }
                free(str);
                return 1;
                }
        }

        printf("Enter 3 strings: ");
        for(int i = 0; i < 3; i++){
                scanf("%49s", str[i]);
        }
	printf("First 3 strings: ");

        for(int i = 0; i < 3; i++){
                printf("%s ", str[i]);
        }

	char ** temp = (char **)realloc(str, 5*sizeof(char*));
	if(temp == NULL) {
		perror("reallocation failed");
		for (int j = 0; j < 3; j++){
                         free(str[j]);
			 str[j] = NULL;
                }
		free(str);
		str = NULL;
		return 1;
	}
	str = temp;
	     for(int i = 3; i < 5; i++){
                str[i] = (char*)malloc(50*sizeof(char));
                if (str[i] == NULL) {
			perror("failed to allocate memory to char pointer");
			for (int j = 0; j < i; j++){
                        free(str[j]);
			str[j] = NULL;
                }
                free(str);
		str = NULL;
                return 1;
                }
        }

	printf("\nEnter 2 more strings: ");
	for(int i = 3; i < 5; i++){
                scanf("%49s", str[i]);
        }
	printf("All strings: ");
	for(int i = 0; i < 5; i++){
                printf("%s ", str[i]);
        }

	for (int j = 0; j < 5; j++){
		free(str[j]);
		str[j] = NULL;
        }
        free(str);
	str = NULL;

}
