



struct Student_info 
{
	string name;
	double midterm, final;
	vector<double> homework;
};


istream& read(istream& is, Student_info& s)
{
	//read and store the student's name and midterm and final exam grades
	is >> s.name >> s.midterm >> s.final;

	read_hw(is, s.homework);
	
	return is;
}

double grade(const Student_info& s)
{
	return grade(s.midterm, s.final, s.homework);
}	
