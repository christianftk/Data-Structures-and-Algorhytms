
namespace lasd {

template <typename Data>
long AVL<Data>::h(AVLNode* nod){
    if(nod == nullptr){
        return 0;
    }
    else{
        return nod->height;
    }
}
template <typename Data>
long AVL<Data>::is_Balanced(AVLNode* nod){
    if(nod == nullptr){
        return 0;
    }
    else{
        return h(nod->Left()) - h(nod->Right());
    }
}
template <typename Data>
long AVL<Data>::MaxSubTree(AVLNode* nod){
    if(h(nod->Left()) >= h(nod->Right())){
        return h(nod->Left());
    }
    else{
        return h(nod->Right());
    }
}
template <typename Data>
bool AVL<Data>::is_SS(AVLNode* nod){
    return h(nod->Left()) > h(nod->Right());
}
template <typename Data>
bool AVL<Data>::is_SD(AVLNode* nod){
    return h(nod->Right()) > h(nod->Left());
}

template <typename Data>
typename AVL<Data>::AVLNode* AVL<Data>::Rotate_SS(AVLNode* nod){
    if(nod != nullptr){
        AVL<Data>::AVLNode* nRoot = nod->Left();
        if(nRoot != nullptr){
            nod->left = (NodeLnk*)nRoot->Right();
            nRoot->right = (NodeLnk*)nod;
            nod->height = 1 + MaxSubTree(nod);
            nRoot->height = 1 + MaxSubTree(nRoot);
            nod = nRoot;
        }
    }
    return nod;
}
template <typename Data>
typename AVL<Data>::AVLNode* AVL<Data>::Rotate_DS(AVLNode* nod){
    nod->left = (NodeLnk*)Rotate_SD(nod->Left());
    return Rotate_SS(nod);
}
template <typename Data>
typename AVL<Data>::AVLNode* AVL<Data>::Rotate_SD(AVLNode* nod){
    if(nod != nullptr){
        AVL<Data>::AVLNode* nRoot = nod->Right();
        if(nRoot != nullptr){
            nod->right = (NodeLnk*)nRoot->Left();
            nRoot->left = (NodeLnk*)nod;
            nod->height = 1 + MaxSubTree(nod);
            nRoot->height = 1 + MaxSubTree(nRoot);
            nod = nRoot;
        }
    }
    return nod;
}
template <typename Data>
typename AVL<Data>::AVLNode* AVL<Data>::Rotate_DD(AVLNode* nod){
    nod->right = (NodeLnk*)Rotate_SS(nod->Right());
    return Rotate_SD(nod);
}

template <typename Data>
typename AVL<Data>::AVLNode* AVL<Data>::Bilancia_sx(AVLNode* nod){
//    std::cout << "\nchecking nod with height = " << nod->height << "\n" ;
    if(is_Balanced(nod) == 2){
        if(is_SS(nod->Left())){
            nod = Rotate_SS(nod);
        }
        else{
            nod = Rotate_DS(nod);
        }
    }
    else{
        nod->height = 1 + (h(nod->Left())> h(nod->Right()) ? h(nod->Left()) : h(nod->Right()));
    }
    return nod;
}
template <typename Data>
typename AVL<Data>::AVLNode* AVL<Data>::Bilancia_dx(AVLNode* nod){
    if(is_Balanced(nod) == -2){
        if(is_SD(nod->Right())){
            nod = Rotate_SD(nod);
        }
        else{
            nod = Rotate_DD(nod);
        }
    }
    else{
        nod->height = 1 + (h(nod->Left())> h(nod->Right()) ? h(nod->Left()) : h(nod->Right()));
    }
    return nod;
}

template <typename Data>
typename AVL<Data>::AVLNode* AVL<Data>::AVLNode::Left(){
    return (AVLNode*)left;
}
template <typename Data>
typename AVL<Data>::AVLNode const* AVL<Data>::AVLNode::Left() const{
    return (AVLNode*)left;
}
template <typename Data>
typename AVL<Data>::AVLNode* AVL<Data>::AVLNode::Right(){
    return (AVLNode*)right;
}
template <typename Data>
typename AVL<Data>::AVLNode const* AVL<Data>::AVLNode::Right() const{
    return (AVLNode*)right;
}

/* ************************************************************************** */

template <typename Data>
AVL<Data>::AVL(const AVL& yTree){
    if(yTree.size != 0){
        NewRoot(yTree.Root().Element());
        TreeLnkCopy(&(yTree.Root()), &Root());
        size = yTree.Size();
    }
}
template <typename Data>
void AVL<Data>::TreeLnkCopy(const AVLNode* src, AVLNode* dest){
    if(src->HasLeftChild()){
        dest->left = new NodeLnk(src->Left()->Element());
        dest->Left()->color = src->Left()->color;
        TreeLnkCopy(src->Left() , dest->Left());
    }
    if(src->HasRightChild()){
        dest->right = new NodeLnk(src->Right()->Element());
        dest->Right()->color = src->Right()->color;
        TreeLnkCopy(src->Right(), dest->Right());
    }
}
template <typename Data>
AVL<Data>::AVL(AVL&& yTree) noexcept : BinaryTreeLnk<Data>(std::move(yTree)){

}
template <typename Data>
AVL<Data>& AVL<Data>::operator=(const AVL& yTree){
    AVL<Data>* tmp = new AVL<Data>(yTree);
    std::swap(*this, *tmp);
    delete tmp;
    return *this;
}
template <typename Data>
AVL<Data>& AVL<Data>::operator=(AVL&& yTree) noexcept{
    std::swap(root, yTree.root);
    std::swap(size, yTree.size);
    return *this;
}
template <typename Data>
bool AVL<Data>::operator==(const AVL& yTree) const noexcept{
    return BST<Data>::operator==(yTree);
}
template <typename Data>
bool AVL<Data>::operator!=(const AVL& yTree) const noexcept{
    return !(*this == yTree);
}
template <typename Data>
typename AVL<Data>::AVLNode& AVL<Data>::Root(){
    if(root != nullptr){
        return *(AVL<Data>::AVLNode*)root;    
    }
    else{
        throw std::length_error("No Root");
    }
}
template <typename Data>
typename AVL<Data>::AVLNode const& AVL<Data>::Root() const{
    if(root != nullptr){
        return *(AVL<Data>::AVLNode*)root;    
    }
    else{
        throw std::length_error("No Root");
    }
}
template <typename Data>
void AVL<Data>::NewRoot(const Data& dat){
    BinaryTreeLnk<Data>::NewRoot(dat);
    Root().height = 1;
}
template <typename Data>
void AVL<Data>::NewRoot(Data&& dat) noexcept{
    BinaryTreeLnk<Data>::NewRoot(dat);
    Root().height = 1;
}
template <typename Data>
void AVL<Data>::Insert(const Data& dat){
    if(size != 0){
        root = Insert(&Root(), dat);
        size++;
    }
    else{
        NewRoot(dat);
    }
}
template <typename Data>
void AVL<Data>::Insert(Data&& dat){
    if(size != 0){
        root = Insert(&Root(), dat);
        size++;
    }
    else{
        NewRoot(dat);
    }
}
template <typename Data>
typename AVL<Data>::AVLNode* AVL<Data>::Insert(AVLNode* nod, const Data& dat){
    if(nod != nullptr){
        if(nod->Element() < dat){
            nod->right = (NodeLnk*)Insert(nod->Right(), dat);
            nod = Bilancia_dx(nod);
        }
        else if(nod->Element() > dat){
            nod->left = (NodeLnk*)Insert(nod->Left(), dat);
            nod = Bilancia_sx(nod);
        }
    }
    else{
        nod = (AVLNode*)new NodeLnk(dat);
        nod->height = 1;
    }
    return nod;
}
template <typename Data>
typename AVL<Data>::AVLNode* AVL<Data>::Insert(AVLNode* nod, Data&& dat){
    if(nod != nullptr){
        if(nod->Element() < dat){
            nod->right = (NodeLnk*)Insert(nod->Right(), dat);
            nod = Bilancia_dx(nod);
        }
        else if(nod->Element() > dat){
            nod->left = (NodeLnk*)Insert(nod->Left(), dat);
            nod = Bilancia_sx(nod);
        }
    }
    else{
        nod = (AVLNode*)new NodeLnk(dat);
        nod->height = 1;
    }
    return nod;
}
template <typename Data>
void AVL<Data>::Remove(const Data& dat){
    if(size > 1){
        root = Remove(&Root(),dat);
        size--;
    }
    else if(size == 1){
        delete root;
        root = nullptr;
        size--;
    }
    else{
        throw std::length_error("No Tree");
    }
}

template <typename Data>
typename AVL<Data>::AVLNode* AVL<Data>::Remove(AVLNode* nod, const Data& dat){
    if(nod != nullptr){
        if(nod->Element() > dat){
            nod->left = (NodeLnk*)Remove(nod->Left(), dat);
            nod = Bilancia_dx(nod);
        }
        else if(nod->Element() < dat){
            nod->right = (NodeLnk*)Remove(nod->Right(), dat);
            nod = Bilancia_sx(nod);
        }
        else {
            nod = RemoveRoot(nod);
        }
    }
    else{
        size++; // No dat found so it's necessary to increment size by 1 to balance the decrement at the end of the remove
    }
    return nod;
}

template <typename Data>
typename AVL<Data>::AVLNode* AVL<Data>::RemoveMin(AVLNode* nod, AVLNode* parent){
    AVL<Data>::AVLNode* ret = nullptr;
    AVL<Data>::AVLNode* newRoot = nullptr;
    if(nod != nullptr){
        if(nod->HasLeftChild()){
            ret = RemoveMin(nod->Left(), nod);
            newRoot = Bilancia_dx(nod);
        }
        else{
            ret = nod;
            newRoot = nod->Right();
        }
    }
    if(parent->left == nod){
        parent->left = newRoot;
    }
    else{
        parent->right = newRoot;
    }
    return ret;
}
template <typename Data>
typename AVL<Data>::AVLNode* AVL<Data>::RemoveRoot(AVLNode* nod){
    if(nod != nullptr){
        AVL<Data>::AVLNode* tmp;
        if(nod->HasLeftChild() && nod->HasRightChild()){
            tmp = RemoveMin(nod->Right(), nod);
            nod->Element() = tmp->Element();
        }
        else{
            tmp = nod;
            if(nod->HasRightChild()){
                nod = nod->Right();    
            }
            else if(nod->HasLeftChild()){
                nod = nod->Left();
            }
            else{
                nod = nullptr;
            }
        }
        delete tmp;
    }
    return nod;
}

template <typename Data>
Data AVL<Data>::MinNRemove(){
    if(size > 0){
        Data dat = this->Min();
        root = DeleteMin(&Root());
        size--;
        return dat;
    }
    else{
        throw std::length_error("Tree is empty");
    }
}
template <typename Data>
void AVL<Data>::RemoveMin(){
    if(size > 0){
        root = DeleteMin(&Root());
        size--;
    }
    else{
        throw std::length_error("Tree is empty");
    }
}

template <typename Data>
typename AVL<Data>::AVLNode* AVL<Data>::DeleteMin(AVLNode* nod){
    if(nod->Left() != nullptr){
        nod->left = (NodeLnk*)DeleteMin(nod->Left());
        nod = Bilancia_dx(nod);
    }
    else{
        nod = RemoveRoot(nod);
    }
    return nod;
}

template <typename Data>
Data AVL<Data>::MaxNRemove(){
    if(size > 0){
        Data dat = this->Max();
        root = DeleteMax(&Root());
        size--;
        return dat;
    }
    else{
        throw std::length_error("Tree is empty");
    }
}
template <typename Data>
void AVL<Data>::RemoveMax(){
    if(size > 0){
        root = DeleteMax(&Root());
        size--;
    }
    else{
        throw std::length_error("Tree is empty");
    }
}
template <typename Data>
typename AVL<Data>::AVLNode* AVL<Data>::DeleteMax(AVLNode* nod){
    if(nod->Right() != nullptr){
        nod->right = (NodeLnk*)DeleteMax(nod->Right());
        nod = Bilancia_sx(nod);
    }
    else{
        nod = RemoveRoot(nod);
    }
    return nod;
}

/* ************************************************************************** */

/* template <typename Data>
void lasd::AVL<Data>::MapInOrder(MapFunctor mf, void* par){
    if(size > 0)
        MapInOrder(mf, &Root(), par);
}

template <typename Data>
void lasd::AVL<Data>::MapPreOrder(MapFunctor mf, void* par){
    if(size > 0)
        MapPreOrder(mf, &Root(), par);
}
template <typename Data>
void lasd::AVL<Data>::MapPostOrder(MapFunctor mf, void* par){
    if(size > 0)
        MapPostOrder(mf, &Root(), par);
}

template <typename Data>
void lasd::AVL<Data>::MapBreadth(MapFunctor mf, void* par){
    if(size > 0)
        MapBreadth(mf, &Root(), par);
}

template <typename Data>
void lasd::AVL<Data>::FoldInOrder(FoldFunctor ff, const void* par, void* acc) const{
    if(size > 0)
        FoldInOrder(ff, &Root(), par, acc);
}
template <typename Data>
void lasd::AVL<Data>::FoldPreOrder(FoldFunctor ff, const void* par, void* acc) const{
    if(size > 0)
        FoldPreOrder(ff, &Root(), par, acc);
}
template <typename Data>
void lasd::AVL<Data>::FoldPostOrder(FoldFunctor ff, const void* par, void* acc) const{
    if(size > 0)
        FoldPostOrder(ff, &Root(), par, acc);
}
template <typename Data>
void lasd::AVL<Data>::FoldBreadth(FoldFunctor ff, const void* par, void* acc) const{
    if(size > 0)
        FoldBreadth(ff, &Root(), par, acc);
}


template <typename Data>
void lasd::AVL<Data>::MapInOrder(MapFunctor mf, AVLNode* curr, void* par){
    if(curr != nullptr){
        MapInOrder(mf, curr->Left(), par);
        mf(curr->Element(), par);
        MapInOrder(mf, curr->Right(), par);
    }
}

template <typename Data>
void lasd::AVL<Data>::MapPreOrder(MapFunctor mf, AVLNode* curr, void* par){
    if(curr != nullptr){
        mf(curr->Element(), par);
        MapInOrder(mf, curr->Left(), par);
        MapInOrder(mf, curr->Right(), par);
    }
}
template <typename Data>
void lasd::AVL<Data>::MapPostOrder(MapFunctor mf, AVLNode* curr, void* par){
    if(curr != nullptr){
        MapInOrder(mf, curr->Left(), par);
        MapInOrder(mf, curr->Right(), par);
        mf(curr->Element(), par);
    }
}

template <typename Data>
void lasd::AVL<Data>::MapBreadth(MapFunctor mf, AVLNode* curr, void* par){
    if(curr != nullptr){
        lasd::QueueLst<AVLNode*> mQueue;
        mQueue.Enqueue(curr);
        AVLNode* tmp;
        while(!mQueue.Empty()){
            tmp = mQueue.HeadNDequeue();
            mf(tmp->Element(), par);
            if(tmp->HasLeftChild()){
                mQueue.Enqueue(tmp->Left());
            }
            if(tmp->HasRightChild()){
                mQueue.Enqueue(tmp->Right());
            }
        }
    }
}

template <typename Data>
void lasd::AVL<Data>::FoldInOrder(FoldFunctor ff, const AVLNode* curr, const void* par, void* acc) const{
    if(curr != nullptr){
        FoldPostOrder(ff, curr->Left(), par, acc);
        ff(curr->Element(), par, acc);
        FoldPostOrder(ff, curr->Right(), par, acc);
    }
}
template <typename Data>
void lasd::AVL<Data>::FoldPreOrder(FoldFunctor ff, const AVLNode* curr, const void* par, void* acc) const{
    if(curr != nullptr){
        ff(curr->Element(), par, acc);
        FoldPostOrder(ff, curr->Left(), par, acc);
        FoldPostOrder(ff, curr->Right(), par, acc);
    }
}
template <typename Data>
void lasd::AVL<Data>::FoldPostOrder(FoldFunctor ff, const AVLNode* curr, const void* par, void* acc) const{
    if(curr != nullptr){
        FoldPostOrder(ff, curr->Left(), par, acc);
        FoldPostOrder(ff, curr->Right(), par, acc);
        ff(curr->Element(), par, acc);
    }
}
template <typename Data>
void lasd::AVL<Data>::FoldBreadth(FoldFunctor ff, const AVLNode* curr, const void* par, void* acc) const{
    lasd::QueueVec<const AVLNode*> mQueue;
    mQueue.Enqueue(curr);
    const AVLNode* tmp;
    while(!mQueue.Empty()){
        tmp = mQueue.HeadNDequeue();
        ff(tmp->Element(), par, acc);
        if(tmp->HasLeftChild()){
            mQueue.Enqueue(tmp->Left());
        }
        if(tmp->HasRightChild()){
            mQueue.Enqueue(tmp->Right());
        }
    }
}
 */
}