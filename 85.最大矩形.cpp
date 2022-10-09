/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int maxRectangle = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int max_cols[rows][cols];
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == '0')
                    max_cols[i][j] = 0;
                else
                    max_cols[i][j] = 1;
            }
        for (int i = 0; i < rows; i++)
            for (int j = 1; j < cols; j++)
            {
                if (max_cols[i][j - 1] != 0 && max_cols[i][j] != 0)
                    max_cols[i][j] = max_cols[i][j - 1] + 1;
            }
        int max_rect[rows][cols];
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
            {
                max_rect[i][j] = max_cols[i][j];
                maxRectangle = max(maxRectangle, max_rect[i][j]);
            }
        for (int i = 1; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (max_cols[i][j] > 0)
                {
                    int min_tmp = max_cols[i][j], max_tmp = max_cols[i][j];
                    for (int k = i - 1; k >= 0; k--)
                    {
                        if (max_cols[k][j] == 0)
                            break;
                        else
                        {
                            min_tmp = min(min_tmp, max_cols[k][j]);
                            max_tmp = max(max_tmp, min_tmp * (i - k + 1));
                        }
                    }
                    maxRectangle = max(maxRectangle, max_tmp);
                }
        return max(maxRectangle, maxRectangle);
    }
};
// @lc code=end
