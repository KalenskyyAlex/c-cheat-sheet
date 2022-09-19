#include <stdlib.h>
/*
    Queue is a ArrayList with following restrictions:
        - can add an element only to the beginning
        - can access only the last element

    Therefore Queue follows the rule: "Last in - last out"

    Available methods:
        - Create(queue, size); - creates an empty Queue with <size> of '0'
        - Enqueue(queue, object, size); - add <object> to the beginning of <queue>
                                 + increase <size> by 1
        - Dequeue(stack, size); - returns the last element of the <queue>
                        + removes the last element of the <Queue>
                        + decrease <size> by 1
        - Peek(stack, size); - returns the last element of the <queue>
        - Contains(stack, size, object); - returns '1' (true) if the <queue> contains <object>, otherwise '0' (false)
*/

int * Create_Queue(int * queue, int * size){
    queue = malloc(0); // making sure the <stack> is empty

    * size = 0; // making sure the <size> is '0'

    return queue;
}

void Enqueue_Queue(int ** queue, int object, int * size){
    int index;
    int * queueCopy = malloc(* size);

    // copying the old <queue> to rewrite it later
    for (index = 0; index < * size; ++index){
        queueCopy[index] = (* queue)[index];
    }

    // redefining + adding element to the beginning;
    (*queue) = malloc (* size + 1);
    (*queue)[0] = object;

    // rewriting from old
    for(index = 0; index < * size; ++index){
        (* queue)[index + 1] = queueCopy[index];
    }

    ++(* size);
}

int Dequeue_Queue(int ** queue, int * size){
    int index;
    int * queueCopy = malloc(* size - 1);
    int dequeued_element = (* queue)[* size - 1];

    // we just do not write the last element to the new <queue>
    for(index = 0; index < * size - 1; ++index){
        queueCopy[index] = (* queue)[index];
    }

    --(* size);

    (* queue) = queueCopy;
    return dequeued_element;
}

int Peek_Queue(int * queue, int size){
    return queue[size - 1];
}

int Contains_Queue(int * queue, int size, int object){
    int index = 0;

    for (index = 0; index < size; ++index){
        if (queue[index] == object){
            return 1;
        }
    }

    return 0;
}
