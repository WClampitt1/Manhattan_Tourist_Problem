//============================================================================
// Name        : Manhattan_Tourist_Problem.cpp
// Author      : William Clampitt
// ID		   : 1527418
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Graph.h"


bool has_only_digits(const std::string s){
  return s.find_first_not_of( "0123456789" ) == std::string::npos;
}


int main() {

	std::ifstream in;
	std::vector<std::string> rows;
	std::string cell;

	in.open("Input.csv");

	while(in.good()){
		std::getline(in, cell, ',');

		if(cell != ""){
			rows.push_back(cell);
		}
	}

	in.close();

	std::vector<std::vector<int>> edge_weights;
	std::vector<int> temp_row;

	for(unsigned int index = 0; index < rows.size(); index++){
		if(has_only_digits(rows.at(index))){
			std::cout << "Pushing: " << rows.at(index) << std::endl;

			temp_row.push_back(std::stoi(rows.at(index)));
		}
		else{
			std::cout << "Not pushing: " << rows.at(index) << std::endl;
			edge_weights.push_back(temp_row);
			temp_row.clear();
			std::cout << std::endl;
		}
	}

	for(unsigned int i = 0; i < edge_weights.size(); i++){
		for(unsigned int j = 0; j < edge_weights.at(i).size(); j++){
			std::cout << edge_weights.at(i).at(j) << " ";
		}
		std::cout << std::endl;
	}


	//Graph my_graph = Graph(3, 3);

	//my_graph.print_graph();
	return 0;
}
