/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 */

// @lc code=start
class Solution
{
public:
    int splitArray(vector<int> &nums, int m)
    {
        int n = nums.size();
        int dp[n + 1][m + 1], preSum[n + 1];
        memset(dp, 0, sizeof(dp));
        // 2、初始化presum数组
        preSum[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }
        //计算所有dp数组
        for (int i = 1; i <= n; i++)
            dp[i][1] = preSum[i];
        for (int j = 2; j <= m; j++)     //列
            for (int i = j; i <= n; i++) //行
            {
                int min_dp = INT_MAX;
                for (int k = j-1; k <= i-1; k++)
                    min_dp = min(min_dp, max(dp[k][j - 1], preSum[i] - preSum[k]));
                dp[i][j] = min_dp;
            }
        return dp[n][m];
    }
};
// @lc code=end
