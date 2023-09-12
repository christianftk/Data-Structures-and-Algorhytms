#ifndef CONTAINER_HPP
#define CONTAINER_HPP
#include <functional>

namespace lasd {

/* ************************************************************************** */

class Container {

private:

protected:
  unsigned long size = 0;

public:
  // Destructor
  virtual ~Container() = default;

  /* ************************************************************************ */

  // Copy assignment
  Container& operator=(const Container&) = delete; // Copy assignment of abstract types should not be possible.
  

  // Move assignment
  Container& operator=(Container &&) = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const Container&) = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const Container&) = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  // type Empty() specifiers;
  virtual bool Empty() const noexcept{
    return size==0;
  }
  // type Size() specifiers;
  virtual unsigned long Size() const noexcept{
    return size;
  }
  // type Clear() specifiers;
  virtual void Clear() = 0;
};

/* ************************************************************************** */

template <typename Data>
class LinearContainer : virtual public Container { // Should extend Container

private:

protected:

public:

  // Destructor
  virtual ~LinearContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  LinearContainer& operator=(const LinearContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  LinearContainer& operator=(LinearContainer&&) = delete ;  // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const LinearContainer&) = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const LinearContainer&) = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual Data& Front() const = 0;
  // type Back() specifiers;
  virtual Data& Back() const = 0;
  // type operator[](argument) specifiers;
  virtual Data& operator[](const unsigned long) const = 0;
};

/* ************************************************************************** */

template <typename Data>
class TestableContainer : virtual public Container{ // Should extend Container

private:

protected:

public:

  // Destructor
  virtual ~TestableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  TestableContainer& operator=(const TestableContainer&) = delete; // Copy assignment of abstract types should not be possible.
  // Move assignment
  TestableContainer& operator=(TestableContainer&&) = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const TestableContainer&) = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const TestableContainer&) = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual bool Exists(const Data&) const noexcept = 0;

};

/* ************************************************************************** */

template <typename Data>
class SearchableContainer : virtual public TestableContainer<Data>{ // Should extend TestableContainer<Data>

private:

protected:

public:

  // Destructor
  virtual ~SearchableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  SearchableContainer& operator=(const SearchableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  SearchableContainer& operator=(SearchableContainer&&) = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const SearchableContainer&) = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const SearchableContainer&) = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  // typedef void (*MapFunctor)(Data&, void*)  -- C version;
  typedef std::function<void(Data&, void*)> MapFunctor;  // -- C++ version
  virtual void MapPreOrder(MapFunctor, void*) = 0;
  virtual void MapPostOrder(MapFunctor, void*) = 0;

  // typedef void (*FoldFunctor)(const Data&, const void*, void*)  -- C version;
  typedef std::function<void(const Data&, const void*, void*)> FoldFunctor;  // -- C++ version
  virtual void FoldPreOrder(FoldFunctor, const void*, void*) const = 0;
  virtual void FoldPostOrder(FoldFunctor, const void*, void*) const = 0;

  virtual bool Exists(const Data&) const noexcept override; // Override TestableContainer member

};

/* ************************************************************************** */

template <typename Data>
class BreadthSearchableContainer : virtual public SearchableContainer<Data>{ // Should extend SearchableContainer<Data>

private:

protected:

public:

  // Destructor
  virtual ~BreadthSearchableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  BreadthSearchableContainer& operator=(const BreadthSearchableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  BreadthSearchableContainer& operator=(BreadthSearchableContainer&&) = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BreadthSearchableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const BreadthSearchableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  using typename SearchableContainer<Data>::MapFunctor;
  virtual void MapBreadth(MapFunctor, void*) = 0;

  using typename SearchableContainer<Data>::FoldFunctor;
  virtual void FoldBreadth(FoldFunctor, const void*, void*) const = 0;

};

/* ************************************************************************** */

#include "container.cpp"

}

#endif
