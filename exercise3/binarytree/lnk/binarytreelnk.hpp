
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */
#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeLnk : virtual public BinaryTree<Data>{ // Should extend BinaryTree<Data>

private:

  // ...

public:

  using typename BinaryTree<Data>::Node;

  struct NodeLnk : virtual public Node { // Should extend Node

  private:

    // ...

  protected:

    NodeLnk* left = nullptr;
    NodeLnk* right= nullptr;
    using Node::data;
    

  public:

    friend class BinaryTreeLnk<Data>;
    NodeLnk() = default;
    NodeLnk(const Data&);
    NodeLnk(Data&&) noexcept;
    /* ********************************************************************** */
    ~NodeLnk();

    // Specific member functions (inherited from Node)

    Data& Element() override; // Override Node member Mutable access to the element
    Data const& Element() const override; // Override Node member Immutable access to the element

    bool IsLeaf() const noexcept; // Override Node member
    bool HasLeftChild() const noexcept override; // Override Node member
    bool HasRightChild() const noexcept override; // Override Node member

    NodeLnk const& LeftChild() const override; // Override Node member (might throw std::out_of_range)
    NodeLnk const& RightChild() const override; // Override Node member (might throw std::out_of_range)
    NodeLnk& LeftChild() override; // Override Node member (might throw std::out_of_range)
    NodeLnk& RightChild() override; // Override Node member (might throw std::out_of_range)
  };
  
protected:
  NodeLnk* root = nullptr;
  using BinaryTree<Data>::size;
  void TreeLnkCopy(const NodeLnk&, NodeLnk&);
  bool treeCompare(const NodeLnk&, const NodeLnk&) const noexcept;
  unsigned long NodesCount (const NodeLnk&) const noexcept;
public:

  /* ************************************************************************ */

  // Default constructor
  BinaryTreeLnk() = default;


  // Specific constructors
  BinaryTreeLnk(const Data&); // Construct a tree with a given root data (Copy of the value)
  BinaryTreeLnk(Data&&); // Construct a tree with a given root data (Move of the value)

  // Copy constructor
  BinaryTreeLnk(const BinaryTreeLnk&);

  // Move constructor
  BinaryTreeLnk(BinaryTreeLnk&&);

  /* ************************************************************************ */

  // Destructor
  ~BinaryTreeLnk();

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeLnk&  operator=(const BinaryTreeLnk&);

  // Move assignment
  BinaryTreeLnk&  operator=(BinaryTreeLnk&&);

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BinaryTreeLnk&) const noexcept;
  bool operator!=(const BinaryTreeLnk&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  NodeLnk const& Root() const override; // Override Node member (might throw std::length_error)
  NodeLnk& Root() override; // Override Node member (might throw std::length_error)
  void NewRoot(const Data&) override; // Override Node member (Copy of the value)
  void NewRoot(Data&&) override; // Override Node member (Move of the value)

  void AddLeftChild(NodeLnk&, const Data&); // Add a child to a given node (Copy of the value)
  void AddLeftChild(NodeLnk&, Data&&); // Add a child to a given node (Move of the value)
  void AddRightChild(NodeLnk&, const Data&); // Add a child to a given node (Copy of the value)
  void AddRightChild(NodeLnk&, Data&&); // Add a child to a given node (Move of the value)

  void RemoveLeftChild(NodeLnk&); // Remove an entire subtree rooted in a child of a given node
  void RemoveRightChild(NodeLnk&); // Remove an entire subtree rooted in a child of a given node

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  void Clear() override; // Override Container member

protected:

  // ...

};

/* ************************************************************************** */

#include "binarytreelnk.cpp"

}

#endif
