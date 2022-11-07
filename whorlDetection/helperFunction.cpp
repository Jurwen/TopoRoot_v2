#include <iostream>
#include <fstream>
#include <sstream>
#include<string>
#include <stack>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include "helperFunction.h"


int getSkeleton(vector<vector<double long>>& vertexData, vector<vector<int>>& edgeData, const char* fileName, vector<int>& level, vector<double long>& radius) {


	ifstream myFile;
	myFile.open(fileName);
	if (myFile.is_open()) { // a checker to see if the file is opened properly.
		vertexData.clear();
		edgeData.clear();
		radius.clear();
		level.clear();
		string word, line;
		double long verCoordinate;
		int edgeIndices;
		int lineNum = 0;
		int row = 0;
		int vNum = 0;
		int eNum = 0;
		while (getline(myFile, line)) {
			lineNum++;
			if (lineNum == 3) {
				istringstream iss(line);
				int col = 0;
				while (iss >> word) {
					if (col == 1) {
						iss >> row;
						vNum = row;
					}
					col++;
				}
			}
			if (lineNum == 10) {
				istringstream iss(line);
				int col = 0;
				while (iss >> word) {
					if (col == 1) {
						iss >> row;
						eNum = row;
					}
					col++;
				}
			}
			if (lineNum >= 16 && lineNum < 16 + vNum) {
				vector<double long> vertex;
				istringstream iss(line);
				int col = 0;
				while (iss >> verCoordinate) {
					if (col == 0) {
						double long rad;
						iss >> rad;
						radius.push_back(rad);
						int hierarchy;
						iss >> hierarchy;
						level.push_back(hierarchy);
						col += 2;
					}
					if (col == 3 || col == 4 || col == 5) {
						vertex.push_back(verCoordinate);
					}
					col++;
				}
				vertexData.push_back(vertex);
			}
			if (lineNum >= 16 + vNum && lineNum < 16 + vNum + eNum) {
				vector<int> edge;
				istringstream iss(line);
				while (iss >> edgeIndices) {
					edge.push_back(edgeIndices);
				}
				edgeData.push_back(edge);
			}
		}
		//From here, all the data from the file is been put into fileData. 
		myFile.close();
		return 1;
	}
	else { // when the file is not opened after calling the open function, display an error msg.
		cout << "Error/ Cannot open the file" << endl;
		return 0;
	}
}

double long euclid(vector<double long> x, vector<double long> y) {
	double long x1 = y[0] - x[0];
	double long x2 = y[1] - x[1];
	double long x3 = y[2] - x[2];
	double long dist = sqrt(pow(x1, 2) + pow(x2, 2) + pow(x3, 2));
	return dist;
}

double long dot(vector<double long> x, vector<double long> y) {
	double long output = x[0] * y[0] + x[1] * y[1] + x[2] * y[2];
	return output;
}

vector<double long> my_minus(vector<double long> x, vector<double long> y) {
	vector<double long> output = { x[0] - y[0], x[1] - y[1],x[2] - y[2] };
	return output;
}

vector<double long> my_plus(vector<double long> x, vector<double long> y) {
	vector<double long> output = { x[0] + y[0], x[1] + y[1],x[2] + y[2] };
	return output;
}

vector<double long> my_mult(vector<double long> x, double long y) {
	vector<double long> output = { x[0] * y, x[1] * y,x[2] * y };
	return output;
}

vector<vector<int>> createMatrix(vector<vector<int>> edgeList, vector<int>& connectivity) {
	int col = int(connectivity.size());
	vector<vector<int>> output(col);
	for (int i = 0; i < edgeList.size(); i++) {
		int vertA = edgeList[i][0];
		int vertB = edgeList[i][1];
		if (vertA != vertB) {
			output[vertA].push_back(vertB);
			output[vertB].push_back(vertA);
			connectivity[vertA] = connectivity[vertA] + 1;
			connectivity[vertB] = connectivity[vertB] + 1;
		}
	}
	return output;
}

vector<int> graph::print_path(int source, int dest) {
	// it stores parent for each vertex to trace the path.
	vector<int> parent(v);
	// BFS returns false means destination is not reachable.
	if (BFS(source, dest, parent) == false) {
		cout << "Destination is not reachable from this source.\n";
		return {};
	}
	// stack to store the shortest path.
	stack<int> st;
	// tracing the path.
	while (parent[dest] != -1) {
		st.push(dest);
		dest = parent[dest];
	}
	// printing the path.
	cout << source;
	vector<int> output;
	while (!st.empty()) {
		output.push_back(st.top());
		st.pop();
	}
	return output;
}

bool graph::BFS(int source, int dest, vector<int> parent) {
	queue<int> q;
	vector<bool> visited(v);
	// setting all the vertices as non-visited
	// and parents of all vertices as -1.
	for (int i = 0; i < v; i++) {
		visited[i] = false;
		parent[i] = -1;
	}
	// pushing the source into the queue and mark it as visited.
	q.push(source);
	visited[source] = true;
	// loop executes until all vertices are traversed.
	while (!q.empty()) {
		// popping one element from queue.
		int temp = q.front();
		q.pop();
		// check for all adjacents.
		for (int k : adj[temp]) {
			if (visited[k] == false) {

				// pushing into queue and mark it visited as well as
				// set the parent of the adjacent in parent array.
				q.push(k);
				visited[k] = true;
				parent[k] = temp;
				// if destination is reached, returns true
				// to state that there exist a path.
				if (k == dest)
					return true;
			}
		}
	}
	// if destination is not reachable.
	return false;
}