#include <vector>
using namespace std;

template<typename t>
void merge(vector<t>& arr, int left, int mid, int right,int& comparisons)
{
    int n1 = mid - left + 1, n2 = right - mid;
    t L[n1], R[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
            comparisons++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            comparisons++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++; k++;
        comparisons++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++; k++;
        comparisons++;
    }
}
template<typename t>
void mergeSort(vector<t>& arr, int left, int right,int& comaprisons)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid,comaprisons);
        mergeSort(arr, mid + 1, right,comaprisons);
        merge(arr, left, mid, right,comaprisons);
    }
}