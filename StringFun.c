#include <stdio.h>
#include <stdlib.h>

void reverseString(char *str);
void firstUnique(char *str);

int main (int *argc, char **argv) {
	int cmd = 0;
	char *word = argv[1];
	
	if (argv[1] == NULL || argv[1] == "") {
		printf("Try again, stupid. Enter a working string to the command line.\n");
		return 0;
	}
	
	printf("\nGot it, your working string is: %s\n", argv[1]);
	
	while (cmd != 9) {
		
		switch (cmd) {
			case 1:
				printf("%s\n\n", argv[1]);
			break;
			
			case 2:
				reverseString(argv[1]);
				printf("\n\n");
			break;
			
			case 3:
				printf("\n\n");
			break;
			
			case 0: 
				printf("\nPlease enter one of the following commands:\n");
				printf("\t1. Print String\n\t2. Reverse String\n");
				printf("\t3. 1st Unique \n\t4. \n");
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

//create second array in alphabetical order
void firstUnique(char *str) {
	int len = strlen(str);
	char swap;
	char *word = 
	
	for (i = 0; i < len - 1; i++) {
		
		//2nd letter in str[] later than 1st
		if (str[i] - str[i + 1] < 0) {
			
			//last index of word[] earlier than str[]
			if (word[len] - str[i + 1] < 0) {
				shiftDown(word, len);
				word[len] = str[i + 1];
			}
		}
			
	}
}

void shiftDown(char *str, int n) {
	int low = n;
	
	//move low index down until a NULL is found
	while (str[low - 1] != NULL && low > 0) {
		low--;
	}
	
	//shift all chars down an index
	while (low <= n) {
		str[low - 1] = str[low];
		low++;
	}
}