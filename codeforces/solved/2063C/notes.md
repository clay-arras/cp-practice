
This problem can be simplified using the following observation. when we
remove any arbitrary vertex v, then number of connected components increases
by `deg(v) - 1`. therefore, to maximize the number of connected
components, we want to remove the two vertexes with the highest degree. 

The tricky part of this problem is the following. a vertex's degree may
decrease after we remove the first vertex. therefore, when choosing the
first vertex, we'd like it to NOT neighbor any vertices that also have
high degrees. the only time this is relevant is if you have TWO vertices
that both have the maximum degree.

<!-- therefore, we can construct  -->
