#include<iostream>
using namespace std;

void bubble_sort(int* arr, int size)
{
    int flag = 1;
    while(flag)
    {
        flag = 0;
        for(int i=0; i<size; i++)
        {
            if(arr[i]>arr[i+1])
            {
                int t = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = t;
                flag = 1;
            }
        }
    }
}

void insertion_sort (int *arr, int size)
{
    int j, temp;
	for (int i = 0; i < size; i++)
	{
		j = i;

		while (j > 0 && arr[j] < arr[j-1])
		{
			  temp = arr[j];
			  arr[j] = arr[j-1];
			  arr[j-1] = temp;
			  j--;
        }
    }
}

void select_Sort(int *arr, int size)
{
	int pos_min,temp;

	for (int i=0; i < size-1; i++)
	{
	    pos_min = i;

		for (int j=i+1; j <size; j++)
		{

		if (arr[j] < arr[pos_min])
                   pos_min=j;
		}
            if (pos_min != i)
            {
                 temp = arr[i];
                 arr[i] = arr[pos_min];
                 arr[pos_min] = temp;
            }
	}
}

int main()
{
    int arr[10] = {10,1,4,15,5,2,3,8,4,6};
    insertion_sort(arr,10);

    for(int i=0; i<10; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
