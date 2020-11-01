#include <iostream>
#include <map>
#include <vector>


void DFS(std::map<int, std::vector<int>>& graph, int ver)
{
	static enum class Colors
	{
		WHITE, GRAY, BLACK
	};

	static std::vector<Colors> color;

	for (int i = 0; i < graph.size(); ++i)
		color.emplace_back(Colors::WHITE);

	auto it = graph.find(ver);
	std::cout << ver << " -> ";
	color[it->first] = Colors::GRAY;

	for (auto& i : it->second)
	{
		if (color[i] == Colors::WHITE)
			DFS(graph, i);
	}
}

int main()
{
	std::map<int, std::vector<int>> graph;

	graph[0] = { 1, 2 };
	graph[1] = { 2, 3 };
	graph[2] = { 3 };
	graph[3] = { 4 };
	graph[4] = { 0, 1, 5 };
	graph[5];

	// printing out the graph
	// vertex: neighbors
	for (auto it = graph.begin(); it != graph.end(); ++it)
	{
		std::cout << it->first << ": ";
		for (auto& i : it->second)
			std::cout << i << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;

	// starting vertex

	std::cout << "Enter the initial vertex: ";

	int start;
	std::cin >> start;

	DFS(graph, start);

	system("pause");
}