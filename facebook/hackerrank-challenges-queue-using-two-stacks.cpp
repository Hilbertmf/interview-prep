#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

void transfer(stack<int>& transmitter, stack<int>& receiver) {
	while(!transmitter.empty()) {
		receiver.push(transmitter.top());
		transmitter.pop();
	}
}
int main() {
	int numQueries;
	cin >> numQueries;
	stack<int> stack_insert, stack_delete;
	
	for(int i = 0; i < numQueries; i++) {
		int typeQuery, value;
		cin >> typeQuery;

		if(typeQuery == 1) { // enqueue
			cin >> value;
			stack_insert.push(value);
		}
		else if(typeQuery == 2) { // pop
			if(stack_delete.empty()) {
				transfer(stack_insert, stack_delete);
			}
			stack_delete.pop();
		}
		else if(typeQuery == 3) { // top
			if(stack_delete.empty()) {
				transfer(stack_insert, stack_delete);
			}
			cout << stack_delete.top() << endl;
		}    
	}
	
	return 0;
}