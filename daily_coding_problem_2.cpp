/**
 * Given an array of integers, return a new array such that each
 * element at index i of the new array is the product of all the
 * numbers in the original array except the one at i.
 *
 * For example, if our input was [1, 2, 3, 4, 5], 
 * the expected output would be [120, 60, 40, 30, 24]. 
 *
 * If our input was [3, 2, 1], 
 * the expected output would be [2, 3, 6].
 *
 * Follow-up: what if you can't use division?
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> arr = {1, 2, 3, 4, 5}; // Input Vector
    vector <int> newArr;                // New Vector
    int totalProduct = 1;               // Total Calculated Product

    // Calculate the total product of the array
    for (int i = 0; i < arr.size(); i++)
        totalProduct *= arr[i];

    // Produce the new array
    for (int i = 0; i < arr.size(); i++)
    {
        newArr.push_back(totalProduct / arr[i]);
        cout << "Arr[" << i << "] = " << newArr[i] << endl;
    }

    return 1;
}

