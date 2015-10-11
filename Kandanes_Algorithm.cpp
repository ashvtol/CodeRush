#include<iostream>
using namespace std;


/* Kandane's Algorithm helps to find out the largest sum
of a contiguous sub-array.

The algorithm is pretty staright forward.
1. Initialize two variables max_current, max_so_far to a[0]
2. Start from a[i] and compute the value of max_current.
3. If max_current surpasses the value of max_so_far, update
   the value of the max_so_far to max_current.
4. Repeat step 2, until the value of 'i' reaches the end of
   the array.
*/

int kandane(int *a, int &n)
{
    int max_current = a[0];
    int max_so_far  = a[0];
    for(int i=1; i<n; i++)
    {
        max_current = max(a[i], max_current + a[i]);
        max_so_far  = max(max_so_far, max_current);
    }

    return max_so_far;
}

int main()
{
    //Given array whose maximum sum of the contiguous sub-arry
    //is to be found.
    int a[] = {1,2,3,4,-1,5,6,7,-4,-7,-8,11,5};
    int n = sizeof(a)/sizeof(a[0]);
    cout << kandane(a, n) << "\n";
    return 0;
}
