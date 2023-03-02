/*
 * Graph.cpp
 *
 *  Created on: Feb 27, 2023
 *      Author: William Clampitt
 */

#include "Graph.h"


bool Graph::is_connected(unsigned int node_1, unsigned int node_2){
	return Graph::adjacency_matrix.at(node_1).at(node_2).connected;
}


void Graph::print_graph(){
	std::string node_str = "* ";
	std::string space_str = "  ";

	for(unsigned int row = 0; row < 2 * Graph::rows - 1; row++){
		for(unsigned int col = 0; col < 2 * Graph::cols - 1; col++){
			if((row % 2 == 0) & (col % 2 == 0)){
				std::cout << node_str;
			}
			else if((row % 2 == 0) & (col % 2 == 1)){
				std::cout << Graph::adjacency_matrix.at((col - 1)/2 + (row/2)*Graph::cols).at((col + 1)/2 + (row/2)*Graph::cols).weight << " ";
			}
			else if((row % 2 == 1) & (col % 2 == 0)){
				std::cout << Graph::adjacency_matrix.at((col / 2) + ((row - 1) / 2) * Graph::cols).at((col / 2) + ((row + 1) / 2) * Graph::cols).weight << " ";
			}
			else {
				std::cout << space_str;
			}
		}
		std::cout << std::endl;
	}
}

void Graph::make_edge(unsigned int source, unsigned int destination, int weight){
	Graph::adjacency_matrix.at(source).at(destination).connected = true; // This line crashes program
	Graph::adjacency_matrix.at(source).at(destination).weight = weight;
}

Graph::Graph(unsigned int rows, unsigned int cols){
	Graph::rows = rows;
	Graph::cols = cols;
	Graph::total_nodes = rows * cols;

	Graph::edge default_edge;
	Graph::node default_node;

	std::vector<Graph::edge> temp_matrix_row; // used for making adjacency_matrix
	std::vector<Graph::node> temp_grid_row; // used for creating node_grid

	unsigned int index = 0;

	for(unsigned int row = 0; row < Graph::total_nodes; row++){
		for(unsigned int col = 0; col < Graph::total_nodes; col++){
			temp_matrix_row.push_back(default_edge);

			default_node.index = index;
			Graph::nodes.push_back(default_node);
			index++;
		}
		Graph::adjacency_matrix.push_back(temp_matrix_row);
		temp_matrix_row.clear();

	}
}
