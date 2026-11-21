#include <stdio.h>

#include <stdlib.h>

#define MAX 100

// Node structure

struct Node {

int vertex;

struct Node *next;

};

// Adjacency list

struct Node *adj[MAX];

int n;

// Create a new node

struct Node* createNode(int vertex) {

struct Node *newNode;

newNode = (struct Node*)malloc(sizeof(struct Node));

if (newNode == NULL) {

printf("Memory allocation failed!\n");

exit(1);

}

newNode->vertex = vertex;

newNode->next = NULL;

return newNode;

}

// Add connection between two users

void addConnection(int u, int v) {

if (u < 0 || u >= n || v < 0 || v >= n) {

printf("Invalid user ID!\n");

return;

}

if (u == v) {

printf("Self-connection is not allowed.\n");

return;

}

// Add v to u's list

struct Node *newNode = createNode(v);

newNode->next = adj[u];

adj[u] = newNode;

// Add u to v's list

newNode = createNode(u);

newNode->next = adj[v];

adj[v] = newNode;

printf("Connection added successfully.\n");

}

// Breadth First Search

void BFS(int start) {

int visited[MAX] = {0};

int queue[MAX];

int front = 0, rear = 0;

if (start < 0 || start >= n) {

printf("Invalid starting user ID!\n");

return;

}

visited[start] = 1;

queue[rear++] = start;

printf("BFS Traversal: ");

while (front < rear) {

int current = queue[front++];

struct Node *temp = adj[current];

printf("%d ", current);

while (temp != NULL) {

int v = temp->vertex;

if (!visited[v]) {

visited[v] = 1;

queue[rear++] = v;

}

temp = temp->next;

}

}

printf("\n");

}

// DFS using recursion

void DFSUtil(int vertex, int visited[]) {

struct Node *temp;

visited[vertex] = 1;

printf("%d ", vertex);

temp = adj[vertex];

while (temp != NULL) {

int v = temp->vertex;

if (!visited[v]) {

DFSUtil(v, visited);

}

temp = temp->next;

}

}

// Depth First Search

void DFS(int start) {

int visited[MAX] = {0};

if (start < 0 || start >= n) {

printf("Invalid starting user ID!\n");

return;

}

printf("DFS Traversal: ");

DFSUtil(start, visited);

printf("\n");

}

// Display adjacency list

void displayGraph() {

int i;

struct Node *temp;

printf("\nSocial Network (Adjacency List):\n");

for (i = 0; i < n; i++) {

printf("User %d: ", i);

temp = adj[i];

while (temp != NULL) {

printf("%d -> ", temp->vertex);

temp = temp->next;

}

printf("NULL\n");

}

}

// Main function

int main() {

int choice, u, v, start;

int i;

printf("Enter number of users (1-%d): ", MAX);

scanf("%d", &n);

if (n < 1 || n > MAX) {

printf("Invalid number of users!\n");

return 1;

}

// Initialize adjacency list

for (i = 0; i < n; i++) {

adj[i] = NULL;

}

do {

printf("\n--- Social Network Menu ---\n");

printf("1. Add Connection\n");

printf("2. Display Graph\n");

printf("3. Perform BFS\n");

printf("4. Perform DFS\n");

printf("5. Exit\n");

printf("Enter your choice: ");

scanf("%d", &choice);

switch (choice) {

case 1:

printf("Enter two user IDs (0 to %d): ", n - 1);

scanf("%d %d", &u, &v);

addConnection(u, v);

break;

case 2:

displayGraph();

break;

case 3:

printf("Enter starting user ID: ");

scanf("%d", &start);

BFS(start);

break;

case 4:

printf("Enter starting user ID: ");

scanf("%d", &start);

DFS(start);

break;

case 5:

printf("Exiting program.\n");

break;

default:

printf("Invalid choice! Try again.\n");

}

} while (choice != 5);

// Free dynamically allocated memory

for (i = 0; i < n; i++) {

struct Node *temp = adj[i];

while (temp != NULL) {

struct Node *toDelete = temp;

temp = temp->next;

free(toDelete);

}

}

return 0;
