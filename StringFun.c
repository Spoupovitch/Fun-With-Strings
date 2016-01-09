#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseString(char *str);
char firstUnique(char *str);
void bubbleSort(char *str, int len);
void swap(char *str, int a, int b);

int main (int *argc, char **argv) {
	int cmd = 0;
	char unique;
	
	if (argv[1] == NULL || argv[1] == "") {
		printf("Try again, stupid. Enter a working string to the command line.\n");
		return 0;
	}
	
	printf("\nGot it, your working string is: %s\n", argv[1]);
	
	while (cmd != 9) {
		
		switch (cmd) {
			case 1:
				printf("\t-%s\n\n", argv[1]);
			break;
			
			case 2:
				printf("\t-");
				reverseString(argv[1]);
				printf("\n\n");
			break;
			
			case 3:
				unique = firstUnique(argv[1]);
				printf("\t-%c\n\n", unique);
			break;
			
			case 0: 
				printf("\nPlease enter one of the following commands:\n");
				printf("\t1. Print String\n\t2. Reverse String\n");
				printf("\t3. 1st Unique Letter\n\t4. \n");
				printf("\t9. Exit\n\t0. Command List\n\n");
			break;
			
			default:
			;
		}
		
		//cmd initialized to 0 will print prompt, cmd need only be changed
		//outside of switch() after first call of while(). saves n lines
		//of code where n is number of lines of prompt.
		scanf("%d", &cmd);
	}
	
	printf("\n---------------Bye, bitch!---------------\n");
	
	return 0;
}

void reverseString(char *str) {
	if (str[0] == '\0') {
		return;
	}
	
	//str++ screwing up recursive call
	reverseString(str + 1);
	printf("%c", str[0]);
}

char firstUnique(char *str) {
	int i, j, match, len = strlen(str);
	char *word = malloc(sizeof(char) * len + 1);
	strcpy(word, str); 
	
	//edge case
	if (len == 1) {
		return str[0];
	}
	
	//word[] = sorted version of str[]
	bubbleSort(word, len);
	
	printf("str: %s\nword: %s\n", str, word);
	
	//traverse original string in order
	for (i = 0; i < len; i++) {
		match = 0;
		
		//check str[i] against entire sorted array
		for (j = 0; j < len; j++) {
			
			//increment only if letters match
			if (str[i] - word[j] == 0) {
				match += 1;
			}
		}
		
		if (match == 1) {
			return str[i];
		}
	}
	
	return '\0';
}

void bubbleSort(char *str, int len) {
	int i, j, swapped = 1;
	
	//exit early if no swaps made
	for (i = 0; i < len && swapped; i++) {
		swapped = 0;
		
		for (j = 0; j < len - i - 1; j++) {
			
			//bubble up
			if (str[j] - 'a' > str[j + 1] - 'a') {
				swap(str, j, j + 1);
				swapped = 1;
			}
			//takes care of adjacent duplicate letters
			else if (str[j] - 'a' == str[j + 1] - 'a') {
				swapped = 1;
			}
		}
	}
	
	//return str;
}

void swap(char *str, int a, int b) {
	char temp = str[a];
	str[a] = str[b];
	str[b] = temp;
}
kjhfkasjhdfkasdjh
