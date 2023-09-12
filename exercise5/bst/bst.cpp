#include "../stack/stack.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../vector/vector.hpp"

namespace lasd {

template <typename Data>
typename BST<Data>::BSTNode* BST<Data>::BSTNode::Left(){
    return (BSTNode*)left;
}
template <typename Data>
typename BST<Data>::BSTNode const* BST<Data>::BSTNode::Left() const{
    return (BSTNode*)left;
}
template <typename Data>
typename BST<Data>::BSTNode* BST<Data>::BSTNode::Right(){
    return (BSTNode*)right;
}
template <typename Data>
typename BST<Data>::BSTNode const* BST<Data>::BSTNode::Right() const{
    return (BSTNode*)right;
}
template <typename Data>
typename BST<Data>::BSTNode* BST<Data>::BSTNode::Find(const Data& dat) noexcept{
    if(dat == data){
        return this;
    }
    else if (dat < data){
        if(left != nullptr){
            return Left()->Find(dat);
        }
        else{
            return nullptr;
        }
    }
    else{
        if(right != nullptr){
            return Right()->Find(dat);
        }
        else{
            return nullptr;
        }
    }
}
template <typename Data>
typename BST<Data>::BSTNode* BST<Data>::BSTNode::FindParent(BSTNode* parent, const Data& dat) noexcept{
    if(dat == data){
        return parent;
    }
    else if (dat < data){
        if(left != nullptr){
            return Left()->FindParent(this, dat);
        }
        else{
            return this;
        }
    }
    else{
        if(right != nullptr){
            return Right()->FindParent(this, dat);
        }
        else{
            return this;
        }
    }
}
template <typename Data>
typename BST<Data>::BSTNode* BST<Data>::BSTNode::MinParent(BSTNode* parent) noexcept{
    if(left != nullptr){
        return Left()->MinParent(this);
    }
    return parent;
}
template <typename Data>
typename BST<Data>::BSTNode* BST<Data>::BSTNode::MaxParent(BSTNode* parent) noexcept{
    if(right != nullptr){
        return Right()->MaxParent(this);
    }
    return parent;
}

template <typename Data>
typename BST<Data>::BSTNode const* BST<Data>::BSTNode::Find(const Data& dat) const noexcept{
    if(dat == data){
        return this;
    }
    else if (dat < data){
        if(left != nullptr){
            return Left()->Find(dat);
        }
        else{
            return nullptr;
        }
    }
    else{
        if(right != nullptr){
            return Right()->Find(dat);
        }
        else{
            return nullptr;
        }
    }
}
template <typename Data>
typename BST<Data>::BSTNode const* BST<Data>::BSTNode::FindParent(BSTNode* parent, const Data& dat) const noexcept{
    if(dat == data){
        return parent;
    }
    else if (dat < data){
        if(left != nullptr){
            return Left()->FindParent(this, dat);
        }
        else{
            return this;
        }
    }
    else{
        if(right != nullptr){
            return Right()->FindParent(this, dat);
        }
        else{
            return this;
        }
    }
}
template <typename Data>
typename BST<Data>::BSTNode const* BST<Data>::BSTNode::MinParent(const BSTNode* parent) const noexcept{
    if(left != nullptr){
        return Left()->MinParent(this);
    }
    return parent;
}
template <typename Data>
typename BST<Data>::BSTNode const* BST<Data>::BSTNode::MaxParent(const BSTNode* parent) const noexcept{
    if(right != nullptr){
        return Right()->MaxParent(this);
    }
    return parent;
}


/* ************************************************************************** */

template <typename Data>
BST<Data>::BST(const BST& yTree) : BinaryTreeLnk<Data>(yTree) {
}
template <typename Data>
BST<Data>::BST(BST&& yTree) noexcept {
    std::swap(root, yTree.root);
    std::swap(size, yTree.size);
}
template <typename Data>
BST<Data>& BST<Data>::operator=(const BST& yTree){
    BST<Data>* tmp = new BST<Data>(yTree);
    std::swap(*this, *tmp);
    delete tmp;
    return *this;
}
template <typename Data>
BST<Data>& BST<Data>::operator=(BST&& yTree) noexcept{
    std::swap(root, yTree.root);
    std::swap(size, yTree.size);
    return *this;
}

template <typename Data>
void CopyData(const Data& dat, const void* vec, void* index){
    (*(Vector<Data>*)vec)[(*(unsigned long*)index)] = dat;
    (*(unsigned long*)index) += 1;
}
template <typename Data>
Vector<Data> CopyInVector(const BST<Data>& mTree){
    Vector<Data> vec(mTree.Size());
    unsigned long index = 0;
    mTree.FoldInOrder(CopyData<Data>, &vec, &index);
    return vec;
}
template <typename Data>
bool BST<Data>::operator==(const BST& yTree) const noexcept{
    Vector<Data> v1 = CopyInVector(*this);
    Vector<Data> v2 = CopyInVector(yTree);
    return v1 == v2;   
}

template <typename Data>
bool BST<Data>::operator!=(const BST& yTree) const noexcept{
    return !(*this == yTree);
}
template <typename Data>
typename BST<Data>::BSTNode& BST<Data>::Root(){
    if(root != nullptr){
        return *(BST<Data>::BSTNode*)root;    
    }
    else{
        throw std::length_error("No Root");
    }
}
template <typename Data>
typename BST<Data>::BSTNode const& BST<Data>::Root() const{
    if(root != nullptr){
        return *(BST<Data>::BSTNode*)root;    
    }
    else{
        throw std::length_error("No Root");
    }
}
template <typename Data>
void BST<Data>::Insert(const Data& dat){
    if(size != 0){
        BST<Data>::BSTNode* curr = &Root();
        BST<Data>::BSTNode* p = nullptr;
        while (curr != nullptr){
            p = curr;
            if(curr->Element() > dat){
                curr = curr->Left();
            }
            else{
                curr = curr->Right();
            }
        }
        if(p->Element() > dat){
            p->left = new NodeLnk(dat);
            size++;
        }
        else if(p->Element() < dat){
            p->right = new NodeLnk(dat);
            size++;
        }
    }
    else{
        this->NewRoot(dat);
    }
}
template <typename Data>
void BST<Data>::Insert(Data&& dat){
    if(size > 0){
        BST<Data>::BSTNode* curr = &Root();
        BST<Data>::BSTNode* p = nullptr;
        while (curr != nullptr){
            p = curr;
            if(curr->Element() > dat){
                curr = curr->Left();
            }
            else{
                curr = curr->Right();
            }
        }
        if(p->Element() > dat){
            p->left = new NodeLnk(dat);
            size++;
        }
        else if(p->Element() < dat){
            p->right = new NodeLnk(dat);
            size++;
        }
    }
    else{
        this->NewRoot(dat);
    }
}
template <typename Data>
void BST<Data>::Remove(const Data& dat){
    if(size > 0){
        root = Remove(&Root(), dat);
        size--;
    }
}
template <typename Data>
typename BST<Data>::BSTNode* BST<Data>::Remove(BSTNode* nod, const Data& dat){
    if(nod != nullptr){
        if(nod->Element() < dat){
            nod->right = Remove(nod->Right(), dat);
        }
        else if(nod->Element() > dat){
            nod->left = Remove(nod->Left(), dat);
        }
        else{
            nod = RemoveRoot(nod);
        }
    }
    return nod;
}
template <typename Data>
typename BST<Data>::BSTNode* BST<Data>::RemoveRoot(BSTNode* nod){
    if(nod != nullptr){
        BST<Data>::BSTNode* tmp;
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
typename BST<Data>::BSTNode* BST<Data>::RemoveMin(BSTNode* nod, BSTNode* parent){
    if(nod != nullptr){
        if(nod->HasLeftChild()){
            return RemoveMin(nod->Left(), nod);
        }
        else{
            if(parent->left == nod){
                parent->left = nod->right;
            }
            else{
                parent->right = nod->right;
            }
        }
    }
    return nod;
}
template <typename Data>
Data const& BST<Data>::Min(){
    if(size > 0){
        return Min(&Root());
    }
    else{
        throw std::length_error("Tree is empty");
    }
}
template <typename Data>
Data const& BST<Data>::Min(BSTNode* nod){
    if(nod != nullptr){
        if(nod->Left() != nullptr){
            return Min(nod->Left());
        }
        else{
            return nod->Element();
        }
    }
    else{
        throw std::length_error("Tree is Empty");
    }
}
template <typename Data>
Data BST<Data>::MinNRemove(){
    if(size > 0){
        Data dat;
        BST<Data>::BSTNode* parent = Root().MinParent(nullptr);
        BST<Data>::BSTNode* tmp = nullptr;
        if(parent == nullptr){
            tmp = &Root();
            if(root->HasRightChild()){
                root = Root().Right();
            }
            dat = tmp->Element();
        }
        else{
            tmp = parent->Left();
            dat = tmp->Element();
            if(parent->Left()->HasRightChild()){
                parent->left = tmp->Right();
            }
            else{
                parent->left = nullptr;
            }
        }
        delete tmp;
        size--;
        return dat;
    }
    else{
        throw std::length_error("Tree is empty");
    }
}
template <typename Data>
void BST<Data>::RemoveMin(){
    if (size > 0){
        root = (NodeLnk*)DeleteMin(&Root());
        size--;
    }
    else{
        throw std::length_error("Tree is empty");
    }
}
template <typename Data>
typename BST<Data>::BSTNode* BST<Data>::DeleteMin(BSTNode* nod){
    if(nod->Left() != nullptr){
        nod->left = (NodeLnk*)DeleteMin(nod->Left());
    }
    else{
        nod = RemoveRoot(nod);
    }
    return nod;
}
template <typename Data>
Data const& BST<Data>::Max(){
    if(size > 0){
        return Max(&Root());
    }
    else{
        throw std::length_error("Tree is empty");
    }
}
template <typename Data>
Data const& BST<Data>::Max(BSTNode* nod){
    if(nod != nullptr){
        if(nod->Right() != nullptr){
            return Max(nod->Right());
        }
        else{
            return nod->Element();
        }
    }
    else{
        throw std::length_error("Tree is Empty");
    }
}
template <typename Data>
Data BST<Data>::MaxNRemove(){
    if(size > 0){
        Data dat;
        BST<Data>::BSTNode* parent = Root().MaxParent(nullptr);
        BST<Data>::BSTNode* tmp = nullptr;
        if(parent == nullptr){
            tmp = &Root();
            if(root->HasLeftChild()){
                root = Root().Left();
            }
            dat = tmp->Element();
        }
        else{
            tmp = parent->Right();
            dat = tmp->Element();
            if(parent->Right()->HasLeftChild()){
                parent->right = tmp->Left();
            }
            else{
                parent->right = nullptr;
            }
        }
        delete tmp;
        size--;
        return dat;
    }
    else{
        throw std::length_error("Tree is empty");
    }
}
template <typename Data>
void BST<Data>::RemoveMax(){
    if(size > 0){
        BST<Data>::BSTNode* parent = Root().MaxParent(nullptr);
        BST<Data>::BSTNode* tmp = nullptr;
        if(parent == nullptr){
            tmp = &Root();
            if(root->HasLeftChild()){
                root = Root().Left();
            }
        }
        else{
            tmp = parent->Right();
            if(parent->Right()->HasLeftChild()){
                parent->right = tmp->Left();
            }
            else{
                parent->right = nullptr;
            }
        }
        delete tmp;
        size--;
    }
    else{
        throw std::length_error("Tree is empty");
    }
}

template <typename Data>
Data const& BST<Data>::Successor(const Data& dat){
    if(size > 0){
        return Successor(&Root(), nullptr, dat);
    }
    else{
        throw std::length_error("Tree is Empty");
    }
}
template <typename Data>
Data const& BST<Data>::Successor(BSTNode* nod, BSTNode* candidate, const Data& dat){
    if(nod != nullptr){
        if(nod->Element() < dat){
            return Successor(nod->Right(), candidate, dat);
        }
        else if(nod->Element() > dat){
            return Successor(nod->Left(), nod, dat);
        }
        else{
            if(nod->Right() != nullptr){
                return Min(nod->Right());
            }
        }
    }
    else{
        if(candidate == nullptr){
            throw std::length_error("No Successor Found");
        }
    }
    return candidate->Element();
}
template <typename Data>
Data BST<Data>::SuccessorNRemove(const Data& dat){
    Data tmp = Successor(dat);
    Remove(tmp);
    return tmp;
}
template <typename Data>
void BST<Data>::RemoveSuccessor(const Data& dat){
    if(size > 0){
        Remove(Successor(dat));
    }
    else{
        throw std::length_error("No Tree");
    }
}
template <typename Data>
Data const& BST<Data>::Predecessor(const Data& dat){
    if(size > 0){
        return Predecessor(&Root(), nullptr, dat);
    }
    else{
        throw std::length_error("Tree is Empty");
    }
}
template <typename Data>
Data const& BST<Data>::Predecessor(BSTNode* nod, BSTNode* candidate, const Data& dat){
    if(nod != nullptr){
        if(nod->Element() > dat){
            return Predecessor(nod->Left(), candidate, dat);
        }
        else if(nod->Element() < dat){
            return Predecessor(nod->Right(), nod, dat);
        }
        else{
            if(nod->Left() != nullptr){
                return Max(nod->Left());
            }
        }
    }
    else{
        if(candidate == nullptr){
            throw std::length_error("No Predecessor Found");
        }
    }
    return candidate->Element();
}
template <typename Data>
Data BST<Data>::PredecessorNRemove(const Data& dat){
    Data tmp = Predecessor(dat);
    Remove(tmp);
    return tmp;
}
template <typename Data>
void BST<Data>::RemovePredecessor(const Data& dat){
    if(size > 0){
        Remove(Predecessor(dat));
    }
    else{
        throw std::length_error("No Tree");
    }
}

template <typename Data>
bool BST<Data>::Exists(const Data& dat) const noexcept{
    if(size > 0){
        if(Root().Find(dat) == nullptr){
            return false;
        }
        else{
            return true;
        }
    }
    return false;
    
}
template <typename Data>
void lasd::BST<Data>::MapInOrder(MapFunctor mf, void* par){
    if(size > 0)
        MapInOrder(mf, &Root(), par);
}

template <typename Data>
void lasd::BST<Data>::MapPreOrder(MapFunctor mf, void* par){
    if(size > 0)
        MapPreOrder(mf, &Root(), par);
}
template <typename Data>
void lasd::BST<Data>::MapPostOrder(MapFunctor mf, void* par){
    if(size > 0)
        MapPostOrder(mf, &Root(), par);
}

template <typename Data>
void lasd::BST<Data>::MapBreadth(MapFunctor mf, void* par){
    if(size > 0)
        MapBreadth(mf, &Root(), par);
}

template <typename Data>
void lasd::BST<Data>::FoldInOrder(FoldFunctor ff, const void* par, void* acc) const{
    if(size > 0)
        FoldInOrder(ff, &Root(), par, acc);
}
template <typename Data>
void lasd::BST<Data>::FoldPreOrder(FoldFunctor ff, const void* par, void* acc) const{
    if(size > 0)
        FoldPreOrder(ff, &Root(), par, acc);
}
template <typename Data>
void lasd::BST<Data>::FoldPostOrder(FoldFunctor ff, const void* par, void* acc) const{
    if(size > 0)
        FoldPostOrder(ff, &Root(), par, acc);
}
template <typename Data>
void lasd::BST<Data>::FoldBreadth(FoldFunctor ff, const void* par, void* acc) const{
    if(size > 0)
        FoldBreadth(ff, &Root(), par, acc);
}


template <typename Data>
void lasd::BST<Data>::MapInOrder(MapFunctor mf, BSTNode* curr, void* par){
    if(curr != nullptr){
        MapInOrder(mf, curr->Left(), par);
        mf(curr->Element(), par);
        MapInOrder(mf, curr->Right(), par);
    }
}

template <typename Data>
void lasd::BST<Data>::MapPreOrder(MapFunctor mf, BSTNode* curr, void* par){
    if(curr != nullptr){
        mf(curr->Element(), par);
        MapInOrder(mf, curr->Left(), par);
        MapInOrder(mf, curr->Right(), par);
    }
}
template <typename Data>
void lasd::BST<Data>::MapPostOrder(MapFunctor mf, BSTNode* curr, void* par){
    if(curr != nullptr){
        MapInOrder(mf, curr->Left(), par);
        MapInOrder(mf, curr->Right(), par);
        mf(curr->Element(), par);
    }
}

template <typename Data>
void lasd::BST<Data>::MapBreadth(MapFunctor mf, BSTNode* curr, void* par){
    if(curr != nullptr){
        lasd::QueueLst<BSTNode*> mQueue;
        mQueue.Enqueue(curr);
        BSTNode* tmp;
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
void lasd::BST<Data>::FoldInOrder(FoldFunctor ff, const BSTNode* curr, const void* par, void* acc) const{
    if(curr != nullptr){
        FoldPostOrder(ff, curr->Left(), par, acc);
        ff(curr->Element(), par, acc);
        FoldPostOrder(ff, curr->Right(), par, acc);
    }
}
template <typename Data>
void lasd::BST<Data>::FoldPreOrder(FoldFunctor ff, const BSTNode* curr, const void* par, void* acc) const{
    if(curr != nullptr){
        ff(curr->Element(), par, acc);
        FoldPostOrder(ff, curr->Left(), par, acc);
        FoldPostOrder(ff, curr->Right(), par, acc);
    }
}
template <typename Data>
void lasd::BST<Data>::FoldPostOrder(FoldFunctor ff, const BSTNode* curr, const void* par, void* acc) const{
    if(curr != nullptr){
        FoldPostOrder(ff, curr->Left(), par, acc);
        FoldPostOrder(ff, curr->Right(), par, acc);
        ff(curr->Element(), par, acc);
    }
}
template <typename Data>
void lasd::BST<Data>::FoldBreadth(FoldFunctor ff, const BSTNode* curr, const void* par, void* acc) const{
    lasd::QueueVec<const BSTNode*> mQueue;
    mQueue.Enqueue(curr);
    const BSTNode* tmp;
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


/* ************************************************************************** */

}
