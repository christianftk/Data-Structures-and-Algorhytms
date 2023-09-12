
template <typename Data>
bool lasd::BinaryTree<Data>::treeCompare(const Node& mRoot, const Node& yRoot) const noexcept{
    if(mRoot.Element() != yRoot.Element()){
            return false;
        }
        if((mRoot.HasLeftChild() != yRoot.HasLeftChild()) || (mRoot.HasRightChild() != yRoot.HasRightChild())){
            return false;
        }
        else{
            if(mRoot.HasLeftChild()){
                return treeCompare(mRoot.LeftChild(), yRoot.LeftChild());
            }
            if(mRoot.HasRightChild()){
                return treeCompare(mRoot.RightChild(), yRoot.RightChild());
            }
            return true;
        }
}
/* ************************************************************************** */
template <typename Data>
bool lasd::BinaryTree<Data>::operator==(const BinaryTree<Data>& yTree) const noexcept{
    if(size == yTree.size && size > 0){
        if(Root().Element() != yTree.Root().Element()){
            return false;
        }
        if((Root().HasLeftChild() != yTree.Root().HasLeftChild()) || (Root().HasRightChild() != yTree.Root().HasRightChild())){
            return false;
        }
        else{
            if(Root().HasLeftChild()){
                return treeCompare(Root().LeftChild(), yTree.Root().LeftChild());
            }
            if(Root().HasRightChild()){
                return treeCompare(Root().RightChild(), yTree.Root().RightChild());
            }
            return true;
        }
    }
    else{
        return false;
    }
}
// ...
template <typename Data>
bool lasd::BinaryTree<Data>::operator!=(const BinaryTree<Data>& yTree) const noexcept{
    return !(*this == yTree);
}

template <typename Data>
void lasd::BinaryTree<Data>::MapInOrder(MapFunctor mf, void* par){
    MapInOrder(mf, &Root(), par);
}

template <typename Data>
void lasd::BinaryTree<Data>::MapPreOrder(MapFunctor mf, void* par){
    MapPreOrder(mf, &Root(), par);
}
template <typename Data>
void lasd::BinaryTree<Data>::MapPostOrder(MapFunctor mf, void* par){
    MapPostOrder(mf, &Root(), par);
}

template <typename Data>
void lasd::BinaryTree<Data>::MapBreadth(MapFunctor mf, void* par){
    MapBreadth(mf, &Root(), par);
}

template <typename Data>
void lasd::BinaryTree<Data>::FoldInOrder(FoldFunctor ff, const void* par, void* acc) const{
    FoldInOrder(ff, Root(), par, acc);
}
template <typename Data>
void lasd::BinaryTree<Data>::FoldPreOrder(FoldFunctor ff, const void* par, void* acc) const{
    FoldPreOrder(ff, Root(), par, acc);
}
template <typename Data>
void lasd::BinaryTree<Data>::FoldPostOrder(FoldFunctor ff, const void* par, void* acc) const{
    FoldPostOrder(ff, Root(), par, acc);
}
template <typename Data>
void lasd::BinaryTree<Data>::FoldBreadth(FoldFunctor ff, const void* par, void* acc) const{
    FoldBreadth(ff, Root(), par, acc);
}


template <typename Data>
void lasd::BinaryTree<Data>::MapInOrder(MapFunctor mf, Node* curr, void* par){
    if(curr != nullptr){
        if(curr->HasLeftChild()){
            MapInOrder(mf, &(curr->LeftChild()), par);
        }
        mf(curr->Element(), par);
        if(curr->HasRightChild()){
            MapInOrder(mf, &(curr->RightChild()), par);
        }
    }
}

template <typename Data>
void lasd::BinaryTree<Data>::MapPreOrder(MapFunctor mf, Node* curr, void* par){
    if(curr != nullptr){
        mf(curr->Element(), par);
        if(curr->HasLeftChild()){
            MapPreOrder(mf, &(curr->LeftChild()), par);
        }
        if(curr->HasRightChild()){
            MapPreOrder(mf, &(curr->RightChild()), par);
        }
    }
}
template <typename Data>
void lasd::BinaryTree<Data>::MapPostOrder(MapFunctor mf, Node* curr, void* par){
    if(curr != nullptr){
        if(curr->HasLeftChild()){
            MapPreOrder(mf, &(curr->LeftChild()), par);
        }
        if(curr->HasRightChild()){
            MapPreOrder(mf, &(curr->RightChild()), par);
        }
        mf(curr->Element(), par);
    }
}

template <typename Data>
void lasd::BinaryTree<Data>::MapBreadth(MapFunctor mf, Node* curr, void* par){
    if(curr != nullptr){
        lasd::QueueLst<Node*> mQueue;
        mQueue.Enqueue(curr);
        Node* tmp;
        while(!mQueue.Empty()){
            tmp = mQueue.HeadNDequeue();
            mf(tmp->Element(), par);
            if(tmp->HasLeftChild()){
                mQueue.Enqueue(&(tmp->LeftChild()));
            }
            if(tmp->HasRightChild()){
                mQueue.Enqueue(&(tmp->RightChild()));
            }
        }
    }
}

template <typename Data>
void lasd::BinaryTree<Data>::FoldInOrder(FoldFunctor ff, const Node& curr, const void* par, void* acc) const{
    if(curr.HasLeftChild()){
        FoldInOrder(ff, curr.LeftChild(), par, acc);
    }
    ff(curr.Element(), par, acc);
    if(curr.HasRightChild()){
        FoldInOrder(ff, curr.RightChild(), par, acc);
    }
}
template <typename Data>
void lasd::BinaryTree<Data>::FoldPreOrder(FoldFunctor ff, const Node& curr, const void* par, void* acc) const{
    ff(curr.Element(), par, acc);
    if(curr.HasLeftChild()){
        FoldPreOrder(ff, curr.LeftChild(), par, acc);
    }
    if(curr.HasRightChild()){
        FoldPreOrder(ff, curr.RightChild(), par, acc);
    }
}
template <typename Data>
void lasd::BinaryTree<Data>::FoldPostOrder(FoldFunctor ff, const Node& curr, const void* par, void* acc) const{
    if(curr.HasLeftChild()){
        FoldPostOrder(ff, curr.LeftChild(), par, acc);
    }
    if(curr.HasRightChild()){
        FoldPostOrder(ff, curr.RightChild(), par, acc);
    }
    ff(curr.Element(), par, acc);
}
template <typename Data>
void lasd::BinaryTree<Data>::FoldBreadth(FoldFunctor ff, const Node& curr, const void* par, void* acc) const{
    lasd::QueueVec<const Node*> mQueue;
    mQueue.Enqueue(&curr);
    const Node* tmp;
    while(!mQueue.Empty()){
        tmp = mQueue.HeadNDequeue();
        ff(tmp->Element(), par, acc);
        if(tmp->HasLeftChild()){
            mQueue.Enqueue(&(tmp->LeftChild()));
        }
        if(tmp->HasRightChild()){
            mQueue.Enqueue(&(tmp->RightChild()));
        }
    }
}
