//this is one of the two files that you need to submit

#include "tree.h"

using namespace std;
//you are NOT allowed to include additional libraries yourself

//you do NOT need to include "tree.h" in this file
//this is NOT a cpp file, but simply a part of "tree.h"
//see the bottom of tree.h for explanation
//just write your tree implementation here right away

template<typename T>
Tree<T>::Tree(const Tree &another) {
    if (another.isEmpty())
        return;

    *this = another;
}

template<typename T>
Tree<T>::~Tree() {
    if (!root)
        delete root;
    root = nullptr;
}

template<typename T>
const Tree<T>& Tree<T>::operator=(const Tree &another) {
    if (this != &another)
    {
        if (root)
            delete root;
        if (another.root)
            root = new Node<T>(*another.root);
        else
            root = nullptr;
    }
    return *this;
}

template<typename T>
Tree<T>* Tree<T>::find(const T &data) {
    if (this->isEmpty()) {
        return nullptr;
    } else {
        if (this->root->data == data) {
            return this;
        } else {
            for (int i = 0; i < this->root->childCount; i++) {
                if (this->root->children[i].find(data) != nullptr) {
                    return this->root->children[i].find(data);
                }
            }
            return nullptr;
        }
    }
}

template<typename T>
const Tree<T> *Tree<T>::find(const T &data) const {
    if (this->isEmpty()) {
        return nullptr;
    } else {
        if (this->root->data == data) {
            return this;
        } else {
            for (int i = 0; i < this->root->childCount; i++) {
                if (this->root->children[i].find(data) != nullptr) {
                    return this->root->children[i].find(data);
                }
            }
            return nullptr;
        }
    }
}

template<typename T>
int Tree<T>::getDepth(const T &data) const {
    int count = 0;
    if (this->isEmpty()) {
        return -1;
    } else {
        if (this->root->data == data) {
            return count;
        } else {
            count += 1;
            for (int i = 0; i < this->root->childCount; i++) {
                if (this->root->children[i].getDepth(data) != -1) {
                    return count + this->root->children[i].getDepth(data);
                }
            }
            return -1;
        }
    }
}

template<typename T>
int Tree<T>::getDescendantCount(const T &data) const {
   const Tree<T>* target = this->find(data);
   if (target == nullptr) {return -1;}
   int count = target->getDescendantCount();
   return count;
}

template<typename T>
int Tree<T>::getDescendantCount() const {
    int count = 0;
    if (this->isEmpty()) {
        return 0;
    } else {
        for (int i = 0; i < this->root->childCount; i++) {
            count += 1;
            if (this->root->children[i].getDescendantCount() != 0) {
                count += this->root->children[i].getDescendantCount();
            }
        }
        return count;
    }
}

template<typename T>
bool Tree<T>::addRoot(const T &data) {
    if (this->find(data) != nullptr) {
        return false;
    }
    if (isEmpty()) {
        this->root = new Node<T>(data);
        return true;
    } else {
        Node<T>* temp = new Node<T>(data, 1);
        temp->children[0].root = this->root;
        this->root = temp;
        return true;
    }
}

template<typename T>
bool Tree<T>::addChild(const T &parentData, const T &childData) {
    if (this->find(parentData) == nullptr || this->find(childData) != nullptr) {
        return false;
    }
    Tree<T>* parent = this->find(parentData);
    Tree<T>* child = this->find(childData);
    int og_child_count = parent->root->childCount;
    Tree<T>* temp_children = new Tree<T>[og_child_count + 1];
    for (int i = 0; i < og_child_count; i++) {
        temp_children[i] = parent->root->children[i];
    }
    temp_children[og_child_count].root = new Node<T>(childData);
    parent->root->childCount += 1;
    parent->root->children = temp_children;
    return true;
}
