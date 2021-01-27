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
Book getBook();
int writeBooksToFile(Book *books, int count, const char *fileName);
int readBooksFromFile(Book *books, int *count, const char *fileName);

int main(int argCount, char** args){
    Book books[500];
    int i, count=0;

    //Read from file
    readBooksFromFile(books, &count, "books.csv");
    //add book
    books[count] = getBook();
    count++;
    //display all books
    for(i=0; i<count; i++){
        printBookDetails(books[i]);
    }
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
    Book b;
    //input b2
    printf("ISBN: ");
    gets(b.isbn);
    printf("Title: ");
    gets(b.title);
    printf("Author: ");
    gets(b.author);
    printf("Price: ");
    scanf("%f", &b.price);
    return b;
}

void printBookDetails(Book book){
    printf("===========================================\n");
    printf("ISBN: %s\n", book.isbn);
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Price: %0.2f\n", book.price);
}