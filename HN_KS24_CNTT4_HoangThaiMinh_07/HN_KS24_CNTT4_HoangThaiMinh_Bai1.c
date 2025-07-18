#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Order {
    int id;
    char customer[20];
    int status;
    char total[10];
} Order;

typedef struct OrderManager {
    Order orders;
    struct OrderManager* next;
} OrderManager;

typedef struct OrderHistory {
    Order orders;
    struct OrderHistory* next;
} OrderHistory;

OrderHistory* createSinglyNode(Order order) {
    OrderHistory* newNode = (OrderHistory*)malloc(sizeof(OrderHistory));
    newNode->orders = order;
    newNode->next = NULL;
    return newNode;
}

OrderManager* insertNodeAtEnd(OrderManager* head, Order order) {
    OrderManager* newNode = createSinglyNode(order);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    OrderManager* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void displayOrderList(OrderManager* head) {
    OrderManager* current = head;
    if (head == NULL) {
        printf("Empty\n");
        return;
    }
    while(current != NULL){
        printf("ID:%d\n", current->orders.id);
        printf("Customer:%s\n", current->orders.customer);
        printf("Status:%d\n", current->orders.status);
        printf("Total:%s\n", current->orders.total);
        current = current->next;
    }
}

OrderManager* deleteNodeAt(OrderManager* head, int id) {
    if(head == NULL) {
        printf("Empty\n");
        return head;
    }
    OrderManager* current = head;
    OrderManager* prev = NULL;
    while(current != NULL && current->orders.id != id) {
        prev = current;
        current = current->next;
    }
    if(current == head) {
        head = head->next;
        free(current);
        return head;
    }
    prev->next = current->next;
    free(current);
    return head;
}

void updateOrderListById(OrderManager* head, int id) {
    if (head == NULL) {
        printf("Empty\n");
        return;
    }
    OrderManager* current = head;
    while(current != NULL && current->orders.id != id) {
        current = current->next;
    }
    if (current == head) {
        head = head->next;
        free(current);
        return;
    }
    printf("Old Customer:%s\n", current->orders.customer);
    printf("Old Total:%s\n", current->orders.total);
    printf("New Customer:");
    scanf("%s", current->orders.customer);
    printf("New Total:");
    scanf("%s", current->orders.total);
}

void sortTotalByBubbleSort(OrderManager* head) {
    if (head == NULL) return;
    int swapped;
    OrderManager* ptr1;
    OrderManager* lptr = NULL;
    do {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != lptr) {
            if (ptr1->orders.total > ptr1->next->orders.total) {
                Order temp = ptr1->orders;
                ptr1->orders = ptr1->next->orders;
                ptr1->next->orders = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void searchCourseByCustomer(OrderManager* head, char* title) {
    OrderManager* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->orders.customer, title) == 0) {
            printf("Tim thay:\n");
            printf("Course ID: %d\n", temp->orders.id);
            printf("Customer: %s\n", temp->orders.customer);
            printf("Status: %d\n", temp->orders.status);
            printf("Total: %s\n\n", temp->orders.total);
        }
        temp = temp->next;
    }
}

int main() {
    int choice;
    int id = 1;
    OrderManager* head = NULL;
    OrderHistory* head2 = NULL;
    do {
        printf("MENU\n");
        printf("1. Add order\n");
        printf("2. Display order\n");
        printf("3. Delete order\n");
        printf("4. Update order\n");
        printf("5. Mark order\n");
        printf("6. Sort order\n");
        printf("7. Search order\n");
        printf("8. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                Order newOrder;
                newOrder.id = id++;
                printf("Customer:");
                scanf("%s", newOrder.customer);
                printf("Status(0/1):");
                scanf("%d", &newOrder.status);
                printf("Total:");
                scanf("%s", newOrder.total);
                head = insertNodeAtEnd(head, newOrder);
                break;
            case 2:
                printf("ORDER LIST\n");
                displayOrderList(head);
                break;
            case 3:
                int deleteId;
                printf("Enter delete ID:");
                scanf("%d", &deleteId);
                deleteNodeAt(head, deleteId);
                break;
            case 4:
                int updateId;
                printf("Enter update ID:");
                scanf("%d", &updateId);
                updateOrderListById(head, updateId);
                break;
            case 5:
                break;
            case 6:
                sortTotalByBubbleSort(head);
                break;
            case 7:
                char name[20];
                printf("Enter name:");
                scanf("%s", name);
                searchCourseByCustomer(head, name);
                break;
            case 8:
                printf("Exit...\n");
                break;
            default:
                printf("Invalid Choice\n");
        }
    } while (choice != 8);
    return 0;
}