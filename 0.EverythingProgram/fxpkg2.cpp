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
// #include <string_view>
#include "main.h"


/*
Fx prefix   constexpr allows Fx to run at compiletime;
            consteval ensures the function gets called at compile time (or throw error)

*/
// int* copy pointer = no local copy of DATA
// const int* =  data protected from modification
// onst int* const = the local pointer copy is protected
void passByPointerDemoFx(int* val){
    ++(*val);
    std::cout << "int value passed by pointer *val:" << *val << "  &(*val):" << &(*val) << std::endl;
}

//pass by refernce is fastest and cleanest
//int& directly refers to the data = no local copy of data
//const int& prevents modification of referenced data
void passByReferenceDemoFx(int& val){
    ++val;
    std::cout << "int value passed by reference val:" << val << "  &val:" << &val << std::endl;
}


/*
constinit float badvalue1 {global_floatVal}; 
*/ 
//compiler error: global_floatVal must be const
void scopeDemoFx(){
    int local_var{30};//scope only within function
    {
        int nested_local_var{5};//scope only within braces
    }
}


void hunt_for_vowels(char message[], unsigned int size){
//see assignment 4
    unsigned int vowel_count{};//Initialized to zero

    for(size_t i{0} ; i<size ; ++i){
        if (message[i] == 'a' || message[i] == 'e' || message[i] == 'i' || message[i] == 'o' || message[i] == 'u' ||
         message[i] == 'A' || message[i] == 'E' || message[i] == 'I' || message[i] == 'O' || message[i] == 'U')
        {
            vowel_count++;
        }
        
    }
  
    std::cout << "The string : " << message << " has " << vowel_count << " vowels";  
}

//the array decays into a pointer, disallowing sizeof()
void common_elements_val(int array_1[], int array_2[], size_t size1, size_t size2){
    // REMEMBER, The input arrays array_1 and array_2 have a fixed size of 10
        size_t num_common_elements{0};
    int matches[size1]{};//initialize to all to 0
    for (size_t i = 0; i < size1; i++)//cycle through dataset 1
    {
        for (size_t j = 0; j < size1; j++)
        {
            if (array_1[i]==array_2[j]){
                matches[num_common_elements] = array_1[i];
                ++num_common_elements;
                break;
            }
        }
    }
  if (num_common_elements==0)
  {
    std::cout << "There are 0 common elements";
  }else{
    std::cout << "There are " << num_common_elements << " common elements they are : ";
    for (size_t i = 0; i < num_common_elements; i++)
    {
        std::cout <<  matches[i] << " ";
    }
  }
}

//the array is passed by reference, allowing sizeof()
void common_elements_ref(int (&array_1)[], int (&array_2)[], size_t size1, size_t size2){
    // REMEMBER, The input arrays array_1 and array_2 have a fixed size of 10
    size_t num_common_elements{0};
    int matches[size1]{};//initialize to all to 0
    for (size_t i = 0; i < size1; i++)//cycle through dataset 1
    {
        for (size_t j = 0; j < size2; j++)
        {
            if (array_1[i]==array_2[j]){
                matches[num_common_elements] = array_1[i];
                ++num_common_elements;
                break;
            }
        }
    }
  if (num_common_elements==0)
  {
    std::cout << "There are 0 common elements";
  }else{
    std::cout << "There are " << num_common_elements << " common elements they are : ";
    for (size_t i = 0; i < num_common_elements; i++)
    {
        std::cout <<  matches[i] << " ";
    }
  }
}



int max_subsequence_sum(int sequence[] , unsigned int size){
    //YOUR CODE WILL GO BELOW THIS LINE 
    //DON'T MODIFY ANYTHING ABOVE THIS LINE
    std::cout << "\nSEQ Size: " << size << std::endl;
    int maxSum{-2147483647};
    for (unsigned int subwidth = size; subwidth > 0; subwidth--) {
            unsigned int shifts = size - subwidth;
            std::cout << "\n-----subwidth: " << subwidth << "    shifts: " << shifts;
            for (unsigned int shift = 0; shift < shifts + 1; shift++) {
                std::cout << "\nsh:" << shift;
                int sum{};
                for (int i = shift; i < shift+subwidth; i++) {
                    sum+=sequence[i];
                    std::cout << " " << i;
                }
                if(sum>maxSum){
                    maxSum = sum;
                }
                std::cout << " sum: " << sum;
            }
    }
    return maxSum;
    //YOUR CODE WILL GO ABOVE THIS LINE
    //DON'T MODIFY ANYTHING BELOW THIS LINE 
}

std::string_view month_to_string(Month month){
    switch(month)
    {
        using enum Month;
        case Jan : return "January";
        case Feb : return "February";
        case Mar : return "March";
        case Apr : return "April";
        case May : return "May";
        case Jun : return "June";
        case Jul : return "July";
        case Aug : return "August";
        case Sep : return "September";
        case Oct : return "October";
        case Nov : return "November";
        case Dec : return "December";
        default : return "None";
    }
}