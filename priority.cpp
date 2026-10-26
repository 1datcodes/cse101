/* 
 * ADT: Priority Queue
 * A queue but every object has a priority value ("key")
 * 1. insert
 * 2. FindMax (return object with highest priority)
 * 3. ExtractMax (remove object with highest priority)
 * 4. IncreaseKey (update priority)
 *
 * Implementation:
 * - lots of ways to implement a priority queue like linked lists
 *   but efficiency will be measured by the time complexities of the above functions
 * 
 * Assume sorted
 *              FindMax   |   ExtractMax    |   insert
 * Array:       O(n)          O(n)              O(1)
 * LinkedList:  O(1)          O(1)              O(n)
 * BinaryHeap:  O(1)          O(logn)           O(logn)
 *
 * Binary Heap:
 * binary heap is an array of objects
 * ADT is a tree-like structure but uses an array
 * [NULL, ] * first entry is left empty which makes the life easy
 *        1
 *       / \
 *      2   3
 *     / \ / \
 *    4  5 6  7
 *
 * left(i) = 2*i;
 * right() = 2*i + 1;
 * parent(i) = i/2;
 *
 * Invariant: key at any parent must be larger than the key of their child 
 * *However there is no constraints between siblings or any node other than the direct parent
 *
 * Any subtree of a binary heap is also a binary heap
 * */
