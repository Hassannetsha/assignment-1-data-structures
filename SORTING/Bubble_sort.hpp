#include <vector>
using namespace std;
template<typename T>
void BubbleSort(vector<T>& arr, int n){
    bool sorted = true;
    for (int i = 0; i < n; ++i) {
        T max = arr[0];

        for (int j = 1; j < n; ++j) {
            if(max > arr[j])
            {
                T swap = arr[j];
                arr[j] = max;
                arr[j - 1] = swap;
                sorted = false;
            }

            else if(max < arr[j])
            {
                max = arr[j];
            }
        }
        if (sorted) break;

    }
}
