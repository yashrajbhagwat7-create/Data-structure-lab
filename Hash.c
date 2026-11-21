#include <stdio.h>

#define TABLE_SIZE 10

#define EMPTY -1

int hashTable[TABLE_SIZE];

// Initialize hash table

void initialize() {

int i;

for (i = 0; i < TABLE_SIZE; i++) {

hashTable[i] = EMPTY;

}

}

// Insert book ID using linear probing

void insert(int key) {

int index = key % TABLE_SIZE;

int pos, i;

for (i = 0; i < TABLE_SIZE; i++) {

pos = (index + i) % TABLE_SIZE;

if (hashTable[pos] == EMPTY) {

hashTable[pos] = key;

printf("Book ID inserted successfully.\n");

return;

}

if (hashTable[pos] == key) {

printf("Book ID already exists.\n");

return;

}

}

printf("Hash table is full.\n");

}

// Search for a book ID

void search(int key) {

int index = key % TABLE_SIZE;

int pos, i;

for (i = 0; i < TABLE_SIZE; i++) {

pos = (index + i) % TABLE_SIZE;

if (hashTable[pos] == EMPTY) {

printf("Book ID not found.\n");

return;

}

if (hashTable[pos] == key) {

printf("Book ID found at position %d.\n", pos);

return;

}

}

printf("Book ID not found.\n");

}

// Display hash table

void display() {

int i;

printf("\nHash Table:\n");

for (i = 0; i < TABLE_SIZE; i++) {

if (hashTable[i] == EMPTY) {

printf("Index %d : EMPTY\n", i);

}

else {

printf("Index %d : %d\n", i, hashTable[i]);

}

}

}

// Main function

int main() {

int choice, key;

initialize();

do {

printf("\n--- Library Book Indexing ---\n");

printf("1. Insert Book ID\n");

printf("2. Search Book ID\n");

printf("3. Display Hash Table\n");

printf("4. Exit\n");

printf("Enter your choice: ");

scanf("%d", &choice);

switch (choice) {

case 1:

printf("Enter Book ID: ");

scanf("%d", &key);

if (key < 0) {

printf("Book ID must be non-negative.\n");

}

else {

insert(key);

}

break;

case 2:

printf("Enter Book ID to search: ");

scanf("%d", &key);

if (key < 0) {

printf("Invalid Book ID.\n");

}

else {

search(key);

}

break;

case 3:

display();

break;

case 4:

printf("Exiting program.\n");

break;

default:

printf("Invalid choice! Try again.\n");

}

} while (choice != 4);

return 0;

}
