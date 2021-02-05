#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

long split(long *arr, long left, long right, long pivot)
{
    while (left <= right)
    {
        while (arr[left] < pivot)
        {
            left++;
        }
        while (arr[right] > pivot)
        {
            right--;
        }
        if (left <= right)
        {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
    return left;
}

void quicksort(long *arr, long left, long right)
{
    if (left >= right)
    {
        return;
    }
    long pivot = arr[(left + right) / 2];
    long index = split(arr, left, right, pivot);
    quicksort(arr, left, index - 1);
    quicksort(arr, index, right);
}

int main()
{
    ifstream input("INPUT.txt");
    if (!input)
    {
        exit(1);
    }
    long M, N;
    input >> N >> M;
    long *arr1 = new long[N];
    long *arr2 = new long[M];
    for (long i = 0; i < N; i++)
    {
        input >> arr1[i];
    }
    for (long i = 0; i < M; i++)
    {
        input >> arr2[i];
    }
    input.close();
    quicksort(arr1, 0, N - 1);
    ofstream output("OUTPUT.txt");
    if (!output)
    {
        exit(2);
    }
    for (long i = 0; i < N; i++)
    {
        output << arr1[i] << ' ';
    }
    output.close();
    return 0;
}
