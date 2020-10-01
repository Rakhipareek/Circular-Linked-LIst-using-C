#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};
typedef struct Node cll;
void traverse(cll * head);
cll * insertAtFirst(cll * head, int element);
cll * insertAtLast(cll * head, int element);
cll * insertAtIndex(cll * head, int element, int index);
cll * insertAtData(cll * head, int element, int data);

void traverse(cll * head)
{
    struct Node * p = head;
    do
    {
        printf("Element: %d\n", p->data);
        p = p->next;
    }while(p != head);
}

cll * insertAtFirst(cll * head, int element)
{
    cll * node = (cll *)malloc(sizeof(cll));
    node->data = element;

    cll * p = head;
    do
    {
        p = p->next;
    }while(p->next != head);
    p->next = node;
    node->next = head;
    head = node;
    return head;
}
cll * insertAtLast(cll * head, int element)
{
    cll * node = (cll *)malloc(sizeof(cll));
    node->data = element;
    cll * p = head;
    do{
        p = p->next;
    }while(p->next != head);
    p->next = node;
    node->next = head;

    return head;
}

cll * insertAtIndex(cll * head, int element, int index)
{
    cll * node = (cll *)malloc(sizeof(cll));
    node->data = element;

    cll * p = head;
    int i = 0;
    while(i < (index-1))
    {
        p = p->next;
        i++;
    }
    cll * q = p->next;
    p->next = node;
    node->next = q;
    return head;
}
cll * insertAtData(cll * head, int element, int data)
{
    cll * node = (cll *)malloc(sizeof(cll));
    node->data = element;

    cll * p = head;
    cll * q = p->next;
    while(q->data != data)
    {
        p = p->next;
        q = q->next;
    }
    p->next = node;
    node->next = q;
    return head;
}

int main()
{

    cll * head = (cll *)malloc(sizeof(cll));
    cll * second = (cll *)malloc(sizeof(cll));
    cll * third = (cll *)malloc(sizeof(cll));
    cll * fourth = (cll *)malloc(sizeof(cll));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = head;
    
    int n;
    printf("Enter 1 for traverse only, 2 for insert at first, 3 for insert at last, 4 for inserting at index, 5 for inserting a node at the node having a data value\n");
    scanf("%d", &n);
    switch(n)
    {
        case 1:
            {
                printf("Elements  of circular linked list are: \n");
                traverse(head);
                break;
            }
        case 2:
            {
                printf("\nElements of circular linked list after inserting a node at start are: \n");
                head = insertAtFirst(head, 98);
                traverse(head);
                break;
            }
        case 3:
            {
                printf("\nElements of circular linked list after inserting a node at the end are: \n");
                head = insertAtLast(head, 898);
                traverse(head);
                break;
            }
        case 4:
            {
                int index = 2;
                printf("\nElements of circular linked list after inserting a node at the index %d are: \n", index);
                head = insertAtIndex(head, 8976, index);
                traverse(head);
                break;
            }
        case 5:
            {
                int data = 8976;
                printf("\nElements of circular linked list after inserting a node inplace of node having data value %d are: \n", data);
                head = insertAtData(head, 888, data);
                traverse(head);
                break;
            }
        default:
            {
                printf("!!!!!!!!!!!ERROR!!!!!!!!!Wrong Choice, Try again\n");
                break;
            }

    }
    return 0;
}
