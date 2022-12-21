#include <stdio.h>

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
        val = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > val) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = val;
    }
}
int main()
{
    int arr[] = {1,2,3,4,5,0};
    int len = sizeof(arr) / sizeof(arr[0]);
    insertion_sort(arr,len);
   for(int i=0; i < len; i++)
       printf("%d  ",arr[i]);

}