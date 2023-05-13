#include "Graph.h"

void just_dfs(const Graph_type3& graph, vertex_t start, vector<bool>& used) {
	used[start] = true;
	cout << start << " ";
	for (auto neighbour : graph.lists_of_adjacency[start]) {
		if (not used[neighbour]) {
			just_dfs(graph, neighbour, used);
		}
	}
}


void just_bfs(const Graph_type3& graph, 
				vertex_t start,
				vector<bool>& fired) {
	/*
	*
	* функция выполняет обход графа в ширину
	* graph - граф по которому обходят
	* vertex start - точка, с которой надо начать обход
	* vector fired - вектор булеввых значений для вершин, которые уже были использованы при обходе
	*
	*/
	deque<vertex_t> firing_list;
	firing_list.push_back(start);

	vertex_t current;

	while (not firing_list.empty()) {
		current = firing_list.front();
		firing_list.pop_front();
		fired[current] = true;;
		cout << current << " has burnt" << endl;
		for (auto vertex : graph.lists_of_adjacency[current]) {

			cout << "trying to burn vertex " << vertex << "... ";

			if (not fired[vertex]) {
				firing_list.push_back(vertex);
				cout << vertex << " is now burning!" << endl;
			}
			else {
				cout << "but it's burnt already..." << endl;
			}
		}
	}
	cout << "EVERY VERTEX IS BURNT FUCK YEAH" << endl;
}