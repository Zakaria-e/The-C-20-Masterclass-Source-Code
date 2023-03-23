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
#include <string_view>
#include <optional>
#include "functions1.h"
#include "scripts1.h"

//GLOBAL VARIABLES OUTSIDE FUNCTIONS: ACCESSIBLE TO ANYTHING AFTER ITS INIT
// Run time value
float global_floatVal {12.34567890123456789012345f};

void scriptfxn1(){//definition
fputs("\nPrimative Types, References, and compile vs runtime\n", stdout);
     double PI {3.14159f}; // constexpr variables (Read only) only used at compile time to calculate const values in runtime.
    // static_assert(PI == 5, "Bad PI"); // only uses const or constexpr
    char character1 {'a'};
    auto auto_uint { 123u}; // unsigned
    auto auto_uintl { 123ul}; //unsigned long
    auto auto_uintll { 123ll}; // long long
    unsigned short float2uint16Val(global_floatVal);//Narrowing Functional Conversion
    unsigned short uint16Val{13214};//Braced Initialization
    unsigned short uint16Diff(float2uint16Val - uint16Val);//negative uint wraps around range
    //unsigned short uint16Diff2 = float2uint16Val - uint16Val;//Assignment Initialization

    //references cant be repurposed like pointers - More like const pointers
    unsigned short & ref2uint16Diff{uint16Diff};//the two names will be interchangable (same address)
    //ref2uint16Diff = uint16Val;//would simply change the value for uint16Diff as well. They are inseperable
    //const unsigned short & ref2uint16Diff{uint16Diff};// would mean that the value can't be modified via the ref
    
    std::cout << std::setprecision(20);
    std::cout << 
    "float2uint16Val: " << float2uint16Val <<
    "\nuint16Val: " << uint16Val <<
    "\nuint16Diff: " << uint16Diff <<
    "\nref2uint16Diff: " << ref2uint16Diff <<
    std::endl;

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

fputs("\nCASTING\n", stdout);
    auto diffint = uint16Val1 - uint16Val2;
    std::cout << "Implicit cast: auto diffint = uint16Val1 - uint16Val2 = " << diffint << std::endl;
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

    //range based for loop with reference to self
    for (auto& i : coll00){ 
        i*=10;//in this case i refers back to the original collection
    }
    std::cout <<  "coll00 is now multiplied by 10" << std::endl;

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

fputs("\nPointers\n", stdout);
{
    int       *      mutable_pointer_to_mutable_int{};
    int const *      mutable_pointer_to_constant_int{};
    int       *const constant_pointer_to_mutable_int{};
    int const *const constant_pointer_to_constant_int{};
    //although int *p_var dataVar {}; is valid and would create a pointer
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
    int *p_var55 {&coll00[sizeof(coll00)/sizeof(coll00[0])]};//points to last element of coll00
    {
        std::ptrdiff_t ptrDiff = p_var55 - coll00; // works consistently across architectures
        std::cout << "ptrDiff = p_var55 - coll00: " << ptrDiff << std::endl;
    }

    //Dynamic allocation on heap
    int *p_var56{ new int}; //new dangling int-pointer pointing to allocated (uninitialized) memory space
    p_var50 = new int(23); //Repurpose pointer to reserve heap for a single int and initialize (direct)
    p_var51 = new int{41}; //Repurpose pointer to reserve heap for a single int and  initialize (uniform)

    delete p_var56; //deallocation leaves us with a dangling pointer
    p_var56 = p_var50; //Both currently point to same allocated heap address
    delete p_var56; //The heap address is de-allocated leaving both p_var50 p_var56 as dangling pointers
    p_var56 = nullptr; //ALWAYS reset to nullptr if done using a pointer
    p_var50 = nullptr; //accessing data via p_var50 can cause crash
    delete p_var51; //never double delete a pointer - 2nd delete will crash
    p_var51 = nullptr; //free to reuse a pointer after delete
    delete p_var51; //but deleting again nullptr is safe

    if (p_var51 != nullptr)//verbose nullptr check
    {
        /* check if ptr is nullptr before use */
    }else{
        std::cerr << "WARNING: Trying to use invalid pointer!" << std::endl;
    }
    //Equivalent
    if (p_var51)//verbose nullptr check
    {
        /* check if ptr is nullptr before use */
    }else{
        std::cerr << "WARNING: Trying to use invalid pointer!" << std::endl;
    }

    //Pointers initialized with dynamic arrays
    //std::size, sizeof, range based for loop WONT work with dynamic arrays
    //will need to use index based for loop and a size variable
    size_t size{10}; //doesn't have to be const for dynamic arrays
    //double *p_var57{ new double[size] }; //  allocates space for array on heap but no initialization (junk data)
    //double *p_var57{ new(std::nothrow) double[size]{} }; //  allocates space for array on heap and initialize to 0.0
    double *p_var57{ new(std::nothrow) double[size]{11,12,13,14} }; //allocates space for array on heap and initialize, padding with 0.0
    if (p_var57)//verbose nullptr check
    {
        std::cout << "On Heap *p_var57: ";
        for (size_t i{0}; i < size; ++i)
        {
            std::cout << *(p_var57+i) << " ";
        }
        std::cout << std::endl;
    }else{
        std::cerr << "WARNING: Trying to use invalid pointer!" << std::endl;
    }
    delete[] p_var57; //must use []
    p_var57 = nullptr;

    //Memory Leak: When we lose track/access to dynamic memory (such as overwriting a heap pointer and then not being able to delete)
    p_var51 = new int{67}; // Ok
    //p_var51 = &var50; //NO! We now have no way to deallocate (delete) the heap space!
    {
        //p_var51 = new int{67}; NO! The pointer has no scope outside these brackets. Must delete within brackets
    }



}   

fputs("\nException Handling\n", stdout);
{
    //for heap allocation:
    int * data = new(std::nothrow) int[1000000000000000000];
    //equal to:
    try
    {
        int *data = new int[1000000000000000000]; //This is too big to allocate to heap and will throw an std::bad_alloc
    }
    catch(const std::exception& e0001)
    {
        int *data {nullptr};
        std::cerr << "Failed heap allocation-Resorted to nullptr: " << e0001.what() << '\n';
    }

    
    
}

fputs("\nText Management\n", stdout);
{
    char charArr[] {"Hello World!"};//cstring is modifiable at the character level
    charArr[11] = '?';
    std::cout << "charArr : " << charArr << std::endl; //decomposed char array
    //Array pointer points to first element in array
    //some compilers turn cstring literal into array of const char,
    //is not writable by pointer in the future... some will throw error
    const char *p_charArr{"Hello World!"};//wont compile without the const
    std::cout << "Location of the pointer: &p_charArr : " << &p_charArr << std::endl; //location of the pointer
    std::cout << "cout reads cstring instead of ptr val: p_charArr : " << p_charArr << std::endl; //cout would print the pointer value normally, but for char* reads the cstring
    std::cout << "must interpret as void* to shpw ptr val: (void*)p_charArr : " << (void*)p_charArr << std::endl; //first char - behavior similar to int* in this case
    std::cout << "cout reads ith char of cstring: p_charArr[0] : " << p_charArr[0] << std::endl; //first char (only for cstring)
    std::cout << "normal pointer read: *p_charArr : " << *p_charArr << std::endl; //first char - behavior similar to int* in this case

    //const char* is not writable at the character level.
    //If wish to write, then use char textVar[] {"test"} to replace entire text
    
    //count lowercase
    {
        int count{};

        for (size_t i = 0; i < std::size(charArr); i++)//sizeof(charArr)/sizeof(charArr[0]) same
            {
                if(islower(charArr[i])){
                    charArr[i] = std::toupper(charArr[i]);
                    count++;
                }
            }
        std::cout << "There was " << count << " lowercase letters in " << charArr << std::endl;
    }
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
    // better way of storing several Cstrings (no limit per string):
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
        const char *string1[] {"These are swappable strings"};
        textVar[0] = string1[0];
        for (const char * Line : textVar)
        {
            std::cout << Line << " ";
        }
        std::cout << std::endl;
        std::cout << "sizeof(textVar): "<< sizeof(textVar) << std::endl; //4 pointers x 8Byte = 32
        std::cout << "sizeof(textVar[0]): "<< sizeof(textVar[0]) << std::endl; //single pointer x 8Byte = 8
        std::cout << "sizeof(textVar)/sizeof(textVar[0]): "<< sizeof(textVar)/sizeof(textVar[0]) << std::endl; //will count cstring pointers - not chars
        std::cout << "std::strlen(textVar[0]): "<< std::strlen(textVar[0]) << std::endl; //counts till /0
       
        const char *dir1{"D:\\Users\\ZGamingPC\\Downloads\\file.xls"};
        const char *dir2{"D:\\Users\\ZGamingPC\\Downloads\\filE.xlsx"};
        std::cout << "dir1: " << dir1 << std::endl;
        std::cout << "dir2: " << dir2 << std::endl;
        
        //strcmp returns 0 if str1==str2. 1 if str1 is lexicographically after str2 (str1>str2). -1 if str1<str2
        // ASCII ORDER: /0 < SPACE < NUM < UPPER < LOWER
        std::cout << "std::strcmp(dir1,dir2): "<< std::strcmp(dir1,dir2) << std::endl;
        std::cout << "std::strcmp(dir2,dir1): "<< std::strcmp(dir2,dir1) << std::endl;
        
        // strchr finds the target character and returns a the char pointer starting with the first found instance
        //strrchr is the right to left scan and is better for this application
        // returns nullptr when no more found (which is the cue to break the loop)
        char targetChar{'\\'};
        const char *result = dir1; //initialize to the cstring to be scanned
        const char *lastValidResult{}; //initialize to the cstring to be scanned
        size_t i{};
        while ((result = std::strrchr(result,targetChar)) != nullptr)
        {
            std::cout << "i: " << i << "\tFound '" << targetChar << "' at "<< (void*)result << "\t" << result << std::endl;
            lastValidResult = result;
            ++result;
            ++i;
        }

        //we will compare the directory excluding the file name
        // std::ptrdiff_t dirLength = dir1 - static_cast<void*>(result);
        std::cout << "(void*)dir1: " << (void*)dir1 << std::endl;
        std::cout << "(void*)lastValidResult: " << (void*)lastValidResult << std::endl;
        std::ptrdiff_t dirLength = lastValidResult - dir1;
        std::cout << "dirLength = dir1 - result: " << dirLength << std::endl;
        std::cout << "std::strncmp(dir1,dir2,dirLength): "<< std::strncmp(dir1,dir2,dirLength) << std::endl;

        {
        using namespace std::string_literals; //for s suffix (needed for some compilers to handle str literals)
        std::string str_0REG {"REG"};
        // std::string str_0ZON {"ZON"};
        int REG_read = 10;
        // int ZON_read = 32;
        std::string str_0FullFileName =
            str_0REG + std::to_string(REG_read) +
            "ZON"s + std::to_string(32) + ".zip";
        // std::string str_0Name = str_0REG.append(std::to_string(REG));
        std::cout << "str_0Name: " << str_0FullFileName << std::endl;

        std::string str_ZON_OUT = "Zone #: ";
        str_ZON_OUT = str_ZON_OUT.append(str_0FullFileName,8,2);//append(SourceStr,startCharIdx,NumChar)
        std::cout << "str_ZON_OUT: " << str_ZON_OUT << std::endl;

        std::cout << "str_0FullFileName.size(): " << str_0FullFileName.size() << std::endl;
        str_0FullFileName[8] = '4';
        str_0FullFileName.at(9) = '3';
        std::cout << "str_0FullFileName: " << str_0FullFileName << std::endl;
        std::cout << "char: str_0FullFileName.at(9): " << str_0FullFileName.at(9) << std::endl;
        std::cout << "char: str_0FullFileName.front(): " << str_0FullFileName.front() << std::endl;
        std::cout << "char: str_0FullFileName.back(): " << str_0FullFileName.back() << std::endl;
        const char * wrapped_c_string = str_0FullFileName.c_str();
        std::cout << "const char * wrapped_c_string: " << wrapped_c_string << std::endl;// can't be used to modify
        char * data = str_0FullFileName.data();

        // std::cout << "str_ZON_OUT: " << str_0FullFileName. << std::endl;
        // std::cout << "str_ZON_OUT: " << str_0FullFileName << std::endl;
        // int REG_read = std::to_;
        // int ZON_read = 32;
        }

        /*
        SEE 190,191 for stringview implicit conversion in fx params
        */

        
    }
fputs("\nFunctions, Enums, and Type Aliases\n", stdout);
    {
        //pass by pointer
        int value = 753;
        std::cout << "int value:" << value << " &val:" << &value << std::endl;
        passByPointerDemoFx(&value);
        passByReferenceDemoFx(value);


        //Using New Enum
        Month mth{Month::Feb};
        std::cout << "New Enum (Via sting_view): " << month_to_string(mth) << std::endl;
        std::cout << "New Enum (static_cast<uint>): " << static_cast<unsigned int>(mth) << std::endl;

        //Using old Enum
        Direction direction{Direction::Bottom};//could also forgo "Direction::"
        //returns int represented by "Direction" value
        // enabling comparisons and math... which is wierd
        std::cout << "Direction: " << direction << std::endl; 

        //Type aliases are shorthand for annoying type names
        using ULLInt = unsigned long long int;
        //same as:
        //typedef unsigned long long int ULLInt;
        ULLInt huge_num {12'345'678'901'234'567ull};
        std::cout << "huge_num: " << huge_num << std::endl;
    

        std::string str1 {"Hello World in C++20!"};
	    std::optional<char> c{'C'};
        auto result1 = find_character(str1,c); //Will search for SPACE if you don't specify 
        if(result1.has_value()){
            std::cout << "Found character '" << c.value() <<"' at index " << result1.value() << std::endl;
        }else{
            std::cout << "Could not find character '" << c.value() <<"' in the string : " << str1 << std::endl;
        }

        //OVERLOADS: see functions1.cpp/h
        {
            short x{32LL};
            short y{-123LL};
            //const short would still use overload: const int&
            //and obiously, const int pararm -> const int& overload
            short z = add(x,y);//impConv overload: const int& (imconv allowed since const->copy)
        }

        {
            int x{32LL};
            int y{-123LL};
            short z = add(x,y);//overload: int&
        }

        {
            int x{32LL};
            int y{-123LL};
            const int u{32LL};
            const int v{-123LL};
            int z = add(&x,&y); //overload: int *
            int w = add(&u,&v); //overload: const int *
        }

        {
            float x{32LL};
            float y{-123LL};
            float z = add(x,y);//impConv to overload: double
        }
        {
            std::string x{"Hello"};
            std::string y{"World"};
            std::string z = add(x,y);//overload: string &
        }
        {
            char x[20] = "Hello ";
            char y[] = "World";
            const char* z{add(x,y)};
            std::cout << z << std::endl;//overload: const *
        }
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
        common_elements_val(data1, data2,10,10);
        common_elements_ref(data1, data2,10,10);
    }break;
    case 6:{
        fputs("\nMaximum Subsequence\n", stdout);
        //excersize defines 10 elements per dataset
        int data[] {3,-4 ,6,1,1,-2,2,3};
        auto result = max_subsequence_sum(data , sizeof(data)/sizeof(data[0]));
        std::cout << std::endl << "result : " << result << std::endl;
    }break;
    case 7:{
        fputs("\nInsertion Sort\n", stdout);
        //excersize defines 10 elements per dataset
        int data[] {3,-4 ,6,1,1,-2,2,3};
        insertion_sort(data , sizeof(data)/sizeof(data[0]));
    }break;
    default:
        break;
    }

}

/* DONTS
---Never write a value through an ininitialized pointer or a nullptr
int * unininitializedPointer{};//nullptr
OR
int * unininitializedPointer;//random address which we probably don't own
*unininitializedPointer = 5;//CRASH
---Writing to de-allocated pointer
int *ptrVar{};//nullptr
ptrVar = new int; Dyncamically allocate for single int on heap. Exists until delete.
*ptrVar = 77;// value stored on heap
delete ptrVar; de-allocated the variable from the heap (GOOD HABIT TO: ptrVar = nullptr;)
*ptrVar = 50;// writing to what is now foreign memory - may crash
---Delete a hash variable twice
delete ptrVar; //2nd delete CRASH
*/