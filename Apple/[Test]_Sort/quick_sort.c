#include<stdio.h>

void swap (int *a, int *b) {
    int tmp = 0;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int Partition(int *arr, int low, int high) {
    int pivot;
    int front_p, rear_p;

    pivot = arr[high];
    front_p = low;
    rear_p = low - 1;

    while (front_p < high) {
        if (arr[front_p] < pivot) {
            rear_p++;
            swap(&arr[rear_p], &arr[front_p]);
        }
        
        front_p++;
    }

    swap(&arr[rear_p + 1], &arr[high]);

    return (rear_p + 1);
}

void QuickSort(int *arr, int low, int high) {
    int return_high = 0;

    if (low < high) {
        return_high = Partition(arr, low, high);

        QuickSort (arr, low, return_high - 1);
        QuickSort (arr, return_high + 1, high);
    }
}

int main (void) {
    int input1[] = {-1,0,1,2,-1,-4};
    int input2[] = {0, 0, 0};
    int input3[] = {10, 7, 8, 9, 1, 5};
    int index = 0;

    QuickSort (input1, 0, sizeof(input1)/sizeof(input1[0]) - 1);
    QuickSort (input2, 0, sizeof(input2)/sizeof(input2[0]) - 1);
    QuickSort (input3, 0, sizeof(input3)/sizeof(input3[0]) - 1);

    for (index = 0; index < sizeof(input1)/sizeof(input1[0]); index++)
        printf("%d ", input1[index]);
    printf("\n");

    for (index = 0; index < sizeof(input2)/sizeof(input2[0]); index++)
        printf("%d ", input2[index]);
    printf("\n");

    for (index = 0; index < sizeof(input3)/sizeof(input3[0]); index++)
        printf("%d ", input3[index]);
    printf("\n");

    return 0;
}

#if 0
void quicksort(int number[25],int first,int last)
{
    int i, j, pivot, temp;
    
    if(first<last) {
        pivot = first;
        i = first;
        j = last;

        while(i<j) {
            while(number[i]<=number[pivot]&&i<last) i++;
            while(number[j]>number[pivot]) j--;

            if(i<j) {
                temp=number[i];
                number[i]=number[j];
                number[j]=temp;
            }
        }
    
        temp=number[pivot];
        number[pivot]=number[j];
        number[j]=temp;

        quicksort(number,first,j-1);
        quicksort(number,j+1,last);
    }
}

int main() {
    int i, count, number[25];

    printf("Enter some elements (Max. - 25): ");
    scanf("%d",&count);

    printf("Enter %d elements: ", count);

    for(i=0; i < count; i++) scanf("%d",&number[i]);

    quicksort(number,0,count-1);

    printf("The Sorted Order is: ");

    for(i=0; i < count; i++) printf(" %d",number[i]);

    return 0;

}
#endif