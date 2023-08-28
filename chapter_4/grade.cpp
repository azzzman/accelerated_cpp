

#include "grade.h"
#include "Student_info.h"
#include "median.h"

#include <vector>
#include <stdexcept>

using std::vector;
using std::domain_error;

double grade(const Student_info& student)
{
	return grade(student.midterm, student.final, student.homework);
}

double grade(double midterm, double final, const vector<double>& hw)
{
	if(hw.size() == 0)
		throw domain_error("Student has not done any homework\n");

	return grade(midterm, final, median(hw));
}

double grade(double midterm, double final, double hw_grade)
{
	return 0.4*final + 0.4*hw_grade + 0.2*midterm;
}
