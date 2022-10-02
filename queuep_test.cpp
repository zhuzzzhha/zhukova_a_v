#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <queuep/queuep.h>
#include<vector>
TEST_CASE("[queue] - queue ctor")
{
	Queue a;
	a.push(5);
	a.push(-1);
	a.push(0);
	CHECK(a.top() == -1);
	a.pop();
	CHECK(a.top() == 5);
}
TEST_CASE("[queue] - queue operators")
{
	
}
