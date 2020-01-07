#ifndef library_h
#define library_h
#include <string>
#include <ostream>
using namespace std;

class library {
public:

	string author;
	string category;
	string status;
	int num_pag;

	library(string _author = "", string _category = "", string _status = "", int _num_pag = 0) {
		author = _author;
		category = _category;
		status = _status;
		num_pag = _num_pag;
	}

	~library() {
	};
	friend ostream& operator <<(ostream& o, const library& e) {
		return o << e.author << ' ' << e.category << ' ' << e.status << ' ' << e.num_pag;
	}
};
#endif /* library.h */ 