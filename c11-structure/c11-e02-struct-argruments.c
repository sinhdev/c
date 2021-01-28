#include <stdio.h>
#include <string.h>
 
struct Book{
    char isbn[15];
	char title[50];
	char author[50];
	float price;
};

void printBookDetails(struct Book book);

int main( ) {
   struct Book book1;        /* Declare Book1 of type Book */
   struct Book book2;        /* Declare Book2 of type Book */
 
   /* book 1 specification */
   strcpy(book1.isbn, "978-0131103627");
   strcpy(book1.title, "The C Programming Language");
   strcpy(book1.author, "Dennis M. Ritchie");
   book1.price = 52.89;

   /* book 2 specification */
   strcpy(book2.isbn, "978-0789751980");
   strcpy(book2.title, "C Programming Absolute Beginner's Guide");
   strcpy(book2.author, "Dean Miller");
   book2.price = 24.32;
 
   /* print Book1 info */
   printBookDetails(book1);
   /* print Book2 info */
   printBookDetails(book2);

   return 0;
}

void printBookDetails(struct Book book){
   printf("=================================================\n");
   printf("Book isbn: %s\n", book.isbn);
   printf("Book title: %s\n", book.title);
   printf("Book author: %s\n", book.author);
   printf("Book price: %.2f\n", book.price);
}