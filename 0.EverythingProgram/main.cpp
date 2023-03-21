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
#include "scripts1.h"

// This is initialized at compile time, and can be modified at runtime
constinit double global_doubleVal {12.34567890123456789012345f};
//const and constinit can be combined
const constinit long double global_longdoubleVal {12.34567890123456789012345f};
 
//FIRST PARAM: argc: the number of SPACE seperated parameters including the name of the program itself
// "C:/ ... /rooster.exe fast -J" counts as 3 parameters
//SECOND PARAM:
// char const * argv[]: argv[i] is the CString associated with each parameter
// char** argv is functionally equivalent since the const char array decays into a pointer
int main(int argc, char const *argv[])//char **argv
{   
    scriptfxn1();
    return 0;//Tell OS that program has terminated
} 


