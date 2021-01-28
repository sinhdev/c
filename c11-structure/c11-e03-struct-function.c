#include <stdio.h>
#include <string.h>
 
struct Book{
    char isbn[15];
	char title[51];
	char author[51];
	float price;
};

void printBook(struct Book book);
void printBooks(struct Book *books, int count);
struct Book getBook();
void getString(char *str, int length);

int main( ) {
    struct Book books[3] = {
		{"978-0131103627", "The C Programming Language", "Dennis M. Ritchie", 52.89},
		{"978-0789751980", "C Programming for Beginner", "Dean Miller", 24.32}
    };
    int i, count = 3;
   
    printf("Input book 3:\n");
    books[2] = getBook();
   
    printBooks(books, count);

    return 0;
}

struct Book getBook(){
    struct Book book;
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

void printBook(struct Book book){
    printf( "| %-14s | %-26s | %-20s | %6.2f |\n",
           book.isbn, book.title, book.author, book.price);
}
void printBooks(struct Book *books, int count){
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