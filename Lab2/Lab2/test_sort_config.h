#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iomanip>

clock_t begin, end;


std::vector<int> v3_bubble(3);
clock_t v3_bubble_time = 0;

std::vector<int> v5_bubble(5);
clock_t v5_bubble_time = 0;

std::vector<int> v10_bubble(10);
clock_t v10_bubble_time = 0;

std::vector<int> v3_sort(3);
clock_t v3_sort_time = 0;

std::vector<int> v5_sort(5);
clock_t v5_sort_time = 0;

std::vector<int> v10_sort(10);
clock_t v10_sort_time = 0;
