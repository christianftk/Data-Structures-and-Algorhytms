
#ifndef AVL_HPP
#define AVL_HPP

/* ************************************************************************** */

#include "../bst.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class AVL : virtual public BST<Data> { // Should extend BST<Data>

protected:

  using BST<Data>::size;
  using BST<Data>::root;
  

  // ...

public:

  using typename BST<Data>::BSTNode;
  using typename BST<Data>::NodeLnk;

  struct AVLNode : public BSTNode{ // Should extend BSTNode

  protected:

    using BSTNode::left;
    using BSTNode::right;

    long height = 0;
    AVLNode* Left() override;
    AVLNode const* Left() const override;
    AVLNode* Right() override;
    AVLNode const* Right() const override;


  public:

    using NodeLnk::HasLeftChild;
    using NodeLnk::HasRightChild;
    
    friend class AVL<Data>;
  };

private:

  void TreeLnkCopy(const AVLNode*, AVLNode*);

  // Accessory Functions for Balancing
  long MaxSubTree(AVLNode*);
  long is_Balanced(AVLNode*);

  AVLNode* Bilancia_sx(AVLNode*);
  AVLNode* Bilancia_dx(AVLNode*);

  bool is_SS(AVLNode*);
  bool is_SD(AVLNode*);

  AVLNode* Rotate_SS(AVLNode*);
  AVLNode* Rotate_DS(AVLNode*);
  AVLNode* Rotate_SD(AVLNode*);
  AVLNode* Rotate_DD(AVLNode*);



protected:

  AVLNode* Insert(AVLNode*, const Data&);
  AVLNode* Insert(AVLNode*, Data&&);
  AVLNode* Remove(AVLNode*, const Data&);
  AVLNode* RemoveMin(AVLNode*, AVLNode*);
  AVLNode* RemoveRoot(AVLNode*);
  AVLNode* DeleteMin(AVLNode*);
  AVLNode* DeleteMax(AVLNode*);

  long h(AVLNode*);


public:

  /* ************************************************************************ */

  // Default constructor
  AVL() = default;

  // Copy constructor
  AVL(const AVL&);

  // Move constructor
  AVL(AVL&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~AVL() = default;

  /* ************************************************************************ */

  // Copy assignment
  AVL& operator=(const AVL&);

  // Move assignment
  AVL& operator=(AVL&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const AVL&) const noexcept;
  bool operator!=(const AVL&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  AVLNode& Root() override; // Override BinaryTree member (might throw std::length_error)
  AVLNode const& Root() const override; // Override BinaryTree member (might throw std::length_error)
  void NewRoot(const Data&) override; // Override BinaryTree member (Copy of the value)
  void NewRoot(Data&&) noexcept override; // Override BinaryTree member (Move of the value)

  /* ************************************************************************ */

  // Specific member functions

  void Insert(const Data&) override; // Copy of the value
  void Insert(Data&&) override; // Move of the value
  void Remove(const Data&) override;

  Data MinNRemove() override; // (might throw std::length_error)
  void RemoveMin() override; // (might throw std::length_error)

  Data MaxNRemove() override; // (might throw std::length_error)
  void RemoveMax() override; // (might throw std::length_error)

  /* ************************************************************************ */

};

}

/* ************************************************************************** */

#include "avl.cpp"

/* ************************************************************************** */

#endif
