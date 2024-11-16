#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct books {
    char title[5][100];
    char author[5][100];
    int ISBN[5];
    int publicationYear[5];
    bool isAvailable[5];
};

struct books s1; 
void addBook(char bookTitle[100], int index, char bookAuthor[100], int bookISBN, int bookPublicationYear) {
    
    strcpy(s1.title[index], bookTitle);
    strcpy(s1.author[index], bookAuthor);
    s1.ISBN[index] = bookISBN;
    s1.publicationYear[index] = bookPublicationYear;
    s1.isAvailable[index] = true; 
}

void availability(char bookTitle[100], char bookAuthor[100]) {
    bool found = false; 
    for (int i = 0; i < 5; i++) {
        if (strcmp(s1.title[i], bookTitle) == 0 || strcmp(s1.author[i], bookAuthor) == 0) {
            printf("Book is available at index %d\n", i);
            found = true; 
            break; 
        }
    }
    
    if (!found) { 
        printf("Book is not available\n");
    }
}

int main() {
 
    addBook("C Programming", 0, "Dennis Ritchie", 123456789, 1978);
    addBook("Effective C++", 1, "Scott Meyers", 987654321, 2005);

    availability("C Programming", "Dennis Ritchie");
    availability("Unknown Book", "Unknown Author");

    return 0;
}