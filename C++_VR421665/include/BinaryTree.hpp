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
 *
 * @file
 */
#pragma once

#include "LAObject.hpp" // linear_algebra::LAObject
#include "Operator.hpp" // operator+(Vector, Vector)
#include <cstddef>      // size_t
#include <ostream>      // std::ostream

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


template<typename T>
class BinaryTree;           // forward declaration

template<typename T>
class Vector : public LAObject<T> {
    using LAObject<T>::_array;
    using LAObject<T>::_ld;
    using LAObject<T>::_rows;

    template<typename> friend class Matrix;

public:
    /**
     * @brief
     */
    explicit class BinaryTree() = default;

    /**
     * @brief
     * @param[in] size
     * @param[in] ld
     */
    explicit BinaryTree(size_t size, size_t ld = 1);    //DA MODIFICARE I PARAMETRI

    

    /**
     * @brief
     * @return
     */
    int size() const override;

    /**
    * @brief
    */

    void add(T val);
   
    /**
    * @brief
    */
    void add(struct node** node, T val);
    
    /**
     * @brief
     */
    void printInOrder() ;

    /**
    * @brief
    */
    void printPostOrder(struct node* node);
    
    
    /**
     * @brief
     */
    void deleteTree(struct node* node);
    
     /**
     * @brief
     * @return
     */
    bool lookup(T val) const;

    /**
    * @brief
    * @return
    */
    bool lookup(struct node* node, T val)


};

}

#include "impl/BinaryTree.i.hpp"
