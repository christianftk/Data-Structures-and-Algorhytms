
#ifndef BST_HPP
#define BST_HPP

/* ************************************************************************** */

#include "../binarytree/lnk/binarytreelnk.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BST : virtual public BinaryTreeLnk<Data> { // Should extend BinaryTreeLnk<Data>

private:

  // ...

protected:

  using BinaryTreeLnk<Data>::root;

  using BinaryTreeLnk<Data>::size;

  // ...

public:

  using typename BinaryTreeLnk<Data>::NodeLnk;

  struct BSTNode : public NodeLnk{ // Should extend NodeLnk

  private:

    // ...

  protected:

    using NodeLnk::left;
    using NodeLnk::right;
    using NodeLnk::data;


    BSTNode* Find(const Data&) noexcept;
    BSTNode* FindParent(BSTNode*, const Data&) noexcept;

    BSTNode* MinParent(BSTNode*) noexcept;
    BSTNode* MaxParent(BSTNode*) noexcept;

    BSTNode const* Find(const Data&) const noexcept;
    BSTNode const* FindParent(BSTNode*, const Data&) const noexcept;

    BSTNode const* MinParent(const BSTNode*) const noexcept;
    BSTNode const* MaxParent(const BSTNode*) const noexcept;
    
    virtual BSTNode* Left() override;
    virtual BSTNode const* Left() const override;
    virtual BSTNode* Right() override;
    virtual BSTNode const* Right() const override;

  public:
    using NodeLnk::HasLeftChild;
    using NodeLnk::HasRightChild;

    friend class BST<Data>;

  };

protected:

  // Accessory Functions
  Data const& Successor(BSTNode*, BSTNode*, const Data&);
  Data const& Predecessor(BSTNode*, BSTNode*, const Data&);

  Data const& Min(BSTNode*);
  Data const& Max(BSTNode*);

  BSTNode* DeleteMin(BSTNode*); // delete Min of a given tree
  BSTNode* RemoveRoot(BSTNode*);

  using typename SearchableContainer<Data>::MapFunctor;
  void MapBreadth  (MapFunctor, BSTNode*, void*);
  void MapPreOrder (MapFunctor, BSTNode*, void*);
  void MapInOrder  (MapFunctor, BSTNode*, void*);
  void MapPostOrder(MapFunctor, BSTNode*, void*);

  using typename SearchableContainer<Data>::FoldFunctor;
  void FoldBreadth  (FoldFunctor, const BSTNode*, const void*, void*) const;
  void FoldPreOrder (FoldFunctor, const BSTNode*, const void*, void*) const;
  void FoldInOrder  (FoldFunctor, const BSTNode*, const void*, void*) const;
  void FoldPostOrder(FoldFunctor, const BSTNode*, const void*, void*) const;

public:
  /* ************************************************************************ */

  // Default constructor
  BST() = default;

  // Copy constructor
  BST(const BST&);

  // Move constructor
  BST(BST&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~BST() = default;

  /* ************************************************************************ */

  // Copy assignment
  BST& operator=(const BST&);

  // Move assignment
  BST& operator=(BST&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BST&) const noexcept;
  bool operator!=(const BST&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  BSTNode& Root() override; // Override BinaryTree member (might throw std::length_error)
  BSTNode const& Root() const override;

  /* ************************************************************************ */

  // Specific member functions

  virtual void Insert(const Data&); // Copy of the value
  virtual void Insert(Data&&); // Move of the value
  virtual void Remove(const Data&);

  virtual Data const& Min(); // (might throw std::length_error)
  virtual Data MinNRemove(); // (might throw std::length_error)
  virtual void RemoveMin(); // (might throw std::length_error)
 
  virtual Data const& Max(); // (might throw std::length_error)
  virtual Data MaxNRemove(); // (might throw std::length_error)
  virtual void RemoveMax(); // (might throw std::length_error)
 
  virtual Data const& Predecessor(const Data&); // (might throw std::length_error)
  virtual Data PredecessorNRemove(const Data&); // (might throw std::length_error)
  virtual void RemovePredecessor(const Data&); // (might throw std::length_error)
 
  virtual Data const& Successor(const Data&); // (might throw std::length_error)
  virtual Data SuccessorNRemove(const Data&); // (might throw std::length_error)
  virtual void RemoveSuccessor(const Data&); // (might throw std::length_error)

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  bool Exists(const Data&) const noexcept override; // Override TestableContainer member

  void MapBreadth  (MapFunctor, void*) override;
  void MapPreOrder (MapFunctor, void*) override;
  void MapInOrder  (MapFunctor, void*) override;
  void MapPostOrder(MapFunctor, void*) override;

  void FoldBreadth  (FoldFunctor, const void*, void*) const override;
  void FoldPreOrder (FoldFunctor, const void*, void*) const override;
  void FoldInOrder  (FoldFunctor, const void*, void*) const override;
  void FoldPostOrder(FoldFunctor, const void*, void*) const override;
protected:

  BSTNode* Remove(BSTNode*, const Data&);
  BSTNode* RemoveMin(BSTNode*, BSTNode*); // Removes Min from a given tree and returns the Node to delete
  void RemoveMax(const BSTNode&);
};

}

/* ************************************************************************** */

#include "bst.cpp"

/* ************************************************************************** */

#endif
