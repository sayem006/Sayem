#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
   struct Node* current = *head;
    for (int i = 0; current != NULL && i < position - 1; i++) {
        current = current->next;
    }
   if (current == NULL) {
        printf("Position out of bounds. Inserting at the end instead.\n");
    }
   newNode->next = current ? current->next : NULL;
    if (current) {
        current->next = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode; // Insert at the end
    }
}
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head = NULL;
    int n, data, position;
   printf("Enter the number of elements to create the linked list: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        insertAtPosition(&head, data, i); // Insert at the end initially
    }
   printf("Linked List before insertion: ");
    printList(head);

    printf("Enter the value to insert: ");
    scanf("%d", &data);
    printf("Enter the position to insert at (0-based index): ");
    scanf("%d", &position);
   insertAtPosition(&head, data, position);
    printf("Linked List after insertion: ");
    printList(head);
   struct Node* current = head;
    struct Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    return 0;
}
