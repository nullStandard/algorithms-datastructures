Graph traversal algorithm. 
What do we need:
A queue, an array for already-viewed vertices, 
an array (index is the number of vertex) 
with distances from the current vertex (by index) 
to the initial vertex are used. It is immediately initialized 
with infinity (999). The goal vertex is also optional.

1. Each vertex has a neighbor. Insert the starting vertex in the queue.

2. Explore the new vertex and remove it from the queue. 
Check have we already considered this vertex 
(i.e., is it exists in the vector of the visited vertices). 
Yes -  repeat this paragraph, no:

3. If necessary, we check is it our goal vertex. Yes - we finish the work, no:

4. Add all neighbors to the queue. Then for each of the neighbors 
(the corresponding index) check its value in the range array. 
If the infinity (999) - infinity is changed by the value 
*value of the parent + 1* for each of the parent�s neighbors.

5. Add the considered vertex to the array of visited vertices.
Move to paragraph 2.

If the queue is empty, then we�ve bypassed the graph.