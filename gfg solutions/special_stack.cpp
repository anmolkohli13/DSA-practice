#include<bits/stdc++.h>
void push(stack<int>& s, int a){
	// Your code goes here
	s.push(a);
}

bool isFull(stack<int>& s,int n){
	// Your code goes here
	return (s.size() == n);
}

bool isEmpty(stack<int>& s){
	// Your code goes here
	return s.empty();
}

int pop(stack<int>& s){
	// Your code goes here
	int ans = s.top();
	s.pop();
	return ans;
}

int getMin(stack<int>& s){
	// Your code goes here
	
	stack<int>temp = s;
	int min = INT_MAX;
	while(!temp.empty())
	{
	    if(temp.top() < min)
	    min = temp.top();
	    temp.pop();
	}
	
	return min;
}
