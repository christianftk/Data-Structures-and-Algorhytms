// NODEVEC

template <typename Data>
lasd::BinaryTreeVec<Data>::NodeVec::NodeVec(const Data& dat){
    data = dat;
}
template <typename Data>
lasd::BinaryTreeVec<Data>::NodeVec::NodeVec(Data&& dat) noexcept{
    std::swap(data, dat);
}
template <typename Data>
lasd::BinaryTreeVec<Data>::NodeVec::~NodeVec(){
    (*TreeRef)[pos] = nullptr;
    TreeRef = nullptr;
}

template <typename Data>
bool lasd::BinaryTreeVec<Data>::NodeVec::HasParent() const noexcept{
    if(pos != 0){
        return true;
    }
    return false;
}
template <typename Data>
bool lasd::BinaryTreeVec<Data>::NodeVec::HasLeftSibling() const noexcept{
    if(pos % 2 == 0){
        if((*TreeRef)[pos-1] != nullptr){
            return true;
        }
    }
    return false;
}
template <typename Data>
bool lasd::BinaryTreeVec<Data>::NodeVec::HasRightSibling() const noexcept{
    if(pos % 2 == 1){
        if((*TreeRef)[pos+1] != nullptr){
            return true;
        }
    }
    return false;
}
template <typename Data>
typename lasd::BinaryTreeVec<Data>::NodeVec& lasd::BinaryTreeVec<Data>::NodeVec::Parent() const{
    if(HasParent()){
        return (*(*TreeRef)[floor((pos-1)/2)]);
    }
    else{
        throw std::out_of_range("Out of range");
    }
}
template <typename Data>
typename lasd::BinaryTreeVec<Data>::NodeVec& lasd::BinaryTreeVec<Data>::NodeVec::LeftSibling() const{
    if(HasLeftSibling()){
        return (*(*TreeRef)[pos-1]);
    }
    else{
        throw std::out_of_range("Out of range");
    }
}
template <typename Data>
typename lasd::BinaryTreeVec<Data>::NodeVec& lasd::BinaryTreeVec<Data>::NodeVec::RightSibling() const{
    if(HasRightSibling()){
        return (*(*TreeRef)[pos+1]);
    }
    else{
        throw std::out_of_range("Out of range");
    }
}
template <typename Data>
Data& lasd::BinaryTreeVec<Data>::NodeVec::Element(){
    return data;
}
template <typename Data>
Data const& lasd::BinaryTreeVec<Data>::NodeVec::Element() const{
    return data;
}
template <typename Data>
bool lasd::BinaryTreeVec<Data>::NodeVec::IsLeaf() const noexcept{
    return !(HasLeftChild() || HasRightChild());
}
template <typename Data>
bool lasd::BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept{
    if((pos * 2 + 1) < TreeRef->Size()){
        if((*TreeRef)[pos * 2 + 1] != nullptr){
            return true;
        }
    }
    return false;
}
template <typename Data>
bool lasd::BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept{
    if((pos * 2 + 2) < TreeRef->Size()){
        if((*TreeRef)[pos * 2 + 2] != nullptr){
            return true;
        }
    }
    return false;
}
template <typename Data>
typename lasd::BinaryTreeVec<Data>::NodeVec& lasd::BinaryTreeVec<Data>::NodeVec::LeftChild(){
    if(HasLeftChild()){
        return (*(*TreeRef)[pos * 2 + 1]);
    }
    else{
        throw std::out_of_range("Out of range");
    }
}
template <typename Data>
typename lasd::BinaryTreeVec<Data>::NodeVec& lasd::BinaryTreeVec<Data>::NodeVec::RightChild(){
    if(HasRightChild()){
        return (*(*TreeRef)[pos * 2 + 2]);
    }
    else{
        throw std::out_of_range("Out of range");
    }
}
template <typename Data>
typename lasd::BinaryTreeVec<Data>::NodeVec const& lasd::BinaryTreeVec<Data>::NodeVec::LeftChild() const{
    if(HasLeftChild()){
        return (*(*TreeRef)[pos * 2 + 1]);
    }
    else{
        throw std::out_of_range("Out of range");
    }
}
template <typename Data>
typename lasd::BinaryTreeVec<Data>::NodeVec const& lasd::BinaryTreeVec<Data>::NodeVec::RightChild() const{
    if(HasRightChild()){
        return (*(*TreeRef)[pos * 2 + 2]);
    }
    else{
        throw std::out_of_range("Out of range");
    }
}

template <typename Data>
void lasd::BinaryTreeVec<Data>::NodeVec::DebugNod() const{
    std::cout << "\nDATA= " << data;
    std::cout << "\nPOS= " << pos;
    std::cout << "\nTREE= " << TreeRef;
}
template <typename Data>
void lasd::BinaryTreeVec<Data>::DebugTree() const{
    for(unsigned long i = 0; i < Tree.Size(); i++){
        std::cout << "\ni= "<< i;
        if(Tree[i] != nullptr){
            Tree[i]->DebugNod();
        }
    }
}
template <typename Data>
unsigned long lasd::BinaryTreeVec<Data>::NodeVec::Position() const{
    return pos;
}
// BINARYTREEVEC
// Constructors
template <typename Data>
lasd::BinaryTreeVec<Data>::BinaryTreeVec(){
    size = 0;
    Tree.Resize(7);
    NodesAtLevel.Resize(3);
    for(unsigned long i = 0; i < Tree.Size(); i++){
        Tree[i] = nullptr;
    }
    for(unsigned long i = 0; i < NodesAtLevel.Size(); i++){
        NodesAtLevel[i] = 0;
    }
}

template <typename Data>
lasd::BinaryTreeVec<Data>::~BinaryTreeVec(){
    RemoveTree(Root());
    delete Tree[0];
    NodesAtLevel.Clear();
    size = 0;
}
template <typename Data>
lasd::BinaryTreeVec<Data>::BinaryTreeVec(const Data& dat){
    NewRoot(dat);
}
template <typename Data>
lasd::BinaryTreeVec<Data>::BinaryTreeVec(Data&& dat) noexcept{
    NewRoot(dat);
}
template <typename Data>
lasd::BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec& yTree){
    size = yTree.Size();
    Tree.Resize(yTree.Tree.Size());
    NodesAtLevel.Resize(yTree.NodesAtLevel.Size());
    for(unsigned long i = 0; i < NodesAtLevel.Size(); i++){
        NodesAtLevel[i] = yTree.NodesAtLevel[i];
    }
    for(unsigned long i = 0; i < yTree.Tree.Size(); i++){
        if(yTree.Tree[i] != nullptr){
            Tree[i] = new NodeVec(yTree.Tree[i]->Element());
            Tree[i]->pos = i;
            Tree[i]->TreeRef = &Tree;
        }
        else{
            Tree[i] = nullptr;
        }
    }
}
template <typename Data>
lasd::BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec&& yTree) noexcept{
    std::swap(size, yTree.size);
    std::swap(Tree, yTree.Tree);
    std::swap(NodesAtLevel, yTree.NodesAtLevel);
}

// Operators
template <typename Data>
lasd::BinaryTreeVec<Data>& lasd::BinaryTreeVec<Data>::operator=(const BinaryTreeVec& yTree){
    BinaryTreeVec<Data>* tmp = new BinaryTreeVec<Data>(yTree);
    std::swap (*this, *tmp);
    delete tmp;
    return *this;
}
template <typename Data>
lasd::BinaryTreeVec<Data>& lasd::BinaryTreeVec<Data>::operator=(BinaryTreeVec&& yTree) noexcept{
    std::swap(size, yTree.size);
    std::swap(Tree, yTree.Tree);
    std::swap(NodesAtLevel, yTree.NodesAtLevel);
    return *this;
}

template <typename Data>
bool lasd::BinaryTreeVec<Data>::operator==(const BinaryTreeVec& yTree) const noexcept{
    bool equals = true;
    if(size == yTree.size){
        unsigned long i = 0;
        while(equals && i < size){
            if((Tree[i] != nullptr && yTree.Tree[i] == nullptr) || (Tree[i] == nullptr && yTree.Tree[i] != nullptr)){
                equals = false;
            }
            else if((Tree[i] != nullptr && yTree.Tree[i] != nullptr) && (Tree[i]->Element() != yTree.Tree[i]->Element())){
                equals = false;
            }
            i++;
        }
    }
    else 
        equals = false;
    return equals;
}

template <typename Data>
bool lasd::BinaryTreeVec<Data>::operator!=(const BinaryTreeVec& yTree) const noexcept{
    return !(*this == yTree);
}

// Specific member functions (inherited from BinaryTree)
template <typename Data>
typename lasd::BinaryTreeVec<Data>::NodeVec& lasd::BinaryTreeVec<Data>::Root(){
    if(size != 0){
        return *Tree[0];
    }
    else{
        throw std::length_error("Accessing unknwon location");
    }
}
template <typename Data>
typename lasd::BinaryTreeVec<Data>::NodeVec const& lasd::BinaryTreeVec<Data>::Root() const{
    if(size != 0){
        return *Tree[0];
    }
    else{
        throw std::length_error("Accessing unknwon location");
    }
}
template <typename Data>
void lasd::BinaryTreeVec<Data>::NewRoot(const Data& dat){
    size = 1;
    Tree.Clear();
    Tree.Resize(7);
    NodesAtLevel.Clear();
    NodesAtLevel.Resize(3);
    for(unsigned long i = 0; i < Tree.Size(); i++){
        Tree[i] = nullptr;
    }
    for(unsigned long i = 0; i < NodesAtLevel.Size(); i++){
        NodesAtLevel[i] = 0;
    }
    Tree[0] = new NodeVec(dat);
    Tree[0]->pos = 0;
    Tree[0]->TreeRef = &Tree;
    NodesAtLevel[0] += 1;
}
template <typename Data>
void lasd::BinaryTreeVec<Data>::NewRoot(Data&& dat){
    size = 1;
    Tree.Clear();
    Tree.Resize(7);
    NodesAtLevel.Clear();
    NodesAtLevel.Resize(3);
    for(unsigned long i = 0; i < Tree.Size(); i++){
        Tree[i] = nullptr;
    }
    for(unsigned long i = 0; i < NodesAtLevel.Size(); i++){
        NodesAtLevel[i] = 0;
    }
    Tree[0] = new NodeVec(dat);
    Tree[0]->pos = 0;
    Tree[0]->TreeRef = &Tree;
    NodesAtLevel[0] += 1;
}
template <typename Data>
void lasd::BinaryTreeVec<Data>::AddLeftChild(NodeVec& mRoot, const Data& dat){
    if(!mRoot.HasLeftChild()){
        if(mRoot.pos * 2 + 1 >= Tree.Size()){
            Expand();
        }
        Tree[mRoot.pos * 2 + 1] = new NodeVec(dat);
        Tree[mRoot.pos * 2 + 1]->pos = mRoot.pos * 2 + 1;
        Tree[mRoot.pos * 2 + 1]->TreeRef = &Tree;
        NodesAtLevel[floor(log2(mRoot.pos * 2 + 1))] += 1;
        size += 1;
    }
    else{
        mRoot.DebugNod();
        throw std::length_error("Can't access this area1");
    }
}
template <typename Data>
void lasd::BinaryTreeVec<Data>::AddLeftChild(NodeVec& mRoot, Data&& dat){
    if(!mRoot.HasLeftChild()){
        if(mRoot.pos * 2 + 1 >= Tree.Size()){
            Expand();
        }
        Tree[mRoot.pos * 2 + 1] = new NodeVec(dat);
        Tree[mRoot.pos * 2 + 1]->pos = mRoot.pos * 2 + 1;
        Tree[mRoot.pos * 2 + 1]->TreeRef = &Tree;
        NodesAtLevel[floor(log2(mRoot.pos * 2 + 1))] += 1;
        size += 1;
    }
    else{
        throw std::length_error("Can't access this area2");
    }
}
template <typename Data>
void lasd::BinaryTreeVec<Data>::AddRightChild(NodeVec& mRoot, const Data& dat){
    if(!mRoot.HasRightChild()){
        if(mRoot.pos * 2 + 2 >= Tree.Size()){
            Expand();
        }
        Tree[mRoot.pos * 2 + 2] = new NodeVec(dat);
        Tree[mRoot.pos * 2 + 2]->pos = mRoot.pos * 2 + 2;
        Tree[mRoot.pos * 2 + 2]->TreeRef = &Tree;
        NodesAtLevel[floor(log2(mRoot.pos * 2 + 1))] += 1;
        size += 1;
    }
    else{
        throw std::length_error("Can't access this area3");
    }
}
template <typename Data>
void lasd::BinaryTreeVec<Data>::AddRightChild(NodeVec& mRoot, Data&& dat){
    if(!mRoot.HasRightChild()){
        if(mRoot.pos * 2 + 2 >= Tree.Size()){
            Expand();
        }
        Tree[mRoot.pos * 2 + 2] = new NodeVec(dat);
        Tree[mRoot.pos * 2 + 2]->pos = mRoot.pos * 2 + 2;
        Tree[mRoot.pos * 2 + 2]->TreeRef = &Tree;
        NodesAtLevel[floor(log2(mRoot.pos * 2 + 1))] += 1;
        size += 1;
    }
    else{
        throw std::length_error("Can't access this area4");
    }
}
template <typename Data>
void lasd::BinaryTreeVec<Data>::RemoveLeftChild(NodeVec& mRoot){
    if(mRoot.HasLeftChild()){
        RemoveTree(mRoot.LeftChild());
        delete Tree[mRoot.LeftChild().pos];
        size -= 1;
        Tree[mRoot.pos * 2 + 1] = nullptr;
        NodesAtLevel[floor(log2(mRoot.pos * 2 + 1))] -= 1;
        if(NodesAtLevel[NodesAtLevel.Size() - 1] == 0 && NodesAtLevel[NodesAtLevel.Size() - 2] == 0 && NodesAtLevel.Size() > 3){
            Reduce();
        }
    }
}
template <typename Data>
void lasd::BinaryTreeVec<Data>::RemoveRightChild(NodeVec& mRoot){
    if(mRoot.HasRightChild()){
        RemoveTree(mRoot.RightChild());
        delete Tree[mRoot.RightChild().pos];
        size -= 1;
        Tree[mRoot.pos * 2 + 2] = nullptr;
        NodesAtLevel[floor(log2(mRoot.pos * 2 + 1))] -= 1;
        if(NodesAtLevel[NodesAtLevel.Size() - 1] == 0 && NodesAtLevel[NodesAtLevel.Size() - 2] == 0 && NodesAtLevel.Size() > 3){
            Reduce();
        }
    }
}
template <typename Data>
void lasd::BinaryTreeVec<Data>::RemoveTree(NodeVec& mRoot){
    if(mRoot.HasLeftChild()){
        RemoveTree(mRoot.LeftChild());
        delete Tree[mRoot.LeftChild().pos];
        Tree[mRoot.pos * 2 + 1] = nullptr;
        NodesAtLevel[floor(log2(mRoot.pos * 2 + 1))] -= 1; 
        size -= -1;
    }
    if(mRoot.HasRightChild()){
        RemoveTree(mRoot.RightChild());
        delete Tree[mRoot.RightChild().pos];
        Tree[mRoot.pos * 2 + 2] = nullptr;
        NodesAtLevel[floor(log2(mRoot.pos * 2 + 1))] -= 1; 
        size -= -1;
    }
}

template <typename Data>
void lasd::BinaryTreeVec<Data>::Clear(){
    NodesAtLevel.Clear();
    Tree.Clear();
    size = 0;
}

template <typename Data>
void lasd::BinaryTreeVec<Data>::MapBreadth(MapFunctor mf, void* par){
    for(unsigned long i = 0; i < Tree.Size(); i++){
        if(Tree[i] != nullptr){
            mf(Tree[i]->Element(), par);
        }
    }
}
template <typename Data>
void lasd::BinaryTreeVec<Data>::FoldBreadth(FoldFunctor ff, const void* par, void* acc) const{
    for(unsigned long i = 0; i < Tree.Size(); i++){
        if(Tree[i] != nullptr){
            ff(Tree[i]->Element(), par, acc);
        }
    }
}

template <typename Data>
void lasd::BinaryTreeVec<Data>::Expand(){
    unsigned long tmpsize = NodesAtLevel.Size();
    NodesAtLevel.Resize(NodesAtLevel.Size() + 2);
    for(unsigned long i = tmpsize; i < NodesAtLevel.Size(); i++){
        NodesAtLevel[i] = 0;
    }
    tmpsize = Tree.Size();
    Tree.Resize(pow(2, NodesAtLevel.Size()) - 1);
    for(unsigned long i = tmpsize; i < Tree.Size(); i++){
        Tree[i] = nullptr;
    }
}
template <typename Data>
void lasd::BinaryTreeVec<Data>::Reduce(){
    NodesAtLevel.Resize(NodesAtLevel.Size() - 2);
    Tree.Resize(pow(2, NodesAtLevel.Size()) - 1);
}


