#include "functions1.h"


/*
Fx prefix   constexpr allows Fx to run at compiletime;
            consteval ensures the function gets called at compile time (or throw error)
*/

// FUNCTION OVERLOADS
// functions can be overloaded by any functional difference in fx params such as 
// varying order,quantity, or type of parameters(T* and const T* are seen as different)
//
// for passing by value, constness does not differentiate since copying anyway
//
// example of functional equivilance is int * foo, int foo[], and int foo[6], sinch last 2 decay to int *
// weird situations with refs when more than 1 overload is acceptable for implicit conversion:
// Alternative fx param definitions: const std::string& name, std::string name
//  actual param: std::strng OR string literal
//      compiler error due to ambiguity on how std::string input should be handled
// Alternative fx param definitions: double a, int& a (const to allow for implicit conversion)
//  actual param: char a{45}
//      compiler will 

//anything that implicitly convert to int captured here
// integer types will prefer implicit convertion here
int add(const int& a, const int& b){
    std::cout << "Using overload: 'const int&'" <<std::endl;
    return a+b;
}

int add(int& a, int& b){
    std::cout << "Using overload: 'int&'" <<std::endl;
    return a+b;
}

int add(int *a, int *b){
    std::cout << "Using overload: 'int*'" <<std::endl;
    return *a+*b;
}

// SAME AS THE ABOVE, since both will be copys of pointer
// choose *const variant to indicate that the local pointer should not be modified
// int add(int *const a, int *const b){
//     std::cout << "Using overload: 'int *const'" <<std::endl;
//     return *a+*b;
// }

int add(const int *a, const int *b){
    std::cout << "Using overload: 'const int*'" <<std::endl;
    return *a+*b;
}

//anything that implicitly convert to double captured here
// float types will prefer implicit convertion here
double add(const double& a, const double& b){
    std::cout << "Using overload: 'const double&'" <<std::endl;
    return a+b;
}
// using non-const reference removes the posibility of char*
// being implicitly converted to string. This overload will now
// not compete with the char* overload, removing ambiguity error
std::string add( std::string& a,std::string& b){
    std::cout << "Using overload: 'std::string&'" <<std::endl;
    return a+b;
}

const char* add( char* a, const char* b){
    //requires a to have enough reserved space for b
    std::cout << "Using overload: 'char*'" <<std::endl;
    return std::strcat(a,b);
}

// int* copy pointer = no local copy of DATA
// const int*:  data protected from modification
// onst int* const:  the local pointer copy is protected
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

void print_array(int* arr, unsigned int n) 
{ 
    for (unsigned int i = 0; i < n; i++){
        std::cout << arr[i] << " "; 
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

//the array is passed by reference, allowing sizeof() and avoiding copies
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

//Using new Enums
std::string_view month_to_string(Month month){
    switch(month)
    {
        using enum Month;//older compilers require Month::Jan and removing this line
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

std::optional<size_t> find_character(const std::string & str,
										std::optional<char> c = std::nullopt){
    //If found set return index, else return empty
    //If c is specified, find it else just find 'z'
    /*
    char char_to_find;
    if(c.has_value()){
        char_to_find = c.value();
    }else{
        char_to_find = 'z'; // Will find z by default
    }
    */
   char char_to_find = c.value_or(' ');
    
    for (size_t i{} ; i < str.size()  ; ++i){
        //std::cout << "str[i] : " << str.at(i) << " , c : " << c << std::endl;
        if(str.c_str()[i] == char_to_find){
            return i;
        }
    }
   return {};// Or std::nullopt
}

void insertion_sort(int * array, unsigned int size){
    std::cout << "\nSEQ Size: " << size << std::endl;
    print_array(array,size);
    std::cout << std::endl;
    for (size_t key_i = 1; key_i < size; key_i++) {
        int key_v = array[key_i];
        std::cout << "\nKey_v: " << key_v << "  @Key_i: " << key_i << std::endl;
        for (size_t cmp_i = key_i - 1; cmp_i >= 0; --cmp_i)
        {
            std::cout << "cmp_i = " << cmp_i << " : ";
            print_array(array,size);
            std::cout << ">> ";
            if(array[cmp_i] > key_v){
                array[cmp_i+1] = array[cmp_i];//shift compared val left
                if (cmp_i == 0)
                {
                    array[cmp_i] = key_v;
                    print_array(array,size);
                    std::cout << std::endl;
                    break;
                }
                print_array(array,size);
                std::cout << std::endl;
            }else{
                array[cmp_i+1] = key_v; //replace with key val
                print_array(array,size);
                std::cout << std::endl;
                break;
            }
        }

    }
}

