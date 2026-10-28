
# File System Representation and Search Using BFS and DFS

## Activity Details
- **Activity ID:** SY-S3-B-09
- **Challenge:** 17-B 09
- **Subject:** Data Structures and Algorithms
- **Programming Language:** C

## Aim
To represent a file system as a graph using an adjacency matrix and implement Breadth-First Search (BFS) and Depth-First Search (DFS) to traverse the graph and search for a specified file or directory.

## Objectives
- Represent files and directories as graph nodes.
- Represent connections between nodes using an adjacency matrix.
- Implement BFS traversal using a queue.
- Implement DFS traversal using recursion.
- Search for a specified node using both BFS and DFS.

## Concepts Used
- Graphs
- Adjacency Matrix
- Breadth-First Search (BFS)
- Depth-First Search (DFS)
- Queue
- Recursion

## Algorithm

### BFS
1. Start from the given node.
2. Mark the node as visited and insert it into the queue.
3. Remove a node from the queue and display it.
4. Visit all its unvisited adjacent nodes and insert them into the queue.
5. Repeat until the queue is empty.

### DFS
1. Start from the given node.
2. Mark the node as visited and display it.
3. Visit an unvisited adjacent node recursively.
4. Repeat until no unvisited adjacent nodes remain.

## Sample Input
```text
5
0 1 1 0 0
1 0 0 1 0
1 0 0 0 1
0 1 0 0 0
0 0 1 0 0
0
4
```

## Sample Output
```text
BFS Traversal: 0 1 2 3 4
DFS Traversal: 0 1 3 2 4
BFS Search: File found.
DFS Search: File found.
```

## How to Compile and Run

Save the program as `filesystem_bfs_dfs.c`.

Compile:
```bash
gcc filesystem_bfs_dfs.c -o filesystem
```

Run on Linux:
```bash
./filesystem
```

Run on Windows:
```bash
filesystem.exe
```

## Result
The file system graph was represented using an adjacency matrix. BFS and DFS traversals were performed successfully, and the specified node was searched using both algorithms.

## Author
Vaigapradeep
