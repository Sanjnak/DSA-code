#include <iostream>
using namespace std;

bool checkUnderflow(int tos)
{
    return (tos == -1);
}

int popStack(int *arr, int &tos)
{

    if (checkUnderflow(tos))
    {
        cout << "Stack Underflow!";
        return -1;
    }
    int data = arr[tos];
    tos--;
    return data;
}

void pushStack(int *arr, int &tos, int element)
{
    tos++;
    arr[tos] = element;
    return;
}
void swapElements(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void quickFunc(int *arr, int size, int left, int right, int & pivot)
{
    //right to left
    while (arr[pivot] <= arr[right] && pivot != right)
    {
        right--;
    }
    if (pivot == right)
    {
        return;
    }
    if (arr[pivot] > arr[right])
    {
        swapElements(arr[pivot], arr[right]);
        pivot = right;
    }
    //left to right
    while (arr[pivot] >= arr[left] && pivot != left)
    {
        left++;
    }
    if (pivot == left)
    {
        return;
    }
    if (arr[pivot] < arr[left])
    {
        swapElements(arr[pivot], arr[left]);
        pivot = left;
    }
    return;
}

void quickSort(int *arr, int size)
{
    int lower[size];
    int upper[size];
    int topLower = -1;
    int topUpper = -1;
    if(size > 1){
        pushStack(lower, topLower, 0);
        pushStack(upper, topUpper, size-1);
    }
    while(!checkUnderflow(topLower)){
        int beg = popStack(lower, topLower);
        int end = popStack(upper, topUpper);
        int pivot = beg;
        quickFunc(arr, size, beg, end, pivot);

        if(beg < pivot-1){
            pushStack(lower, topLower, beg);
            pushStack(upper, topUpper, pivot+1);
        }
        else if(pivot+1 < end){
            pushStack(lower, topLower, pivot+1);
            pushStack(upper, topUpper, end);
        }
    }
}

int main()
{
    int n = 0;
    cout << "Enter number of elements for array: ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Unsorted Array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    quickSort(arr, n);

    cout << "Sorted Array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}