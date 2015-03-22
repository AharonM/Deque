#include <iostream>
#include <sstream>
#include <deque>

using namespace std;

template <typename T>
ostream &operator <<(ostream &os,const deque<T> &d) {
	os << "[";
	for(typename deque<T>::const_iterator iter = d.begin(); iter != d.end(); iter++)
		os << *iter << " ";
	os << "]";
	return os;
}

template <typename T>
bool contains(deque<T> &d, T val) {
	for(typename deque<T>::iterator iter = d.begin(); iter != d.end();iter++)
		if (*iter == val) return true;
	return false;
}

int main() {
	cout << boolalpha;

	deque<int> di;

	for (int i = 10; i >= 0; i--)
		di.push_front(i);
	for (int i = 11; i < 20; i++)
		di.push_back(i);
	cout << di << endl;
	
	cout << "di contains 15: " << contains(di, 15) << endl;
	cout << "di contains 23: " << contains(di, 23) << endl << endl;
	
	deque<int>::reverse_iterator iter = di.rbegin();
	while (iter != di.rend()) {
		cout << *iter << " ";
	iter++;
	}	
	cout << endl;
	cout << di << endl;
	const int ARR_SIZE = 4;
	string arr[ARR_SIZE] = {"cat", "dog", "cow", "elephant"};

	cout << endl;

	deque<string> ds;

	for (int i = 0; i < ARR_SIZE; i++)
		ds.push_back(arr[i]);

	cout << ds << endl;

	cout << "vs contains \"dog\": " << contains(ds, string("dog")) << endl;
	cout << "vs contains \"muskrat\": " << contains(ds, string("muskrat")) << endl;

	cout << endl << endl;

	deque<string> ds2;

	for (int i = 5; i >= 0; i--) {
		ostringstream oss;
		oss << "String-" << i;
		ds2.push_front(oss.str());
	}
	
	for (int i = 6; i < 11; i++) {
		ostringstream oss;
		oss << "String-" << i;
		ds2.push_back(oss.str());
	}
	
	
	cout << "front: " << ds2.front() << endl;
	cout << "back: " << ds2.back() << endl;
	cout << ds2 << endl;

	cout << "\nds2 contains \"String-1\": " << contains(ds2, string("String-1")) << endl;
	cout << "ds2 contains \"String-15\": " << contains(ds2, string("String-15")) << endl;
	
	ds2.clear();
	cout << ds2 << endl;

	return 0;
}
