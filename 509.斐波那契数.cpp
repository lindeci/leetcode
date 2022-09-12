/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution
{
public:
    int fib(int n)
    {
        if (n <= 1)
            return n;
        int result[n + 1];
        result[0] = 0;
        result[1] = 1;
        for (int i = 2; i <= n; i++)
            result[i] = result[i - 1] + result[i - 2];
        return result[n];
    }
};
// @lc code=end
