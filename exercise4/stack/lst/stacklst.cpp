
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
lasd::StackLst<Data>::StackLst(StackLst&& yStack) noexcept{
    std::swap(size, yStack.size);
    std::swap(head, yStack.head);
}

//Operators
//-Assignment operators
template <typename Data>
lasd::StackLst<Data>& lasd::StackLst<Data>::operator=(const StackLst& yStack){
    StackLst<Data>* tmpStack = new StackLst<Data>(yStack);
    std::swap(*this, *tmpStack);
    delete tmpStack;
    return *this;
}
template <typename Data>
lasd::StackLst<Data>& lasd::StackLst<Data>::operator=(StackLst&& yStack) noexcept{
    std::swap(size, yStack.size);
    std::swap(head, yStack.head);
    return *this;
}

//-Comparison operators
template <typename Data>
bool lasd::StackLst<Data>::operator==(const StackLst& yStack) const noexcept{
    return List<Data>::operator==(yStack);
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