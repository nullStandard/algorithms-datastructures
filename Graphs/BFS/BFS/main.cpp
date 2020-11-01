#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

// breadth-first search algorithm with the distance calculating
void BFS(std::map<int, std::vector<int>>& graph, int start)
{
	std::queue<int> q;
	std::vector<int> used;
	std::vector<int> dist;

	for (int i = 0; i < graph.size(); ++i)
		dist.emplace_back(999);

	auto it = graph.find(start);
	q.emplace(it->first);

	dist[it->first] = 0;

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();

		// checking is an vertex already used
		if (std::find(used.begin(), used.end(), curr) == used.end())
		{
			std::cout << curr << " ";

			it = graph.find(curr);

			for (auto& i : it->second)
			{
				q.push(i);
				if (dist[i] == 999)
					dist[i] = dist[curr] + 1;
			}
			used.emplace_back(curr);
		}
	}
	std::cout << std::endl;
	for (int i = 0; i < graph.size(); ++i)
		if (dist[i] != 999)
			std::cout << "Distance between vertices 0 and " << i << " is " << dist[i] << std::endl;
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

	std::cout << "Enter the initial vertex: ";

	// starting vertex
	int start;
	std::cin >> start;

	BFS(graph, start);

	system("pause");
}