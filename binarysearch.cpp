#include <iostream>

using namespace std;

int binarySearch(int data[], int num, int left, int right);
int main()
{
        int data[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
        int num, found;
        cout << "Enter an integer to search : ";
        cin >> num;
        found = binarySearch(data, num, 0, 9);
        if (found == -1)
                cout << "Not in the list" << endl;
        else
                cout << "Found at position " << found << endl;
}

int binarySearch(int data[], int num, int left, int right)
{
        int middle = 0;

        while(left <= right) {
                middle = (left + right) / 2;

                if(num < data[middle]) {
                        right = middle - 1;
                }
                else if(num > data[middle]) {
                        left = middle + 1;
                }
                else{
                        return middle;
                }
        }
        return -1;
}
