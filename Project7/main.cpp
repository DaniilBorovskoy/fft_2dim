// argument_definitions.cpp
// compile with: /EHsc
#include <iostream>
#include <string.h>
#include "bmptrans.h"
#include "complex.h"

using namespace std;
int main(int argc, char* argv[], char* envp[])
{
	bmptrans* trans = new bmptrans();
	//inverse* inv = new inverse();
	//inv->picifft();
	trans->picfft();
}
