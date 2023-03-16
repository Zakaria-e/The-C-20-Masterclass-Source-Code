//Enum types really map to integers BUT WILL NOT BE IMPLICITLY CONVERTED to ANY other type
//Default class type is int, unless other is specified
//Default starts from 0 and increments unless 
enum class Month : unsigned char{
    Jan = 1, January = Jan, Feb, Mar,
    Apr, May, Jun,
    Jul, Aug, Sep,
    Oct, Nov, Dec
};

void scriptfxn1();//decleration/protoype
void hunt_for_vowels(char message[], unsigned int size);
void common_elements_val(int array_1[], int array_2[], size_t size1, size_t size2);
void common_elements_ref(int (&array_1)[], int (&array_2)[], size_t size1, size_t size2);
void passByPointerDemoFx(int* val);
void passByReferenceDemoFx(int& val);
int max_subsequence_sum(int sequence[] , unsigned int size);

std::string_view month_to_string(Month month);