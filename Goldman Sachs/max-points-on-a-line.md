<h2><a href="https://leetcode.com/problems/max-points-on-a-line/">149. Max Points on a Line</a></h2><h3>Hard</h3><hr><div><p>Given an array of <code>points</code> where <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> represents a point on the <strong>X-Y</strong> plane, return <em>the maximum number of points that lie on the same straight line</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/25/plane1.jpg" style="width: 300px; height: 294px;">
<pre><strong>Input:</strong> points = [[1,1],[2,2],[3,3]]
<strong>Output:</strong> 3
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/25/plane2.jpg" style="width: 300px; height: 294px;">
<pre><strong>Input:</strong> points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
<strong>Output:</strong> 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= points.length &lt;= 300</code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>-10<sup>4</sup> &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
	<li>All the <code>points</code> are <strong>unique</strong>.</li>
</ul>
</div>

### Solution: 
```cpp
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        unordered_map<double,int> mp;
        int ans=1;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                double slope=DBL_MAX;
                if(points[i][0]!=points[j][0])
                    slope=(0.0+points[j][1]-points[i][1])/(0.0+points[j][0]-points[i][0]);
                mp[slope]++;
                ans=max(ans,mp[slope]+1);
            }
            mp.clear();
        }
        return ans;
    }
};
```
