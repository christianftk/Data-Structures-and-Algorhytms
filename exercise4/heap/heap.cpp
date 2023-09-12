template <typename Data>
void lasd::Heap<Data>::BuildTree(const LinearContainer<Data>& lc){
    BinaryTreeVec<Data>::NewRoot(lc[0]);
    unsigned long currIndex = 0;
    for(unsigned long i = 1; i < lc.Size(); i++){
        if(i % 2 == 1){
            this->AddLeftChild(*Tree[currIndex], lc[i]);
        }
        if(i % 2 == 0){
            this->AddRightChild(*Tree[currIndex], lc[i]);
            currIndex += 1;
        }
    }
}
template <typename Data>
void lasd::Heap<Data>::BuildHeap(){
    for(unsigned long i = (size-1)/2; i != -1; i--){
        Heapify(i);
    }
}

template <typename Data>
lasd::Heap<Data>::Heap(const LinearContainer<Data>& lc){
    if(lc.Size() > 0){
        BuildTree(lc);
        BuildHeap();
    }
}

template <typename Data>
void lasd::Heap<Data>::Heapify(unsigned long min){
    unsigned long l = min * 2 + 1;
    unsigned long r = min * 2 + 2;
    unsigned long i = min;
    if(l < size  && Tree[l]->Element() < Tree[min]->Element()){
        min = l;
    }
    if(r < size && Tree[r]->Element() < Tree[min]->Element()){
        min = r;
    }
    if (min != i){
        std::swap(Tree[i]->Element(), Tree[min]->Element());
        Heapify(min);
    }
}
template <typename Data>
lasd::Heap<Data>::Heap(const Heap& yHeap){
    BinaryTreeVec<Data>::NewRoot(yHeap.Root().Element());
    unsigned long currIndex = 0;
    for(unsigned long i = 1; i < yHeap.Size(); i++){
        if(i % 2 == 1){
            this->AddLeftChild(*Tree[currIndex], yHeap.Tree[i]->Element());
        }
        if(i % 2 == 0){
            this->AddRightChild(*Tree[currIndex], yHeap.Tree[i]->Element());
            currIndex += 1;
        }
    }
}
template <typename Data>
lasd::Heap<Data>::Heap(Heap&& yHeap) noexcept{
    std::swap(size, yHeap.size);
    std::swap(Tree, yHeap.Tree);
    std::swap(NodesAtLevel, yHeap.NodesAtLevel);
}
template <typename Data>
lasd::Heap<Data>& lasd::Heap<Data>::operator=(const Heap& yHeap){
    Heap<Data>* tmp = new Heap<Data>(yHeap);
    std::swap (*this, *tmp);
    delete tmp;
    return *this;
}
template <typename Data>
lasd::Heap<Data>& lasd::Heap<Data>::operator=(Heap&& yHeap) noexcept{
    std::swap(size, yHeap.size);
    std::swap(Tree, yHeap.Tree);
    std::swap(NodesAtLevel, yHeap.NodesAtLevel);
    return *this;
}
template <typename Data>
bool lasd::Heap<Data>::operator==(const Heap& yHeap) const noexcept{
    return BinaryTreeVec<Data>::operator==(yHeap);
}
template <typename Data>
bool lasd::Heap<Data>::operator!=(const Heap& yHeap) const noexcept{
    return !(*this == yHeap);    
}
template <typename Data>
void lasd::Heap<Data>::Sort(){
    unsigned long tmpSize = size;
    while(size > 0){
        std::swap(Tree[0]->Element(), Tree[--size]->Element());
        Heapify(0);
    }
    size = tmpSize;
    for(unsigned long i = 0; i < (size-1)/2 ; i++){
        std::swap(Tree[i]->Element(), Tree[size -i -1]->Element());
    }
}
template <typename Data>
void lasd::Heap<Data>::MapPreOrder(MapFunctor mf, void* par){
    for(unsigned long i = 0; i < size; i++){
        mf(Tree[i]->Element(), par);
    }
    BuildHeap();
}
template <typename Data>
void lasd::Heap<Data>::MapPostOrder(MapFunctor mf, void* par){
    for(unsigned long i = size - 1; i != -1; i--){
        mf(Tree[i]->Element(), par);
        if(i < (size - 1)/2){
            Heapify(i);
        }
    }
}
template <typename Data>
void lasd::Heap<Data>::FoldPreOrder(FoldFunctor ff, const void* par, void* acc) const{
    for(unsigned long i = 0; i < size; i++){
        ff(Tree[i]->Element(), par, acc);
    }
}
template <typename Data>
void lasd::Heap<Data>::FoldPostOrder(FoldFunctor ff, const void* par, void* acc) const{
    for(unsigned long i = size - 1; i != -1; i++){
        ff(Tree[i]->Element(), par, acc);
    }
}