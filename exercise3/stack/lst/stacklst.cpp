
#include <stdexcept>

/* ************************************************************************** */

//Constructors
template <typename Data>
lasd::StackLst<Data>::StackLst(const StackLst& yStack){
    if(yStack.head != nullptr){
        size = yStack.size;
        head= new Node(yStack.head->data);
        Node* curr = yStack.head->next;
        Node* tmp = head;
        while(curr != nullptr){
            tmp->next= new Node(curr->data);
            tmp = tmp->next;
            curr = curr->next;
        }
    }
}
template <typename Data>
lasd::StackLst<Data>::StackLst(StackLst&& yStack){
    std::swap(size, yStack.size);
    std::swap(head, yStack.head);
}
template <typename Data>
lasd::StackLst<Data>::~StackLst(){
    if(head != nullptr){
        Node* tmp;
        while (head != nullptr){
            tmp = head;
            head = head->next;
            delete tmp;
        }
        size = 0;
        head = nullptr;
    }
}

//Operators
//-Assignment operators
template <typename Data>
lasd::StackLst<Data>& lasd::StackLst<Data>::operator=(const StackLst& yStack){
    StackLst<Data> tmp(yStack);
    std::swap(*this, *tmp);
    delete tmp;
    return *this;
}
template <typename Data>
lasd::StackLst<Data>& lasd::StackLst<Data>::operator=(StackLst&& yStack){
    std::swap(size, yStack.size);
    std::swap(head, yStack.head);
    return *this;
}

//-Comparison operators
template <typename Data>
bool lasd::StackLst<Data>::operator==(const StackLst& yStack) const noexcept{
    return ((List<Data>)*this == (List<Data>)yStack);
}
template <typename Data>
bool lasd::StackLst<Data>::operator!=(const StackLst& yStack) const noexcept{
    return !(*this == yStack);
}

//Specific member functions (inherited from Stack)
template <typename Data>
Data& lasd::StackLst<Data>::Top() const{
    return List<Data>::Front();
}
template <typename Data>
void lasd::StackLst<Data>::Pop(){
    List<Data>::RemoveFromFront();
}
template <typename Data>
Data lasd::StackLst<Data>::TopNPop(){
    return List<Data>::FrontNRemove();
}
template <typename Data>
void lasd::StackLst<Data>::Push(const Data& newData){
    List<Data>::InsertAtFront(newData);
}
template <typename Data>
void lasd::StackLst<Data>::Push(Data&& newData){
    List<Data>::InsertAtFront(newData);
}

//Specific member function (inherited from Container)
template <typename Data>
void lasd::StackLst<Data>::Clear(){
    List<Data>::Clear();
}