//adding functions to abstract functionality


// add all include directiver
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ios>
#include <iomanip>
#include <stdexcept>
#include <typeinfo>

// add all using declarations
using std::cout;	using std::cin;
using std::endl;	using std::string;
using std::vector;	using std::streamsize;
using std::sort;	using std::setprecision;
using std::istream;	using std::domain_error;

// code for median()
// passing a vec, check if empty, sort it and return the median element
double median(vector<double> hw)				//call-by-value
{
	typedef vector<double>::size_type vec_sz;
	vec_sz size = hw.size();
	if(size == 0)
		throw domain_error("Cannot calculate median of an empty vector\n");

	sort(hw.begin(), hw.end());

	vec_sz mid = size/2;
	
	return size % 2 == 0 ? (hw[mid] + hw[mid-1])/2 : hw[mid];
}


// code for grade() - calc only
// implemented like this to practice function overloading
// passing final, midterm, median to calc overall grade

double grade(double final, double midterm, double hw) 
{
	return 0.4*final + 0.2*midterm + 0.4*hw;
}


// code for grade()
// passing the final, midterm and hw_grade_vec. call median(hw_grade_vec). call grade() to calc overall grade


double grade(double final, double midterm, const vector<double>& hw)
{
	if (hw.size() == 0)
		throw domain_error("Student hasn't done any homework\n");	
	
	return grade(final, midterm, median(hw));
}


//code for read_hw()
//passing a stream & vector; stream reads values & stores in vector for each student

istream& read_hw(istream& in, vector<double>& hw) 
{
	// in case no input exists. this way protecting against user accidentally entereing values:
	if (in) 
	{
		//removing old values in hw
		hw.clear();

		//read hw grades
		double x;
		while (cin >> x)
			hw.push_back(x);

		//reset stream 'in' from failure state when eof/wrong char entered for next set of entries
		in.clear();
	}
	return in;
}


int main()
{
//	get users name
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	
//	get final, midterm grades
	cout << "Please enter your final and midterm grades :";
	double final, midterm;
	cin >> final >> midterm;

//  ask for hw grades
	cout << "Please enter your homework grades: ";
	vector<double> homework;

//	call read_hw()
	read_hw(cin, homework);
	

	
//	call grade(....,median())

	try
	{
		double overall_grade = grade(final, midterm, homework);
		streamsize prec = cout.precision();
		cout << "Your grade for the course is " << setprecision(3) 
			 << overall_grade << setprecision(prec) << endl;
	} catch (domain_error)
	{
		cout << endl << "You must enter your grades. "
						"Please try again. "<< endl;
		return 1;
	}

	return 0;
}
