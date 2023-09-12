
// ...

#include <stdexcept>

/* ************************************************************************** */

//-Node
//Specific Constructor with a Data parameter
template <typename Data>
lasd::List<Data>::Node::Node(const Data& dat){
    data = dat;
    next = nullptr;
}
template <typename Data>
lasd::List<Data>::Node::Node(Data&& dat) noexcept{
    std::swap(data, dat);
    next = nullptr;
}
//Copy Constructor
template <typename Data>
lasd::List<Data>::Node::Node(const Node& nod){
    data = nod.data;
    next = nod.next;
}
//Move Constructor
template <typename Data>
lasd::List<Data>::Node::Node(Node&& nod) noexcept{
    std::swap(data, nod.data);
    std::swap(next, nod.next);
}
//Operators Overloading
template <typename Data>
bool lasd::List<Data>::Node::operator==(const Node& nod)const noexcept{
    return data == nod.data;
}
template <typename Data>
bool lasd::List<Data>::Node::operator!=(const Node& nod)const noexcept{
    return data != nod.data;
}

//Specific Node function
template <typename Data>
bool lasd::List<Data>::Node::isEqual(const Node& nod) const noexcept{
    return ((data == nod.data) && (next == nod.next));
}

/* ************************************************************************** */

//-List
//Copy Constructor
template <typename Data>
lasd::List<Data>::List(const List& list){
    if(list.head != nullptr){
        size = list.size;
        head= new Node(list.head->data);
        Node* curr = list.head->next;
        Node* tmp = head;
        while(curr != nullptr){
            tmp->next= new Node(curr->data);
            tmp = tmp->next;
            curr = curr->next;
        }
        tail = list.tail;
    }
}
//Move Constructor
template <typename Data>
lasd::List<Data>::List(List&& list){
    std::swap(size, list.size);
    std::swap(tail, list.tail);
    std::swap(head, list.head);
}
//Destructor
template <typename Data>
lasd::List<Data>::~List(){
    if(head != nullptr){
        Node* tmp;
        while (head != nullptr){
            tmp = head;
            head = head->next;
            delete tmp;
        }
        size = 0;
    }
}

//Operators
//-Assignment operators
template <typename Data>
lasd::List<Data>& lasd::List<Data>::operator=(const List<Data>& list){
    List<Data>* tmp = new List<Data>(list);
    std::swap(*this, *tmp);
    delete tmp;
    return *this;
}
template <typename Data>
lasd::List<Data>& lasd::List<Data>::operator=(List<Data>&& list){
    std::swap(size, list.size);
    std::swap(head, list.head);
    std::swap(tail, list.tail);
    return *this;
}
//-Comparison operators
template <typename Data>
bool lasd::List<Data>::operator==(const List<Data>& list)const noexcept{
    bool equals = true;
    if(size == list.size){
        Node* tmp= head;
        Node* curr= list.head;
        while(equals && curr != nullptr){
            if(tmp->data != curr->data){
                equals = false;
            }
            curr= curr->next;
            tmp= tmp->next;
        }
    }
    else{
        equals = false;
    }
    return equals;
}
template <typename Data>
bool lasd::List<Data>::operator!=(const List<Data>& list)const noexcept{
    return !(*this == list);
}

//Specific Member Functions
template <typename Data>
void lasd::List<Data>::RemoveFromFront(){
    if(head != nullptr){
        Node* tmp = head;
        head = head->next; 
        delete tmp;
        size--;
    }
    else{
        throw std::length_error("Trying to access unknown location");
    }
}
template <typename Data>
Data lasd::List<Data>::FrontNRemove(){
    Data tmp = Front();
    RemoveFromFront();
    return tmp;
}
template <typename Data>
void lasd::List<Data>::InsertAtFront(const Data& dat){
    Node* newHead = new Node(dat);
    if(size == 0){
        tail = newHead;
    }
    else{
        newHead->next = head;
    }
    head = newHead;
    size++;
}
template <typename Data>
void lasd::List<Data>::InsertAtFront(Data&& dat){
    Node* newHead = new Node(dat);
    if(size == 0){
        tail = newHead;
    }
    else{
        newHead->next = head;
    }
    head = newHead;
    size++;
}
template <typename Data>
void lasd::List<Data>::InsertAtBack(const Data& dat){
    if(head != nullptr){
        tail->next = new Node(dat);
        tail = tail->next;
        size += 1;
    }else{
        InsertAtFront(dat);
    }
}
template <typename Data>
void lasd::List<Data>::InsertAtBack(Data&& dat){
    if(head != nullptr){
        tail->next = new Node(dat);
        tail = tail->next;
        size += 1;
    }
    else{
        InsertAtFront(dat);
    }
}

//Specific member function (inherited from Container)
template <typename Data>
void lasd::List<Data>::Clear(){
    if(head != nullptr){
        Node* tmp;
        while(head != nullptr){
            tmp = head;
            head = head->next;
            delete tmp;
        }
        size = 0;
    }
}

//Specific member functions (inherited from LinearContainer)
template <typename Data>
Data& lasd::List<Data>::Front()const{
    if(head != nullptr){
        return head->data;
    }
    else{
        throw std::length_error("Trying to access unknown location");
    }
}
template <typename Data>
Data& lasd::List<Data>::Back()const{
    if(head != nullptr){
        return tail->data;
    }
    else{
        throw std::length_error("Trying to access unknown location");
    }
}
template <typename Data>
Data& lasd::List<Data>::operator[](unsigned long index)const{
    if(index < size){
        if(index == size - 1 ) { return tail->data;};
        Node* curr = head;
        for(unsigned long i = 0; i < index; i++, curr = curr->next);
        return curr->data;
    }else{
        throw std::out_of_range("Out of range access");
    }
}

//Map Functions
template <typename Data>
void lasd::List<Data>::MapPreOrder(MapFunctor mf, void* par){
    MapPreOrder(mf, head, par);
}
template <typename Data>
void lasd::List<Data>::MapPostOrder(MapFunctor mf, void* par){
    MapPostOrder(mf, head, par);
}
template <typename Data>
void lasd::List<Data>::MapPreOrder(MapFunctor mf, Node* nod, void* par){
    if(nod != nullptr){
        for(Node* curr = nod; curr != nullptr; curr = curr->next){
            mf(curr->data, par);
        }
    }
}
template <typename Data>
void lasd::List<Data>::MapPostOrder(MapFunctor mf, Node* nod, void* par){
    if(nod != nullptr){
        MapPostOrder(mf, nod->next, par);
        mf(nod->data, par);
    }
}

//Fold Functions
template <typename Data>
void lasd::List<Data>::FoldPreOrder(FoldFunctor ff, const void* par, void* acc) const{
    FoldPreOrder(ff, head, par, acc);
}
template <typename Data>
void lasd::List<Data>::FoldPostOrder(FoldFunctor ff, const void* par, void* acc) const{
    FoldPostOrder(ff, head, par, acc);
}
template <typename Data>
void lasd::List<Data>::FoldPreOrder(FoldFunctor ff, Node* nod, const void* par, void* acc) const{
    if(nod != nullptr){
        for(Node* curr = nod; curr != nullptr; curr = curr->next){
            ff(curr->data, par, acc);
        }
    }
}
template <typename Data>
void lasd::List<Data>::FoldPostOrder(FoldFunctor ff, Node* nod, const void* par, void* acc) const{
    if(nod != nullptr){
        FoldPostOrder(ff, nod->next, par, acc);
        ff(nod->data, par, acc);
    }
}