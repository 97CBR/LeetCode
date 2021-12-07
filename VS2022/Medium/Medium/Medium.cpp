// Medium.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iosfwd>
#include <queue>
#include <set>
using namespace std;

class Solution
{
public:
	int numSubarrayProductLessThanK(std::vector<int>& nums, int k)
	{
		int cnt = 0;
		vector<int> exits;
		vector<vector<int>> result;
		queue<int> que;
		for (const auto& item : nums)
		{
			que.push(item);
		}
		while (!que.empty())
		{
			int local = que.front();
			printf("first {%d}\n", local);
			vector<int> pp;
			if (local < k)
			{
				pp.emplace_back(que.front());
				bool diff = true;
				for (auto& item : result)
				{
					if (item.size() == pp.size())
					{
						bool tmp = false;
						for (int i = 0; i < item.size(); ++i)
						{
							if (item.at(i) != pp.at(i))
							{
								tmp = true;
								break;
							}
						}
						if (tmp == false)
						{
							printf("筛选目标 {%d}\n", que.front());
							diff = false;
							break;
						}
					}
				}
				if (diff)
				{
					sort(pp.begin(), pp.end());
					result.emplace_back(pp);
				}
				// cnt += 1;
			}
			auto sub = que;
			sub.pop();
			while (!sub.empty())
			{

				if (local * sub.front() < k)
				{
					printf("{%d} * {%d}\t", local, sub.front());
					local *= sub.front();
					auto gg = sub;
					gg.pop();
					if (!gg.empty() && local * gg.front() > k)
					{
						local /= sub.front();
					}

					pp.emplace_back(sub.front());
					bool diff = true;
					for (auto& item : result)
					{
						if (item.size() == pp.size())
						{
							bool tmp = false;
							for (int i = 0; i < item.size(); ++i)
							{
								if (item.at(i) != pp.at(i))
								{
									tmp = true;
									break;
								}
							}
							if (tmp == true)
							{
								diff = true;
								break;
							}
							else
							{
								printf("筛选目标 {%d}\n", sub.front());
							}
						}
					}
					if (diff)
					{
						sort(pp.begin(), pp.end());
						result.emplace_back(pp);
					}
					cnt += 1;
				}
				sub.pop();
			}
			que.pop();
		}
		printf("cnt = {%d} \n", result.size());
		return cnt;
	}
};

void trimLeftTrailingSpaces(string& input)
{
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch)
	{
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string& input)
{
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch)
	{
		return !isspace(ch);
	}).base(), input.end());
}

vector<int> stringToIntegerVector(string input)
{
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim))
	{
		output.push_back(stoi(item));
	}
	return output;
}

int stringToInteger(string input)
{
	return stoi(input);
}

int main()
{
	string line;
	while (getline(cin, line))
	{
		vector<int> nums = stringToIntegerVector(line);
		getline(cin, line);
		int k = stringToInteger(line);

		int ret = Solution().numSubarrayProductLessThanK(nums, k);

		string out = to_string(ret);
		cout << out << std::endl;
	}
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
