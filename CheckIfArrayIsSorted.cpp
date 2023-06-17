#include <iostream>
#include <vector>
using namespace std;

bool IsArraySorted(vector<int> &a)
{
    int i = 1;

    while (i < a.size() - 1)
    {
        if (a[i] < a[i - 1])
            return false;

        i++;
    }
    return true;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> arr1 = {5, 4, 6, 7, 8};

    cout << IsArraySorted(arr) << endl;
    cout << IsArraySorted(arr1) << endl;

    return 0;
}