#include <iostream>

// Specific member functions (Container)
bool lasd::Container::Empty() const noexcept{
    return size==0;
}
unsigned long lasd::Container::Size() const noexcept{
    return size;
}

// Specific member functions (SearchableContainer)
template <typename Data>
void FoldFunctor_Exists(const Data& dat, const void* val, void* found)noexcept {
    if(dat == *((Data*) val)){
        *((bool*) found) = true;
    }
}
template <typename Data>
bool lasd::SearchableContainer<Data>::Exists(const Data& dat) const noexcept{
    bool found = false;
    FoldPreOrder(FoldFunctor_Exists<Data>, &dat, &found);
    return found;
} 