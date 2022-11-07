// whorlDetection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include<string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include "helperFunction.h"
#include <map>


int main(int argc,char *argv[])
{
	vector<vector<double long>> vertexList;
	vector<vector<int>> edgeList;
	vector<double long> radius;
	vector<int> level;
	if (getSkeleton(vertexList, edgeList, "353-10_out_skel_fixed.ply", level, radius) == 1) {
		cout << "Successfully initiated ply data... " << endl;
	}
	int vertexNum = int(vertexList.size());
	int edgeNum = int(edgeList.size());
	vector<int> connectivity(vertexNum);
	for (int i = 0; i < vertexNum; i++) {
		connectivity[i] = 0;
	}
	vector<vector<int>> adjMatrix = createMatrix(edgeList, connectivity);
	vector<int> junctions;
	for (int i = 0; i < edgeList.size(); i++) {
		if (level[edgeList[i][0]] == 1 && level[edgeList[i][1]] == 2) {
			junctions.push_back(edgeList[i][0]);
		}
		if (level[edgeList[i][0]] == 2 && level[edgeList[i][1]] == 1) {
			junctions.push_back(edgeList[i][1]);
		}
	}
	vector<int> twoEnds;
	for (int i = 0; i < vertexList.size(); i++) {
		if (level[i] == 1) {
			int neighborStem = 0;
			vector<int> incidenceV = adjMatrix[i];
			for (auto connectV: incidenceV) {
				if (level[connectV] == 1) { neighborStem = neighborStem + 1; }
			}
			if (neighborStem == 1) {
				twoEnds.push_back(i);
			}
		}
	}
	//for (int i = 0; i < level.size(); i++) {
	//	cout << level[i] << endl;
	//}
	//cout << "twoEnds starting to print: " << endl;
	//for (int i = 0; i < twoEnds.size(); i++) {
	//	cout << twoEnds[i] << endl;
	//}

	if (vertexList[twoEnds[1]][2] < vertexList[twoEnds[0]][2]) {
		vector<int> twoEnds_copy = twoEnds;
		twoEnds[0] = twoEnds_copy[1];
		twoEnds[1] = twoEnds_copy[0];
	}
	int trace = twoEnds[0];
	map<int, double long> indexToDisMap; //for each vertex on the stem path, map to a number representing its geodesic distance form the top.
	map<double long, int> disToIndexMap;
	double long distance = 0; 
	vector <int> stemPath = {trace};
	while (trace != twoEnds[1]){
		indexToDisMap[trace] = distance;
		disToIndexMap[distance] = trace;
		vector<int> incidenceV = adjMatrix[trace];
		for (auto connectV : incidenceV) {
			if (level[connectV] == 1 && connectV != stemPath.back()) {
				if (trace != twoEnds[0]) {
					stemPath.push_back(trace);
				}
				distance += euclid(vertexList[trace], vertexList[connectV]);
				trace = connectV;
				break;
			}
		}

	}
	stemPath.push_back(trace);
	indexToDisMap[trace] = distance;
	disToIndexMap[distance] = trace;
	vector<vector<double long>> nodalRoots;
	for (int i = 0; i < /*junctions.size()*/1; i++) {
		queue<int> bfs;
		bfs.push(junctions[i]);
		vector<int> mark(vertexNum);
		for (int j = 0; j < vertexNum; j++) {
			mark[j] = 0;
		}
		mark[trace] = 1; 
		graph g(vertexList.size());
		vector<int> exitVertex;
		while (!bfs.empty()) {
			trace = bfs.front();
			bfs.pop();
			for (auto connectV : adjMatrix[trace]) {
				if (mark[connectV] == 0) {
					mark[connectV] = 1;
					if (level[connectV] != 1 && level[connectV] != -1) {
						g.add_edge(trace, connectV);
						if (level[connectV] == 0) {
							exitVertex.push_back(connectV);
						}
						else if (level[connectV] == 2) {
							bfs.push(connectV);
						}
					}
				}
			}
		}
		for (int j = 0; j < exitVertex.size(); j++) {
			vector<int> rootPath = g.print_path(junctions[i], exitVertex[j]);
			for (auto v : rootPath) { cout << v << endl; }
			cout << exitVertex[j] << endl;
		}
	}
	cout << "press Enter to continue..." << endl;
	cin.get();
	return success;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
