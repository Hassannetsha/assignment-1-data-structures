#include <vector>
using namespace std;

template<typename t>
void shellSort(vector<t>& arr, int n)
{
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            t temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j-gap] > temp; j -= gap)
                arr[j] = arr[j-gap];
            arr[j] = temp;
        }
    }
}

//void print(int arr[], int n)
//{
//    for (int i = 0; i < n; i++)
//        cout<<arr[i] <<' ';
//    cout<<'\n';
//}

