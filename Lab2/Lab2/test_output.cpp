#include "test_output.h"
#include "test_output_config.h"


void test_output() 
{
    clock_t begin, end; 
    begin = clock();
    for (int i = 0; i < 10000; i++)
    {
        printf("%c", char_test);
    }
    end = clock();
    char_printf_time = end - begin;

    begin = clock();
    for (int i = 0; i < 10000; i++)
    {
        std::cout << char_test;
    }
    end = clock();
    char_cout_time = end - begin;


    begin = clock();
    for (int i = 0; i < 10000; i++)
    {
        printf("%d", int_test);
    }
    end = clock();
    int_printf_time = end - begin;

    begin = clock();
    for (int i = 0; i < 10000; i++)
    {
        std::cout << int_test;
    }
    end = clock();
    int_cout_time = end - begin;

    begin = clock();
    for (int i = 0; i < 10000; i++)
    {
        printf("%f", double_test);
    }
    end = clock();
    double_printf_time = end - begin;

    begin = clock();
    for (int i = 0; i < 10000; i++)
    {
        std::cout << double_test;
    }
    end = clock();
    double_cout_time = end - begin;

    begin = clock();
    for (int i = 0; i < 10000; i++)
    {
        printf("%s", str_test);
    }
    end = clock();
    str_printf_time = end - begin;

    begin = clock();
    for (int i = 0; i < 10000; i++)
    {
        std::cout << str_test;
    }
    end = clock();
    str_cout_time = end - begin;

    std::cout << "\n";
    std::cout << "\n";
    std::cout << std::setw(10) << "function" << std::setw(6) << "char" << std::setw(6) << "int " << std::setw(6) << "double" << std::setw(12) << "PKIMS RULEZ" << std::endl;
    std::cout << std::setw(10) << "printf" << std::setw(6) << char_printf_time << std::setw(6) << int_printf_time << std::setw(6) << double_printf_time << std::setw(12) << str_printf_time << std::endl;
    std::cout << std::setw(10) << "cout" << std::setw(6) << char_cout_time << std::setw(6) << int_cout_time << std::setw(6) << double_cout_time << std::setw(12) << str_cout_time << std::endl;

}