#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

void insertStart(struct Node **head, int data) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    newNode->prev = NULL;

    if (*head != NULL)
        (*head)->prev = newNode;
    *head = newNode;
}

void insertLast(struct Node **head, int data) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
    } else {
        struct Node *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void insertPosition(struct Node **head, int pos, int data) {
    int len = getLength(*head);
    if (pos < 1 || pos > len + 1) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1)
        insertStart(head, data);
    else {
        struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
        newNode->data = data;

        struct Node *temp = *head;
        for (int i = 1; i < pos - 1; i++)
            temp = temp->next;

        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
        if (newNode->next != NULL)
            newNode->next->prev = newNode;
    }
}

void deleteNode(struct Node **head, struct Node *del) {
    if (*head == del)
        *head = del->next;
    else
        del->prev->next = del->next;

    if (del->next != NULL)
        del->next->prev = del->prev;
    free(del);
}

int search(struct Node *head, int key) {
    struct Node *temp = head;
    while (temp != NULL) {
        if (temp->data == key)
            return 1;
        temp = temp->next;
    }
    return 0;
}

int getLength(struct Node *node) {
    int len = 0;
    while (node != NULL) {
        node = node->next;
        len++;
    }
    return len;
}

void display(struct Node *head) {
    printf("List in Forward direction: ");
    while (head != NULL) {
        printf(" %d ", head->data);
        head = head->next;
    }
    printf("\n");

    struct Node *end = head;
    while (end != NULL && end->next != NULL)
        end = end->next;

    printf("List in backward direction: ");
    while (end != NULL) {
        printf(" %d ", end->data);
        end = end->prev;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;
    int ch, data, pos;
    do {
        printf("\n\n1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a specific position\n");
        printf("4. Delete a node\n");
        printf("5. Search for a node\n");
        printf("6. Display the list\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertStart(&head, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertLast(&head, data);
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter data to insert at position %d: ", pos);
                scanf("%d", &data);
                insertPosition(&head, pos, data);
                break;
            case 4:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                if (search(head, data)) {
                    struct Node *del = head;
                    while (del != NULL) {
                        if (del->data == data) {
                            deleteNode(&head, del);
                            printf("Node with data %d deleted successfully.\n", data);
                            break;
                        }
                        del = del->next;
                    }
                } else {
                    printf("Node with data %d not found.\n", data);
                }
                break;
            case 5:
                printf("Enter data to search: ");
                scanf("%d", &data);
                if (search(head, data))
                    printf("Node with data %d found.\n", data);
                else
                    printf("Node with data %d not found.\n", data);
                break;
            case 6:
                display(head);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (ch != 7);
    return 0;
}