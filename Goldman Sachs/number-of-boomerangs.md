<h2><a href="https://leetcode.com/problems/number-of-boomerangs/">447. Number of Boomerangs</a></h2><h3>Medium</h3><hr><div><p>You are given <code>n</code> <code>points</code> in the plane that are all <strong>distinct</strong>, where <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>. A <strong>boomerang</strong> is a tuple of points <code>(i, j, k)</code> such that the distance between <code>i</code> and <code>j</code> equals the distance between <code>i</code> and <code>k</code> <strong>(the order of the tuple matters)</strong>.</p>

<p>Return <em>the number of boomerangs</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> points = [[0,0],[1,0],[2,0]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> points = [[1,1],[2,2],[3,3]]
<strong>Output:</strong> 2
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> points = [[1,1]]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == points.length</code></li>
	<li><code>1 &lt;= n &lt;= 500</code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>-10<sup>4</sup> &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
	<li>All the points are <strong>unique</strong>.</li>
</ul>
</div>

### Solution:
```cpp
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res=0;
        for(auto &p:points){
            unordered_map<int,int> mp;
            for(auto &q:points){
                if(p==q)
                    continue;
                int dist=(p[0]-q[0])*(p[0]-q[0])+(p[1]-q[1])*(p[1]-q[1]);
                mp[dist]++;
            }
            for(auto &x:mp)
                res+=x.second*(x.second-1);
        }
        return res;
    }
};
```