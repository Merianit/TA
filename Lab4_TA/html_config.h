#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <string>



class Html_page {
private:
	std::ofstream out;
    int counter;
public:
    Html_page(std::string &html) {
        counter = 0;
        out.open(html);
        if (!out) {
            std::cout << "file error!" << std::endl;
            exit(1);
        }
        out << "<html>" << std::endl;
        out << "<head>" << std::endl;
        out << "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">" << std::endl;
        out << "  <title> Result table </title>" << std::endl;
        out << "</head>" << std::endl;
        out << "<body>" << std::endl;
        out << "<h1 align=\"center\"> Lab 4 TA </h1>" << std::endl;
    }
    void create_table(int, int, std::vector<std::vector<std::string>> &data);
    ~Html_page() {
        out << "</body>" << std::endl;
        out << "</html>" << std::endl;
        out.close();
	}

};
