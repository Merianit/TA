#include "DRP.h"
#include <iostream>
#include <vector>


int born_on_step = 0;

int get(int i) {
    if (i < 0)
        return columns - 1;
    if (i > columns - 1)
        return 0;
    return i;
}

void DRP::init(int *str) {
    int counter = 0;
    for (int i = 0; i < lines; i++)
        for (int j = 0; j < columns; j++) {
            drp[i][j] = str[counter++];
        }
}

void DRP::print() {
    for (int i = 0; i < lines; i++)
        for (int j = 0; j < columns; j++) {
            std::cout << (drp[i][j] ? 'X' : '_');
            std::cout << ((j == columns - 1) ? '\n' : ' ');
        }
}

void DRP::count() {
    for (int i = 0; i < lines; i++)
        for (int j = 0; j < columns; j++) {
            if (drp[i][get(j + 1)])
                counter_drp[i][j]++;

            if (drp[get(i + 1)][j])
                counter_drp[i][j]++;

            if (drp[get(i + 1)][get(j + 1)])
                counter_drp[i][j]++;

            if (drp[get(i + 1)][get(j - 1)])
                counter_drp[i][j]++;

            if (drp[i][get(j - 1)])
                counter_drp[i][j]++;

            if (drp[get(i - 1)][get(j - 1)])
                counter_drp[i][j]++;

            if (drp[get(i - 1)][get(j)])
                counter_drp[i][j]++;

            if (drp[get(i - 1)][get(j + 1)])
                counter_drp[i][j]++;
        }
}

void DRP::check() {
    for (int i = 0; i < lines; i++)
        for (int j = 0; j < columns; j++) {
            if (drp[i][j] == 0 && counter_drp[i][j] == 3) {
                drp[i][j] = 1;
                born_on_step++;
            }
            else if (drp[i][j] == 1 && (counter_drp[i][j] == 2 || counter_drp[i][j] == 3))
                drp[i][j] = 1;
            else if (drp[i][j] == 1 && (counter_drp[i][j] < 2 || counter_drp[i][j] > 3))
                drp[i][j] = 0;
        }
}

void DRP::clear() {
    for (int i = 0; i < lines; i++)
        for (int j = 0; j < columns; j++) {
            counter_drp[i][j] = 0;
        }
}

void DRP::write_html(Html_page &result_page) {
    std::vector<std::vector<std::string>> data(lines, std::vector<std::string>(columns));
    for (int i = 0; i < lines; i++)
        for (int j = 0; j < columns; j++) {
            data[i][j] = drp[i][j] ? 'X' : '_';
        }
    result_page.create_table(lines, columns, data);
}

void DRP::evolve() {
    count();
    check();
    print();
    clear();
}
