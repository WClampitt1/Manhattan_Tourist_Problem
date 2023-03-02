/*
 * Graph.h
 *
 *  Created on: Feb 27, 2023
 *      Author: William Clampitt
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <string>
#include <iostream>

class Graph{

	struct node{
		int index;
		int score = 0;
	};

	struct edge{
		int weight = 0;
		bool connected = false;
	};

public:
	Graph(unsigned int rows, unsigned int cols);
	void make_edge(unsigned int source, unsigned int destination, int weight);
	void print_graph();
	bool is_connected(unsigned int node_1, unsigned int node_2);

	unsigned int rows = 0, cols = 0, total_nodes = rows * cols;

private:
	std::vector<std::vector<edge>> adjacency_matrix;
	std::vector<node> nodes;

	std::vector<std::vector<node>> get_node_grid();


};



#endif /* GRAPH_H_ */
