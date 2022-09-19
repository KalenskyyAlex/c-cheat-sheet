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

struct Node_LinkedList * Create_LinkedList(struct Node_LinkedList * linkedList, int * size){
    struct Node_LinkedList nullNode;
    nullNode.data = NULL;
    nullNode.next = NULL;

    linkedList = & nullNode;

    * size = 0; // making sure the <size> is '0'

    return linkedList;
}

void AddTail_LinkedList(struct Node_LinkedList ** linkedList, int object, int * size){
    /*
        to add Node to the 'tail':
            1. Create new 'tail' Node
            2. Set Node's <data> to <object>
            3. Set previous 'tail' Node's pointer to new 'tail' Node
            4. Set new 'tail' Node's to NULL
    */
    int index = 0;

    struct Node_LinkedList * head = * linkedList; // we need to traverse from 'head' to 'tail'

    struct Node_LinkedList * newTail; // step 1

    (* newTail).data = & object; // step 2
    (* newTail).next = NULL; // step 4

    // if <linkedList> is filled with nullNode, just replace it
    if ((* head).data == NULL){
        * linkedList = newTail; // a 'tail' is a 'head' as well in this case
    }
    else{
        // getting to actual 'tail'
        for (index = 0; index < * size; ++index){
            head = (* head).next;
        }

        (* head).next = newTail; // step 3

    }
    ++(* size); // increase <size>
    // note: size isn't actually needed for LinkedList, it's used to safely traverse LinkedList
}

void AddHead_LinkedList(struct Node_LinkedList ** linkedList, int object, int * size){
    /*
        to add Node to the 'head'
            1. Create new 'head' Node
            2. Set Node's <data> to <object>
            3. Point new 'head' to old;
            4. Point linkedList to new 'head'
    */

    struct Node_LinkedList * head = * linkedList;

    struct Node_LinkedList * newHead; // step 1
    (* newHead).data = & object; // step 2

    // if <linkedList> is filled with nullNode, just replace it
    if ((* head).data == NULL){
        (* newHead).next = NULL;
        * linkedList = newHead; // a 'head' it a 'tail' as well in this case
    }
    else{
        (* newHead).next = head; // step 3
        * linkedList = newHead; // step 4
    }
}


void Print_LinkedList(struct Node_LinkedList * linkedList, int size){
    for (int index = 0; index < size; ++index){
        printf("%d ", (* linkedList).data);
        linkedList = (* linkedList).next;
    }
    printf("\n");
}
