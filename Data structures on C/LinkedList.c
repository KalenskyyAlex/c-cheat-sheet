#include <stdlib.h>
#include <stdio.h>
/*
    Linked list is a type of collection, where one element points to another
        - it's a dynamic array
        - represented as pointer to the fist Node
        - traverse via pointers to the next element from head to tail

    Available methods:
        - Create(linkedList, size); - create empty <linkedList>
                                      + set <size> to 0
        - Add_Tail(linkedList, object, size); - adds an element <object> to the end of <linkedList>
                                                + increase <size> by 1
        - Add_Head(linkedList, object, size); - adds an element <object> to the beginning of <linkedList>
                                                + increase <size> by 1
        - Add_At(linkedList, object, index, size); - adds an element <object> at specific <index> to <linkedList>
                                                     + increase <size> by 1
        - Remove_Tail(linkedList, size); - removes an element from the end of <linkedList>
                                           + decrease <size> by 1
        - Remove_Head(linkedList, size); - removes an element from the beginning of <linkedList>
                                           + decrease <size> by 1
        - Remove_At(linkedList, index, size) - removes an element at specific <index> from <linkedList>
                                               + decrease <size> by 1
        - Contains(linkedList, index, size) - returns '1' (true) if the <stack> contains <object>, otherwise '0' (false)

        - Print(linkedList, size) - prints <linkedList>
*/

// use a struct, to both contain data(value) and pointer to the next element
struct Node_LinkedList{
    int * data;
    struct Node_LinkedList * next;
};

void Create_LinkedList(struct Node_LinkedList * linkedList, int * size){
    struct Node_LinkedList nullNode;
    nullNode.data = NULL;
    nullNode.next = NULL;

    * linkedList = nullNode;

    * size = 0; // making sure the <size> is '0'
}

void AddTail_LinkedList(struct Node_LinkedList * linkedList, int object, int * size){
    /*
        to add Node to the 'tail':
            1. Create new 'tail' Node
            2. Set Node's <data> to <object>
            3. Set previous 'tail' Node's pointer to new 'tail' Node
            4. Point new 'tail' Node to NULL
    */

    // steps 1, 2, 4
    struct Node_LinkedList newTail;
    newTail.data = malloc(1); // need to allocate some memory before putting a data in it
    * (newTail.data) = object;
    newTail.next = NULL; // new 'tail' points to nothing

    struct Node_LinkedList * head = linkedList; // get 'head', which is exactly the <linkedList>

    // if our 'head' is <nullNode> (see Create_LinkedList) we should actually replace it by our <newTail> node
    if ((* head).data == NULL){
        * linkedList = newTail; // step 3
    }
    else{
        // otherwise we go through up to the last element - our current 'tail'
        while((* head).next != NULL){
            head = (* head).next;
        }
        printf("data: %p\n", (* head).next);

        (* head).next = & newTail; // step 3

        printf("data: %p\n", (* head).next);
        printf("data: %d\n", *((* head).data));
        printf("data: %p\n", & newTail);
        printf("data: %d\n", *(newTail.data));
    }

    ++(* size);
}

void AddHead_LinkedList(struct Node_LinkedList * linkedList, int object, int * size){
    /*
        to add Node to the 'head'
            1. Create new 'head' Node
            2. Set Node's <data> to <object>
            3. Point new 'head' to old;
            4. Point linkedList to new 'head'
    */
}


void Print_LinkedList(struct Node_LinkedList linkedList, int size, char * additional){
    printf("%s: ", additional);
    for (int index = 0; index < size - 1; ++index){
        printf("%d -> ", *(linkedList.data));
        linkedList = *(linkedList.next);
    }

    printf("%d -> ", *(linkedList.data));

    printf("NULL\n");
}
