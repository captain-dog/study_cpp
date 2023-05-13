#pragma once
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>
using namespace std;

typedef int32_t vertex_t; // вершина
typedef set<vertex_t> setOfVertexes; // список смежных вершин для вершины

// vertex - вершина
// edge - ребро, пара вершин (vertex)

class Graph {
public:
	Graph() : vertexes_number(0), edges_number(0)
	{

	}
	int vertexes_number;
	int edges_number;
	virtual void input_set_of_edges() = 0;
	virtual void print_set_of_edges() const = 0;
};

class Graph_type1 : public Graph {
public:

	set<pair<vertex_t, vertex_t>> set_of_edges; // список смежностей вершин со смежной им вершиной

	void input_set_of_edges() override {
		cout << "input vertexes number: ";
		cin >> vertexes_number;

		cout << "input edges number: ";
		cin >> edges_number;

		set_of_edges.clear();

		cout << "enter " << edges_number << " edges:" << endl;
		for (vertex_t i = 0; i < edges_number; i++)
		{
			vertex_t a, b;
			cin >> a >> b;
			set_of_edges.insert(make_pair(a, b));
		}
	}

	void print_set_of_edges() const override {
		cout << "vertexes number = " << vertexes_number << endl;
		for (auto& edge : set_of_edges)
		{
			cout << edge.first << ", " << edge.second << endl;
		}
	}

private:
};


class Graph_type2 : public Graph {
public:

	// Matrix of adjasency
	vector<vector<bool>> matrix;

	void input_set_of_edges() override {
		cout << "input vertexes number: ";
		cin >> vertexes_number;

		cout << "input edges number: ";
		cin >> edges_number;

		// Создаю матрицу нужного размера
		matrix.resize(vertexes_number);
		for (auto& v : matrix) {
			v.resize(vertexes_number, false);
		}

		// заполнение матрицы с клавиатуры
		for (vertex_t i = 0; i < edges_number; i++)
		{
			vertex_t a, b;
			cin >> a >> b;
			matrix[a][b] = true;
			matrix[b][a] = true;
		}
	}

	void print_set_of_edges() const override {
		cout << "vertexes number = " << vertexes_number << endl;
		for (vertex_t i = 0; i < matrix.size(); i++)
		{
			for (vertex_t j = 0; j < matrix[i].size(); j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}

private:
};


class Graph_type3 : public Graph {

public:
	vector<set<vertex_t>> lists_of_adjacency;
	void input_set_of_edges() override {
		cout << "input vertexes number: ";
		cin >> vertexes_number;
		// список смежности для каждой вершины графа

		cout << "input edges number: ";
		cin >> edges_number;

		// полная очистка всех списков смежности
		lists_of_adjacency.clear();
		// создаю массив списков смежности
		lists_of_adjacency.resize(vertexes_number);
		cout << "enter " << edges_number << " edges in format \"vertex vertex_neighbourh\":" << endl;
		for (int i = 0; i < edges_number; i++)
		{
			vertex_t a, b;
			cin >> a >> b;
			lists_of_adjacency[a].insert(b);
			lists_of_adjacency[b].insert(a);
		}
	}

	void print_set_of_edges() const override {
		for (vertex_t i = 0; i < lists_of_adjacency.size(); i++)
		{
			cout << "Vertex " << i << ": ";
			for (auto neighbour : lists_of_adjacency[i]) {
				cout << neighbour << ", ";
			}
			cout << "\b\b" << endl;
		}

	}
private:
};

void just_dfs(const Graph_type3& graph, vertex_t start, vector<bool>& used);
void just_bfs(const Graph_type3& graph, vertex_t start, vector<bool>& fired);