<h2><a href="https://leetcode.com/problems/shortest-unsorted-continuous-subarray/">581. Shortest Unsorted Continuous Subarray</a></h2><h3>Medium</h3><hr><div><p>Given an integer array <code>nums</code>, you need to find one <b>continuous subarray</b> that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.</p>

<p>Return <em>the shortest such subarray and output its length</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,6,4,8,10,9,15]
<strong>Output:</strong> 5
<strong>Explanation:</strong> You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,4]
<strong>Output:</strong> 0
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Can you solve it in <code>O(n)</code> time complexity?</div>

### Solution:
```cpp
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int st=0,n=nums.size(),end=n-1;
        for(;st<n-1&&nums[st]<=nums[st+1];st++);
        for(;end>0&&nums[end]>=nums[end-1];end--);
        if(st>=end)
            return 0;
        int minn=INT_MAX,maxx=INT_MIN;
        for(int i=st;i<=end;i++){
            minn=min(minn,nums[i]);
            maxx=max(maxx,nums[i]);
        }
        for(;st>0&&minn<nums[st-1];)
            st--;
        for(;end<n-1&&maxx>nums[end+1];)
            end++;
        return end-st+1;
    }
};
```
