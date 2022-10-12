#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Html_page {
private:
	std::ofstream out;
public:
    Html_page() {
        out.open("d:\\web.html");
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
        out << "<h1 align=\"center\"> Lab 2 TA </h1>" << std::endl;
    }
    void create_table(int, int, std::vector<std::vector<std::string>> &data, std::vector<std::vector<std::string>> &color);
    ~Html_page() {
        out << "</body>" << std::endl;
        out << "</html>" << std::endl;
        out.close();
	}

};
