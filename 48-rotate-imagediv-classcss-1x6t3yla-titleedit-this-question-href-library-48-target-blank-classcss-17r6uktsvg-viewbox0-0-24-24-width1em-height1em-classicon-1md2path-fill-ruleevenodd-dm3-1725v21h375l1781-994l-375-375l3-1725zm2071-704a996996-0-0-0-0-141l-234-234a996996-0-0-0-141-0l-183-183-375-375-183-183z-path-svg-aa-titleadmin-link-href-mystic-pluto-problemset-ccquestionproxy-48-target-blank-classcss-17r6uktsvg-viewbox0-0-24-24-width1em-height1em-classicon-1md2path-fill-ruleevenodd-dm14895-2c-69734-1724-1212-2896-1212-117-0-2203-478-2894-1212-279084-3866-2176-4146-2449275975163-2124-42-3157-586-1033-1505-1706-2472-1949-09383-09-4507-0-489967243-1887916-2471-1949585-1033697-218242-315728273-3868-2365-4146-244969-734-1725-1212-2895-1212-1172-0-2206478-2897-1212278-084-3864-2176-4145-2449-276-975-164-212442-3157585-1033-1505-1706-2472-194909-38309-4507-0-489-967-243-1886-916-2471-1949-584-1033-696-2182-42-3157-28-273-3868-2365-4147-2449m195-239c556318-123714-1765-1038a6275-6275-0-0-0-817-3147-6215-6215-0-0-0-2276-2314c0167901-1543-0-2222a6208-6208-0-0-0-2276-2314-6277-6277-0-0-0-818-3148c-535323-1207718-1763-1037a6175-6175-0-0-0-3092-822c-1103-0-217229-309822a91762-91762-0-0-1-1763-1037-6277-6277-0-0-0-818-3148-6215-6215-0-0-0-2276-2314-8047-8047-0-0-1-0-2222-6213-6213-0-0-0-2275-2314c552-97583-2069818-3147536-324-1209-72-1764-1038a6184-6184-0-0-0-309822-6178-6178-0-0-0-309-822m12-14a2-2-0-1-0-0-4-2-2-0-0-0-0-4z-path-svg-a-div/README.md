<h2><a href="https://leetcode.com/problems/rotate-image/">48. Rotate Image<div class="css-1x6t3yl"><a title="Edit this question" href="/library/48" target="_blank" class="css-17r6ukt"><svg viewBox="0 0 24 24" width="1em" height="1em" class="icon__1Md2"><path fill-rule="evenodd" d="M3 17.25V21h3.75L17.81 9.94l-3.75-3.75L3 17.25zM20.71 7.04a.996.996 0 0 0 0-1.41l-2.34-2.34a.996.996 0 0 0-1.41 0l-1.83 1.83 3.75 3.75 1.83-1.83z"></path></svg></a><a title="Admin link" href="/mystic/pluto/problemset/ccquestionproxy/48" target="_blank" class="css-17r6ukt"><svg viewBox="0 0 24 24" width="1em" height="1em" class="icon__1Md2"><path fill-rule="evenodd" d="M14.895 2c-.69.734-1.724 1.212-2.896 1.212-1.17 0-2.203-.478-2.894-1.212-.279.084-3.866 2.176-4.146 2.449.275.975.163 2.124-.42 3.157-.586 1.033-1.505 1.706-2.472 1.949-.09.383-.09 4.507 0 4.89.967.243 1.887.916 2.471 1.949.585 1.033.697 2.182.42 3.157.28.273 3.868 2.365 4.146 2.449.69-.734 1.725-1.212 2.895-1.212 1.172 0 2.206.478 2.897 1.212.278-.084 3.864-2.176 4.145-2.449-.276-.975-.164-2.124.42-3.157.585-1.033 1.505-1.706 2.472-1.949.09-.383.09-4.507 0-4.89-.967-.243-1.886-.916-2.471-1.949-.584-1.033-.696-2.182-.42-3.157-.28-.273-3.868-2.365-4.147-2.449m.195 2.39c.556.318 1.23.714 1.765 1.038a6.275 6.275 0 0 0 .817 3.147 6.215 6.215 0 0 0 2.276 2.314c.01.679.01 1.543 0 2.222a6.208 6.208 0 0 0-2.276 2.314 6.277 6.277 0 0 0-.818 3.148c-.535.323-1.207.718-1.763 1.037a6.175 6.175 0 0 0-3.092-.822c-1.103 0-2.172.29-3.09.822a91.762 91.762 0 0 1-1.763-1.037 6.277 6.277 0 0 0-.818-3.148 6.215 6.215 0 0 0-2.276-2.314 80.47 80.47 0 0 1 0-2.222 6.213 6.213 0 0 0 2.275-2.314c.552-.975.83-2.069.818-3.147.536-.324 1.209-.72 1.764-1.038a6.184 6.184 0 0 0 3.09.822 6.178 6.178 0 0 0 3.09-.822M12 14a2 2 0 1 0 0-4 2 2 0 0 0 0 4z"></path></svg></a></div></a></h2><h3>Medium</h3><hr><div><p>You are given an <code>n x n</code> 2D <code>matrix</code> representing an image, rotate the image by <strong>90</strong> degrees (clockwise).</p>

<p>You have to rotate the image <a href="https://en.wikipedia.org/wiki/In-place_algorithm" target="_blank"><strong>in-place</strong></a>, which means you have to modify the input 2D matrix directly. <strong>DO NOT</strong> allocate another 2D matrix and do the rotation.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/28/mat1.jpg" style="width: 500px; height: 188px;">
<pre><strong>Input:</strong> matrix = [[1,2,3],[4,5,6],[7,8,9]]
<strong>Output:</strong> [[7,4,1],[8,5,2],[9,6,3]]
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/28/mat2.jpg" style="width: 500px; height: 201px;">
<pre><strong>Input:</strong> matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
<strong>Output:</strong> [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == matrix.length == matrix[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 20</code></li>
	<li><code>-1000 &lt;= matrix[i][j] &lt;= 1000</code></li>
</ul>
</div>