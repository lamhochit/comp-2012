//this is one of the two files that you need to submit

#include "infectionAnalyzer.h"
#include <fstream> //for reading file
#include <queue> //you may use STL queue
#include <algorithm> //you may use STL algorithm
using namespace std;
//you are NOT allowed to include additional libraries yourself

InfectionAnalyzer::~InfectionAnalyzer() {
    vector<Tree<string>*>::iterator t;
    for (t = trees.begin(); t != trees.end(); ++t) {
        delete *t;
    }
}

bool InfectionAnalyzer::loadInfectionFile(string filename) {
    std::ifstream infile(filename);
    string a, b;
    queue<string> a_stack;
    queue<string> b_stack;
    while (infile >> a >> b)
    {
        a_stack.push(a);
        b_stack.push(b);
    }
    if (a_stack.empty() && b_stack.empty()) {return false;}

    for (int i = 0, j =0; !a_stack.empty() && !b_stack.empty(); i++, j++) {
        if (!isInfected(a_stack.front())) {
            Tree<string> *temp_trees = new Tree<string>();
            temp_trees->addRoot(a_stack.front());
            temp_trees->addChild(a_stack.front(), b_stack.front());
            a_stack.pop();
            b_stack.pop();
            trees.push_back(temp_trees);
        } else if (isInfected(a_stack.front())){
            vector<Tree<string>*>::const_iterator t;
            for (t = trees.begin(); t != trees.end(); ++t) {
                if ((*t)->find(a_stack.front()) != nullptr) {
                    (*t)->addChild(a_stack.front(), b_stack.front());
                    a_stack.pop();
                    b_stack.pop();
                    break;
                }
            }
        }
    }
    if (trees.size() == 1) {return true;}
//    Begin Merge Tree
//    queue<vector<Tree<string>*>::const_iterator> del_queue;
    queue<Tree<string>*> tree_queue;
    vector<Tree<string>*>::const_iterator t1;
    vector<Tree<string>*>::const_iterator t2;
    for (t1 = trees.begin(); t1 != trees.end(); ++t1) {
        string temp = (*t1)->root->data;
        for (t2 = trees.begin(); t2 != trees.end(); ++t2) {
            if (t1 == t2) { continue;}
            if ((*t2)->find(temp) != nullptr) {
                if ((*t2)->find(temp)->root->childCount == 0) {
                    (*t2)->find(temp)->root->childCount = (*t1)->root->childCount;
                    (*t2)->find(temp)->root->children = (*t1)->root->children;
                    tree_queue.push(*t1);
                }
            }
        }
    }

    for (int i = 0; !tree_queue.empty(); i++) {
        trees.erase(std::remove(trees.begin(), trees.end(), tree_queue.front()), trees.end());
        tree_queue.pop();
    }


    return true;
}

bool InfectionAnalyzer::isInfected(string name) const {
    vector<Tree<string>*>::const_iterator t;
    for (t = trees.begin(); t != trees.end(); ++t) {
        if ((*t)->find(name) != nullptr) {return true;}
    }
    return false;
}

string InfectionAnalyzer::getInfectionSource(string name) const {
    if (!isInfected(name)) {return "NA";}
    int tree_index;
    for (int i = 0; i < trees.size(); i++) {
        if (trees[i]->find(name) != nullptr) {tree_index = i;
            break;}
    }
    Tree<string>* mytree = trees[tree_index];
    int dp = mytree->getDepth(name);
    if (dp == 0) {
        return "ZERO";
    } else {
        queue<Tree<string>*> qq;
        qq.push(mytree);
        for (int layer = 0; layer < dp; layer++) {
            for (int i = 0; i < qq.size(); i++) {
                int cCount = qq.front()->root->childCount;
                for (int c = 0; c < cCount; c++) {
                    if (qq.front()->root->children[c].root->data == name) {
                        return qq.front()->root->data;
                    } else {
                        qq.push(&qq.front()->root->children[c]);
                    }
                }
                qq.pop();
            }
        }
    }
    return "NA";
}

int InfectionAnalyzer::getInfectionGeneration(string name) const {
    for (int i = 0; i < trees.size(); i++) {
            if (trees[i]->getDepth(name) != -1) {return trees[i]->getDepth(name);}
    }
    return -1;
}

const vector<pair<string, int>> &InfectionAnalyzer::getInfectionPowerVector() {
    vector<pair<string, int>> vec;
    return vec;
}

