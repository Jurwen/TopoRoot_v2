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



int main(int argc,char *argv[])
{
	vector<vector<double long>> vertexList;
	vector<vector<int>> edgeList;
	vector<double long> radius;
	vector<int> level;
	std::cout << "Hello World!\n";
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
	cout << "hi" << endl;
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
			for (int element:incidenceV){
				if (level[element] == 1) { neighborStem++; }
			}
			if (neighborStem == 1) {
				twoEnds.push_back(i);
			}
		}
	}
	for (int i = 0; i < junctions.size(); i++) {
		cout << junctions[i] << endl;
	}
	for (int i = 0; i < twoEnds.size(); i++) {
		cout << twoEnds[i] << endl;
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
