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
#include <optional>
//Enum types really map to integers BUT WILL NOT BE IMPLICITLY CONVERTED to ANY other type
//Default class type is int, unless other is specified
//Default starts from 0 and increments unless 
enum class Month : unsigned char{
    Jan = 1, January = Jan, Feb, Mar,
    Apr, May, Jun,
    Jul, Aug, Sep,
    Oct, Nov, Dec
};

// Old enums implicitly tranform to int
enum Direction{
    Top=30, Bottom, Left, Right
};

void hunt_for_vowels(char message[], unsigned int size);
void common_elements_val(int array_1[], int array_2[], size_t size1, size_t size2);
void common_elements_ref(int (&array_1)[], int (&array_2)[], size_t size1, size_t size2);
void passByPointerDemoFx(int* val);
void passByReferenceDemoFx(int& val);
int max_subsequence_sum(int sequence[] , unsigned int size);
std::string_view month_to_string(Month month);
std::optional<size_t> find_character(const std::string & str,std::optional<char>);