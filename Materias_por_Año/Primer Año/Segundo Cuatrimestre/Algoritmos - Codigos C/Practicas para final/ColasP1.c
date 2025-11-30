#include <stdio.h>
#include <stdlib.h>

// Define a structure to hold data for each test
struct Test {
  int testNumber;
  int dni;
  char name[50];
  int location;
  char date[11]; 
};

// Define a node for the linked list queue
struct Node {
  struct Test test;
  struct Node *next;
};

// Define a queue data structure
struct Queue {
  struct Node *front;
  struct Node *rear;
};

// Function to create a new node for the queue
struct Node *newNode(struct Test test) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->test = test;
  node->next = NULL;
  return node;
}

// Function to initialize an empty queue
void initQueue(struct Queue *queue) {
  queue->front = NULL;
   queue->rear = NULL;
}

// Function to add a test to the queue
void addTest(struct Queue *queue) {
  struct Test newTest;
  printf("Enter test number: ");
  scanf("%d", &newTest.testNumber);
  printf("Enter DNI: ");
  scanf("%d", &newTest.dni);
  printf("Enter name: ");
  scanf("%s", newTest.name);
  printf("Enter location code: ");
  scanf("%d", &newTest.location);
  printf("Enter date (YYYY-MM-DD): ");
  scanf("%s", newTest.date);

  struct Node *node = newNode(newTest);
  if (queue->rear == NULL) {
    queue->front = queue->rear = node;
    return;
  }
  queue->rear->next = node;
  queue->rear = node;
}

// Function to count tests in a specific location
int countTests(struct Queue *queue, int locationCode) {
  int count = 0;
  struct Node *current = queue->front;
  while (current != NULL) {
    if (current->test.location == locationCode) {
      count++;
    }
    current = current->next;
  }
  return count;
}

// Function to display pending tests
void displayPendingTests(struct Queue *queue) {
  struct Node *current = queue->front;
  printf("Pending Tests:\n");
  while (current != NULL) {
    printf("Test Number: %d, DNI: %d, Name: %s, Location: %d, Date: %s\n",
           current->test.testNumber, current->test.dni, current->test.name,
           current->test.location, current->test.date);
    current = current->next;
  }
}

// Main function
int main() {
  struct Queue queue;
  initQueue(&queue);
  int choice, locationCode;

  do {
    printf("1. Add Test\n2. Count Tests by Location\n3. Display Pending Tests\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addTest(&queue);
        break;
      case 2:
        printf("Enter location code to count: ");
        scanf("%d", &locationCode);
        printf("Number of tests in location %d: %d\n", locationCode, countTests(&queue, locationCode));
        break;
      case 3:
        displayPendingTests(&queue);
        break;
      case 4:
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n");
    }
  } while (choice != 4);

  return 0;
}
