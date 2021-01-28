#include <stdio.h>
#include <string.h>

//struct define
typedef struct{
    char isbn[20];
    char title[100];
    char author[50];
    float price;
}Book;

void printBookDetails(Book book);
void printBook(Book book);
void printBooks(Book *books, int count);
Book getBook();
int writeBooksToFile(Book *books, int count, const char *fileName);
int readBooksFromFile(Book *books, int *count, const char *fileName);
void getString(char *str, int length);

int main(int argCount, char** args){
    Book books[500];
    int i, count=0;

    //Read from file
    readBooksFromFile(books, &count, "books.csv");
    //add book
    books[count] = getBook();
    count++;
    //display all books
    printBooks(books, count);
    //save to file
    writeBooksToFile(books, count, "books.csv");

    return 0;
}
int readBooksFromFile(Book *books, int *count, const char *fileName){
    FILE *f;
    //1. Open file
    f = fopen(fileName, "rb");
    if(f==NULL){
        return 0;
    }
    //2. Manipulate file
    int i = 0;
    for(i=0;!feof(f);i++){
        fscanf(f, "%[^,],%[^,],%[^,],%f\n", (books+i)->isbn, (books+i)->title, (books+i)->author, &books[i].price);
    }
    *count = i;
    //3. Close file
    fclose(f);
    return 1;
}
int writeBooksToFile(Book *books, int count, const char *fileName){
    FILE *f;
    //1. Open file
    f = fopen(fileName, "wb");
    if(f==NULL){
        return 0;
    }
    //2. Manipulate file
    int i;
    for(i=0; i<count; i++){
        fprintf(f, "%s,%s,%s,%f\n", books[i].isbn, books[i].title, books[i].author, books[i].price);
    }

    //3. Close file
    fclose(f);
    return 1;
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

void printBookDetails(Book book){
    printf("===========================================\n");
    printf("ISBN: %s\n", book.isbn);
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Price: %0.2f\n", book.price);
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