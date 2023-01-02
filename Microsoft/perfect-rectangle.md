<h2><a href="https://leetcode.com/problems/perfect-rectangle/">391. Perfect Rectangle</a></h2><h3>Hard</h3><hr><div><p>Given an array <code>rectangles</code> where <code>rectangles[i] = [x<sub>i</sub>, y<sub>i</sub>, a<sub>i</sub>, b<sub>i</sub>]</code> represents an axis-aligned rectangle. The bottom-left point of the rectangle is <code>(x<sub>i</sub>, y<sub>i</sub>)</code> and the top-right point of it is <code>(a<sub>i</sub>, b<sub>i</sub>)</code>.</p>

<p>Return <code>true</code> <em>if all the rectangles together form an exact cover of a rectangular region</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/27/perectrec1-plane.jpg" style="width: 300px; height: 294px;">
<pre><strong>Input:</strong> rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
<strong>Output:</strong> true
<strong>Explanation:</strong> All 5 rectangles together form an exact cover of a rectangular region.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/27/perfectrec2-plane.jpg" style="width: 300px; height: 294px;">
<pre><strong>Input:</strong> rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
<strong>Output:</strong> false
<strong>Explanation:</strong> Because there is a gap between the two rectangular regions.
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/27/perfecrrec4-plane.jpg" style="width: 300px; height: 294px;">
<pre><strong>Input:</strong> rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
<strong>Output:</strong> false
<strong>Explanation:</strong> Because two of the rectangles overlap with each other.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= rectangles.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>rectangles[i].length == 4</code></li>
	<li><code>-10<sup>5</sup> &lt;= x<sub>i</sub>, y<sub>i</sub>, a<sub>i</sub>, b<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
</ul>
</div>

### Solution:
```cpp
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        set<pair<int,int>> st;
        int x1=INT_MAX,x2=INT_MIN,y1=INT_MAX,y2=INT_MIN;
        long long area=0;
        for(auto rect:rectangles){
            x1=min(rect[0],x1);
            y1=min(rect[1],y1);
            x2=max(rect[2],x2);
            y2=max(rect[3],y2);
            area+=(1LL*(rect[2]-rect[0]))*(1LL*(rect[3]-rect[1]));
            if(st.count({rect[0],rect[1]}))
                st.erase({rect[0],rect[1]});
            else
                st.insert({rect[0],rect[1]});
            if(st.count({rect[0],rect[3]}))
                st.erase({rect[0],rect[3]});
            else
                st.insert({rect[0],rect[3]});
            if(st.count({rect[2],rect[3]}))
                st.erase({rect[2],rect[3]});
            else
                st.insert({rect[2],rect[3]});
            if(st.count({rect[2],rect[1]}))
                st.erase({rect[2],rect[1]});
            else
                st.insert({rect[2],rect[1]});
        }
        if(st.size()!=4||!st.count({x1,y1})||!st.count({x1,y2})||!st.count({x2,y1})||!st.count({x2,y2}))
            return 0;
        return area==(1LL*(x2-x1))*(1LL*(y2-y1));
    }
};
```
