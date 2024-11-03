<h2><a href="https://www.geeksforgeeks.org/problems/pair-in-array-whose-sum-is-closest-to-x1124/0">Sum Pair closest to k</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a sorted array <strong>arr[]</strong> &nbsp;and a number <strong>k</strong>, find a pair in sorted order in an array whose sum is closest to <strong>k</strong>.<br></span><strong><span style="font-size: 18px;">Note: </span></strong><span style="font-size: 18px;">If there are multiple such pairs return the pair with maximum absolute difference.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr[] = [10, 22, 28, 29, 30, 40], k = 54
<strong>Output:</strong> [22, 30]
<strong>Explanation:</strong> As 22 + 30 = 52 is closest to 54.
</span></pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong> arr[] = [1, 2, 3, 4, 5], k = 10
<strong>Output:</strong> [4, 5]
<strong>Explanation:</strong>&nbsp;As 4 + 5 = 9 is closest to 10.<br></span></pre>
<pre><span style="font-size: 14pt;"><strong>Input:</strong> arr[] = [1, 2, 4, 5, 7], k = 10
<strong>Output:</strong> [2, 7]
<strong>Explanation:</strong> As [4,7] and [2,7] both equals 11 and closest to k=10,so abs(7-2)=5 and abs(7-4)=3.Hence,[2,7] has maximum absolute difference and closest to k. </span></pre>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(n)<br><strong>Expected Auxiliary Space:</strong>&nbsp;O(1)</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>2 &lt;= arr.size() &lt;= 10<sup>6</sup><br>0 &lt;=k&lt;= 10<sup>6</sup><br>0 &lt;= arr[i] &lt;= 10<sup>6</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Ola Cabs</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Data Structures</code>&nbsp;<code>two-pointer-algorithm</code>&nbsp;