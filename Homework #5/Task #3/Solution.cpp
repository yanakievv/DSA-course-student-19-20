#include <iostream>
#include <queue>
#include <string>

int main()
{
	std::queue<std::pair<std::string, int>> groups[100000];
	std::queue<int> groupQueue;
	int n, m;

	std::cin >> n >> m;

	int i;
	for (i = 0; i < n; i++) 
	{
		std::string name;
		int group;

		std::cin >> name >> group;
		
		if (groups[group].empty())
		{
			groupQueue.push(group);
		}

		groups[group].push({ name, i });

		if (i > 0 && i % 2 == 0) 
		{
			std::cout << groups[groupQueue.front()].front().first << " ";
			std::cout << groups[groupQueue.front()].front().second << " " << i << std::endl;

			groups[groupQueue.front()].pop();

			if (groups[groupQueue.front()].empty()) 
			{
				groupQueue.pop();
			}

		}

	}

	if (i % 2 == 1) 
  {
		i++;
	}

	while (!groupQueue.empty()) 
  {
		while (!groups[groupQueue.front()].empty()) 
		{
			std::cout << groups[groupQueue.front()].front().first << " ";
			std::cout << groups[groupQueue.front()].front().second << " " << i << std::endl;

			groups[groupQueue.front()].pop();
			i += 2;
		}

		groupQueue.pop();
	}

	return 0;
}

