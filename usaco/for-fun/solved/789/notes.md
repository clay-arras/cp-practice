
## solution. 

we can process the information as follows. firstly, we can sort the
edges from biggest to smallest. we can treat constructing the tree as a
series of "merges". the key observation here is that on each merge, when
we are merging connected components, because we are processing the
largest nodes first, this edge will the the SMALLEST edge connecting any
two members of these connected components.

let us build a tree, where each merge between two videos will create a
new node in the graph. each node will be populated by the edge joining
those two connected components together. the size of the tree is at most
2N (since there are N-1 merges and we only create a new node on a
merge), and the depth is at most N. notice that to find the answer for
node V with relevance K, all we need to do is start at the node V and go
up the tree. when relevance of the node is not <= K, we query the size
of the subtree, which will be our answer.

this operation will take at most NQ, which is not enough to AC. however,
we can do a clever optimization to "path compress" the nodes. we can
answer the queries offline, in the order from LARGEST K to smallest K.
each node has an id from 0 to 2N. each node also points to at most one
other node. therefore, after each query, we can point the ORIGINAL nodes
that we started out on to the END nodes of our query. this should ensure
a QlogN solution (on the order of)


important information in the tree:
- it's leader
- it's size
- it's minK
