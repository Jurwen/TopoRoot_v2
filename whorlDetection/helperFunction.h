#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
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

double long euclid(vector <double long> x, vector <double long> y);
double long dot(vector<double long> x, vector<double long> y);
vector<double long> my_minus(vector<double long> x, vector<double long> y);
vector<double long> my_plus(vector<double long> x, vector<double long> y);
vector<double long> my_mult(vector<double long> x, double long y);
int getSkeleton(vector<vector<double long>>& vertexData, vector<vector<int>>& edgeData, const char* fileName, vector<int>& level, vector<double long>& radius);
vector<vector<int>> createMatrix(vector<vector<int>> edgeList, vector<int>& connectivity);
