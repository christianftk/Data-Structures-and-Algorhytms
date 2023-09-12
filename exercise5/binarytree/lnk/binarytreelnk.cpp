// NODELNK
// Specific member functions (inherited from Node)
template <typename Data>
typename lasd::BinaryTreeLnk<Data>::NodeLnk* lasd::BinaryTreeLnk<Data>::NodeLnk::Left(){
    return (NodeLnk*)left;
}
template <typename Data>
typename lasd::BinaryTreeLnk<Data>::NodeLnk const* lasd::BinaryTreeLnk<Data>::NodeLnk::Left() const{
    return (NodeLnk*)left;
}
template <typename Data>
typename lasd::BinaryTreeLnk<Data>::NodeLnk* lasd::BinaryTreeLnk<Data>::NodeLnk::Right(){
    return (NodeLnk*)right;
}
template <typename Data>
typename lasd::BinaryTreeLnk<Data>::NodeLnk const* lasd::BinaryTreeLnk<Data>::NodeLnk::Right() const{
    return (NodeLnk*)right;
}

template <typename Data>
lasd::BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const Data& dat){
    data = dat;
    left = nullptr;
    right = nullptr;
}
template <typename Data>
lasd::BinaryTreeLnk<Data>::NodeLnk::NodeLnk(Data&& dat) noexcept{
    data = std::move(dat);
    left = nullptr;
    right = nullptr;
}

template <typename Data>
Data& lasd::BinaryTreeLnk<Data>::NodeLnk::Element(){
    return data;
}
template <typename Data>
Data const& lasd::BinaryTreeLnk<Data>::NodeLnk::Element() const{
    return data;
}

template <typename Data>
bool lasd::BinaryTreeLnk<Data>::NodeLnk::IsLeaf() const noexcept{ 
    return !(HasLeftChild() || HasRightChild());
}
template <typename Data>
bool lasd::BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() const noexcept{
    return left != nullptr;
}
template <typename Data>
bool lasd::BinaryTreeLnk<Data>::NodeLnk::HasRightChild() const noexcept{
    return right != nullptr;
}

template <typename Data>
typename lasd::BinaryTreeLnk<Data>::NodeLnk const& lasd::BinaryTreeLnk<Data>::NodeLnk::LeftChild() const{
    if(left != nullptr){
        return *left;
    }
    else{
        throw std::out_of_range("Out of range");
    }
}
template <typename Data>
typename lasd::BinaryTreeLnk<Data>::NodeLnk const& lasd::BinaryTreeLnk<Data>::NodeLnk::RightChild() const{
    if(right != nullptr){
        return *right;
    }else{
        throw std::out_of_range("Out of range");
    }
}
template <typename Data>
typename lasd::BinaryTreeLnk<Data>::NodeLnk& lasd::BinaryTreeLnk<Data>::NodeLnk::LeftChild(){
    if(left != nullptr){
        return *left;
    }
    else{
        throw std::out_of_range("Out of range");
    }
}
template <typename Data>
typename lasd::BinaryTreeLnk<Data>::NodeLnk& lasd::BinaryTreeLnk<Data>::NodeLnk::RightChild(){
    if(right != nullptr){
        return *right;
    }else{
        throw std::out_of_range("Out of range");
    }
}
// BINARYTREELNK
template <typename Data>
lasd::BinaryTreeLnk<Data>::BinaryTreeLnk(const Data& dat) {
    NewRoot(dat);
}
template <typename Data>
lasd::BinaryTreeLnk<Data>::BinaryTreeLnk(Data&& dat) {
    NewRoot(dat);
}

template <typename Data>
lasd::BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk& yTree){
    if(yTree.Size() != 0){
        NewRoot(yTree.Root().Element());
        TreeLnkCopy(yTree.Root(), Root());
        size = yTree.Size();
    }
}
template <typename Data>
lasd::BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk&& yTree){
    std::swap(root, yTree.root);
    std::swap(size, yTree.size);
}
template <typename Data>
void lasd::BinaryTreeLnk<Data>::TreeLnkCopy(const NodeLnk& src, NodeLnk& dest){
    if(src.HasLeftChild()){
        dest.left = new NodeLnk(src.LeftChild().Element());
        TreeLnkCopy(src.LeftChild() , dest.LeftChild());
    }
    if(src.HasRightChild()){
        dest.right = new NodeLnk(src.RightChild().Element());
        TreeLnkCopy(src.RightChild(), dest.RightChild());
    }
}
template <typename Data>
lasd::BinaryTreeLnk<Data>::~BinaryTreeLnk(){
    if(size > 0){
        Clear();
    }
}

template <typename Data>
lasd::BinaryTreeLnk<Data>& lasd::BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk& yTree){
    BinaryTreeLnk<Data>* tmp = new BinaryTreeLnk<Data>(yTree);
    std::swap(*this, *tmp);
    delete tmp;
    return *this;
}
template <typename Data>
lasd::BinaryTreeLnk<Data>& lasd::BinaryTreeLnk<Data>::operator=(BinaryTreeLnk&& yTree){
    std::swap(root, yTree.root);
    std::swap(size, yTree.size);
    return *this;
}
template <typename Data>
bool lasd::BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk& yTree) const noexcept{
    if(size == yTree.Size() && size > 0){
        return treeCompare(Root(), yTree.Root());
    }
    else{
        return false;
    }
}
template <typename Data>
bool lasd::BinaryTreeLnk<Data>::treeCompare(const NodeLnk& mRoot,const NodeLnk& yRoot) const noexcept{
    if((mRoot.HasLeftChild() != yRoot.HasLeftChild()) || (mRoot.HasRightChild() != yRoot.HasRightChild())){
        return false;
    }
    else{
        if(mRoot.Element() == yRoot.Element()){
            if(mRoot.HasLeftChild()){
                return treeCompare(mRoot.LeftChild(), yRoot.LeftChild());
            }
            if(mRoot.HasRightChild()){
                return treeCompare(mRoot.RightChild(), yRoot.RightChild());
            }
            return true;
        }
        else{
            return false;
        }
    }
}
template <typename Data>
bool lasd::BinaryTreeLnk<Data>::operator!=(const BinaryTreeLnk& yTree) const noexcept{
    return !(*this == yTree);
}

// Specific member functions (inherited from BinaryTree)
template <typename Data>
typename lasd::BinaryTreeLnk<Data>::NodeLnk const& lasd::BinaryTreeLnk<Data>::Root() const{
    if(root != nullptr){
        return *root;
    }
    else{
        throw std::length_error("Accessing unknown location");
    }
}
template <typename Data>
typename lasd::BinaryTreeLnk<Data>::NodeLnk& lasd::BinaryTreeLnk<Data>::Root(){
    if(root != nullptr){
        return *root;
    }
    else{
        throw std::length_error("Accessing unknown location");
    }
}
template <typename Data>
void lasd::BinaryTreeLnk<Data>::NewRoot(const Data& dat){
    if(root != nullptr){
        Clear();
    }
    root = new NodeLnk(dat);
    size = 1;
}
template <typename Data>
void lasd::BinaryTreeLnk<Data>::NewRoot(Data&& dat){
    if(root != nullptr){
        Clear();
    }
    root = new NodeLnk(dat);
    size = 1;
}

template <typename Data>
void lasd::BinaryTreeLnk<Data>::AddLeftChild(NodeLnk& mNode,const Data& dat){
    if(!mNode.HasLeftChild()){
        mNode.left = new NodeLnk(dat);
        size += 1;
    }
    else{
        throw std::length_error("Can't access this area");
    }
}
template <typename Data>
void lasd::BinaryTreeLnk<Data>::AddLeftChild(NodeLnk& mNode,Data&& dat){
    if(!mNode.HasLeftChild()){
        mNode.left = new NodeLnk(dat);
        size += 1;
    }
    else{
        throw std::length_error("Can't access this area");
    }
}
template <typename Data>
void lasd::BinaryTreeLnk<Data>::AddRightChild(NodeLnk& mNode,const Data& dat){
    if(!mNode.HasRightChild()){
        mNode.right = new NodeLnk(dat);
        size += 1;
    }
    else{
        throw std::length_error("Can't access this area");
    }
}
template <typename Data>
void lasd::BinaryTreeLnk<Data>::AddRightChild(NodeLnk& mNode,Data&& dat){
    if(!mNode.HasRightChild()){
        mNode.right = new NodeLnk(dat);
        size += 1;
    }
    else{
        throw std::length_error("Can't access this area");
    }
}
template <typename Data>
unsigned long lasd::BinaryTreeLnk<Data>::NodesCount(const NodeLnk& mRoot) const noexcept {
  unsigned long x = 0;
  unsigned long y = 0;
  if(mRoot.right != nullptr){
    x = NodesCount(mRoot.RightChild());
  }
  if(mRoot.left != nullptr){
    y = NodesCount(mRoot.LeftChild());
  }
  return (x+y+1);
}
template <typename Data>
void lasd::BinaryTreeLnk<Data>::RemoveTree(NodeLnk* mRoot){
    if(mRoot->left != nullptr){
        RemoveTree(mRoot->left);
    }
    if(mRoot->right != nullptr){
        RemoveTree(mRoot->right);
    }
    size--;
    mRoot->left = nullptr;
    mRoot->right = nullptr;
    delete mRoot;
}
template <typename Data>
void lasd::BinaryTreeLnk<Data>::RemoveLeftChild(NodeLnk& mRoot){
    if(mRoot.left != nullptr){
        RemoveTree(mRoot.left);
        mRoot.left = nullptr;
    }
}
template <typename Data>
void lasd::BinaryTreeLnk<Data>::RemoveRightChild(NodeLnk& mRoot){
    if(mRoot.right != nullptr){
        RemoveTree(mRoot.right);
        mRoot.right = nullptr;
    }
}

template <typename Data>
void lasd::BinaryTreeLnk<Data>::Clear(){
    if(size > 0){
        RemoveTree(root);
        size = 0;
    }
}
