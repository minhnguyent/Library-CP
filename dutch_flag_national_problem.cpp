// https://en.wikipedia.org/wiki/Dutch_national_flag_problem/

#include <iostream>
#include <vector>

using namespace std;

void fun(vector<int> &arr) {
    // move all elements less than pivot to the left of the array
    // E.g. [1, 0, 0, 1, 1], pivot = 1 -> [0, 0, 1, 1, 1]
    int pivot = 1;
    int sz = arr.size();
    int left = 0;
    for (int i = 0; i < sz; ++i) {
        if (arr[i] == 0) {
            swap(arr[left], arr[i]);
            left++;
        }
    }
}  
void funfun(vector<int> &arr) {
    // move all elements less than pivot to the left of the array
    // move all elements greater than pivot to the right of the array
    // E.g. [1, 2, 0, 0, 2, 2, 1], pivot = 1 -> [0, 0, 1, 1, 2, 2, 2]
    int sz = arr.size();
    int i = 0, j = 0, k = sz - 1;
    int mid = 1;
    // 0....i....j....k....size
    while (j <= k) {
        if (arr[j] < mid) {
            swap(arr[i], arr[j]);
            i++;
            j++;
        }
        else if (arr[j] > mid) {
            swap(arr[j], arr[k]);
            k--;
        }
        else {
            j++;
        }
    }

    // 0 <= index <= i - 1: arr[index] < mid
    // i <= index <= k: arr[index] = mid
    // k + 1 <= index < sz: arr[index] > mid
} 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &v : arr) {
        cin >> v;
    }
    funfun(arr);
    for (int i = 0; i < n; ++i) {
        if (i > 0) cout << ' ';
        cout << arr[i];
    }
    cout << '\n';
        
    // input:  [0, 1, 2, 1, 1, 2, 0]
    // output: [0, 0, 1, 1, 1, 2, 2]
    return 0;
}