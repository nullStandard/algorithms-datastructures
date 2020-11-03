#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <stack>

constexpr int INF = 999;

void dijkstra(std::unordered_map<int, std::unordered_map<int, int>>& graph, int start, int goal)
{
	std::vector<bool> used;
	for (int i = 0; i < graph.size(); ++i)
		used.emplace_back(false);

	std::vector<int> cost_for_min;
	for (int i = 0; i < graph.size(); ++i)
		cost_for_min.emplace_back(INF);

	std::vector<int> final_cost;
	for (int i = 0; i < graph.size(); ++i)
		final_cost.emplace_back(INF);

	std::vector<int> parents;
	for (int i = 0; i < graph.size(); ++i)
		parents.emplace_back(INF);

	cost_for_min[start] = 0;
	while (std::find(used.begin(), used.end(), false) != used.end())
	{
		int min = *std::min_element(cost_for_min.begin(), cost_for_min.end());

		auto it = std::find(cost_for_min.begin(), cost_for_min.end(), min);
		int cost_index = std::distance(cost_for_min.begin(), it);

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

		used[cost_index] = true;
		final_cost[cost_index] = cost_for_min[cost_index];

		if (cost_index == goal)
			break;

		cost_for_min[cost_index] = INF;
	}

	std::stack<int> s;

	int curr = goal;
	while (curr != INF)
	{
		s.emplace(curr);
		curr = parents[curr];
	}

	while (!s.empty())
	{
		std::cout << s.top() << ' ';
		if(s.top() != goal)
			std::cout << "-> ";

		s.pop();
	}

	std::cout << "\nTotal pass is " << final_cost[goal] << std::endl;
}

int main()
{
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

	int start, goal;

	std::cin >> start >> goal;

	dijkstra(graph, start, goal);

	system("pause");
}
