#include <stdio.h>
#include <string.h>
 
typedef struct{
    char isbn[15];
	char title[51];
	char author[51];
	float price;
}Book;

void printBook(Book book);
void printBooks(Book *books, int count);
Book getBook();
void getString(char *str, int length);

int main( ) {
    Book books[3] = {
		{"9780131103627","The C Programming Language","Dennis Ritchie",52.89},
		{"9780789751980","C Programming for Beginner","Dean Miller",24.32}
    };
    int i, count = 3;
   
    printf("Input book 3:\n");
    books[2] = getBook();
   
    printBooks(books, count);

    return 0;
}

Book getBook(){
    Book book;
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

void printBook(Book book){
    printf( "| %-14s | %-26s | %-20s | %6.2f |\n",
           book.isbn, book.title, book.author, book.price);
}
void printBooks(Book *books, int count){
    printf( "+-%-14s-+-%-26s-+-%-20s-+-%-6s-+\n", "--------------",
        "--------------------------", "--------------------", "------");
    printf( "| %-14s | %-26s | %-20s | %-6s |\n", "isbn", "Title", "Author", "Price");
    printf( "+-%-14s-+-%-26s-+-%-20s-+-%-6s-+\n", "--------------",
        "--------------------------", "--------------------", "------");
    for(int i=0; i<count; i++){
        printBook(books[i]);
    }
    printf( "+-%-14s-+-%-26s-+-%-20s-+-%-6s-+\n", "--------------",
        "--------------------------", "--------------------", "------");
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

