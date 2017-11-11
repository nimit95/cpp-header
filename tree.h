#ifndef TREE_H
#define TREE_H

#include "treenode.h"



template<class T>
class BinarySearchTree {

private:

    int mod(int num) {
        return num>0?num:-num;
    }

    TreeNode<T>* rightRotate(TreeNode<T>* y)
{
    TreeNode<T>* x = y->leftChild.get();
    TreeNode<T>* T2 = x->rightChild.get();

    // Perform rotation
    x->rightChild.release();
    x->rightChild.reset(y);

    TreeNode<T>* temp = y->parent;
    y->parent = x;

    y->leftChild.release();
    y->leftChild.reset(T2);
    if(T2)
      T2->parent = y;

    x->parent = temp;
    // Return new root
    return x;
}

// A utility function to left rotate subtree rooted with x

TreeNode<T>* leftRotate(TreeNode<T>* x)
{

    TreeNode<T>* y = x->rightChild.get();
    TreeNode<T>* T2 = y->leftChild.get();

    // Perform rotation
    y->leftChild.release();
    y->leftChild.reset(x);

    TreeNode<T>* temp = x->parent;


    x->parent = y;
    x->rightChild.release();
    (x->rightChild).reset(T2);
  //  cout<<x->data<<endl;
    if(T2)
      T2->parent = x;

    y->parent = temp;
    // Return new root

  //  cout<<x->data<<endl<<y->data<<endl<<y;


    return y;
}
    TreeNode<T>* checkAndBalance(TreeNode<T>* root, T data ,int flag) {
          int balance = root->leftChild->maxDepth() - root->rightChild->maxDepth();
          if(mod(balance)<=1)
              return NULL;

          else {
              if(flag==0) {
                  if(data<root->data) {
                     
                     TreeNode<T>* temp = leftRotate(root->leftChild.get());
                     root->leftChild.release();
                     root->leftChild.reset(temp);
                     return rightRotate(root);

                  }
                  else {
                      // left rotation
                      TreeNode<T>* temp = root->parent;
                      if(temp==NULL)
                          return leftRotate(root);
                      if(temp->leftChild.get()==root) {
                         TreeNode<T>* temp2 = leftRotate(root);
                         temp->leftChild.release();
                         temp->leftChild.reset(temp2);
                         return temp2;
                      }
                      else {
                        TreeNode<T>* temp2 = leftRotate(root);
                        temp->rightChild.release();
                        temp->rightChild.reset(temp2);
                        return temp2;
                      }
                    //  return temp;
                  }
              }
              else {
                if(data<root->data) {
                     //right rotation
                     TreeNode<T>* temp = root->parent;
                     if(temp==NULL)
                        return rightRotate(root);
                     if(temp->leftChild.get()==root) {
                           TreeNode<T>* temp2 = rightRotate(root);
                           temp->leftChild.release();
                           temp->leftChild.reset(temp2);
                           return temp2;
                        }
                        else {
                          TreeNode<T>* temp2 = leftRotate(root);
                          temp->rightChild.release();
                          temp->rightChild.reset(temp2);
                          return temp2;
                        }
                }
                else {
                    // right left rotation
                    TreeNode<T>* temp = rightRotate(root->rightChild.get());
                    root->rightChild.release();
                    root->rightChild.reset(temp);
                    return leftRotate(root);
                }
              }
          }
    }

    TreeNode<T> *insert(unique_ptr<TreeNode<T>> &ptr, T data) {
    //    cout<< "data add"<<data;
        if (ptr.get() == NULL) {
            return NULL;
        }

        if (ptr->data < data){
            if(ptr->rightChild.get()==NULL) {
                  TreeNode<T>* insertedNode = new TreeNode<T>(data);
                  ptr->setRightChild(insertedNode);
                  if(ptr->parent) {
                         checkAndBalance(ptr->parent, data, 0);
  //                      if(temp)
//                          return temp;
                  }
                  return insertedNode;
            }
            return insert(ptr->rightChild, data);
        }
        else{
            if(ptr->leftChild.get()==NULL) {
              TreeNode<T>* insertedNode = new TreeNode<T>(data);
                ptr->setLeftChild(insertedNode);
                if(ptr->parent) {
                     checkAndBalance(ptr->parent, data, 1);
                      // if(temp)
                      //   return temp;
                }
                return insertedNode;
            }
            return insert(ptr->leftChild, data);
        }


    }

    TreeNode<T> *find(unique_ptr<TreeNode<T>> &ptr, T data) {

        if (ptr.get() == nullptr)
            return nullptr;


        if (ptr->data < data)
            return find(ptr->rightChild, data);
        else if (data < ptr->data)
            return find(ptr->leftChild, data);
        else
            return ptr.get();

    }

public:
   unique_ptr<TreeNode<T>> root;
    void write(ostream &output) const {
        root->write(output);
    }

    BinarySearchTree() {
        this->root = nullptr;
    }
    TreeNode<T> *insert(T data) {
        if(this->root==nullptr){
            root.reset(new TreeNode<T>(data));
            return root.get();
        }
        TreeNode<T>* temp = insert(this->root, data);
        while(this->root->parent!=NULL){
            TreeNode<T>* temp2 = this->root->parent;
            this->root.release();
            this->root.reset(temp2);
        }
      //  cout<<root->data<<"end ";
        return temp;
    }


    TreeNode<T> *find(T data) {
        return find(this->root, data);
    }

    int maxDepth() {
         if(root==nullptr) return 0;
         //cout<<root->leftChild->data;
         return root->maxDepth();
    }


  //  typename TreeNode<T>::TreeNodeIterator
    typename TreeNode<T>::TreeNodeIterator begin() {

        if(root==nullptr)
            return typename TreeNode<T>::TreeNodeIterator(NULL);
        TreeNode<T>* temp = root.get();
        //temp.reset(root);
        while(temp->leftChild!=nullptr)
            temp = (temp->leftChild).get();
        return typename TreeNode<T>::TreeNodeIterator(temp);
    }
    //typename TreeNode<T>::TreeNodeIterator
    typename TreeNode<T>::TreeNodeIterator end() {
        return typename TreeNode<T>::TreeNodeIterator(NULL);
    }

};

// do not edit below this line

#endif
