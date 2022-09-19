#include <stdio.h>
#include <stdlib.h>
#include "Queue.c"

void printStructure(int * structure, int size);

void arrayListTest();
void stackTest();
void queueTest();

int main(){
    printf("Array List\n\n");
    arrayListTest();

    printf("\nStack\n");
    stackTest();

    printf("\nQueue\n");
    queueTest();
}

void printStructure(int * structure, int size){
    int index;

    for(index = 0; index < size; ++index){
        printf("%d ", structure[index]);
    }
    printf("\n");
}

void printStructMsg(int * structure, int size, char * additional){
    printf("%s: ", additional);
    printStructure(structure, size);
}

void arrayListTest(){
    int index;

    int * ArrayList;
    int size = 0;
    ArrayList = Create_ArrayList(ArrayList, size); // creating an empty arrayList

    printStructMsg(ArrayList, size, "Empty at first Array List");

    for (index = 0; index < 3; ++index){
        ArrayList = Add_ArrayList(ArrayList, index, & size); // adding an element
    }

    printStructMsg(ArrayList, size, "Added \'0\', \'1\', \'2\' to the end");

    // inserting
    ArrayList = AddAt_ArrayList(ArrayList, 2, 1, & size);

    ArrayList = AddAt_ArrayList(ArrayList, 4, 1, & size);
    // inserting

    printStructMsg(ArrayList, size, "Inserted \'2\', than \'4\' at the 2nd place");

    ArrayList = Remove_ArrayList(ArrayList, 1, & size); // removing an element at 3rd position

    printStructMsg(ArrayList, size, "2nd element was removed");

    ArrayList = RemoveFirst_ArrayList(ArrayList, 2, & size); // searching for '2' and removing first match

    printStructMsg(ArrayList, size, "Remove first \'2\'");

    ArrayList = Clear_ArrayList(ArrayList, & size);

    printStructMsg(ArrayList, size, "Array List is cleared");
}

void stackTest(){
    int size = 0;
    int * stack = Create_Stack(stack, & size);

    printStructMsg(stack, size, "Empty new Stack");

    Push_Stack(& stack, 3, & size);
    Push_Stack(& stack, 8, & size);
    Push_Stack(& stack, -1, & size);

    printStructMsg(stack, size, "Pushed some values to the Stack");

    int popped_element = Pop_Stack(&stack, &size);
    printStructMsg(stack, size, "Popped one element from the Stack");
    printf("Popped value: %d\n", popped_element);

    int peeked_element = Peek_Stack(stack, size);
    printStructMsg(stack, size, "Peeked the last element in the Stack");
    printf("Last element: %d\n", peeked_element);

    int contains = Contains_Stack(stack, size, 2);
    if (contains == 0){
        printf("Stack does not contain 2\n");
    }
    else{
        printf("Stack contains 2\n");
    }

    contains = Contains_Stack(stack, size, 3);
    if (contains == 0){
        printf("Stack does not contain 3\n");
    }
    else{
        printf("Stack contains 3\n");
    }
}

void queueTest(){
    int size = 0;
    int * queue = Create_Queue(queue, & size);

    printStructMsg(queue, size, "Empty new Queue");

    Enqueue_Queue(& queue, 3, & size);
    Enqueue_Queue(& queue, 0, & size);
    Enqueue_Queue(& queue, 8, & size);

    printStructMsg(queue, size, "Enqueued some values");

    int dequeued = Dequeue_Queue(& queue, & size);
    printStructMsg(queue, size, "Dequeued last value");
    printf("Dequeued value: %d\n", dequeued);

    int peeked_element = Peek_Stack(queue, size);
    printStructMsg(queue, size, "Peeked the last element in the Queue");
    printf("Last element: %d\n", peeked_element);

    int contains = Contains_Stack(queue, size, 2);
    if (contains == 0){
        printf("Queue does not contain 2\n");
    }
    else{
        printf("Queue contains 2\n");
    }

    contains = Contains_Queue(queue, size, 8);
    if (contains == 0){
        printf("Queue does not contain 8\n");
    }
    else{
        printf("Queue contains 8\n");
    }
}
