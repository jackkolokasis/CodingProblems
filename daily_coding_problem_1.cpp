/**
 * This problem was recently asked by Google.
 *
 * Given a list of numbers and a number k, return whether any two
 * numbers from the list add up to k. 
 * For example, given [10, 15, 3, 7] and k of 17,
 * return true since 10 + 7 is 17.
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector <int> myList = {10, 15, 3, 7};

    int k = 17;
    bool flag = false;

    for (int i = 0; i < myList.size(); i++)
    {
        int s = k - myList[i];

        for (int j = i + 1; j < myList.size(); j++)
        {
            if (s == myList[j])
                flag = true;
        }
    }

    if (flag)
        cout << "TRUE" << endl;
    else
        cout << "FALSE" << endl;
}
