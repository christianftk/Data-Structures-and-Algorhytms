template <typename Data>
lasd::PriorityQueue<Data>::PriorityQueue(const LinearContainer<Data>& lc) : Heap<Data>(lc){
}
template <typename Data>
lasd::PriorityQueue<Data>::PriorityQueue(const PriorityQueue<Data>& yQueue) : Heap<Data>(yQueue){
}
template <typename Data>
lasd::PriorityQueue<Data>::PriorityQueue(PriorityQueue<Data>&& yQueue) : Heap<Data>(yQueue){
}
template <typename Data>
lasd::PriorityQueue<Data>& lasd::PriorityQueue<Data>::operator=(const PriorityQueue<Data>& yQueue){
    PriorityQueue<Data>* tmp = new PriorityQueue<Data>(yQueue);
    std::swap(*tmp, *this);
    delete tmp;
    return *this;
}
template <typename Data>
lasd::PriorityQueue<Data>& lasd::PriorityQueue<Data>::operator=(PriorityQueue<Data>&& yQueue){
    std::swap(size, yQueue.size);
    std::swap(Tree, yQueue.Tree);
    std::swap(NodesAtLevel, yQueue.NodesAtLevel);
    return *this;
}
template <typename Data>
bool lasd::PriorityQueue<Data>::operator==(const PriorityQueue<Data>& yQueue) const noexcept{
    return Heap<Data>::operator==(yQueue);
}
template <typename Data>
bool lasd::PriorityQueue<Data>::operator!=(const PriorityQueue<Data>& yQueue) const noexcept{
    return !(*this == yQueue);
}
template <typename Data>
Data const& lasd::PriorityQueue<Data>::Tip() const{
    return Root().Element();
}
template <typename Data>
void lasd::PriorityQueue<Data>::RemoveTip(){
    if(size > 0){
        size--;
        std::swap (Tree[0]->Element(), Tree[size]->Element());
        delete Tree[size];
        this->Heapify(0);
    }
}
template <typename Data>
Data lasd::PriorityQueue<Data>::TipNRemove(){
    Data tmp = Tip();
    RemoveTip();
    return tmp;
}
template <typename Data>
void lasd::PriorityQueue<Data>::Insert(const Data& dat){
    if(size > 0){
        if(size % 2 == 1){
            AddLeftChild(*(Tree[(size-1)/2]), dat);
        }
        else{
            AddRightChild(*(Tree[(size-1)/2]), dat);
        }
        NodeVec* curr = Tree[size-1];
        while(curr->HasParent() && curr->Element() < curr->Parent().Element()){
            std::swap(curr->Element(), curr->Parent().Element());
            curr = &(curr->Parent());
        }
    }
    else{
        NewRoot(dat);
    }
}
template <typename Data>
void lasd::PriorityQueue<Data>::Insert(Data&& dat){
    if(size > 0){
        if(size % 2 == 1){
            AddLeftChild(*(Tree[(size-1)/2]), dat);
        }
        else{
            AddRightChild(*(Tree[(size-1)/2]), dat);
        }
        NodeVec* curr = Tree[size-1];
        while(curr->HasParent() && curr->Element() < curr->Parent().Element()){
            std::swap(curr->Element(), curr->Parent().Element());
            curr = &(curr->Parent());
        }
    }
    else{
        NewRoot(dat);
    }
}
template <typename Data>
void lasd::PriorityQueue<Data>::ChangePriority(NodeVec& nod, const Data& dat){
    if(dat != nod.Element()){
        if(nod.Element() > dat){
            nod.Element() = dat;
            NodeVec* curr = &nod;
            while(curr->HasParent() && curr->Element() < curr->Parent().Element()){
                std::swap(curr->Element(), curr->Parent().Element());
                curr = &(curr->Parent());
            }
        }
        else{
            nod.Element() = dat;
            this->Heapify(nod.Position());
        }
    }
}
template <typename Data>
void lasd::PriorityQueue<Data>::ChangePriority(NodeVec& nod, Data&& dat){
    if(dat != nod.Element()){
        if(nod.Element() > dat){
            nod.Element() = std::move(dat);
            NodeVec* curr = &nod;
            while(curr->HasParent() && curr->Element() < curr->Parent().Element()){
                std::swap(curr->Element(), curr->Parent().Element());
                curr = &(curr->Parent());  
            }
        }
        else{
            nod.Element() = std::move(dat);
            this->Heapify(nod.Position());
        }
    }
}