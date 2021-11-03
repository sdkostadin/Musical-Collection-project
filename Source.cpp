#include <iostream>
#include <list>
#include <queue>
#include "System.h"

int main()
{
	std::priority_queue<int> s;
	s.push(3);
	s.push(1);
	s.push(5);
	s.push(7);
	s.push(2);
	while (!s.empty())
	{
		std::cout << s.top();
		s.pop();
	}
	System::i().run();
	return 0;

}