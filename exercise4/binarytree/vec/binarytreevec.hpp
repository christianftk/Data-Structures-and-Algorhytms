
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"
#include <ctgmath>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec : virtual public BinaryTree<Data>{ // Should extend BinaryTree<Data>

private:

  // ...

public:

  using typename BinaryTree<Data>::Node;

  struct NodeVec : virtual public Node { // Should extend Node

  private:

    // ...

  protected:

    unsigned long pos;
    lasd::Vector<NodeVec*>* TreeRef;
    using Node::data;

  public:
    void DebugNod() const;

    // Constructor
    NodeVec(const Data&);
    NodeVec(Data&&) noexcept;
    // Destructor
    virtual ~NodeVec();

    friend class BinaryTreeVec<Data>;

    /* ********************************************************************** */

    // Specific member functions

    bool HasParent() const noexcept;
    bool HasLeftSibling() const noexcept;
    bool HasRightSibling() const noexcept;

    NodeVec& Parent() const; // (might throw std::out_of_range)
    NodeVec& LeftSibling() const; // (might throw std::out_of_range)
    NodeVec& RightSibling() const; // (might throw std::out_of_range)

    /* ********************************************************************** */

    // Specific member functions (inherited from Node)

    Data const& Element() const override; // Override Node member Mutable access to the element
    Data& Element() override; // Override Node member Immutable access to the element
    unsigned long Position() const; // Get the index of the node

    bool IsLeaf() const noexcept override; // Override Node member
    bool HasLeftChild() const noexcept override; // Override Node member
    bool HasRightChild() const noexcept override; // Override Node member

    NodeVec& LeftChild() override; // Override Node member (might throw std::out_of_range)
    NodeVec& RightChild() override; // Override Node member (might throw std::out_of_range)
    NodeVec const& LeftChild() const override; // Override Node member (might throw std::out_of_range)
    NodeVec const& RightChild() const override; // Override Node member (might throw std::out_of_range)

  };

  /* ************************************************************************ */
protected:

  using BinaryTree<Data>::size;
  lasd::Vector<unsigned long> NodesAtLevel;
  lasd::Vector<NodeVec*> Tree;

public:

  void DebugTree() const;
  // Default constructor
  BinaryTreeVec();

  // Specific constructors
  BinaryTreeVec(const Data&) ; // Construct a tree with a given root data (Copy of the value)
  BinaryTreeVec(Data&&) noexcept; // Construct a tree with a given root data (Move of the value)

  // Copy constructor
  BinaryTreeVec(const BinaryTreeVec&);

  // Move constructor
  BinaryTreeVec(BinaryTreeVec&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BinaryTreeVec();

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeVec& operator=(const BinaryTreeVec&);

  // Move assignment
  BinaryTreeVec& operator=(BinaryTreeVec&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BinaryTreeVec&) const noexcept;
  bool operator!=(const BinaryTreeVec&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  NodeVec& Root() override; // Override Node member (might throw std::length_error)
  NodeVec const& Root() const override; // Override Node member (might throw std::length_error)
  void NewRoot(const Data&) override; // Override Node member (Copy of the value)
  void NewRoot(Data&&) override; // Override Node member (Move of the value)

  void AddLeftChild(NodeVec&, const Data&); // Add a child to a given node (Copy of the value)
  void AddLeftChild(NodeVec&, Data&&); // Add a child to a given node (Move of the value)
  void AddRightChild(NodeVec&, const Data&); // Add a child to a given node (Copy of the value)
  void AddRightChild(NodeVec&, Data&&); // Add a child to a given node (Move of the value)

  void RemoveLeftChild(NodeVec&); // Remove an entire subtree rooted in a child of a given node
  void RemoveRightChild(NodeVec&); // Remove an entire subtree rooted in a child of a given node

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  void Clear() override; // Override Container member

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthSearchableContainer)

  using typename BinaryTree<Data>::MapFunctor;
  void MapBreadth(MapFunctor, void*) override; // Override BreadthSearchableContainer member

  using typename BinaryTree<Data>::FoldFunctor;
  void FoldBreadth(FoldFunctor, const void*, void*) const; // Override BreadthSearchableContainer member
protected:

  void RemoveTree(NodeVec&);
  void Expand(); // Accessory function
  void Reduce(); // Accessory function

  // ...

};

/* ************************************************************************** */

#include "binarytreevec.cpp"

}

#endif
