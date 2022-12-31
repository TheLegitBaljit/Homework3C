#include <stdio.h>
#define SIZE 50
void shift_element(int* arr, int i)
{
    int temp = i;
    while(temp > 0)
    {
        *(arr + temp)= *(arr + temp - 1);
        temp--;
    }
}
void insertion_sort(int array[], int len) {
    int i, j, val;
    for (i = 1; i < len; i++) {
        val = *(array + i);
        j = i - 1;
        while (j >= 0 && *(array +j) > val) {
            *(array +j+1) = *(array +j);
            j = j - 1;
        }
         *(array +j+1) = val;
    }
}
int main()
{
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        scanf(" %d",&(*(arr+i)));
    }
    insertion_sort(arr,SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        if(i==SIZE-1)
        {
          printf("%d",*(arr+i));
          break;
        }
        printf("%d,",*(arr+i));
    }
    printf("\n");

}