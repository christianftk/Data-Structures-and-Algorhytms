
#include <stdexcept>

/* ************************************************************************** */
//Constructors
template <typename Data>
lasd::Vector<Data>::Vector(unsigned long dim){
    size=dim;
    Elements=new Data[size];
}
template <typename Data>
lasd::Vector<Data>::Vector(const Vector<Data>& v){
    Elements = new Data[v.size];
    std::copy(v.Elements, v.Elements + v.size, Elements);
    size = v.size;
}
template <typename Data>
lasd::Vector<Data>::Vector(Vector<Data>&& v) noexcept{
    std::swap(Elements, v.Elements);
    std::swap(size, v.size);
}
template <typename Data>
lasd::Vector<Data>::~Vector(){
    delete [] Elements;
    Elements = nullptr;
}

//Operators
//-Assignment operators
template <typename Data>
lasd::Vector<Data>& lasd::Vector<Data>::operator=(const Vector<Data>& v1){
    Vector<Data> v2(v1);
    std::swap(*v2, *this);
    delete v2;
    return *this;
}

template <typename Data>
lasd::Vector<Data>& lasd::Vector<Data>::operator=(Vector<Data>&& v1){
    std::swap(Elements, v1.Elements);
    std::swap(size, v1.size);
    delete v1;
    return *this;
}
//-Comparison operators
template <typename Data>
bool lasd::Vector<Data>::operator==(const Vector<Data>& v1) const noexcept{
    bool equals = true;
    if(size == v1.size){
        unsigned long i = 0;
        while(equals && i<size){
            if(Elements[i] != v1.Elements[i])
                equals = false;
            i++;
        }
    }
    else 
        equals = false;
    return equals;
}
template <typename Data>
bool lasd::Vector<Data>::operator!=(const Vector<Data>& v1) const noexcept{
    bool unequals = false;
    if(size == v1.size){
        for(unsigned long i; i < size; i++){
            if(Elements[i] != v1.Elements[i])
                unequals = true;
        }
    }
    return unequals;
}

//Specific member functions (inherited from Container)
template <typename Data>
void lasd::Vector<Data>::Clear(){
    delete [] Elements;
    Elements = nullptr;
    size = 0;
}

//Specific member functions of Vector
template <typename Data>
void lasd::Vector<Data>::Resize(unsigned long newDim){
    if(newDim == 0){
        Clear();
    }
    else if(newDim != size){
        unsigned long limit = (size < newDim) ? size : newDim;
        Data* tmpElements = new Data[newDim];
        for(unsigned long i = 0; i < limit; i++){
            std::swap(Elements[i], tmpElements[i]);
        }
        std::swap(Elements, tmpElements);
        size = newDim;
        delete [] tmpElements;
    }
}

//Specific member functions (inherited from LinearContainer)
template <typename Data>
Data& lasd::Vector<Data>::Front() const{
    if(size != 0){
        return Elements[0];
    }
    else{
        throw std::length_error("No elements foound");
    }
}
template <typename Data>
Data& lasd::Vector<Data>::Back() const{
    if(size != 0){
        return Elements[size - 1];
    }
    else{
        throw std::length_error("No elements found");
    }
}
template <typename Data>
Data& lasd::Vector<Data>::operator[](const unsigned long index)const {
    if(index < size){
        return Elements[index];
    }
    else{
        throw std::out_of_range("Accessing unknown position");
    }
}

//Specific member functions (inherited from SearchableContainer)
template <typename Data>
void lasd::Vector<Data>::MapPreOrder(MapFunctor mf, void* par){
    for(unsigned long i = 0; i < size; i++){
        mf(Elements[i], par);
    }
}
template <typename Data>
void lasd::Vector<Data>::MapPostOrder(MapFunctor mf, void* par){
    unsigned long i= size;
    while(i-- > 0){
        mf(Elements[i], par);
    }
}
template <typename Data>
void lasd::Vector<Data>::FoldPreOrder(FoldFunctor ff, const void* par, void* acc) const{
    for(unsigned long i = 0; i < size; i++){
        ff(Elements[i], par, acc);
    }
}
template <typename Data>
void lasd::Vector<Data>::FoldPostOrder(FoldFunctor ff, const void* par, void* acc) const{
    unsigned long i = size;
    while(i-- > 0){
        ff(Elements[i--], par, acc);
    }
}