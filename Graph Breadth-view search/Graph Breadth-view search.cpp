// Graph Breadth-view search.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void initialiseVisitedAndInQueue(vector<bool>& visited, vector<bool>& isInQueue, int vertexesNumber);
void initialiseVertexes(vector<vector<int> >& vertex, int vertexesNumber);
void setVertexes(vector<vector<int> >& vertexes, int edgesNumber);
int findNextNotVisited(vector<bool> visited);
void bfs(vector<vector<int> > vertexes, vector<bool>& visited, vector<bool>& isInQueue,queue<int>& vertexQueue);

int main()
{
	int vertexesNumber, edgesNumber;
	vector<vector<int> > vertexes;
	vector<bool> visited;
	vector<bool> isInQueue;
	queue<int> vertexQueue;
	cin >> vertexesNumber >> edgesNumber;
	initialiseVertexes(vertexes, vertexesNumber);
	initialiseVisitedAndInQueue(visited, isInQueue, vertexesNumber);
	setVertexes(vertexes, edgesNumber);

	int vertex = findNextNotVisited(visited);
	vertexQueue.push(vertex);
	while (vertex != -1) {
		while (!vertexQueue.empty()) {
			bfs(vertexes, visited, isInQueue, vertexQueue);
		}
		vertex = findNextNotVisited(visited);
		vertexQueue.push(vertex);
	}
}

void initialiseVisitedAndInQueue(vector<bool>& visited, vector<bool>& isInQueue, int vertexesNumber) {
	for (int i = 0; i < vertexesNumber; i++) {
		visited.push_back(false);
		isInQueue.push_back(false);
	}
}

void initialiseVertexes(vector<vector<int> >& vertex, int vertexesNumber) {
	for (int i = 0; i < vertexesNumber; i++) {
		vector<int> temp;
		vertex.push_back(temp);
	}
}

void setVertexes(vector<vector<int> >& vertexes, int edgesNumber) {
	int vertex1, vertex2;
	for (int i = 0; i < edgesNumber; i++) {
		cin >> vertex1 >> vertex2;
		vertexes[vertex1 - 1].push_back(vertex2 - 1);
		vertexes[vertex2 - 1].push_back(vertex1 - 1);
	}
}

int findNextNotVisited(vector<bool> visited) {
	for (int i = 0; i < visited.size(); i++) {
		if (!visited[i])
			return i;
	}
	return -1;
}

void bfs(vector<vector<int> > vertexes, vector<bool>& visited, vector<bool>& isInQueue, queue<int>& vertexQueue) {
	int vertex = vertexQueue.front();
	vertexQueue.pop();
	isInQueue[vertex] = false;
	cout << vertex + 1 << endl;
	visited[vertex] = true;
	for (int i = 0; i < vertexes[vertex].size(); i++) {
		if (!visited[vertexes[vertex][i]] && !isInQueue[vertexes[vertex][i]]) {
			vertexQueue.push(vertexes[vertex][i]);
			isInQueue[vertexes[vertex][i]] = true;
		}
	}
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
