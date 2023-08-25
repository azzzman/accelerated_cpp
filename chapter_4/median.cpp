

// source file for median function
// program produces the median of a set of values in a vec




#include <stdexcept>
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;
using std::domain_error;

double median(vector<double> hw)
{
	typedef vector<double>::size_type sz;
	sz size = hw.size();
	
	if(size == 0)
		throw domain_error("Cannot calculate median of an empty vector\n");

	sort(hw.begin(), hw.end);
	sz mid = size/2;

	return size%2 = 0 ? (hw[mid] + hw[mid-1])/2 : hw[mid];
}
