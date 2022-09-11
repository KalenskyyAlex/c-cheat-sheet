#include <stdio.h>

#include <stdlib.h>


int * merge_sort(int * array, int size);

int main()
{
    int n;
    scanf("%d", &n);

    int unsorted_array[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &unsorted_array[i]);
    }

    int * sorted_array = merge_sort(unsorted_array, n);

    for (int i = 0; i < n; i++){
        printf("%d ", sorted_array[i]);
    }
}

int * merge_sort(int * array, int size)
{
    if (size == 1){
        return array;
    }
    else{
        int size1 = size / 2;
        int size2 = size / 2;

        if (size % 2 == 1)
        {
            size2 ++;
        }

        int part1[size1];
        for (int i = 0; i < size1; i++)
        {
            part1[i] = array[i];
        }

        int part2[size2];
        for (int i = 0; i < size2; i++)
        {
            part2[i] = array[size1 + i];
        }

        int * part1_sorted = merge_sort(part1, size1);
        int * part2_sorted = merge_sort(part2, size2);

        int index1 = 0;
        int index2 = 0;

        for (int index = 0; index < size; index++)
        {
            if (index1 >= size1 || (part2_sorted[index2] < part1_sorted[index1] && !(index2 >= size2)))
            {
                array[index] = part2_sorted[index2];
                index2++;
            }
            else if ((index1 < size1 && part1_sorted[index1] <= part2_sorted[index2]) || index2 >= size2)
            {
                array[index] = part1_sorted[index1];
                index1++;
            }
        }

        return array;
    }
}
