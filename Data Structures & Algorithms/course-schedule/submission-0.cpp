class Solution
{
public:
	bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
	{
		vector<int> indegree(numCourses, 0);
		vector<vector<int>> adj(numCourses);
		for (int i = 0; i < prerequisites.size(); i++)
		{
			indegree[prerequisites[i][0]]++;
			adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
		}
		queue<int> ready;
		for (int i = 0; i < numCourses; i++)
		{
			if (!indegree[i])
				ready.push(i);
		}
		int foundCourses = 0;

		while (!ready.empty())
		{
			int cur = ready.front();
			ready.pop();
			foundCourses++;
			for (int i : adj[cur])
			{
				if (--indegree[i] == 0)
					ready.push(i);
			}
		}
		return numCourses == foundCourses;
	}
};


