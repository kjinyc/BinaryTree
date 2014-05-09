#include <iostream>
using namespace std;

int bsearch(int a[],int sz,int x)
{
    int low = 0;
    int high = sz - 1;
    while(low <= high){
        int mid = (high + low)/2;
        if(x > a[mid]) low = mid + 1;
        else if(x < a[mid]) high = mid -1;
        else
            return mid ;
    }

    return -1;
}

// recursive
int bsearch_recursive(int a[], int low, int high, int x)
{
    if (low < high) return -1;

    int mid = (high + low)/2;
    if(x < a[mid]){
        bsearch_recursive(a,low,mid-1,x);
    }
    else if (x >a[mid]){
        bsearch_recursive(a,mid+1,high,x);
    }
    else return mid;
}

