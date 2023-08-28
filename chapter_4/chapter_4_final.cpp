

#include "Student_info.h"
#include "grade.h"


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ios>
#include <stdexcept>
#include <iomanip>

using std::cin;		using std::setprecision;
using std::cout;	using std::streamsize;
using std::vector;	using std::string;
using std::sort;	using std::max;
using std::endl;	using std::domain_error;

int main()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;
	while(read(cin, record))
	{
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}
	sort(students.begin(), students.end(), compare);
	for(vector<Student_info>::size_type i = 0; i < students.size(); i++)
	{
		cout << students[i].name << string(maxlen - students[i].name.size() + 1, ' ');
		try
		{
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec);
		} catch (domain_error e)
		{
			cout << e.what();
		}
		cout << endl;
	}

	return 0;
}

