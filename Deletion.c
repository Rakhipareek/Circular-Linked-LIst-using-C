#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node * next;
};
typedef struct Node cll;
void traverse(cll * head);
cll * deletingFirstNode(cll * head);
cll * deletingLastNode(cll * head);
cll * deletingAtIndex(cll * head, int index);
cll * deletingAtData(cll * head, int data);

void traverse(cll * head)
{
    struct Node * p = head;
    do
    {
        printf("Element: %d\n", p->data);
        p = p->next;
    }while(p != head);
}
cll * deletingFirstNode(cll * head)
{
    cll * ptr = head;
    cll * q = ptr->next;
    while (q->next != head)
    {
        q = q->next;
    }

    head = head->next;
    q->next = head;
    free(ptr);


    return head;
}
cll * deletingLastNode(cll * head)
{
    cll * p = head;
    cll * q = head->next;

    while(q->next != head)
    {
        p = p->next;
        q = q->next;
    }
    p->next = head;
    free(q);
    return head;
}
cll * deletingAtIndex(cll * head, int index)
{
    int i = 0;
    cll * p = head;
    cll * q = head->next;
    while(i<index-1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    cll * n = q->next;
    p->next = n;
    free(q);
    return head;

}
cll * deletingAtData(cll * head, int data)
{
    cll * ptr = head;
    cll * q = head->next;
    while(q->data != data)
    {
        ptr = ptr->next;
        q = q->next;
    }
    ptr->next = q->next;
    free(q);
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

    printf("Elements  of circular linked list are: \n");
    traverse(head);


    /*
    ////////////////@@@@@@@@@@@@   deleting first node   @@@@@@@@@@@@@///////////////////
    printf("Elements  of circular linked list after deleting the first node are: \n");
    head = deletingFirstNode(head);
    traverse(head);
    */

    /*
    //////////////@@@@@@@@@@@@@@@   deleting last node    @@@@@@@@@@@@@@@//////////////
    printf("Elements  of circular linked list after deleting the last node are: \n");
    head = deletingLastNode(head);
    traverse(head);
    */


    /*
    ////////////          deleting in between node at an index      ///////////////////
    int index = 2;
    printf("Elements  of circular linked list after deleting the node at index %d are: \n", index);
    head = deletingAtIndex(head, index);
    traverse(head);
    */



    ////////////          deleting in between node having data value      ///////////////////
    int data = 2;
    printf("Elements  of circular linked list after deleting the node having data value = %d are: \n", data);
    head = deletingAtData(head, data);
    traverse(head);


    return 0;
}
