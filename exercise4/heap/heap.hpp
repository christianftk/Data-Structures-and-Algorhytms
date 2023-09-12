
#ifndef HEAP_HPP
#define HEAP_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../binarytree/vec/binarytreevec.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Heap : virtual public SearchableContainer<Data>, virtual protected BinaryTreeVec<Data>{ // Should extend SearchableContainer<Data> and BinaryTreeVec<Data>

private:

  // ...

protected:

  using BinaryTreeVec<Data>::size;

  using BinaryTreeVec<Data>::NodesAtLevel;

  using BinaryTreeVec<Data>::Tree;

  using typename BinaryTreeVec<Data>::NodeVec;

  void BuildTree(const lasd::LinearContainer<Data>&); // Funzione di appoggio per costruire un binvec a partire da una radice

  void BuildHeap(); //Rende heap l'albero in forma vettoriale Tree

  void Heapify(unsigned long);
  // ...

public:

  using BinaryTreeVec<Data>::DebugTree;
  // Default constructor
  Heap() = default;

  // Specific constructor
  Heap(const lasd::LinearContainer<Data>&); // Construct a heap from a LinearContainer

  // Copy constructor
  Heap(const Heap&);

  // Move constructor
  Heap(Heap&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~Heap() = default;

  /* ************************************************************************ */

  // Copy assignment
  Heap& operator=(const Heap&);

  // Move assignment
  Heap& operator=(Heap&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const Heap&) const noexcept;
  bool operator!=(const Heap&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  void Sort();

  /* ************************************************************************ */

  // Specific member functions (inherited from SearchableContainer)

  using typename SearchableContainer<Data>::MapFunctor;
  void MapPreOrder(MapFunctor, void*) override; // Override SearchableContainer member
  void MapPostOrder(MapFunctor, void*) override; // Override SearchableContainer member

  using typename SearchableContainer<Data>::FoldFunctor;
  void FoldPreOrder(FoldFunctor, const void*, void*) const override; // Override SearchableContainer member
  void FoldPostOrder(FoldFunctor, const void*, void*) const override; // Override SearchableContainer member

};

/* ************************************************************************** */

#include "heap.cpp"

}

#endif
