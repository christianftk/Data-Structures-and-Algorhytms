
#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

/* ************************************************************************** */

#include "../heap/heap.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class PriorityQueue : virtual public Heap<Data> {

private:

  // ...

protected:

  using typename Heap<Data>::NodeVec;

  using Heap<Data>::Tree;
  
  using Heap<Data>::size;

  using Heap<Data>::NodesAtLevel;

  using BinaryTreeVec<Data>::NewRoot;

  using Heap<Data>::AddLeftChild;

  using Heap<Data>::AddRightChild;
  
  // ...

public:
  using BinaryTreeVec<Data>::DebugTree;

  // Default constructor
  PriorityQueue() = default;

  // Specific constructor
  PriorityQueue(const LinearContainer<Data>&); // Construct a priority queue from a LinearContainer

  // Copy constructor
  PriorityQueue(const PriorityQueue&);

  // Move constructor
  PriorityQueue(PriorityQueue&&);

  /* ************************************************************************ */

  // Destructor
  virtual ~PriorityQueue() = default;

  /* ************************************************************************ */

  // Copy assignment
  PriorityQueue& operator=(const PriorityQueue&);

  // Move assignment
  PriorityQueue& operator=(PriorityQueue&&);

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const PriorityQueue&) const noexcept;
  bool operator!=(const PriorityQueue&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  using BinaryTreeVec<Data>::Root;

  Data const& Tip() const; // (might throw std::length_error)
  void RemoveTip(); // (might throw std::length_error)
  Data TipNRemove(); // (might throw std::length_error)
  void Insert(const  Data&); // Copy of the value
  void Insert(Data&&); // Move of the value

  void ChangePriority(NodeVec&, const Data&); // Change priority of a Node (Copy of the value)
  void ChangePriority(NodeVec&, Data&&); // Change priority of a Node (Move of the value)

};

/* ************************************************************************** */

#include "priorityqueue.cpp"

}

#endif
