#include <stdlib.h>
/*
    Array list is an array with dynamic size.

    Available methods:
        - Create(arrayList, size); - creates an Array List with given <size> with all elements with value of '0'
        - Add(arrayList, object, size); - adds given <object> to the end of the <arrayList>
                         + increase <size> of array in 1;
        - AddAt(arrayList, object, index, size); - adds given <object> on given <index> to the <arrayList>
                                + moves all next elements by 1 towards
                                + increase <size> of array in 1;
        - Remove(arrayList, index, size); - removes <object> on given <index>
                                   + moves all next elements by 1 back
        - RemoveFirst(arrayList, object, size); - traverse the <arrayList> till the first match and removes it
                                 + moves all next elements by 1 back
        - Clear(arrayList, size); - clears an <arrayList>
*/


int * Create_ArrayList(int * arrayList, int size){
    int index;
    arrayList = malloc(size); // here and next allocating memory, so the array wont deallocate after function ends

    for (index = 0; index < size; ++index){
        arrayList[index] = 0;
    }
    return arrayList;
}

int * Add_ArrayList(int * arrayList, int object, int * size){
    int index;
    int * newArrayList = malloc(* size + 1); // can't change size of array in C,
    // so creating new and rewriting with additional element
    // We do it in each method below

    // rewriting old array to first <size> elements
    for (index = 0; index < * size; ++index){
        newArrayList[index] = arrayList[index];
    }

    // adding the <size + 1>th element
    newArrayList[* size] = object;

    ++(* size); // here and next change <size> of via pointer

    return newArrayList;
}

int * AddAt_ArrayList(int * arrayList, int object, int index, int * size){
    int index_;
    int * newArrayList = malloc(* size + 1);

    // till the element to insert we simply rewrite the old array
    for (index_ = 0; index_ < index; ++index_){
        newArrayList[index_] = arrayList[index_];
    }

    newArrayList[index] = object; // inserting new element

    // continue rewriting the old array
    for (index_ = index + 1; index_ < * size + 1; ++index_){
        newArrayList[index_] = arrayList[index_ - 1]; // arrayList doesn't have inserted element, so we step 1 position back
    }

    ++(* size);

    return newArrayList;
}

int * Remove_ArrayList(int * arrayList, int index, int * size){
    int index_;
    int * newArrayList = malloc(* size - 1);

    // rewriting the old array till the element to remove
    for (index_ = 0; index_ < index; ++index_){
        newArrayList[index_] = arrayList[index_];
    }

    // just skipping the element to remove in newArrayList
    for (index_ = index + 1; index_ < * size; ++index_){
        newArrayList[index_ - 1] = arrayList[index_];
    }

    --(* size); // size of the array decreases
    return newArrayList;
}

int * RemoveFirst_ArrayList(int * arrayList, int object, int * size){
    int index;

    // searching for the first match and call Remove() method with specific index
    for(index = 0; index < * size; ++index){
        if (arrayList[index] == object){
            arrayList = Remove_ArrayList(arrayList, index, size);
            break;
        }
    }

    return arrayList; // if we didn't find any match, we return intact array nevertheless
}

int * Clear_ArrayList(int * arrayList, int * size ){
    arrayList = Create_ArrayList(arrayList, 0); // replacing with empty ArrayList;

    * size = 0;

    return arrayList;
}
