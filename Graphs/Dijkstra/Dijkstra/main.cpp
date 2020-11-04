#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <stack>

constexpr int INF = 999;

void dijkstra(std::unordered_map<int, std::unordered_map<int, int>>& graph, int start, int goal)
{

	// already used vertices
	std::vector<bool> used;
	for (int i = 0; i < graph.size(); ++i)
		used.emplace_back(false);

	// initial cost of every vertex, 
	// using to find a minimal-costed vertex
	std::vector<int> cost_for_min;
	for (int i = 0; i < graph.size(); ++i)
		cost_for_min.emplace_back(INF);

	// memorizing cost of the path for particular used vertex
	std::vector<int> final_cost;
	for (int i = 0; i < graph.size(); ++i)
		final_cost.emplace_back(INF);

	// vector that stores parent for particular vertex.
	// Say differently, storing vertex, which we had come from
	std::vector<int> parents;
	for (int i = 0; i < graph.size(); ++i)
		parents.emplace_back(INF);

	// cost for initial vertes is zero
	cost_for_min[start] = 0;

	// until all vertices become used
	while (std::find(used.begin(), used.end(), false) != used.end())
	{
		// finding the vertex with min cost
		int min = *std::min_element(cost_for_min.begin(), cost_for_min.end());
		auto it = std::find(cost_for_min.begin(), cost_for_min.end(), min);
		int cost_index = std::distance(cost_for_min.begin(), it);

		// considering all neighbors for particular vertex
		// and if its cost more than sum of parent vertex and edge weight
		// then
		// update neighbor's cost
		for (auto& i : graph[cost_index])
		{
			if (used[i.first] == false)
			{
				int new_dist = cost_for_min[cost_index] + i.second;
				if (new_dist < cost_for_min[i.first])
				{
					cost_for_min[i.first] = new_dist;
					parents[i.first] = cost_index;
				}
			}
		}

		// mark particular vertex visited
		// memorizing cost for vertex
		used[cost_index] = true;
		final_cost[cost_index] = cost_for_min[cost_index];

		// if we've reached the goal - stop the loop 
		if (cost_index == goal)
			break;

		cost_for_min[cost_index] = INF;
	}

	// adding to stack parents for each vertice
	// to represent the path
	std::stack<int> s;

	int curr = goal;
	while (curr != INF)
	{
		s.emplace(curr);
		curr = parents[curr];
	}
	///////////////////////////////////////////

	// path representation
	while (!s.empty())
	{
		std::cout << s.top() << ' ';
		if(s.top() != goal)
			std::cout << "-> ";

		s.pop();
	}

	// total path cost from initial vertex to goal vertex
	std::cout << "\nTotal pass is " << final_cost[goal] << std::endl;
}

int main()
{
	// storing the sample graph with hash-table
	// it could be represented with file reading, adjacency matrix etc.
	// but for simplicity and practicing data structures that way was chosen

	std::unordered_map<int, std::unordered_map<int, int>> graph;
	graph[0].emplace(1, 10);
	graph[0].emplace(2, 30);
	graph[0].emplace(3, 50);
	graph[0].emplace(4, 10);

	graph[1];

	graph[2].emplace(4, 10);

	graph[3].emplace(1, 40);
	graph[3].emplace(2, 20);

	graph[4].emplace(0, 10);
	graph[4].emplace(3, 30);
	graph[4].emplace(2, 10);
	/////////////////////////////////////////////////////////////////////////

	// start and goal vertices assignment	
	int start, goal;
	std::cin >> start >> goal;

	// dijkstra algorithm
	dijkstra(graph, start, goal);

	system("pause");
}
