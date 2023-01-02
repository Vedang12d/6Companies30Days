<h2><a href="https://leetcode.com/problems/largest-divisible-subset/">368. Largest Divisible Subset</a></h2><h3>Medium</h3><hr><div><p>Given a set of <strong>distinct</strong> positive integers <code>nums</code>, return the largest subset <code>answer</code> such that every pair <code>(answer[i], answer[j])</code> of elements in this subset satisfies:</p>

<ul>
	<li><code>answer[i] % answer[j] == 0</code>, or</li>
	<li><code>answer[j] % answer[i] == 0</code></li>
</ul>

<p>If there are multiple solutions, return any of them.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> [1,2]
<strong>Explanation:</strong> [1,3] is also accepted.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,4,8]
<strong>Output:</strong> [1,2,4,8]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 2 * 10<sup>9</sup></code></li>
	<li>All the integers in <code>nums</code> are <strong>unique</strong>.</li>
</ul>
</div>

### Solution:
```cpp
class Solution {
public:
    vector<int> ans,dp;
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        dp.resize(nums.size()+1,-1);
        vector<int> temp;
        solve(nums,0,1,temp);
        return ans;
    }
    void solve(vector<int> &nums,int i,int prev,vector<int> &temp){
        if(i>=nums.size()){
            if(temp.size()>ans.size())
                ans=temp;
            return;
        }
        if((int)temp.size()>dp[i]&&nums[i]%prev==0){
            dp[i]=temp.size();
            temp.push_back(nums[i]);
            solve(nums,i+1,nums[i],temp);
            temp.pop_back();
        }
        solve(nums,i+1,prev,temp);
    }
};
```
