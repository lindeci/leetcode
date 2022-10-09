/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        if(heights.size()==1)
            return heights[0];
        int tmp=0;
        for(auto i:heights){
            tmp+=i;
        }
        if (tmp==0) return 0;
        auto it = heights.end();
        heights.insert(it,0);
        it = heights.begin();
        heights.insert(it,0);
        int maxRec = 0;
        int m_size = heights.size();
        stack<int> stack_tmp;
        stack_tmp.push(0);
        for (int i = 1; i < m_size; i++)
        {

            if (stack_tmp.empty())
                stack_tmp.push(i);
            else
            {
                int top_idx=stack_tmp.top();
                if (heights[i] >= heights[top_idx])
                    stack_tmp.push(i);
                else
                {
                    while (!stack_tmp.empty())
                    {
                        top_idx=stack_tmp.top();
                        if(heights[top_idx]<heights[i]){
                            stack_tmp.push(i);
                            break;
                        }
                        int length = i - top_idx;
                        int area_tmp = length * heights[top_idx];
                        maxRec=max(maxRec,area_tmp);
                        stack_tmp.pop();
                    }
                }
            }
        }
        return maxRec;
    }
};
// @lc code=end
