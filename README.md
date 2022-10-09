- [二分查找算法模板](#二分查找算法模板)
- [顺序拆分数组贪心算法](#顺序拆分数组贪心算法)
- [动态规划](#动态规划)
- [二叉树遍历](#二叉树遍历)
- [数学图形相关](#数学图形相关)
## 二分查找算法模板
```c++
int left = 0;
int right = 0;
int mid = (left + right) / 2;
while (left < right)
{
	if (check(mid)) //检查完全落在左边(不含mid)，则
		right = mid-1;
	else
		left = mid;
	/或者
	if (check(mid)) //检查完全落在右边(不含mid)，则
		left = mid+1;
	else
		right = mid;

	mid = (left + right) / 2;
}
```
## 顺序拆分数组贪心算法
```c++
bool check(vector<int>& nums, int mid, int m) {
    long long sum = 0;
    int cnt = 1;//默认拆分成一组
    for (int i = 0; i < nums.size(); i++) {
        if (sum + nums[i] > mid) {
            cnt++;        //超过限制，则再多拆分出一组
            sum = nums[i];//约束的状态值，直接从nums[i]开始
        } else {
            sum += nums[i];
        }
    }
    return cnt <= m;
}
```
## 动态规划
- dp[i][j] 表示将数组的前 i 个数分割为 j 段所能得到的最大连续子数组和的最小值  
- preSum(i,j) 表示数组中下标落在区间 [i,j] 内的数的和。  
- sum(i) 标签数组中前i个数的和  

$$\begin{align} 
&
dp[i][j]  =
\min_{k=j-1}^{i-1}
\left\lbrace 
max(dp[k+1][j−1],preSum(0,k)) 
\right\rbrace  
\hspace{100cm}\\
& preSum(i,j)=sum[j]-sum[i-1] \\
\end{align}
$$  

<strong>把动记忆动态规划看为二维数组dp[i][j]：</strong>
| 0,0 | 0,1 | 0,2 | ……| 0,j-1 | 0,j|
| ------ | ------ | ------ | ------ | ------ | ------ |
| 1,0 | 1,1 | 1,2 | ……| 1,j-1 | 1,j|
| 2,0 | 2,1 | 2,2 | ……| 0,j-1 | 0,j|
| …… | …… | …… | ……| …… | ……|
| i-1,0 | i-1,1 | i-1,2 | ……| i-1,j-1 | i-1,j|
| i,0 | i,1 | i,2 | ……| i,j-1 | i,j|

<strong>代码：</strong>
```c++  
//1、初始化dp[0-i][0],dp[0][0-j]为0
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
        for (int i = j; i <= n; i++) //行，i>=j
        {
            int min_dp = INT_MAX;
            for (int k = j-1; k <= i-1; k++)//k从j-1到i-1
                min_dp = min(min_dp, max(dp[k][j - 1], preSum[i] - preSum[k]));
            dp[i][j] = min_dp;
        }
    return dp[n][m];
}
```
## 二叉树遍历
<strong>遍历命名</strong>  
根据访问结点操作发生位置命名：  
① NLR：前序遍历(Preorder Traversal 亦称（先序遍历））  
——访问根结点的操作发生在遍历其左右子树之前。  
② LNR：中序遍历(Inorder Traversal)  
——访问根结点的操作发生在遍历其左右子树之中（间）。  
③ LRN：后序遍历(Postorder Traversal)  
——访问根结点的操作发生在遍历其左右子树之后。  
<strong>代码：</strong>
```c++
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *parent;
} TreeNode;
//前序遍历:
void pre_order(TreeNode *Node) {
    if(Node != NULL) {
        printf("%d ", Node->data);
        middle_order(Node->left);
        middle_order(Node->right);
    }
}
//中序遍历: 
void middle_order(TreeNode *Node) {
    if(Node != NULL) {
        middle_order(Node->left);
        printf("%d ", Node->data);
        middle_order(Node->right);
    }
}
//后序遍历:
void post_order(TreeNode *Node) {
    if(Node != NULL) {
        middle_order(Node->left);
        middle_order(Node->right);
        printf("%d ", Node->data);
    }
}
```
## 数学图形相关
1. 两条边垂直： 向量内积=0   
$$
x_1*x_2+y_1*y_2=0
$$

