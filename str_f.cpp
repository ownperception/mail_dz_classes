#include"str_f.h"

using namespace std;

int clear_stream(istream& in){
		if(in.fail()) in.clear();
		in.ignore(numeric_limits<streamsize>::max(),'\n');
return 0;
}


