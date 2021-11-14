#include<iostream>
#include "header.h"
using namespace std;



int main()
{
	struct point a = { 1,3,4 };
	Linked_list<struct point>d;
	for (int i = 0; i < 10; i++) {
		a.x = a.x + i;
		a.y = a.y - i;
		a.z = a.y * i;
		d.Push_front(a);
	}
	d.print();
	 std::cout <<"find_and_earse with struct point" << std::endl;
	point c = { 4,0,0 };
	d.find_and_erase(c);
	d.print();

	
	Linked_list<int> int_number;
	for (int i = 0; i < 10; i++) {
		int_number.Push_back(i);
		i = -i;
		int_number.Push_front(i);
		i = -i;
	}
	int u = 3;
	int_number.print();
	
	int_number.find_and_erase(u);
	

	return 0;
}