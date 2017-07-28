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
//function to read Books array from file
int readBooksFromFile(Books *lstBooks, int *pCount, const char *fileName);
//function to write Books array with count elements to file
int writeBooksToFile(Books *lstBooks, int count, const char *fileName);

int main( ) {
    Books books[100];
    int i, count = 0;
    
    //read data from file
    readBooksFromFile(books, &count, "books.dat");
   
    printf("Input book %d:\n", count+1);
    books[count] = getBook();
    count++;
   
    printTitle();
    for(i=0; i<count; i++){
        printBook(books[i]);
    }
    printLine();
    
    //write data to file
    writeBooksToFile(books, count, "books.dat");

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

int readBooksFromFile(Books *lstBooks, int *pCount, const char *fileName){
    FILE *f;
    int result = 0;
    f = fopen(fileName, "rb");
    if(f!=NULL){
        //read a int is array element number
        fread(pCount, sizeof(int), 1, f);
        if(*pCount > 0){
            //read data in file to lstBooks
            fread(lstBooks, sizeof(Books), *pCount, f);
            result = 1;
        }
        //close file
        fclose(f);
    }
    return result;
}

int writeBooksToFile(Books *lstBooks, int count, const char *fileName){
    FILE *f;
    int result = 0;
    f = fopen(fileName, "wb");
    if(f!=NULL){
        //write count to file
        fwrite(&count, sizeof(int), 1, f);
        //write lstBooks to file
        fwrite(lstBooks, sizeof(Books), count, f);
        //close file
        fclose(f);
        result = 1;
    }
    return result;
}

