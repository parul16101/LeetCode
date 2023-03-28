#include <bits/stdc++.h>
#include <stack>
void sortedinsert(stack<int> &stack, int res)
{
	if(stack.empty() || (stack.empty()==false && stack.top()<res))
		{stack.push(res);
		return;}

	std::stack<int> s2;
	while(stack.empty()==false && stack.top()>res)
	{
		int t = stack.top();
		stack.pop();
		s2.push(t);
	}

	stack.push(res);

	while(!s2.empty())
	{
		int t = s2.top();
		s2.pop();
		stack.push(t);
	}
}

void sortStack(stack<int> &stack)
{
	if(stack.empty())
	{
		return;
	}

	int res = stack.top();
	stack.pop();
	sortStack(stack);
	sortedinsert(stack,res);

	}
