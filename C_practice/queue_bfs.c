//https://leetcode.com/explore/learn/card/queue-stack/231/practical-application-queue/1376/
/*
Queue and Breadth-First search (BFS)
int BFS(Node root, Node target) {
    Queue<Node> queue;  // store all nodes which are waiting to be processed
    int step = 0;       // number of steps neeeded from root to current node
    // initialize
    add root to queue;
    // BFS
    while (queue is not empty) {
        // iterate the nodes which are already in the queue
        int size = queue.size();
        for (int i = 0; i < size; ++i) {
            Node cur = the first node in queue;
            return step if cur is target;
            for (Node next : the neighbors of cur) {
                add next to queue;
            }
            remove the first node from queue;
        }
        step = step + 1;
    }
    return -1;          // there is no path from root to target
}

it is important to make sure that we never visit a node twice. 
Otherwise, we might get stuck in an infinite loop, e.g. in graph with cycle. 
If so, we can add a hash set to the code above to solve this problem.

for (Node next : the neighbors of cur) {
                if (next is not in visited) {
                    add next to queue;
                    add next to visited;
                }/
*/