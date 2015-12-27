#include <stdio.h>
#include <stdlib.h>

void reverseString(char *str);

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
				printf("\t3. Check \n\t4. \n");
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