
#include <stdexcept>

/* ************************************************************************** */
template <typename Data>
lasd::QueueVec<Data>::QueueVec(){
    rear = 0;
    front = 0;          //index of the next element to add
    size = 4;
    Elements = new Data[size];
}
template <typename Data>
lasd::QueueVec<Data>::QueueVec(const QueueVec& yQueue){
    Elements = new Data[yQueue.size];

    size = yQueue.size;
    unsigned long i = 0;
    unsigned long j = yQueue.front;

    for(; j != yQueue.rear; i++, j = (j + 1) % size)
        Elements[i] = yQueue.Elements[j];

    rear = i;
    front = 0;
}
template <typename Data>
lasd::QueueVec<Data>::QueueVec(QueueVec&& yQueue){
    std::swap(Elements, yQueue.Elements);
    std::swap(rear, yQueue.rear);
    std::swap(front, yQueue.front);
    std::swap(size, yQueue.size);
}
template <typename Data>
lasd::QueueVec<Data>::~QueueVec(){
    delete [] Elements;
    Elements = nullptr;
}

//Operators
//-Assignment operators
template <typename Data>
lasd::QueueVec<Data>& lasd::QueueVec<Data>::operator=(const QueueVec& yQueue){
    QueueVec<Data> tmpQueue(yQueue);
    std::swap(*tmpQueue, *this);

    delete yQueue;
    return *this;
}
template <typename Data>
lasd::QueueVec<Data>& lasd::QueueVec<Data>::operator=(QueueVec&& yQueue){
    std::swap(Elements, yQueue.Elements);
    std::swap(size, yQueue.size);
    std::swap(rear, yQueue.rear);
    std::swap(front, yQueue.front);

    delete yQueue;
    return *this;
}
//-Comparison operators
template <typename Data>
bool lasd::QueueVec<Data>::operator==(const QueueVec& yQueue) const noexcept{
    bool equals = true;
    if(yQueue.Size() == Size()){
        unsigned long i = front;
        unsigned long j = yQueue.front;
        while(equals && i != rear){
            if(Elements[i] != yQueue.Elements[j])
                equals = false;
            i = (i+1) % size;
            j = (j+1) % size;
        }
    }
    else{
        equals = false;
    }
    return equals;
}
template <typename Data>
bool lasd::QueueVec<Data>::operator!=(const QueueVec& yQueue) const noexcept{
    return !(*this == yQueue);
}

//Specific member functions (inherited from Queue)
template <typename Data>
Data& lasd::QueueVec<Data>::Head() const{
    if(Size() != 0){
        return Elements[front];
    }
    else{
        throw std::length_error("Accessing unknown location");
    }
}
template <typename Data>
void lasd::QueueVec<Data>::Dequeue(){
    if(Size() != 0){;
        front = (front + 1) % size;
        if(Size() < size/4){
            Reduce();
        }
    }
    else{
        throw std::length_error("Accessing unknown location");
    }
}
template <typename Data>
Data lasd::QueueVec<Data>::HeadNDequeue(){
    Data tmp = Head();
    Dequeue();
    return tmp;
}
template <typename Data>
void lasd::QueueVec<Data>::Enqueue(const Data& newElem){
    if(((rear + 2) % size) == front){
        Expand();
    }
    Elements[rear] = newElem;
    rear = (rear + 1) % size;
}
template <typename Data>
void lasd::QueueVec<Data>::Enqueue(Data&& newElem){
    if(((rear + 2) % size) == front){
        Expand();
    }
    Elements[rear] = newElem;
    rear = (rear + 1) % size;
}

//Specific member functions (inherited from Container)
template <typename Data>
bool lasd::QueueVec<Data>::Empty() const noexcept{
    return (Size() == 0);
}
template <typename Data>
unsigned long lasd::QueueVec<Data>::Size() const noexcept{
    return ((rear + size) - front) % size;
}
template <typename Data>
void lasd::QueueVec<Data>::Clear(){
    delete [] Elements;
    rear = 0;
    front = 1;          //index of the next element to add
    size = 4;
    Elements = new Data[size];
}

//Accessory Functions for Resizing
template <typename Data>
void lasd::QueueVec<Data>::Expand(){
    Data* tmpElements = new Data[size * 2];
    unsigned long i = 0;
    unsigned long j = front;
    for(; j != rear; i++, j = (j + 1) % size){
        tmpElements[i] = Elements[j];
    }
    std::swap(Elements,tmpElements);
    delete [] tmpElements;
    rear = i;
    front = 0;
    size *= 2; 
}
template <typename Data>
void lasd::QueueVec<Data>::Reduce(){
    if(size > 4){
        Data* tmpElements = new Data[size / 2];
        unsigned long i = 0;
        unsigned long j = front;
        for(; j != rear; i++, j = (j + 1) % size){
           tmpElements[i] = Elements[j];
        }
        std::swap(tmpElements, Elements);
        delete [] tmpElements;
        rear = i;
        front = 0;
        size /= 2;
    }
}
