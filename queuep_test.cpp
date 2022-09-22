#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <queuep/queuep.h>
#include<vector>
/*TEST_CASE("[queue] - queue ctor")
{
	std::vector<int> v(0);
	Queue a();
	Queue b(v);
	//CHECK(a == b);
}*/
TEST_CASE("[queue] - queue operators")
{
	int a = 1;
	std::vector<int> v = { 5,1,2,3,6 };
	std::vector<int> x = { 5,1,1,2,3,6 };
	Queue c(v);
	CHECK(c.top() == a);
	c.push(1);
	Queue b(x);
	CHECK(c == b);
	b.pop();
	CHECK(b==c);
}
