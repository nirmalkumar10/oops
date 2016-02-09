#include<iostream>

using namespace std;

class Static{

public:
static int staticvariable;

Static() { staticvariable++;  };  // Initialized second - after object instantiation //

};

int Static::staticvariable = 10;  // Initialized first //

int main()
{

Static statobj;
Static statobj; 

std::cout << Static::staticvariable << endl;
 
} 
