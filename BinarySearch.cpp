#include <iostream>
using namespace std;

// find element in the sorted array. If it is present print found else not found
int main()
{
    int array[9] = {2, 5, 8, 9, 11, 12, 19, 31, 33};
    int mid, start = 0, end = 8;
    int target = 8;
    while (start <= end)
    {
        mid = (start + end) / 2;

        if (array[mid] == target)
        {
            cout << "element found at index" << mid;
            break;
        }
        else if (array[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
}
