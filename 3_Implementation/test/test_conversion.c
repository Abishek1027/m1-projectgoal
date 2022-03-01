#include "unity.h"
#include "assert.h"
#include "usd.h"
#include "pound.h"

/*required by the unity test framework*/
void setUp()
{

}
void tearDown()
{

}
void test_usd(void)
{
    int n1 = 1000, n2 = 72;
    TEST_ASSERT_EQUAL(13.8, usd(n1,n2));
    
}
void test_pound(void)
{
    int n3 = 400 , n4 = 101;
    TEST_ASSERT_EQUAL(3.9, pound(n3,n4));
    
    
}

int main(void)
{   
    /*required by the unity test framework*/
    UNITY_BEGIN();
    /*required by the unity test framework*/
    RUN_TEST(test_usd);
    RUN_TEST(test_pound);
    /*required by the unity test framework*/
    return UNITY_END();
}