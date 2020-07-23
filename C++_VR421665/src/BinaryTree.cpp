/**
 * @copyright Copyright © 2018 LinearAlgebra. All rights reserved.
 *
 * @license{<blockquote>
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * * Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 * </blockquote>}
 *
 * @author Federico Busato                                                  <br>
 *         Univerity of Verona, Dept. of Computer Science                   <br>
 *         federico.busato@univr.it
 * @date June, 2018
 * @version v1.0
 */
#include "BinaryTree.hpp" // linear_algebra::Vector
#include <iostream>   // std::cout

namespace bin_tree {

    template <class T>
    class BinaryTree
    {

        struct node {
            T value;
            struct node* right;
            struct node* left;
        };

    public:
        BinaryTree();
        ~BinaryTree();
        void add(T val);
        void printPreOrder();
        void printInOrder();
        void printPostOrder();
        int size();
        bool lookup(T val);

    private:
        struct node* root;
        int treeSize;
        void add(struct node** node, T val);
        bool lookup(struct node* node, T val);
        void printPreOrder(struct node* node);
        void printInOrder(struct node* node);
        void printPostOrder(struct node* node);
        void deleteTree(struct node* node);
    };

    template <class T>
    BinaryTree<T>::BinaryTree() {
        this->root = NULL;
        this->treeSize = 0;
    }

    template <class T>
    BinaryTree<T>::~BinaryTree() {
        deleteTree(this->root);
    }

    template <class T>
    int BinaryTree<T>::size() {
        return this->treeSize;
    }

    template <class T>
    void BinaryTree<T>::add(T val) {
        add(&(this->root), val);
    }

    template <class T>
    void BinaryTree<T>::add(struct node** node, T val) {

        if (*node == NULL) {
            struct node* tmp = new struct node;
            tmp->value = val;
            tmp->left = NULL;
            tmp->right = NULL;
            *node = tmp;

            this->treeSize++;
        }
        else {
            if (val > (*node)->value) {
                add(&(*node)->right, val);
            }
            else {
                add(&(*node)->left, val);
            }
        }
    }

    template <class T>
    void BinaryTree<T>::printInOrder() {
        printInOrder(this->root);
        std::cout << std::endl;
    }

    template <class T>
    void BinaryTree<T>::printInOrder(struct node* node) {
        if (node != NULL) {
            printInOrder(node->left);
            std::cout << node->value << ", ";
            printInOrder(node->right);
        }
    }

    template <class T>
    void BinaryTree<T>::printPreOrder() {
        printPreOrder(this->root);
        std::cout << std::endl;
    }

    template <class T>
    void BinaryTree<T>::printPreOrder(struct node* node) {
        if (node != NULL) {
            std::cout << node->value << ", ";
            printInOrder(node->left);
            printInOrder(node->right);
        }
    }

    template <class T>
    void BinaryTree<T>::printPostOrder() {
        printPostOrder(this->root);
        std::cout << std::endl;
    }

    template <class T>
    void BinaryTree<T>::printPostOrder(struct node* node) {
        if (node != NULL) {
            printInOrder(node->left);
            printInOrder(node->right);
            std::cout << node->value << ", ";
        }
    }


    template <class T>
    void BinaryTree<T>::deleteTree(struct node* node) {
        if (node != NULL) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

    template <class T>
    bool BinaryTree<T>::lookup(T val) {
        return lookup(this->root, val);
    }

    template <class T>
    bool BinaryTree<T>::lookup(struct node* node, T val) {
        if (node == NULL) {
            return false;
        }
        else {
            if (val == node->value) {
                return true;
            }

            if (val > node->value) {
                return lookup(node->right, val);
            }
            else {
                return lookup(node->left, val);
            }
        }

    }
}
