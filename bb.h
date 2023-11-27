#include <iostream> 
#include <algorithm> 
#include <vector> 
#include <queue>
#include <bits/stdc++.h>
#include "JOBS.h"

using namespace std; 

#ifndef BB_H
#define BB_H

class BranchAndBoundScheduler {    
    struct Node {
        Node* parent;
        Jobs jobSet;
        int pathCost;
        int cost;
        vector<bool> assigned;
    };

    Node* newNode (Node* parent, Jobs jobSet, vector<bool> assigned, int deadline) {
        Node* node = new Node;
 
        node->parent = parent;
        node->jobSet = jobSet;
        node->assigned = assigned;
        node->assigned[deadline] = true;
     
        return node;
    }

    struct comparator {
        bool operator()(const Node* left, const Node* right) const {
            return left->cost > right->cost;
        } 
    };

    void scheduler (Jobs jobs) {
        priority_queue<Node*, vector<Node*>, comparator> queue;

        vector<bool> assigned(jobs.numJobs, false);
        Node* root = newNode(NULL, {}, assigned, -1);
        root->pathCost = root->cost = 0;

        queue.push(root);

        while (!queue.empty()) {
            Node* min = queue.top();
            queue.pop();
            int i = min->
        }

    }
};


#endif