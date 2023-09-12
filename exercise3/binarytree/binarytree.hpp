
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

#include "../queue/queue.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../queue/lst/queuelst.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTree : virtual public BreadthSearchableContainer<Data>{ // Should extend BreadthSearchableContainer<Data>

private:

  // ...

protected:

  using BreadthSearchableContainer<Data>::size;

  // ...

public:

  struct Node {

  private:

    // ...

  protected:
    Data data;
    // ...

  public:

    Node() = default;
    friend class BinaryTree<Data>;

    /* ********************************************************************** */

    // Specific member functions

    virtual Data& Element() = 0; // Mutable access to the element
    virtual Data const& Element() const = 0; // Immutable access to the element

    virtual bool IsLeaf() const noexcept = 0;
    virtual bool HasLeftChild() const noexcept = 0;
    virtual bool HasRightChild() const noexcept = 0;

    virtual Node const& LeftChild() const = 0; // (might throw std::out_of_range)
    virtual Node const& RightChild() const = 0; // (might throw std::out_of_range)
    virtual Node& LeftChild() = 0; // (might throw std::out_of_range)
    virtual Node& RightChild() = 0; // (might throw std::out_of_range)

  };

  /* ************************************************************************ */
  BinaryTree() = default;

  // Destructor
  virtual ~BinaryTree() = default;

  /* ************************************************************************ */

  // Copy assignment
  BinaryTree& operator=(const BinaryTree&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  BinaryTree& operator=(BinaryTree&&) = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BinaryTree&) const noexcept; // Comparison of abstract binary tree is possible.
  bool operator!=(const BinaryTree&) const noexcept; // Comparison of abstract binary tree is possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual Node const& Root() const = 0; // (might throw std::length_error)
  virtual Node& Root() = 0; // (might throw std::length_error)
  virtual void NewRoot(const Data&) = 0; // Copy of the value
  virtual void NewRoot(Data&&) = 0; // Move of the value

  using typename SearchableContainer<Data>::MapFunctor;
  virtual void MapInOrder(MapFunctor, void*);

  using typename SearchableContainer<Data>::FoldFunctor;
  virtual void FoldInOrder(FoldFunctor, const void*, void*) const;

  /* ************************************************************************ */

  // Specific member functions (inherited from SearchableContainer)

  virtual void MapPreOrder  (MapFunctor, void*) override ; // Override SearchableContainer member
  virtual void MapPostOrder (MapFunctor, void*) override ; // Override SearchableContainer member

  virtual void FoldPreOrder (FoldFunctor, const void*, void*) const override ; // Override SearchableContainer member
  virtual void FoldPostOrder(FoldFunctor, const void*, void*) const override ; // Override SearchableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthSearchableContainer)

  virtual void MapBreadth (MapFunctor, void*) override; // Override BreadthSearchableContainer member

  virtual void FoldBreadth(FoldFunctor, const void*, void*) const override; // Override BreadthSearchableContainer member

protected:

  void MapBreadth  (MapFunctor, Node*, void*); // Accessory function executing from one node of the tree
  void MapPreOrder (MapFunctor, Node*, void*); // Accessory function executing from one node of the tree
  void MapInOrder  (MapFunctor, Node*, void*); // Accessory function executing from one node of the tree
  void MapPostOrder(MapFunctor, Node*, void*); // Accessory function executing from one node of the tree

  void FoldBreadth  (FoldFunctor, const Node&, const void*, void*) const ; // Accessory function executing from one node of the tree
  void FoldPreOrder (FoldFunctor, const Node&, const void*, void*) const ; // Accessory function executing from one node of the tree
  void FoldInOrder  (FoldFunctor, const Node&, const void*, void*) const ; // Accessory function executing from one node of the tree
  void FoldPostOrder(FoldFunctor, const Node&, const void*, void*) const ; // Accessory function executing from one node of the tree

  bool treeCompare(const Node&, const Node&) const noexcept;
};

/* ************************************************************************** */

#include "binarytree.cpp"

}

#endif
