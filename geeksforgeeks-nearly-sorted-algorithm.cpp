// https://practice.geeksforgeeks.org/problems/geeksforgeeks-nearly-sorted-algorithm/0#
// accepted
// time: O(n*logk)
// space: O(k)
#include <bits/stdc++.h>
using namespace std;

vector<int> getSorted(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int i = 0; i < arr.size() && i <= k; ++i) minHeap.push(arr[i]);
    
    for(int left = 0, right = k+1; left < arr.size(); ++left, ++right) {
        arr[left] = minHeap.top();
        minHeap.pop();
        
        if(right < arr.size()) {
            minHeap.push(arr[right]);
        }
    }
    
    return arr;
}

void print(vector<int>& arr) {
    for(const auto& num : arr) {
        if(&num != &arr[0])
            cout << " ";
        cout << num;
    }
    cout << "\n";
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    
	    int n, k;    
	    cin >> n >> k;
	    vector<int> arr(n);
	    for(int& num : arr) cin >> num;
	    
	    getSorted(arr, k);
	    print(arr);
	}
	
	return 0;
}