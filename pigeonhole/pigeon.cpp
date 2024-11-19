// #include <bits/stdc++.h>
#include <vector>
#include <iostream>
void pigeonSort(int arr[], int n)
{
    int min = arr[0];
    int max = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    int range = max - min + 1;

    // Each vector represents a hole that
    // is going to contain matching elements.
    std::vector<int> holes[range];

    for (int i = 0; i < n; i++)
    {
        int order = arr[i] - min;
        holes[order].push_back(arr[i]);
    }

    int index = 0; // index in sorted array
    for (int i = 0; i < range; i++)
    {
        if (!holes[i].empty())
        {
            for (int j = 0; j < holes[i].size(); j++)
            {
                arr[index++] = holes[i][j];
            }
        }
    }
}

int main()
{
    int arr[] = {2, 15, 4, 22, 10, 24};
    int n = sizeof(arr) / sizeof(arr[0]); // sizeof returns bytes, not the size number of elements in arr

    pigeonSort(arr, n);

    for (int i = 0; i < n; i++)
        std::cout << arr[i] << std::endl;
    return 0;
}