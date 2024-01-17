# coding
My own coding practice

#To do
hashmaps. Hashset in C done
Binary search Hacker Rank done. DO more from Leetcode
Self balancing binary search tree
Remove repeated elements in array without sorting them
Two-pointer problems
Data structures you should know:
Arrays, Linked Lists, Stacks, Queues, Trees, Graphs, Heaps, Hash sets, Hash maps

Algorithms you should know:
Breadth first search, Depth first search, Binary search, Quicksort, Mergesort, A*, Dynamic programming, Recursion, Divide and conquer

### Git SSH access rights
if you get the error   
    git@github.com: Permission denied (publickey).
    fatal: Could not read from remote repository.
Perform these steps:
    1. `cat /etc/resolv.conf` has nameserver 8.8.4.4
    2. Check `git config --local --list`
    3. Add SSH key of your profile to ssh agent, `ssh-add /<dir>/github/id_rsa`
    4. Enter `ssh -T git@github.com`
        Hi <username>! You've successfully authenticated, but GitHub does not provide shell access.
