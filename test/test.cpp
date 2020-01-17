#include "pybed.h"
#include <assert.h>
#include <string>
#include <time.h>

#define TEST_PASSED printf("Test passed!\n");

int main(int argc, char** argv)
{
    PyBed pybed = PyBed::InitWithScript("pybed_tests");

    printf("Testing InvokeVoid on test_print function for errors\n");
    pybed.InvokeVoid("test_print");
    TEST_PASSED

    printf("Testing Invoke on get_float function\n");
    float floatingPtVal = pybed.InvokeWithArgs<float>("get_float");
    assert(floatingPtVal == 1.278920f);
    TEST_PASSED

    printf("Testing Invoke on get_day_of_the_month function\n");
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);
    int day = pybed.Invoke<int>("get_day_of_the_month");
    assert(day == aTime->tm_mday);
    TEST_PASSED

    printf("Testing InvokeWithArgs on add function\n");
    int sum = pybed.InvokeWithArgs<int>("add", 1, 2);
    assert(sum == 3);
    TEST_PASSED

    printf("Testing InvokeWithArgs on concat function\n");
    std::string str1("test");
    std::string str2(" this function");
    std::string concatenated = pybed.InvokeWithArgs<std::string>("concat", str1, str2);
    TEST_PASSED

    return 0;
}