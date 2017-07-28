#include <stdio.h>
#include <string.h>
 
typedef struct{
    char isbn[15];
	char title[51];
	char author[51];
	float price;
}Books;

void printBook(Books book);
Books getBook();
void getString(char *str, int length);
void printLine();
void printTitle();

int main( ) {
    Books books[3] = {
		{"9780131103627","The C Programming Language","Dennis Ritchie",52.89},
		{"9780789751980","C Programming for Beginner","Dean Miller",24.32}
    };
    int i, count = 3;
   
    printf("Input book 3:\n");
    books[2] = getBook();
   
    printTitle();
    for(i=0; i<count; i++){
        printBook(books[i]);
    }
    printLine();

    return 0;
}

Books getBook(){
    Books book;
    printf("Input Book isbn: ");
    getString(book.isbn, 14);
    printf("Input Book title: ");
    getString(book.title, 50);
    printf("Input Book author: ");
    getString(book.author, 50);
    printf("Input Book price: ");
    scanf("%f", &book.price);
    return book;
}

void printBook(Books book){
    printf( "| %-14s | %-26s | %-20s | %6.2f |\n",
           book.isbn, book.title, book.author, book.price);
}
void printLine(){
    printf( "+-%-14s-+-%-26s-+-%-20s-+-%-6s-+\n", "--------------",
        "--------------------------", "--------------------", "------");
}
void printTitle(){
    printLine();
    printf( "| %-14s | %-26s | %-20s | %-6s |\n", "isbn", "Title",
        "Author", "Price");
    printLine();
}
void getString(char *str, int length){
    //clear keyboard buffer on UNIX
    fseek(stdin, 0, SEEK_END);
    //clear keyboard buffer on Windows
    fflush(stdin);
    //input string
    fgets(str, length, stdin);
    str[strlen(str)-1] = '\0';
    //clear keyboard buffer on UNIX
    fseek(stdin, 0, SEEK_END);
    //clear keyboard buffer on Windows
    fflush(stdin);
}

