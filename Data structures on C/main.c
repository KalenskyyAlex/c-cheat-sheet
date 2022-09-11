#include <stdio.h>
#include <stdlib.h>

void printStructure(int * structure, int size);

void arrayListTest();
void stackTest();

int main()
{
    printf("Array List\n\n");
    arrayListTest();

    printf("\nStack\n");
    stackTest();
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
    int index;

    int size = 0;
    int * stack = Create_Stack(stack, & size);

    printStructMsg(stack, size, "Empty new Stack");

    Push_Stack(stack, 3, & size);

    printStructMsg(stack, size, "Pushed some values to the Stack");
}
