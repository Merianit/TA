#include "test_sort.h"
#include "test_sort_config.h"

void bubble_sort(std::vector<int>& A)
{
    bool is_sorted = false;
    while (!is_sorted) {
        int i = 0;
        is_sorted = true;
        while (i < A.size() - 1) {
            if (A[i] > A[i + 1]) {
                std::swap(A[i], A[i + 1]);
                is_sorted = false;
            }
            i++;
        }
    }
}

void vector_randomization(std::vector<int>& A) 
{
    for (int i = 0; i < A.size(); i++) {
        A[i] = rand();
    }
}

void vector_display(std::vector<int>& A)
{
    for (auto x : A)
    {
        std::cout << x << std::endl;
    }
    std::cout << "\n";
}

long get_time()
{
    __asm rdtsc;
}

void test_sort() 
{
    srand(time(NULL));

    vector_randomization(v3_bubble);
    vector_randomization(v5_bubble);
    vector_randomization(v10_bubble);

    v3_sort = v3_bubble;
    v5_sort = v5_bubble;
    v10_sort = v10_bubble;

    begin = get_time();
    bubble_sort(v3_bubble);
    end = get_time();
    v3_bubble_time = end - begin;

    begin = get_time();
    bubble_sort(v5_bubble);
    end = get_time();
    v5_bubble_time = end - begin;

    begin = get_time();
    bubble_sort(v10_bubble);
    end = get_time();
    v10_bubble_time = end - begin;

    begin = get_time();
    std::sort(v3_sort.begin(), v3_sort.end());
    end = get_time();
    v3_sort_time = end - begin;

    begin = get_time();
    std::sort(v5_sort.begin(), v5_sort.end());
    end = get_time();
    v5_sort_time = end - begin;

    begin = get_time();
    std::sort(v10_sort.begin(), v10_sort.end());
    end = get_time();
    v10_sort_time = end - begin;

    vector_display(v3_bubble);
    vector_display(v5_bubble);
    vector_display(v10_bubble);
    vector_display(v3_sort);
    vector_display(v5_sort);
    vector_display(v10_sort);

    std::cout << "\n";                                                                                             
    std::cout << std::setw(10) << "sort" << std::setw(6) << "3" << std::setw(6) << "5 " << std::setw(6) << "10" << std::endl;
    std::cout << std::setw(10) << "bubble" << std::setw(6) << v3_bubble_time << std::setw(6) << v5_bubble_time << std::setw(6) << v10_bubble_time << std::endl;
    std::cout << std::setw(10) << "std::sort" << std::setw(6) << v3_sort_time << std::setw(6) << v5_sort_time << std::setw(6) << v10_sort_time << std::endl;
                                                                                                                   
}