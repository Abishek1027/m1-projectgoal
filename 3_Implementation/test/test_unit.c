#include"unity.h"
#include"banking.h"

void test_input(int)
{
    TEST_CHECK_(input(int))

}
TEST_LIST = {
    {"int input(int);", test_input},
    {0}
    
};