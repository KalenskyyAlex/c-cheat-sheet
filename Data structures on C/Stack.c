/*
    Stack is a ArrayList with following restrictions:
        - can add an element only to the end
        - can access only the last element

    Therefore Stack follows the rule: "Last in - first out"

    Available methods:
        - Create(stack, size); - creates an empty Stack with <size> of '0'
        - Push(stack, object); - add <object> to the end of <stack>
                                 + increase <size> by 1
        - Pop(stack); - returns the last element of the <stack>
                        + removes the last element of the <stack>
                        + decrease <size> by 1
        - Peek(stack); - returns the last element of the <stack>
        - Contains(stack, object); - returns '1' (true) if the <stack> contains <object>, otherwise '0' (false)
*/

int * Create_Stack(int * stack, int * size){
    stack = malloc(0); // making sure the <stack> is empty

    * size = 0; // making sure the <size> is '0'

    return stack;
}

void Push_Stack(int * stack, int object, int * size){
    int index;

    // copying the old stack to rewrite it later
    int * stackCopy = malloc(* size);

    for (index = 0; index < size; ++index){
        stackCopy[index] = stack[index];
    }

    stack = malloc (* size + 1);

    // rewriting from old
    for(index = 0; index < * size; ++index){
        stack[index] = stackCopy[index];
    }

    // adding element to the end;
    stack[* size] = object;

    ++(* size);
}

int Pop_Stack(int * stack, int * size){
    int index;
    int * newStack = stack;


    // we just do not write the last element to the <newStack>
    for(index = 0; index < * size - 1; ++index){
        newStack[index] = stack[index];
    }

    --(* size);

    stack = newStack;
    return newStack[* size - 1];
}
