#include <iostream>
#include <fstream>

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
            //swap(arr[left], arr[right]);
            long temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
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
    /*for (long i = 0; i < N; i++)
    {
        cout << arr1[i] << ' ';
    }
    cout << endl;*/
    quicksort(arr2, 0, M - 1);
    /*for (long i = 0; i < M; i++)
    {
        cout << arr2[i] << ' ';
    }
    cout << endl;*/

    ofstream output("OUTPUT.txt");
    if (!output)
    {
        exit(2);
    }
    long first = 0;
    long second = 0;
    while (second < M)
    {
        if (arr1[first] == arr2[second])
        {
            if (first == 0 || second == 0 || arr1[first] != arr1[first - 1])
            {
                output << arr1[first] << ' ';
            }
            first++;
            if (first >= N)
            {
                break;
            }
            second++;
            if (second >= M)
            {
                break;
            }
        }
        while (first < N && arr1[first] < arr2[second])
        {
            first++;
        }
        if (first >= N)
            {
                break;
            }
        while (second < M && arr2[second] < arr1[first])
        {
            second++;
        }
    }
    output.close();
    return 0;
}
