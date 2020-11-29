#include "HashMap.cpp"
#include <iostream>

int main(int args, const char* argv[]) {
	HashMap<char, int, 10> hm;
//
	hm.put('C', 3);
	hm.put('M', 4);
	
	int getval;
	hm.get('C', getval);
	std::cout << getval << std::endl;

	hm.get('M', getval);
	std::cout << getval << std::endl;

	return 1;
}