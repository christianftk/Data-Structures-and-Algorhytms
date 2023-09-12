
#include <stdexcept>

/* ************************************************************************** */
// Constructors
template <typename Data>
lasd::StackVec<Data>::StackVec(){
    size = 4;
    stackSize = 0;
    Elements = new Data[size];
}
template <typename Data>
lasd::StackVec<Data>::StackVec(const StackVec& yStack){
    Elements = new Data[yStack.size];
    std::copy(yStack.Elements, yStack.Elements + yStack.stackSize, Elements);
    size = yStack.size;
    stackSize = yStack.stackSize;
}
template <typename Data>
lasd::StackVec<Data>::StackVec(StackVec&& yStack) noexcept{
    std::swap(Elements, yStack.Elements);
    std::swap(size, yStack.size);
    std::swap(stackSize, yStack.stackSize);
}

// Operators
// -Assignment operators
template <typename Data>
lasd::StackVec<Data>& lasd::StackVec<Data>::operator=(const StackVec& yStack){
    StackVec<Data>* tmpStack = new StackVec<Data>(yStack);
    std::swap(*tmpStack, *this);
    delete tmpStack;
    return *this;
}
template <typename Data>
lasd::StackVec<Data>& lasd::StackVec<Data>::operator=(StackVec&& yStack) noexcept{
    std::swap(Elements, yStack.Elements);
    std::swap(size, yStack.size);
    std::swap(stackSize, yStack.stackSize);
    return *this;
}
// -Comparison operators
template <typename Data>
bool lasd::StackVec<Data>::operator==(const StackVec& yStack) const noexcept{
    bool equals = true;
    if(stackSize == yStack.stackSize){
        unsigned long i = 0;
        while(equals && i < stackSize){
            if(Elements[i] != yStack.Elements[i])
                equals = false;
            i++;
        }
    }
    else 
        equals = false;
    return equals;
}
template <typename Data>
bool lasd::StackVec<Data>::operator!=(const StackVec& yStack) const noexcept{
    return !(this == yStack);
}

// Specific member functions (inherited from Stack)
template <typename Data>
Data& lasd::StackVec<Data>::Top() const{
    if(stackSize != 0){
        return Elements[stackSize-1];
    }
    else{
        throw std::length_error("Accessing unknown position");
    }
}
template <typename Data>
void lasd::StackVec<Data>::Pop(){
    if(stackSize != 0){
        stackSize--;
        if(stackSize <= (size/4)){
            Reduce();
        }
    }
    else{
        throw std::length_error("Accessing unknown position");
    }
}
template <typename Data>
Data lasd::StackVec<Data>::TopNPop(){
    Data tmp = Top();
    Pop();
    return tmp;
}
template <typename Data>
void lasd::StackVec<Data>::Push(const Data& newElem){
    if(stackSize == size){
        Expand();
    }
    Elements[stackSize++] = newElem;
}
template <typename Data>
void lasd::StackVec<Data>::Push(Data&& newElem){
    if(stackSize == size){
        Expand();
    }
    Elements[stackSize++] = newElem;
}
// Specific member functions inherited from Container
template <typename Data>
unsigned long lasd::StackVec<Data>::Size() const noexcept{
    return stackSize;
}
template <typename Data>
bool lasd::StackVec<Data>::Empty() const noexcept{
    return (stackSize == 0);
}
template <typename Data>
void lasd::StackVec<Data>::Clear(){
    delete [] Elements;
    size = 4;
    Elements = new Data[size];
    stackSize = 0;
}
// Accessory functions for Resizing
template <typename Data>
void lasd::StackVec<Data>::Reduce(){
    if(size <= 4){
        Vector<Data>::Resize(size*0.5);
    }
}
template <typename Data>
void lasd::StackVec<Data>::Expand(){
    Vector<Data>::Resize(size*2);
}