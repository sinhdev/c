#include <stdio.h>
#include <string.h>
 
typedef struct{
    char isbn[15];
	char title[51];
	char author[51];
	float price;
}Book;

void printBook(Book book);
Book getBook();
void getString(char *str, int length);
void printBooks(Book *books, int count);
//function to read Books array from file
int readBooksFromFile(Book *lstBooks, int *pCount, const char *fileName);
//function to write Books array with count elements to file
int writeBooksToFile(Book *lstBooks, int count, const char *fileName);

int main( ) {
    Book books[100];
    int i, count = 0;
    
    //read data from file
    readBooksFromFile(books, &count, "books.dat");
   
    printf("Input book %d:\n", count+1);
    books[count] = getBook();
    count++;
   
    printBooks(books, count);
    
    //write data to file
    writeBooksToFile(books, count, "books.dat");

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

int readBooksFromFile(Book *lstBooks, int *pCount, const char *fileName){
    FILE *f;
    int result = 0;
    f = fopen(fileName, "rb");
    if(f!=NULL){
        //read a int is array element number
        fread(pCount, sizeof(int), 1, f);
        if(*pCount > 0){
            //read data in file to lstBooks
            fread(lstBooks, sizeof(Book), *pCount, f);
            result = 1;
        }
        //close file
        fclose(f);
    }
    return result;
}

int writeBooksToFile(Book *lstBooks, int count, const char *fileName){
    FILE *f;
    int result = 0;
    f = fopen(fileName, "wb");
    if(f!=NULL){
        //write count to file
        fwrite(&count, sizeof(int), 1, f);
        //write lstBooks to file
        fwrite(lstBooks, sizeof(Book), count, f);
        //close file
        fclose(f);
        result = 1;
    }
    return result;
}