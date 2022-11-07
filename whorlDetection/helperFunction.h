#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stack>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <vector>
using namespace std;

enum return_value{
	fail,
	success
};

class graph {

private:
	int v;
	vector<int> *adj;
public:
	// constructor.
	graph(int v) {
		this->v = v;
		adj = new vector<int>[v];
	}
	// set all the edges.
	void add_edge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> print_path(int source, int dest);
	bool BFS(int source, int dest, vector<int> parent);
};

double long euclid(vector <double long> x, vector <double long> y);
double long dot(vector<double long> x, vector<double long> y);
vector<double long> my_minus(vector<double long> x, vector<double long> y);
vector<double long> my_plus(vector<double long> x, vector<double long> y);
vector<double long> my_mult(vector<double long> x, double long y);
int getSkeleton(vector<vector<double long>>& vertexData, vector<vector<int>>& edgeData, const char* fileName, vector<int>& level, vector<double long>& radius);
vector<vector<int>> createMatrix(vector<vector<int>> edgeList, vector<int>& connectivity);
