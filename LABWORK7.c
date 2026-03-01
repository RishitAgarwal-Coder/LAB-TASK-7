#include <stdio.h>
#include <stdlib.h>

/* NAME: Rishit Agarwal
   REG NO: AP25110070245
   COURSE: CSE 102 - Data Structures Lab
*/

struct Node {
    int data;
    struct Node* next;
};

// --- TASK 1: LOGISTICS QUEUE REVERSAL ---
// Logic: Uses a temporary stack to flip the order of elements dequeued from the queue.
void task1_logistics() {
    int capacity, queue[100], stack[100];
    int front = 0, rear = -1, top = -1;

    printf("\n--- Task 1: Logistics Queue Reversal ---\n");
    printf("Enter capacity and package codes:\n");
    if (scanf("%d", &capacity) != 1) return;

    for (int i = 0; i < capacity; i++) {
        scanf("%d", &queue[++rear]);
    }

    printf("Original queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d%s", queue[i], (i == rear) ? "" : " ");
    }
    printf("\n");

    // Reverse logic: Queue -> Stack
    while (front <= rear) {
        stack[++top] = queue[front++];
    }

    // Stack -> Queue
    front = 0; rear = -1;
    while (top >= 0) {
        queue[++rear] = stack[top--];
    }

    printf("Reversed queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d%s", queue[i], (i == rear) ? "" : " ");
    }
    printf("\n");
}

// --- TASK 2: STUDENT ROLL NUMBERS (INSERT END) ---
// Logic: Appends each new roll number to the end of the singly linked list to maintain order.
void task2_roll_numbers() {
    int n, val;
    struct Node *head = NULL, *temp = NULL;

    printf("\n--- Task 2: Student Roll Numbers (End) ---\n");
    printf("Enter N and roll numbers:\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL) temp = temp->next;
            temp->next = newNode;
        }
    }

    temp = head;
    while (temp != NULL) {
        printf("%d%s", temp->data, (temp->next == NULL) ? "" : " ");
        temp = temp->next;
    }
    printf("\n");
}

// --- TASK 3: REVERSE LINKED LIST (INSERT FRONT) ---
// Logic: Populates the list by inserting at the front, then reverses the pointers.
void task3_reverse_linked_list() {
    int n, val;
    struct Node* head = NULL;

    printf("\n--- Task 3: Arun's Linked List Reversal ---\n");
    printf("Enter N and elements:\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = head;
        head = newNode;
    }

    // Display original (which is reversed due to front insertion)
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d%s", temp->data, (temp->next == NULL) ? "" : " ");
        temp = temp->next;
    }
    printf("\n");

    // Reverse logic
    struct Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;

    temp = head;
    while (temp != NULL) {
        printf("%d%s", temp->data, (temp->next == NULL) ? "" : " ");
        temp = temp->next;
    }
    printf("\n");
}

// --- TASK 4: MIDDLE ELEMENT (SLOW & FAST POINTER) ---
// Logic: Uses two pointers moving at different speeds to find the middle in one pass.
void task4_middle_element() {
    int n, val;
    struct Node* head = NULL;

    printf("\n--- Task 4: Dev's Middle Element Finder ---\n");
    printf("Enter N and elements:\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = head;
        head = newNode;
    }

    // Display list
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d%s", temp->data, (temp->next == NULL) ? "" : " ");
        temp = temp->next;
    }
    printf("\n");

    // Slow and Fast pointer logic
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Middle Element: %d\n", slow->data);
}

int main() {
    task1_logistics();
    task2_roll_numbers();
    task3_reverse_linked_list();
    task4_middle_element();
    return 0;
}