#pragma once
#include "html_config.h"
extern int born_on_step;

void Html_page::create_table(int rows, int columns, std::vector<std::vector<std::string>> &data) {
	
	out << "<table width=\"600\" align=\"center\" cellpadding=\"4\" cellspacing=\"0\" border=\"1\">" << std::endl;
	for (int i = 0; i < rows; i++) {
		out << "<tr>" << std::endl;
		for (int j = 0; j < columns; j++) {
			out << "<td width=\"150\" valign=\"top\" " << ">" << data[i][j] << " </td>" << std::endl;
		}
		out << "</tr>" << std::endl;
	}
	out << "<br>" << std::endl;
	out << "<br>" << std::endl;
	out << "<h2 align=\"left\">" << counter << "</h2>" << std::endl;
	counter++;
	out << "<h2 align=\"left\"> Born on this step: " << born_on_step << "</h2>" << std::endl;
	born_on_step = 0;
}
