#include <iostream>
#include <iomanip>
 //https://en.cppreference.com/w/cpp/io/manip
#include <cmath> //std::floor,ceil,round,abs,sin,cos,tan,exp,log,log10,pow,sqrt
// https://en.cppreference.com/w/cpp/header/cmath
#include <bitset> //for bitwise ops
#include <vector>
#include <ctime>// for time (used in seeding )
#include <cstdlib>
#include <cctype> //for text analysis (std::isalnum,islower,isdigit,isspace,etc.)
#include <cstring> //for cstring analysis (std::strcpy,strcat,strlen)

#include "main.h"


// This is initialized at compile time, and can be modified at runtime
constinit double global_doubleVal {12.34567890123456789012345f};
//const and constinit can be combined
const constinit long double global_longdoubleVal {12.34567890123456789012345f};


int main(int argc, char const *argv[])
{   
    scriptfxn1();
    return 0;
} 


