

#include "Student_info.h"
#include <iostream>
#include <vector>

using std::cin;
using std::vector;
using std::cout;
using std::istream;

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}

istream& read(istream& is, Student_info& s)
{
	cout << "Please enter your name, midterm and final grades in that order: ";
	is >> s.name >> s.midterm >> s.final;

	read_hw(is, s.homework);
	return is;
} 

istream& read_hw(istream& ir, vector<double>& hw)
{
	if(ir)
	{
		hw.clear();
		double x;
		while(ir >> x)
		{
			hw.push_back(x);
		}
		ir.clear();
	}
	return ir;
}

