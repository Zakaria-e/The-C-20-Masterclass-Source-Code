#include <iostream>
#include <iomanip>
 //https://en.cppreference.com/w/cpp/io/manip
#include <cmath> //std::floor,ceil,round,abs,sin,cos,tan,exp,log,log10,pow,sqrt
// https://en.cppreference.com/w/cpp/header/cmath
#include <bitset> //for bitwise ops
#include <vector>
#include <ctime>// for time (used in seeding )
#include <cstdlib> 
//GLOBAL VARIABLES OUTSIDE FUNCTIONS: ACCESSIBLE TO ANYTHING AFTER ITS INIT
// Run time value
float global_floatVal {12.34567890123456789012345f};
// This is initialized at compile time, and can be modified at runtime
constinit double global_doubleVal {12.34567890123456789012345f};
//const and constinit can be combined
const constinit long double global_longdoubleVal {12.34567890123456789012345f};
/*
constinit float badvalue1 {global_floatVal}; 
*/ 
//compiler error: global_floatVal must be const
void func1(){
    int local_var{30};//scope only within function
    {
        int nested_local_var{5};//scope only within braces
    }
}

void hunt_for_vowels(char message[], unsigned int size){
//see assignment 4
    unsigned int vowel_count{};//Initialized to zero
    
    //Don't modify anything above this line
    //Your code should go below this line
    for(size_t i{0} ; i<size ; ++i){
        if (message[i] == 'a' || message[i] == 'e' || message[i] == 'i' || message[i] == 'o' || message[i] == 'u' ||
         message[i] == 'A' || message[i] == 'E' || message[i] == 'I' || message[i] == 'O' || message[i] == 'U')
        {
            vowel_count++;
        }
        
    }
    
    
    //Your code should go above this line
    //Don't modify anything below this line
    
    
    std::cout << "The string : " << message << " has " << vowel_count << " vowels";  
}

void common_elements(int array_1[], int array_2[]){
    // REMEMBER, The input arrays array_1 and array_2 have a fixed size of 10
   
    //Don't modify anything above this line
    //Your code will go below this line
    size_t size_array = 10;//sizeof(array_1[0]);
    size_t num_common_elements{0};
    int matches[size_array]{};//initialize to all to 0
    for (size_t i = 0; i < size_array; i++)//cycle through dataset 1
    {
        for (size_t j = 0; j < size_array; j++)
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
  
  

  
  //Your code will go above this line
  //Don't modify anything after this line

}


int main(int argc, char const *argv[])
{   
fputs("\nPLAYING WITH PRIMITIVE DATATYPES and compile vs runtime\n", stdout);
     double PI {3.14159f}; // constexpr variables (Read only) only used at compile time to calculate const values in runtime.
    // static_assert(PI == 5, "Bad PI"); // only uses const or constexpr
    char character1 {'a'};
    auto auto_uint { 123u}; // unsigned
    auto auto_uintl { 123ul}; //unsigned long
    auto auto_uintll { 123ll}; // long long
    unsigned short float2uint16Val(global_floatVal);//Narrowing Functional Conversion
    unsigned short uint16Val{13214};//Braced Initialization
    unsigned short uint16Diff(float2uint16Val - uint16Val);//negative uint wraps around range
    unsigned short uint16Diff2 = float2uint16Val - uint16Val;//Assignment Initialization

    std::cout << std::setprecision(20);
    std::cout << 
    "Out1: " << float2uint16Val <<
    "\nOut2: " << uint16Val <<
    "\nOut3: " << uint16Diff <<
    "\nOut4: " << uint16Diff2 <<
    std::endl;

//DO THIS !!!!!!    
fputs("\nFormatting, BOOLS, and Subtracting uint\n", stdout);
    
    //Short hand evaluation:
    //for AND, if a false if found, returns false upon finding a false,
    //for OR, returns true upon finding a true
    bool var31 {true};
    bool var32 {false};
    bool var33 {true};
    bool var34 {true};
    //program will return false when it hits var32 and will not look at 33,34
    bool var35 = var31 && var32 && var33 && var34;

    uint16_t uint16Val1 = 21'23u;//apostraphe no effect on value
    uint16_t uint16Val2 = 2523u;
    uint16_t uint16Diff3 = 0;
    uint16_t uint16Diff4 = 0;
    bool boolVar = (uint16Val1 > uint16Val2); //generally use parenthesis
    bool ILikeTurtles{false};
    std::cout << std::boolalpha; // true/false rather than 1/0
    std::cout << "boolVar : " << boolVar << std::endl;
    printf("boolVar : %s \n",boolVar ? "true" : "false");

    if ((uint16Val1 > uint16Val2) && !ILikeTurtles){ //&&True is same as not having &&
        uint16Diff3 = uint16Val1 - uint16Val2;
    }else if(uint16Val1 < uint16Val2){
        uint16Diff3 = 0;
        
    }else{
        uint16Diff3 = 0;
        ILikeTurtles = true;
    }
    std::cout << std::noboolalpha;

    std::cout << std::left; //justification
    std::cout << std::setfill('-');
    std::cout << std::showpos; //show positive sign
    std::cout << std::uppercase; //chars are uppercase
    std::cout << std::scientific; //scientific notation
    std::cout << std::setprecision(10); //scientific notation
    std::cout << "Difference: " << std::setw(20) << uint16Diff3 <<
    "AS HEX: " << std::setw(20) << std::hex << uint16Diff3 << std::endl;
    std::cout << std::noshowpos;
    std::cout << std::setfill(' ');
    std::cout << "Value 1: " << std::dec << std::setw(8) << uint16Val1 <<
    "AS HEX: " << std::setw(20) << std::hex << uint16Val1 << std::endl;
    std::cout << std::dec;
    std::cout << std::nouppercase; //disable forced uppercase
    std::cout.unsetf(std::ios::scientific|std::ios::fixed); // removes number format flags
fputs("\nPre/Post-fix in/de-crement and COMMA OPERATOR\n", stdout);   
    int var00 = 5;
    std::cout << ++var00 << std::endl;
    std::cout << var00 << std::endl;
    int var01 = 10;
    std::cout << var01++ << std::endl;
    std::cout << var01 << std::endl;
    // value +-*/%= 54 is the same as value = value +-*/%  54
fputs("\nuint16 arithmetic handled as int\n", stdout);
    auto productuint16 = uint16Val1 - uint16Val2;
    std::cout << "Product: " << productuint16 <<
    " Width: " << sizeof(productuint16) << std::endl;
fputs("\nCASTING\n", stdout);
    double var10 = 43.435;
    double var11 {44.325};
    int var12 = var10 + var11; // implicit cast of the sum to int
    int var13 = static_cast<int>(var10) + static_cast<int>(var11); //explicit equivalent (compiler friendly)
    var13 = (int)(var10) + (int)(var11); //C style explicit equivalent (not checked by compiler)
fputs("\nBitwise Ops\n", stdout);
    //bitwise ops usually forced in int (32bit) to conform with architecture, so we cast to go back to 16bit if desired
    auto COL_WIDTH_1{30};
    auto COL_WIDTH_2{15};
    unsigned short int var20 {0b11111110};//short int is 16bit wide so will be padded with 8 bits at the left
    std::cout << std::right << std::setw(COL_WIDTH_1) << "'a': " << std::setw(COL_WIDTH_2) << std::bitset<16>(var20) << //bitset<size to display>
    " HEX: " << std::showbase << std::hex << var20 << " DEC: " << std::showbase << std::dec << var20 <<  std::endl;
    unsigned short int var21 = static_cast<unsigned short int>(var20 << 3); //shift to the left by 3 digits (pad on the right)
    std::cout << std::setw(COL_WIDTH_1) << "'b' = 'a' << 3: " << std::setw(COL_WIDTH_2) << std::bitset<16>(var21) <<
    " HEX: " << std::showbase << std::hex << var21 << " DEC: " << std::showbase << std::dec << var21 <<  std::endl;
    std::cout << std::setw(COL_WIDTH_1) << "COUT 'a' << 3: " << std::setw(COL_WIDTH_2) << std::bitset<16>(var20 << 3) <<
    " HEX: " << std::showbase << std::hex << (var20 << 3) << " DEC: " << std::showbase << std::dec << (var20 << 3) <<  std::endl;
    var21 >>=2; //shift in place to the right by 2 digits
    std::cout << std::setw(COL_WIDTH_1) << "'b' >>= 2: " << std::setw(COL_WIDTH_2) << std::bitset<16>(var21) <<
    " HEX: " << std::showbase << std::hex << var21 << " DEC: " << std::showbase << std::dec << var21 <<  std::endl;
    // NOT: ~a , AND: a&b, (a&=(~MASK) for bit resetting), OR: a|b (a|=MASK For bit Setting), XOR: a^b (a^=MASK For bit toggling), ((a & OneHotPosition)>>HotPosition for checking)
    unsigned short int var22 = static_cast<unsigned short int>(var20^(~var21));
    std::cout << std::setw(COL_WIDTH_1) << "c = a XOR (~b): " << std::setw(COL_WIDTH_2) << std::bitset<16>(var22) <<
    " HEX: " << std::showbase << std::hex << var22 << " DEC: " << std::showbase << std::dec << var22 <<  std::endl;
    var22 ^= var21;
    std::cout << std::setw(COL_WIDTH_1) << "c = c^b: " << std::setw(COL_WIDTH_2) << std::bitset<16>(var22) <<
    " HEX: " << std::showbase << std::hex << var22 << " DEC: " << std::showbase << std::dec << var22 <<  std::endl;
    var22 &= ~(0b1000100000000000); //reset the 11th and 15th bits to 0
    std::cout << std::setw(COL_WIDTH_1) << "c &= ~(0b01100000): " << std::setw(COL_WIDTH_2) << std::bitset<16>(var22) <<
    " HEX: " << std::showbase << std::hex << var22 << " DEC: " << std::showbase << std::dec << var22 <<  std::endl;
    bool var23 = (var22 & 0x0100)>>8; //checking the 8th bit (0th is LSB)
    std::cout << std::setw(COL_WIDTH_1) << "check 8th bit of c: " << std::setw(COL_WIDTH_2) << std::bitset<16>(var23) <<
    " HEX: " << std::showbase << std::hex << var23 << " DEC: " << std::showbase << std::dec << var23 <<
    " BOOL:" << static_cast<bool>(var23) << std::endl;
    var22^=0x0100; //toggle 8th bit
    std::cout << std::setw(COL_WIDTH_1) << "toggle 8th bit of c : " << std::setw(COL_WIDTH_2) << std::bitset<16>(var22) <<
    " HEX: " << std::showbase << std::hex << var22 << " DEC: " << std::showbase << std::dec << var22 << std::endl;

fputs("\nSwitch,Ternary,For,While\n", stdout);
    int var40{-2};

    //Switch only works with integral types and enums
    switch (var40)
    {
        case 1:{
            std::cout <<  "toolid : 1" << std::endl;
            break;//if no break, will excecute the next case regardless
        }
        case 2:{
            std::cout <<  "toolid : 2" << std::endl;
            break;
            }
        case 3:{
            std::cout <<  "toolid : 3" << std::endl;
            break;
            }
        case 4:
        case 5:
        case 6:{
            std::cout <<  "toolid : 4-6" << std::endl;
            break;
            }
        case 0:
        case -1:
        case -2:{
            std::cout <<  "toolid : 0 to -2" << std::endl;
            break;
            }
        default:{
            std::cout <<  "toolid : other" << std::endl;
            break;
        }
    }

    //NO implicit conversion from int to bool, just the appearance of it.
    if (var40){ //when using int as a bool. 0 is false. anything else is true
        std::cout <<  "non-zero integer" << std::endl;
    }else{
        std::cout <<  "zero integer" << std::endl;
    }

    uint16Val1 = 213;
    uint16Val2 = 123;
    if (uint16Val1 > uint16Val2){
        uint16Diff3 = uint16Val1 - uint16Val2;
    }else{
        uint16Diff3 = 0;
    }
    std::cout <<  "uint16Diff IfElse: " << uint16Diff3 << std::endl;
    
        //ternary expression equivalent - Note the two expressions must be same type as output or convertible
    //resultVar = (condition) ? ExpressionIfTrue : ExpressionIfFalse
    uint16Diff3 = (uint16Val1 > uint16Val2) ? uint16Val1 - uint16Val2 : 0;
    std::cout <<  "uint16Diff Ternary Exp: " << uint16Diff3 << std::endl;
    
    
    //Ternary Initialization
    // DataType resultVar = { (condition) ? ExpressionIfTrue : ExpressionIfFalse}
    uint16Val1 = 213;
    uint16Val2 = 423;
    uint16Diff4 = (uint16Val1 > uint16Val2) ? uint16Val1 - uint16Val2 : 0;
    std::cout <<  "uint16Diff Ternary Init: " << uint16Diff4 << std::endl;

    const bool var41{false};
    if constexpr (var41){
        std::cout <<  "Compile time do this " << std::endl;
    }else{
        std::cout <<  "Compile time do that " << std::endl;
    }

    float speed_MPH_scopeMain = 45;
    bool go{true};

    //speed_mps_scopeIfElse initialized in place and has scope within the if statement
    if (float speed_mps_scopeIfElse{speed_MPH_scopeMain*0.44704f}; go){
        if(speed_mps_scopeIfElse>10){
            int scopeBracket{5};
            std::cout <<  "Slow down" << std::endl;
        }else{
            std::cout <<  "OK! " << std::endl;
        }
    }else{
        std::cout <<  "Stop! " << std::endl;
    }

    //speed_mps_scopeIfElse initialized in place and has scope within the switch statement
    switch (float speed_mps_scopeSwitch{speed_MPH_scopeMain*0.44704f};var40)
    { 
    case -1:
    case 0:
    case -2:
        std::cout <<  "switchOut: " << speed_mps_scopeSwitch*var40*4 << std::endl;
        break;
    default:
        std::cout <<  "switchOut: " << speed_mps_scopeSwitch*var40 << std::endl;
        break;
    }
    
    auto count = 10;
    //for(optional initializations;continue loop condition; do after cycle)
    
    for (size_t i = 0; i < count; i++)
    {
        std::cout << i;
        if (i == 5)
        {
            continue; //skip rest of loop iteration
        }
        if (i == 7)
        {
            break; //end loop
        }
        std::cout << i << " ";
    }
    std::cout << std::endl;

    for (auto  i{4} , var35 = 2 , var36 = 42 ; i < count ; i+=2 , var35*=2){
        var36 += var35;
        std::cout << 
        " i: " << i <<  " |Sizeof i: " << sizeof(i) << 
        " a: " << var35 <<  " |Sizeof a: " << sizeof(var35) << 
        " b: " << var36 <<  " |Sizeof b: " << sizeof(var36) << 
        std::endl;
    }
  
    int coll00 [] {3,1,4,1,5,9,3,1,4,1};
    int size_coll00{sizeof(coll00)/sizeof(coll00[0])};//std::size(coll00)// requires #include <iterator>
    
    //range based for loop goes through values in collection
    //can also prefix with helper variable
    std::cout <<  "List: ";
    for (int helperVar01{2}; auto i : coll00){
        std::cout << helperVar01 * i << " ";
    }
    std::cout << std::endl;
    
    //range based for loop with literal collection
    std::cout <<  "List: ";
    for (auto i : {3,1,4,1,5,9,3,1,4,1}){
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    //regular for loop equivalent
    std::cout <<  "List: ";
    for (auto  i{0} ; i < size_coll00 ; i++){
        std::cout << coll00[i] << " ";
    }
    std::cout << std::endl;


    {
        unsigned int i{0};
        std::cout <<  "List: ";
        while (i < size_coll00){
            std::cout << coll00[i] << " ";
            i++;
        }
        std::cout << std::endl;
    }   

    //do while force-runs first and then checks whether to repeat loop
    {
        unsigned int i{0};
        std::cout <<  "List: ";
        do{
            std::cout << coll00[i] << " ";
            ++i;
        }while (i < size_coll00);
        std::cout << std::endl;
    }

fputs("\nRandom Numbers\n", stdout);
    std::cout << "std::rand() is a random integer, like "<< std::rand() << " between 0 and RAND_MAX, which is " << RAND_MAX << std::endl;
    std::cout << "It is drawn from a premade uniform dist and will repeat when program is run"<< std::endl;
    for (size_t i = 0; i < 20; i++)
    {
        std::cout << std::rand() << " ";
    }
    std::cout << std::endl;

    std::cout << "To constrain the upper boundto VAL, use std:rand()%(VAL+1)."<< std::endl;
    std::cout << "In this case will constrain to 50."<< std::endl;
    for (size_t i = 0; i < 20; i++)
    {
        std::cout << std::rand()%51 << " ";
    }
    std::cout << std::endl;
    
    std::cout << "To get truly random, use seeding function with time as seed."<< std::endl;
    std::cout << "std::time(0) is " << std::time(0) << " ->running std::srand(std::time)) creates a new random value series"<< std::endl;
    std::srand(std::time(0));
    for (size_t i = 0; i < 20; i++)
    {
        std::cout << std::rand()%51 << " ";
    }
    std::cout << std::endl;

fputs("\nArrays\n", stdout);
    //int NoInitArray [3][4]; //reserves 12 int slots without intitializing data
    int InitArray [3][4]{}; //reserves 12 int slots with 0 intitialization
    for (size_t i = 0; i < std::size(InitArray); i++)
    {
        for (size_t j = 0; j < std::size(InitArray[i]); j++)
        {
            std::cout << InitArray[i][j] << "   ";
        }
        std::cout << std::endl;        
    }

fputs("\nPointers and text storage\n", stdout);
{
    //although int *p_var reg_var {}; is valid and would create a pointer
    // and int respectively, it is better to seperate into two declarations.
    int var50{71};
    int var51{271};
    int *p_var50{&var50};//& means address of
    int *p_var51{};//same as int *p_var51{nullptr};
    //p_var50 = &doubleVar; // compile error due to type
    //*p_var51 = 2710; //Can't update the value pointed by nullptr - will crash program;
    p_var51 = &var51; // The pointer value (address) will be changed to the address of var51
    *p_var51 = 2710; //The pointed-to value will update from 271 to 2710;
    //---const on left of type*: data treated as const-----const on right  of type*: pointer is const
    const int *p_var52 {&var50}; // this is a non-modifying pointer (regardless 
    // of if the referenced value is declared as a const) and referenced
    // values will be treated as const. The pointer itself can be changed.
    p_var52 = &var51; //The pointer itself is modifiable,
    //*p_var52 = 643;//Compiler blocks this attempt to modify any referenced value
    *p_var51 = 2711;// but allows this pointer to modify the same value
    int * const p_var53 {&var50}; // the pointer address is constant,
    *p_var53 = 72; // but the referenced value is modifiable
    const int * const p_var54 {&var50}; // the pointer address is constant,
    // and the underlying value is not modifiable via this pointer.
    std::cout << "size of all pointers on this system is: " << sizeof(p_var51) << " bytes"<< std::endl;
    std::cout << "Pointer Reference Adresses: " << std::endl;
    std::cout << "p_var50:" << p_var50 << " | p_var51: " << p_var51 << " | p_var52: " << p_var52 << " | p_var53: " << p_var53 << " | p_var54: " << p_var54 << std::endl;
    std::cout << "Pointer Dereferences to: " << std::endl;
    std::cout << "*p_var50:" << *p_var50 << " | *p_var51: " << *p_var51 << " | *p_var52: " << *p_var52 << " | *p_var53: " << *p_var53 << " | *p_var54: " << *p_var54 << std::endl;
    std::cout << "Referenced Value/Address: " << std::endl;
    std::cout << "var50: " << var50 << " at "<< &var50 << 
        " | var51: " << var51 << " at "<< &var51 << std::endl;
    
    //Array name is like a constant pointer, except that
    // size can be deduced from sizeof(coll00)/std::size(coll00) and not from a pointer
    // Also an address &var can be stored in a pointer but not in an array
    std::cout << "coll00: " << coll00 << std::endl;
    std::cout << "coll00[0]: " << coll00[0] << std::endl;
    p_var50 = {coll00};
    std::cout << "p_var50 = {coll00};" << std::endl;
    std::cout << "Address| p_var50: " << p_var50 << std::endl;
    std::cout << "Value (int)| *p_var50: " << *p_var50 << std::endl;
    std::cout << "Address| p_var50 + 4: " << p_var50 + 4 << std::endl;
    std::cout << "Value (int)| *(p_var50 + 4): " << *(p_var50 + 4) << std::endl;
    std::cout << "Value (int)| p_var50[4]: " << p_var50[4] << std::endl;
    std::cout << "Address (int)| &coll00[4]): " << &coll00[4] << std::endl;
    std::cout << "Value (int)| coll00[4]): " << coll00[4] << std::endl;
    ++p_var50;//Moves pointer forward by sizeof(int):4bytes
    std::cout << "++p_var50;//permanently shifts the pointer's base address'" << std::endl;
    std::cout << "Address| p_var50: " << p_var50 << std::endl;
    std::cout << "Value (int)| *(p_var50): " << *(p_var50) << std::endl;
    

    char message1[] {"Hello World!"};//cstring is modifiable
    message1[11] = '?';
    std::cout << "message1 : " << message1 << std::endl;
    //Array pointer points to first element in array
    //some compilers turn cstring literal into array of const char,
    //is not writable by pointer in the future... some will throw error
    const char *p_message2{"Hello World!"};//wont compile without the const
    std::cout << "&p_message2 : " << &p_message2 << std::endl;
    std::cout << "p_message2 : " << p_message2 << std::endl;
    std::cout << "p_message2[0] : " << p_message2[0] << std::endl;
    std::cout << "*p_message2 : " << *p_message2 << std::endl;
    //const char* is not writable. If wish to write, then use char textVar[] {"test"}
    
    // shitty way of storing several strings:
    //disgusting code. each var is a writable c-string of exactly the size needed
    {
        char textVar1[] {"These are strings"};
        char textVar2[] {"that are"};
        char textVar3[] {"being stored"};
        char textVar4[] {"in a bad way!"};
        std::cout << textVar1 << " " << textVar2 << " " << textVar3 << " " << textVar4 << std::endl;
    }
    
    // ok way of storing several strings (90 char limit per string):
    // 4x90 array padded by 0/. Easy code management but wastes memory.
    {
        char textVar[][90] {
            "These are strings",
            "that are",
            "being stored",
            "in an ok way!"
            };
        for (size_t i = 0; i < sizeof(textVar)/sizeof(textVar[0]); i++)
        {
            std::cout << textVar[i] << " ";
        }
        std::cout << std::endl;
    }
    // better way of storing several strings (no limit per string):
    // efficient memory and no char limit, but not writable
    {
        const char *textVar[] {
            "These are strings",
            "that are",
            "being stored",
            "in an better way!"
            };

        // Although the char arrays themselves are const, pointers are not
        // and can be swapped for other pointers to const char array
        const char *string1 {"These are many strings"};
        textVar[0] = string1;
        for (const char * Line : textVar)
        {
            std::cout << Line << " ";
        }
        std::cout << std::endl;
            
    }
}
    
    /***********************************************************************/
    int assignmentNumber{};
    std::cout << "Assignment number: ";
    std::cin >> assignmentNumber;
    switch (assignmentNumber)
    {
    case 1:{
        fputs("\nAssignment C to F\n", stdout);
        double C;
        std::cout << "Enter Val in C" << std::endl;
        std::cin >> C;
        std::cout << C << " Celcius is : " << (9.0/5.0 * C + 32.0) << " F"<< std::endl;
    } break;
    case 2:{
        fputs("\nAssignment Odd or Even\n", stdout);
        int Val;
        std::cout << "Enter Val" << std::endl;
        std::cin >> Val;
        if (Val%2==0)
        {
            std::cout << "Even" << std::endl;
        }else{
            std::cout << "Odd" << std::endl;
        }
    } break;
    case 3:{
        fputs("\nAssignment Age Check\n", stdout);
        int Age;
        std::cout << "Enter Age" << std::endl;
        std::cin >> Age;
        if (Age < 21)
        {
            std::cout << "Too young" << std::endl;
        }else if(Age > 39){
            std::cout << "Too old" << std::endl;
        }else{
            std::cout << "You are eligible for the treatment" << std::endl;
        }
    } break;
    case 4:{
        fputs("\nAssignment Hunt for vowels\n", stdout);
        char message[] {'T','h','e',' ','s','k','y',' ' ,'i','s',' ','b','l','u','e',' ','m','y',' ','f','r','i','e','n','d'};
        unsigned int size = sizeof(message)/sizeof(message[0]);
        std::cout << size << std::endl;
        hunt_for_vowels(message, size);
    }break;
    case 5:{
        fputs("\nCommon Elements\n", stdout);
        //excersize defines 10 elements per dataset
        int data1[] {1,2,4,5,9,3,6,7,44,55};
        int data2[] {11,2,44,45,49,43,46,47,55,88};
        common_elements(data1, data2);
    }break;
    default:
        break;
    }
    
    
    return 0;
} 


