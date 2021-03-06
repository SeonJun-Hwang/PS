#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int solve(vector<int>& height)
{
	stack<int> remaining;

	int result = 0;

	for (int i = 0; i < height.size(); i++)
	{
		//남아있는 판자들 중 오른쪽 끝 판자가 height[i]보다 높다면
		//이 판자의 최대 사각형은 i에서 끝난다

		while (!remaining.empty() && height[remaining.top()] >= height[i])
		{
			int idx = remaining.top();
			remaining.pop();

			int width = remaining.empty() ? i : (i - remaining.top() - 1);

			result = max(result, height[idx] * width);
		}
		remaining.push(i); //스택에 집어넣는다
	}

	return result;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (true)
	{
		int k; cin >> k;
		if (!k) break;

		vector<int> h(k + 1); for (int i = 0; i < k; i++) cin >> h[i];
		cout << solve(h) << '\n';
	}

	return 0;
}