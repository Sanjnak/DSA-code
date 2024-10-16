#include <iostream>
using namespace std;

bool isArrayEmpty(int &length)
{
    return (length) <= 0;
}

void printArray(int *arr, int &length)
{
    if (isArrayEmpty(length))
    {
        cout << "Array is empty.\n";
        return;
    }
    for (int i = 0; i < (length); i++)
    {
        cout << arr[i] << " ";
    }
    return;
}

void insertionSort(int *arr, int &length)
{
    if (isArrayEmpty(length))
    {
        cout << "Array is empty.";
        return;
    }
    else
    {
        for (int i = 1; i < length; i++)
        {
            int temp = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > temp)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;
        }
        cout << "Sorted array is : ";
        printArray(arr, length);
        return;
    }
}

void insertElement(int *arr, int &length, int index, int element)
{
    arr[length++];

    if (index < 0 || index > length - 1)
    {
        cout << "Index doesn't exist!";
        return;
    }

    for (int i = 0; i < length; i++)
    {
        if (index == i)
        {
            for (int j = length - 1; j >= i; j--)
            {
                arr[j + 1] = arr[j];
            }
            arr[index] = element;
        }
    }
    printArray(arr, length);
    return;
}

void deleteElement(int *arr, int &length, int index)
{
    if (isArrayEmpty(length))
    {
        cout << "Array is empty, first add an element.";
        return;
    }
    if (index < 0 || index > length - 1)
    {
        cout << "Invalid index!";
        return;
    }
    for (int i = 0; i < length; i++)
    {
        if (index == i)
        {
            for (int j = i; j < length - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            break;
        }
    }
    arr[length--];

    printArray(arr, length);
    return;
}

void linearSearch(int *arr, int &length, int element)
{
    if (isArrayEmpty(length))
    {
        cout << "Array is empty!\n";
        return;
    }
    for (int i = 0; i < length; i++)
    {
        if (element == arr[i])
        {
            cout << "Element found at index " << i + 1;
            return;
        }
    }
    cout << "Element not found at any index!";
    return;
}

void binarySearch(int *arr, int &length, int element, int beg, int end)
{
    if (isArrayEmpty(length))
    {
        cout << "Array is empty!\n";
        return;
    }
    int mid = (beg + end) / 2;
    if (beg <= end && arr[mid] != element)
    {
        if (element < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            beg = mid + 1;
        }
        binarySearch(arr, length, element, beg, end);
    }
    else
    {
        if (arr[mid] == element)
        {
            cout << "\nElement " << element << " is at index " << mid + 1;
        }
        else
        {
            cout << "\nElement not found at any index!";
        }
    }
    return;
}

int main()
{
    int size;
    cout << "Enter size of array:";
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element: ";
        cin >> arr[i];
    }

    cout << "Array is: ";
    printArray(arr, size);

    int opt;

    do
    {
        cout << "\n\n1.Traverse an array \n2.Insert an element at an index\n";
        cout << "3.Delete any element \n4.Linear Search for any element \n5.Binary Search for any element \n6.Sort an array \n7.Exit\n\n";

        cout << "Enter your option :";
        cin >> opt;

        int n;
        switch (opt)
        {
        case 1:
            printArray(arr, size);
            break;

        case 2:
            cout << "Enter index:";
            cin >> n;
            int ele;
            cout << "Enter element:";
            cin >> ele;
            insertElement(arr, size, n - 1, ele);
            break;

        case 3:
            cout << "Enter index:";
            cin >> n;
            deleteElement(arr, size, n - 1);
            break;

        case 4:
            cout << "Enter element to search:";
            cin >> n;
            linearSearch(arr, size, n);
            break;

        case 5:
            cout << "Enter element to search:";
            cin >> n;
            insertionSort(arr, size);
            binarySearch(arr, size, n, 0, size - 1);
            break;

        case 6:
            insertionSort(arr, size);
            break;

        case 7:
            break;

        default:
            cout << "Invalid option !";
            break;
        }
    } while (opt != 7);

    return 0;
}