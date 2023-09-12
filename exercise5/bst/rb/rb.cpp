
namespace lasd {

/* ************************************************************************** */

template <typename Data>
typename RB<Data>::RBNode* RB<Data>::RBNode::Left(){
    return (RBNode*)left;
}
template <typename Data>
typename RB<Data>::RBNode const* RB<Data>::RBNode::Left() const{
    return (RBNode*)left;
}
template <typename Data>
typename RB<Data>::RBNode* RB<Data>::RBNode::Right(){
    return (RBNode*)right;
}
template <typename Data>
typename RB<Data>::RBNode const* RB<Data>::RBNode::Right() const{
    return (RBNode*)right;
}


// ...

template <typename Data>
RB<Data>::RB(const RB& yTree){
    if(yTree.size != 0){
        NewRoot(yTree.Root().Element());
        TreeLnkCopy(&(yTree.Root()), &Root());
        size = yTree.Size();
    }
}
template <typename Data>
void RB<Data>::TreeLnkCopy(const RBNode* src, RBNode* dest){
    if(src->HasLeftChild()){
        dest->left = new NodeLnk(src->Left()->Element());
        dest->Left()->color = src->Left()->color;
        TreeLnkCopy(src->Left() , dest->Left());
    }
    if(src->HasRightChild()){
        dest->right = new NodeLnk(src->Right()->Element());
        dest->Right()->color = src->Right()->color;
        TreeLnkCopy(src->Right(), dest->Right());
    }
}
template <typename Data>
RB<Data>::RB(RB&& yTree) noexcept : BinaryTreeLnk<Data>(std::move(yTree)){
}
template <typename Data>
RB<Data>& RB<Data>::operator=(const RB& yTree){
    RB<Data>* tmp = new RB<Data>(yTree);
    std::swap(*this, *tmp);
    delete tmp;
    return *this;
}
template <typename Data>
RB<Data>& RB<Data>::operator=(RB&& yTree) noexcept{
    std::swap(root, yTree.root);
    std::swap(size, yTree.size);
    return *this;
}
template <typename Data>
bool RB<Data>::operator==(const RB& yTree) const noexcept{
    return BST<Data>::operator==(yTree);
}
template <typename Data>
bool RB<Data>::operator!=(const RB& yTree) const noexcept{
    return !(*this == yTree);
}
template <typename Data>
typename RB<Data>::RBNode& RB<Data>::Root(){
    if(root != nullptr){
        return *(RB<Data>::RBNode*)root;    
    }
    else{
        throw std::length_error("No Root");
    }
}
template <typename Data>
typename RB<Data>::RBNode const& RB<Data>::Root() const{
    if(root != nullptr){
        return *(RB<Data>::RBNode*)root;    
    }
    else{
        throw std::length_error("No Root");
    }
}

template <typename Data>
void RB<Data>::NewRoot(const Data& dat){
    BinaryTreeLnk<Data>::NewRoot(dat);
    Root().color = Color::black;
}
template <typename Data>
void RB<Data>::NewRoot(Data&& dat) noexcept{
    BinaryTreeLnk<Data>::NewRoot(dat);
    Root().color = Color::black;
}

template <typename Data>
void RB<Data>::Insert(const Data& dat){
    if(size != 0){
        root = Insert(&Root(), dat);
        Root().color = Color::black;
        size++;
    }
    else{
        NewRoot(dat);
    }
}
template <typename Data>
void RB<Data>::Insert(Data&& dat){
    if(size != 0){
        root = Insert(&Root(), dat);
        Root().color = Color::black;
        size++;
    }
    else{
        NewRoot(dat);
    }
}

template <typename Data>
typename RB<Data>::RBNode* RB<Data>::Insert(RBNode* nod, const Data& dat){
    if(nod != nullptr){
        if(nod->Element() < dat){
            nod->right = (NodeLnk*)Insert(nod->Right(), dat);
            nod = Bilancia_Insert_dx(nod);
        }
        else if(nod->Element() > dat){
            nod->left = (NodeLnk*)Insert(nod->Left(), dat);
            nod = Bilancia_Insert_sx(nod);
        }
    }
    else{
        nod = (RBNode*)new NodeLnk(dat);
        nod->color = Color::red;
    }
    return nod;
}

template <typename Data>
typename RB<Data>::RBNode* RB<Data>::Rotate_dx(RBNode* nod){
    if(nod != nullptr){
        RB<Data>::RBNode* nRoot = nod->Right();
        if(nRoot != nullptr){
            nod->right = (NodeLnk*)nRoot->Left();
            nRoot->left = (NodeLnk*)nod;
            nod = nRoot;
        }
    }
    return nod;
}
template <typename Data>
typename RB<Data>::RBNode* RB<Data>::Rotate_sx(RBNode* nod){
    if(nod != nullptr){
        RB<Data>::RBNode* nRoot = nod->Left();
        if(nRoot != nullptr){
            nod->left = (NodeLnk*)nRoot->Right();
            nRoot->right = (NodeLnk*)nod;
            nod = nRoot;
        }
    }
    return nod;
}

template <typename Data>
typename RB<Data>::RBNode* RB<Data>::Bilancia_Insert_sx(RBNode* nod){
    if(!(nod->Left()->IsLeaf())){
        short v = Violation_On_Insert_sx(nod->Left(), nod->Right());
        switch (v){
            case 1:
                nod = Bilancia_Insert_sx_1(nod);
                break;
            case 2:
                nod = Bilancia_Insert_sx_2(nod);
            case 3:
                nod = Bilancia_Insert_sx_3(nod);
        }
    }
    return nod;
}

template <typename Data>
short RB<Data>::Violation_On_Insert_sx(RBNode* l, RBNode* r){
    short violation = 0;
    if(l != nullptr && l->color == Color::red && r != nullptr && r->color == Color::red){
        if((l->Left() != nullptr && l->Left()->color == Color::red) || (l->Right() != nullptr && l->Right()->color == Color::red)){
            violation = 1;
        }
    }
    else{
        if(l != nullptr && l->color == Color::red){
            if(l->Right() != nullptr && l->Right()->color == Color::red){
                violation = 2;
            }
            else if(l->Left() != nullptr && l->Left()->color == Color::red){
                violation = 3;
            }
        }
    }
    return violation;
}
template <typename Data>
typename RB<Data>::RBNode* RB<Data>::Bilancia_Insert_sx_1(RBNode* nod){
    nod->color = Color::red;
    nod->Right()->color = Color::black;
    nod->Left()->color = Color::black;
    return nod;
}
template <typename Data>
typename RB<Data>::RBNode* RB<Data>::Bilancia_Insert_sx_2(RBNode* nod){
    nod->left = (NodeLnk*)Rotate_dx(nod->Left());
    return nod;
}
template <typename Data>
typename RB<Data>::RBNode* RB<Data>::Bilancia_Insert_sx_3(RBNode* nod){
    nod = Rotate_sx(nod);
    nod->color = Color::black;
    nod->Right()->color = Color::red;
    return nod;
}
template <typename Data>
typename RB<Data>::RBNode* RB<Data>::Bilancia_Insert_dx(RBNode* nod){
    if(!(nod->Right()->IsLeaf())){
        short v = Violation_On_Insert_dx(nod->Left(), nod->Right());
        switch (v){
            case 1:
                nod = Bilancia_Insert_dx_1(nod);
                break;
            case 2:
                nod = Bilancia_Insert_dx_2(nod);
            case 3:
                nod = Bilancia_Insert_dx_3(nod);
        }
    }
    return nod;
}

template <typename Data>
short RB<Data>::Violation_On_Insert_dx(RBNode* l, RBNode* r){
    short violation = 0;
    if(r != nullptr && r->color == Color::red && l != nullptr && l->color == Color::red){
        if((r->Right() != nullptr && r->Right()->color == Color::red) || (r->Left() != nullptr && r->Left()->color == Color::red)){
            violation = 1;
        }
    }
    else{
        if(r != nullptr && r->color == Color::red){
            if(r->Left() != nullptr && r->Left()->color == Color::red){
                violation = 2;
            }
            else if(r->Right() != nullptr && r->Right()->color == Color::red){
                violation = 3;
            }
        }
    }
    return violation;
}

// Bilancia_Insert_dx_1 is the same as Bilancia_Insert_sx_1 so i could avoid duplicating code
template <typename Data>
typename RB<Data>::RBNode* RB<Data>::Bilancia_Insert_dx_1(RBNode* nod){
    nod->color = Color::red;
    nod->Right()->color = Color::black;
    nod->Left()->color = Color::black;
    return nod;
}
template <typename Data>
typename RB<Data>::RBNode* RB<Data>::Bilancia_Insert_dx_2(RBNode* nod){
    nod->right = (NodeLnk*)Rotate_sx(nod->Right());
    return nod;
}
template <typename Data>
typename RB<Data>::RBNode* RB<Data>::Bilancia_Insert_dx_3(RBNode* nod){
    nod = Rotate_dx(nod);
    nod->color = Color::black;
    nod->Left()->color = Color::red;
    return nod;
}
template <typename Data>
void RB<Data>::Remove(const Data& dat){
    if(size > 1){
        root = Remove(&Root(),dat);
        size--;
    }
    else if(size == 1){
        delete root;
        root = nullptr;
        size--;
    }
    else{
        throw std::length_error("No Tree");
    }
}

template <typename Data>
typename RB<Data>::RBNode* RB<Data>::Remove(RBNode* nod, const Data& dat){
    if(nod != nullptr){
        if(nod->Element() > dat){
            nod->left = (NodeLnk*)Remove(nod->Left(), dat);
            nod = Bilancia_Delete_sx(nod);
        }
        else if(nod->Element() < dat){
            nod->right = (NodeLnk*)Remove(nod->Right(), dat);
            nod = Bilancia_Delete_dx(nod);
        }
        else {
            nod = RemoveRoot(nod);
        }
    }
    else{
        size++; // No dat found so it's necessary to increment size by 1 to balance the decrement at the end of the remove
    }
    return nod;
}
template <typename Data>
typename RB<Data>::RBNode* RB<Data>::RemoveRoot(RBNode* nod){
    if(nod != nullptr){
        RB<Data>::RBNode* tmp;
        if(nod->HasLeftChild() && nod->HasRightChild()){
            tmp = RemoveMin(nod->Right(), nod);
            nod->Element() = tmp->Element();
            nod = Bilancia_Delete_dx(nod);
        }
        else{
            tmp = nod;
            if(nod->HasRightChild()){
                nod = nod->Right();    
            }
            else if (nod->HasLeftChild()){
                nod = nod->Left();
            }
            else{
                nod = nullptr;
            }
            if(tmp->color == Color::black){
                Propagate_Black(nod);   // Deleting tmp so I propagate the color to the son
            }
        }
        delete tmp;
    }
    return nod;
}

template <typename Data>
void RB<Data>::Propagate_Black(RBNode* nod){
    if(nod != nullptr){
        if(nod->color == Color::red){
            nod->color = Color::black;
        }
        else{
            nod->color == Color::double_black;
        }
    }
}

template <typename Data>
typename RB<Data>::RBNode* RB<Data>::RemoveMin(RBNode* nod, RBNode* parent){
    RB<Data>::RBNode* tmp = nullptr;
    if(nod != nullptr){
        if(nod->HasLeftChild()){
            tmp = RemoveMin(nod->Left(), nod);
            if(nod == parent->left){
                parent->left = (NodeLnk*)Bilancia_Delete_sx(nod);
            }
            else{
                parent->right = (NodeLnk*)Bilancia_Delete_dx(nod);
            }
            nod = tmp;
        }
        else{
            tmp = nod;
            if(parent->left == nod){
                parent->left = nod->right;
            }
            else{
                parent->right = nod->right;
            }
            if(nod->color == Color::black){
                Propagate_Black(nod->Right());
            }
        }
    }
    return tmp;
}

template <typename Data>
typename RB<Data>::RBNode* RB<Data>::Bilancia_Delete_sx(RBNode* nod){
    if(nod != nullptr){
        if(!(nod->IsLeaf())){
            short v = Violation_On_Delete_sx(nod->Left(), nod->Right());
            switch (v){
                case 1:
                    nod = Bilancia_Delete_sx_1(nod);
                    nod->left = (NodeLnk*)Bilancia_Delete_sx(nod->Left());
                    break;
                case 2:
                    nod = Bilancia_Delete_sx_2(nod);
                    break;
                case 3:
                    nod = Bilancia_Delete_sx_3(nod);
                    break;
                case 4:
                    nod= Bilancia_Delete_sx_4(nod);
            }
        }
    }
    return nod;
}

// l and r are x and w in the algorithms 
//FIX FROM HERE
template <typename Data>
short RB<Data>::Violation_On_Delete_sx(RBNode* l, RBNode* r){
    short violation = 0;
    if((l != nullptr ? l->color : Color::double_black) == Color::double_black){
        if((r != nullptr ? r->color : Color::black) == Color::red){
            violation = 1;
        }
        else{
            if(r != nullptr){
                if(((r->Right() != nullptr ?  r->Right()->color : Color::black) == Color::black) && ((r->Left() != nullptr ? r->Left()->color : Color::black) == Color::black)){
                    violation = 2;
                }
                else if((r->Right() != nullptr ? r->Right()->color : Color::black) == Color::black){
                    violation = 3;
                }
                else if((r->Right() != nullptr ? r->Right()->color : Color::black) == Color::red){
                    violation = 4;
                }
            }
        }
    }
    return violation;
}

template <typename Data>
typename RB<Data>::RBNode* RB<Data>::Bilancia_Delete_sx_1(RBNode* nod){
    nod = Rotate_dx(nod);
    nod->color = Color::black;
    nod->Left()->color = Color::red;
    return nod;
}
template <typename Data>
typename RB<Data>::RBNode* RB<Data>::Bilancia_Delete_sx_2(RBNode* nod){
    nod->Right()->color = Color::red;
    if(nod->Left() != nullptr){
        nod->Left()->color = Color::black;
    }
    Propagate_Black(nod);
    return nod;
}
template <typename Data>
typename RB<Data>::RBNode* RB<Data>::Bilancia_Delete_sx_3(RBNode* nod){
    nod->right = (NodeLnk*)Rotate_sx(nod->Right());
    nod->Right()->color = Color::black;
    nod->Right()->Right()->color = Color::red;
    nod = Bilancia_Delete_sx_4(nod);
    return nod;
}
template <typename Data>
typename RB<Data>::RBNode* RB<Data>::Bilancia_Delete_sx_4(RBNode* nod){
    nod = Rotate_dx(nod);
    nod->Right()->color = nod->color;
    nod->color = nod->Left()->color;
    nod->Left()->color = Color::black;
    if(nod->Left()->Left() != nullptr){
        nod->Left()->Left()->color = Color::black;
    }
    return nod;
}
template <typename Data>
typename RB<Data>::RBNode* RB<Data>::Bilancia_Delete_dx(RBNode* nod){
    if(nod != nullptr){
        if(!(nod->IsLeaf())){
            short v = Violation_On_Delete_dx(nod->Left(), nod->Right());
            switch (v){
                case 1:
                    nod = Bilancia_Delete_dx_1(nod);
                    nod->right = (NodeLnk*)Bilancia_Delete_dx(nod->Right());
                    break;
                case 2:
                    nod = Bilancia_Delete_dx_2(nod);
                    break;
                case 3:
                    nod = Bilancia_Delete_dx_3(nod);
                    break;
                case 4:
                    nod= Bilancia_Delete_dx_4(nod);
            }
        }
    }
    return nod;
}

// l and r are x and w in the algorithms 
template <typename Data>
short RB<Data>::Violation_On_Delete_dx(RBNode* l, RBNode* r){
    short violation = 0;
    if((r != nullptr ? r->color : Color::double_black) == Color::double_black){
        //std::cout << "\n R Color is " << r->getColor(); 
        if((l != nullptr ? l->color : Color::black) == Color::red){
            violation = 1;
        }
        else{
            if(l != nullptr){
                if(((l->Left() != nullptr ?  l->Left()->color : Color::black) == Color::black) && ((l->Right() != nullptr ? l->Right()->color : Color::black) == Color::black)){
                    violation = 2;
                }
                else if((l->Left() != nullptr ? l->Left()->color : Color::black) == Color::black){
                    violation = 3;
                }
                else if((l->Left() != nullptr ? l->Left()->color : Color::black) == Color::red){
                    violation = 4;
                }
            }
        }
    }
    return violation;
}

template <typename Data>
typename RB<Data>::RBNode* RB<Data>::Bilancia_Delete_dx_1(RBNode* nod){
    nod = Rotate_sx(nod);
    nod->color = Color::black;
    nod->Right()->color = Color::red;
    return nod;
}
template <typename Data>
typename RB<Data>::RBNode* RB<Data>::Bilancia_Delete_dx_2(RBNode* nod){
    nod->Left()->color = Color::red;
    if(nod->Right() != nullptr){
        nod->Right()->color = Color::black;
    }
    Propagate_Black(nod);
    return nod;
}
template <typename Data>
typename RB<Data>::RBNode* RB<Data>::Bilancia_Delete_dx_3(RBNode* nod){
    nod->left = (NodeLnk*)Rotate_dx(nod->Left());
    nod->Left()->color = Color::black;
    nod->Left()->Left()->color = Color::red;
    nod = Bilancia_Delete_dx_4(nod);
    return nod;
}
template <typename Data>
typename RB<Data>::RBNode* RB<Data>::Bilancia_Delete_dx_4(RBNode* nod){
    nod = Rotate_sx(nod);
    nod->Left()->color = nod->color;
    nod->color = nod->Right()->color;
    nod->Right()->color = Color::black;
    if(nod->Right()->Right() != nullptr){
        nod->Right()->Right()->color = Color::black;
    }
    return nod;
}
/* ************************************************************************** */

template <typename Data>
void RB<Data>::RemoveMin(){
    if(size > 0){
        root = DeleteMin(&Root());
        size--;
    }
    else{
        throw std::length_error("Tree is empty");
    }
}
template <typename Data>
typename RB<Data>::RBNode* RB<Data>::DeleteMin(RBNode* nod){
    if(nod->Left() != nullptr){
        nod->left = (NodeLnk*)DeleteMin(nod->Left());
        nod = Bilancia_Delete_sx(nod);
    }
    else{
        nod = RemoveRoot(nod);
    }
    return nod;
}
template <typename Data>
Data RB<Data>::MinNRemove(){
    if(size > 0){
        Data dat = this->Min();
        root = DeleteMin(&Root());
        size--;
        return dat;
    }
    else{
        throw std::length_error("Tree is empty");
    }
}
template <typename Data>
void RB<Data>::RemoveMax(){
    if(size > 0){
        root = DeleteMax(&Root());
        size--;
    }
    else{
        throw std::length_error("Tree is empty");
    }
}
template <typename Data>
typename RB<Data>::RBNode* RB<Data>::DeleteMax(RBNode* nod){
    if(nod->Right() != nullptr){
        nod->right = (NodeLnk*)DeleteMax(nod->Right());
        nod = Bilancia_Delete_dx(nod);
    }
    else{
        nod = RemoveRoot(nod);
    }
    return nod;
}
template <typename Data>
Data RB<Data>::MaxNRemove(){
    if(size > 0){
        Data dat = this->Max();
        root = DeleteMax(&Root());
        size--;
        return dat;
    }
    else{
        throw std::length_error("Tree is empty");
    }
}

template <typename Data>
std::string RB<Data>::RBNode::getColor(){
    std::string ret;
    if(color == Color::red){
        ret = "R";
    }
    else if(color == Color::black){
        ret = "B";
    }
    else{
        ret = "DB";
    }
    return ret;
}
}
