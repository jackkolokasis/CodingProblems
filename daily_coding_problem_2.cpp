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
#include <assert.h>
#include <string.h>

using namespace std;

/*
 * @desc Print product array for a given array
 *
 * @param arr    Input Array
 * @param n      Size of the given array
 *
 */
void productArray(int arr[], int n)
{
    assert((n > 0, "The array must no be empty"));

    int i;
    int tmp = 1;

    // Allocate memory for the product array
    int * prodArr = new int[(sizeof(int) * n)];

    // Initialize the product array as 1
    memset(prodArr, 1, n);

    // In this loop, temp variable contains product of 
    // elements on left side excluding arr[i]
    for (i = 0; i < n; i++) { 
        prodArr[i] = tmp; 
        tmp *= arr[i]; 
    } 

    // Initialize temp to 1 for product on right side 
    tmp = 1; 

    // In this loop, temp variable contains product of elements on
    // right side excluding arr[i]
    for (i = n - 1; i >= 0; i--) { 
        prodArr[i] *= tmp; 
        tmp *= arr[i]; 
    } 

    // Print the constructed prod array
    for (i = 0; i < n; i++) 
        cout << prodArr[i] << " ";
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};            // Input Array
    int n = sizeof(arr) / sizeof(arr[0]);   // Number of Elements
    productArray(arr, n);

    return 1;
}
