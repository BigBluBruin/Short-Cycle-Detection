# Short-Cycle-Detection
This repository develops a Breadth-First-Search-Based short cycle detection algorithm for binary LDPC parity check matrix. 


Simulation shows that small girht (especially 4) is detrimental to decoding performance of LDPC code. When constructing LDPC code, we will always avoid short cycles. Most research works are foucused on construting LDPC parity chekck metrix which are inherently no short cycles. 

 However, when we construct random LDPC code, we also want to avoid these short and annoying length-4 (or even length-6) cycles. Thus, this repo provids you a easy way to detect if your matirx contains a cycle short than or eaqual to your requirement. 
 
 This algorithm is inspired by Breadth First Search, which aims to find shortest path layer by layer. The difference is we implement a hash table and track whether a node has been visited. Since a cycle forms *once a node is visited twice*. 
 
 Our algorithm is a simple **yes or no** algorithm, feed your matrix in our algortihm and it tells you **IF OR NOT your matrix contains cycles whose length is less than or equal to your requirement**. 
 
 The input of algorithm is a 2-D int-type vector, which is your parity check matrix.
 The output is a bool-type return and :true: means there is no such cycles and :false: mean there is such cycles.
 
 
 
