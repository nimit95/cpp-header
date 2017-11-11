#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>

using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

#include <memory>

using std::unique_ptr;

#include <utility>

using std::pair;



template<class T>
class TreeNode {
public:
    T data;
    unique_ptr<TreeNode<T>> leftChild, rightChild;
    TreeNode<T> *parent;

    TreeNode(T d):data(d) {

        this->parent = nullptr;
        this->leftChild = nullptr;
        this->rightChild = nullptr;
    }

    void setLeftChild(TreeNode<T> *child) {
        this->leftChild.reset(child);
        child->parent = this;
    }

    void setRightChild(TreeNode<T> *child) {
        this->rightChild.reset(child);
        child->parent = this;
    }

    void write(ostream &output) const {
        if (this->leftChild != nullptr) {
            this->leftChild->write(output);
        }
        output <<" " <<data<<" ";
        if (this->rightChild != nullptr) {
            this->rightChild->write(output);
        }
    }
    class TreeNodeIterator {

        TreeNode<T>* itr;
    public:
        TreeNodeIterator(TreeNode<T>* root) {
            itr = root;
        }

        T& operator*() {
            return itr->data;
        }

        bool operator==(TreeNode<T>::TreeNodeIterator temp) {
            return itr == temp.itr;
        }

        bool operator!=(TreeNode<T>::TreeNodeIterator temp) {
            return itr != temp.itr;
        }

        void operator++() {
            if(itr->rightChild!=nullptr)
                itr = (itr->rightChild).get();
            else {
                while(itr->parent!=NULL && (itr->parent->leftChild).get()!=itr)
                    itr = itr->parent;

                if(itr!=NULL)
                    itr=itr->parent;
            }

        }
      };

    int maxDepth() {
        return maxDepth(this);
    }
private:
    int maxDepth(TreeNode<T>* root) {
        if (root == NULL)
            return 0;

        int a = maxDepth(root->leftChild.get());
        int b = maxDepth(root->rightChild.get());

        if (a > b)
            return a + 1;
        else
            return b + 1;
    }
};

#endif
