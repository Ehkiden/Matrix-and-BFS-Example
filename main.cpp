//Project: Matrix and Breadth First Traversal Example
//Date: 04/11/2017
//Purpose: create a graph from given set of vertices and edges
//         repeatedly ask the user to choose a source vertex (enter "Q" or "q" to quit)
//         and calculate the shortest distance of each vertex to the source
//         It is a sub-problem of Project 3.
//Author: Jared Rigdon

/*
This program is basically a sub program for the Bacon Number program
Good for a small test example size to go through step by step
Do note that the default source number is 0, you can change it to another number but there really isnt a need to 
BFS is basically going to each vertex that is 1 away from the chosen vertex, then continue to check all at the next level until the source vertex is found
This only finds the distance but not the shortest distance
*/

#include <iostream>
#include <vector>
#include "Graph.h"
#include <string>

using namespace std;

int main()
{
	// Create a graph given in the above diagram
	const int VERTICESNUM = 7;
	Graph testingGraph(VERTICESNUM);
	testingGraph.addEdge(0, 2, 150);
	testingGraph.addEdge(0, 6, 150);
	testingGraph.addEdge(2, 6, 150);
	testingGraph.addEdge(1, 3, 1472);
	testingGraph.addEdge(2, 4, 2268);
	testingGraph.addEdge(3, 6, 3555);
	testingGraph.addEdge(3, 5, 3979);

	int source;

	while (true)
	{
		//equivalent to asking the name of the actor to search for
		cout << "Please choose the vertex as the source (integer range [0,6]) (type 'Q' or 'q' to quit): " << endl;
		cin >> source;
		cin.ignore(256, '\n');

		if (cin.fail())
		{
			string check_input;
			cin.clear();
			cin >> check_input;
			if (check_input == "Q" || check_input == "q")
				break;
			else {
				cout << "Invalid input, please try again..." << endl;
				continue;
			}
		}
		else if (source < 0 || source>6) {
			cin.clear();
			cout << "Invalid input, please try again..." << endl;
			continue;
		}
		cout << "Breadth First Traversal "
			<< "(starting from the source vertex: " << source << " )" << endl;
		vector<int> distance(VERTICESNUM, -1);
		testingGraph.BFS(source, distance);
		// Display the distance of each vertex to the source vertex
		// the distance is defined as the number of edges
		// the distance of the source to the source is 0
		// there is no path from the source to a vertex if its distance is -1
		cout << "Source vertex: " << source << endl;
		for (int i = 0; i < distance.size(); i++)
		{
			if (i != source)
			{
				if (distance[i] != -1)
					cout << "the distance to vertex " << i << " is " << distance[i] << "-edge away." << endl;
				else
					cout << "there is no path to vertex " << i << endl;
			}
		}
	}
	return 0;
}

