#include "html_page.h"
#include "html_config.h"

void Html_page::create_table(int rows, int columns, std::vector<std::vector<std::string>> &data, std::vector<std::vector<std::string>>& color) {
	out << "<table width=\"600\" align=\"center\" cellpadding=\"4\" cellspacing=\"0\" border=\"1\">" << std::endl;
	for (int i = 0; i < rows; i++) {
		out << "<tr>" << std::endl;
		for (int j = 0; j < columns; j++) {
			out << "<td width=\"150\" valign=\"top\" BGCOLOR=" << color[i][j] << ">" << data[i][j] << " </td>" << std::endl;
		}
		out << "</tr>" << std::endl;
	}
	out << "<br>" << std::endl;
	out << "<br>" << std::endl;
}

template <typename T>
std::string toString(T val)
{
	std::ostringstream oss;
	oss << val;
	return oss.str();
}

template<typename T>
T fromString(const std::string& s)
{
	std::istringstream iss(s);
	T res;
	iss >> res;
	return res;
}

void create_html() 
{
	Html_page result_page; 
	extern clock_t char_printf_time;
	extern clock_t char_cout_time;
	extern clock_t int_printf_time;
	extern clock_t int_cout_time;
	extern clock_t double_printf_time;
	extern clock_t double_cout_time;
	extern clock_t str_printf_time;
	extern clock_t str_cout_time;

	extern clock_t v3_bubble_time;
	extern clock_t v5_bubble_time;
	extern clock_t v10_bubble_time;
	extern clock_t v3_sort_time;
	extern clock_t v5_sort_time;
	extern clock_t v10_sort_time;

	std::vector<std::vector<std::string>> data(3, std::vector<std::string>(5));
	std::vector<std::vector<std::string>> color(3, std::vector<std::string>(5));

	data[0][1] = "char";
	data[0][2] = "int";
	data[0][3] = "double";
	data[0][4] = "\"PKIMS RULEZ\"";

	data[1][0] = "printf";
	data[1][1] = toString(char_printf_time);
	data[1][2] = toString(int_printf_time);
	data[1][3] = toString(double_printf_time);
	data[1][4] = toString(str_printf_time);

	data[2][0] = "std::cout";
	data[2][1] = toString(char_cout_time);
	data[2][2] = toString(int_cout_time);
	data[2][3] = toString(double_cout_time);
	data[2][4] = toString(str_cout_time);
	
	
    for (int j = 1; j < 5; j++) {
		int i = 1;
		if (fromString<int>(data[i][j]) < fromString<int>(data[i + 1][j])) {
			color[i][j] = "\"green\"";
			color[i + 1][j] = "\"red\"";
		}
		else if (fromString<int>(data[i][j]) > fromString<int>(data[i + 1][j])) {
			color[i][j] = "\"red\"";
			color[i + 1][j] = "\"green\"";
		}
	}
	
	
	result_page.create_table(3, 5, data, color);

	data[0][1] = "3 elements";
	data[0][2] = "5 elements";
	data[0][3] = "10 elements";

	data[1][0] = "bubble_sort";
	data[1][1] = toString(v3_bubble_time);
	data[1][2] = toString(v5_bubble_time);
	data[1][3] = toString(v10_bubble_time);
	
	data[2][0] = "std::sort";
	data[2][1] = toString(v3_sort_time);
	data[2][2] = toString(v5_sort_time);
	data[2][3] = toString(v10_sort_time);
	
	
    for (int j = 1; j < 4; j++) {
		int i = 1;
		if (fromString<int>(data[i][j]) < fromString<int>(data[i + 1][j])) {
			color[i][j] = "\"green\"";
			color[i + 1][j] = "\"red\"";
		}
		else if (fromString<int>(data[i][j]) > fromString<int>(data[i + 1][j])) {
			color[i][j] = "\"red\"";
			color[i + 1][j] = "\"green\"";
		}
	}
	
	result_page.create_table(3, 4, data, color);
}
