#include <stdio.h>

int main() {
    
    char ch;		
	printf ("\nEnter a lower cased alphabet (a - z) : ");
	scanf("%c", &ch);
    if (ch < 'a' || ch > 'z'){
	    printf("Character not a lower cased alphabet\n");
    } else {
	    switch (ch)
    	{
    		case 'a': case 'e': case 'i': case 'o': case 'u':
    			printf("Character is a vowel\n");
    			break;
    		case 'z':
    			printf ("Last Alphabet (z) was entered\n");
    			break;
    		default:
    			printf("Character is a consonant\n");
    			break;
		}
	}
	
   return 0;
}

