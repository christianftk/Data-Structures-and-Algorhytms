
#include <stdexcept>

/* ************************************************************************** */

//Constructors
template <typename Data>
lasd::QueueLst<Data>::QueueLst(const QueueLst& yQueue){
    if(yQueue.head != nullptr){
        size = yQueue.size;
        head= new Node(yQueue.head->data);
        Node* curr = yQueue.head->next;
        Node* tmp = head;
        while(curr != nullptr){
            tmp->next= new Node(curr->data);
            tmp = tmp->next;
            curr = curr->next;
        }
        tail = yQueue.tail;
    }
}
template <typename Data>
lasd::QueueLst<Data>::QueueLst(QueueLst&& yQueue){
    std::swap(head, yQueue.head);
    std::swap(tail, yQueue.tail);
    std::swap(size, yQueue.size);
}
template <typename Data>
lasd::QueueLst<Data>::~QueueLst(){
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
lasd::QueueLst<Data>& lasd::QueueLst<Data>::operator=(const QueueLst& yQueue){
    QueueLst<Data> tmp(yQueue);
    std::swap(*this, *tmp);
    delete tmp;
    return *this;
}
template <typename Data>
lasd::QueueLst<Data>& lasd::QueueLst<Data>::operator=(QueueLst&& yQueue){
    std::swap(size, yQueue.size);
    std::swap(head, yQueue.head);
    return *this;
}
//-Comparison operators
template <typename Data>
bool lasd::QueueLst<Data>::operator==(const QueueLst& yQueue) const noexcept{
    return ((List<Data>)*this == (List<Data>)yQueue);
}
template <typename Data>
bool lasd::QueueLst<Data>::operator!=(const QueueLst& yQueue) const noexcept{
    return !(*this == yQueue);
}

//Specific member functions (inherited from Queue)
template <typename Data>
Data& lasd::QueueLst<Data>::Head() const{
    return List<Data>::Front();
}
template <typename Data>
void lasd::QueueLst<Data>::Dequeue(){
    List<Data>::RemoveFromFront();
}
template <typename Data>
Data lasd::QueueLst<Data>::HeadNDequeue(){
    return List<Data>::FrontNRemove();
}
template <typename Data>
void lasd::QueueLst<Data>::Enqueue(const Data& newElem){
    List<Data>::InsertAtBack(newElem);
}
template <typename Data>
void lasd::QueueLst<Data>::Enqueue(Data&& newElem){
    List<Data>::InsertAtBack(newElem);
}
//Specific member function (inherited from Container)
template <typename Data>
void lasd::QueueLst<Data>::Clear(){
    List<Data>::Clear();
}