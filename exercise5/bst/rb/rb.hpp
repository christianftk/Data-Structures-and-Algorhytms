
#ifndef RB_HPP
#define RB_HPP

/* ************************************************************************** */

#include "../bst.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class RB : virtual public BST<Data> {

private:

  // ...

protected:

  using BST<Data>::size;
  using BST<Data>::root;

  // ...

public:
  using typename BST<Data>::BSTNode;
  using typename BST<Data>::NodeLnk;

  enum class Color {red, black, double_black};

  struct RBNode : public BSTNode{ // Should extend BSTNode
  
  protected:
    using BSTNode::left;
    using BSTNode::right;

    Color color = Color::red;
    
  public:
    using NodeLnk::HasLeftChild;
    using NodeLnk::HasRightChild;


    RBNode* Left() override;
    RBNode const* Left() const override;
    RBNode* Right() override;
    RBNode const* Right() const override;

    std::string getColor();
    friend class RB<Data>;
  
    // ...

  };
protected:

  void TreeLnkCopy(const RBNode*, RBNode*);

  // Accessory Functions
  RBNode* Insert(RBNode*, const Data&);
  RBNode* Insert(RBNode*, Data&&);
  RBNode* Remove(RBNode*, const Data&);
  RBNode* RemoveRoot(RBNode*);
  RBNode* RemoveMin(RBNode*, RBNode*);
  RBNode* Rotate_sx(RBNode*);
  RBNode* Rotate_dx(RBNode*);

  // Accessory Functions - Insert
  short Violation_On_Insert_sx(RBNode*, RBNode*);

  RBNode* Bilancia_Insert_sx(RBNode*);
  RBNode* Bilancia_Insert_sx_1(RBNode*);
  RBNode* Bilancia_Insert_sx_2(RBNode*);
  RBNode* Bilancia_Insert_sx_3(RBNode*);

  short Violation_On_Insert_dx(RBNode*, RBNode*);
  
  RBNode* Bilancia_Insert_dx(RBNode*);
  RBNode* Bilancia_Insert_dx_1(RBNode*);
  RBNode* Bilancia_Insert_dx_2(RBNode*);
  RBNode* Bilancia_Insert_dx_3(RBNode*);

  // Accessory Functions - Remove

  void Propagate_Black(RBNode*);

  short Violation_On_Delete_sx(RBNode*, RBNode*);

  RBNode* Bilancia_Delete_sx(RBNode*);
  RBNode* Bilancia_Delete_sx_1(RBNode*);
  RBNode* Bilancia_Delete_sx_2(RBNode*);
  RBNode* Bilancia_Delete_sx_3(RBNode*);
  RBNode* Bilancia_Delete_sx_4(RBNode*);

  short Violation_On_Delete_dx(RBNode*, RBNode*);
  
  RBNode* Bilancia_Delete_dx(RBNode*);
  RBNode* Bilancia_Delete_dx_1(RBNode*);
  RBNode* Bilancia_Delete_dx_2(RBNode*);
  RBNode* Bilancia_Delete_dx_3(RBNode*);
  RBNode* Bilancia_Delete_dx_4(RBNode*);

  RBNode* DeleteMin(RBNode*);
  RBNode* DeleteMax(RBNode*);
  /* ************************************************************************ */


public:

  // Default constructor
  RB() = default;

  // Copy constructor
  RB(const RB&);

  // Move constructor
  RB(RB&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~RB() = default;

  /* ************************************************************************ */

  // Copy assignment
  RB& operator=(const RB&);

  // Move assignment
  RB& operator=(RB&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const RB&) const noexcept;
  bool operator!=(const RB&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  RBNode& Root() override; // Override BinaryTree member (might throw std::length_error)
  RBNode const& Root() const override; // Override BinaryTree member (might throw std::length_error)
  void NewRoot(const Data&) override; // Override BinaryTree member (Move of the value)
  void NewRoot(Data&&) noexcept override; // Override BinaryTree member (Copy of the value)

  /* ************************************************************************ */

  // Specific member functions

  void Insert(const Data&) override;
  void Insert(Data&&) override;
  void Remove(const Data&) override;

  Data MinNRemove() override;
  void RemoveMin() override;

  Data MaxNRemove() override;
  void RemoveMax() override;

  /* ************************************************************************ */

};

}


#include "rb.cpp"

/* ************************************************************************** */

#endif
