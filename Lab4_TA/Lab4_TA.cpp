// Lab4_TA.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <conio.h>

#include "DRP.h"
#include "html_config.h"

extern const int lines;
extern const int columns;


int main(int argc, char* argv[]) {
    DRP drp;
    std::string html_name;
    std::fstream file;

    if (argc > 2)
    {
        std::string path(argv[1]);
        file.open(path);
        if (!file) {
            std::cout << "Can't open file" << std::endl;
            exit(1);
        }
        html_name = argv[2];
    }
    else {
        std::cout << "Can't open file" << std::endl;
        exit(1);
    }

    Html_page result_page(html_name);

    const int length = 2 * lines * columns + 1;
    int drp_data[length] = {0};
    char ch;

    for (int i = 0; i < length; i++) {
        file >> ch;
        if (ch == '0' || ch == '1')
            drp_data[i] = ch - '0';
    }
    drp.init(drp_data);
   
    drp.print();
    drp.write_html(result_page);
    std::cout << '\n';
    while (!_kbhit())
        if (_getch() == 27) break;
        else {
            drp.evolve();
            drp.write_html(result_page);
            std::cout << '\n';
        }
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
