#include <iostream>
#include <vector>
using namespace std;

int high(vector<int>& a, int x) {
    if (a[0] == x) {
        return 0;
    }

    int i;
    for (i = 1; i < a.size(); i = i * 2) {
        if (a[i] > x)
            break;
    }

    if (i >= a.size()) {
        return a.size() - 1;
    }

    return i;
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5, 7, 8, 12, 14, 17, 18, 23, 24, 27, 29, 34, 37, 57, 67, 78, 83, 86, 89};
    int x = 24;
    int h = high(a, x);
    int l = h / 2;

    while (h >= l) {
        int mid = (l + h) / 2;
        if (a[mid] == x) {
            cout << "Found at " << mid;
            return 0;
        } else if (a[mid] > x) {
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << "Element not found";
    return 0;
}
