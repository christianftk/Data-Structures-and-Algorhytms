template <typename Data>
void PrintElem(Data& dat, void* noPe){
    std::cout << dat << "  ";
}
/* template <typename Data>
void MapFunc(Data&, void*){
} */

template <typename Data>
void MainMenu_Heap(lasd::Heap<Data>& ds){
    short choice;
    Data elem;
    do{
        std::cout<< "\nSTATUS OF MY HEAP:\n\n";
        if(ds.Empty()){
            std::cout<< "- - - EMPTY - - -\n";
        }
        else{
            std::cout<< "SIZE= " << ds.Size() << "\nTREE= ";
            ds.MapPreOrder(PrintElem<Data>, nullptr);
        }
        std::cout<< "\n\n 1: Sort Tree\n 2: Apply specific Map Function in Pre Order\n 3: Apply specific Map Function in Post Order\n 4: Apply specific Fold Function in Pre Order\n 5: Apply specific Fold Function in Post Order\n 6: Search Element\n 7: Exit" << std::endl;
        std::cin>> choice;
        switch(choice){
            case 1:
                ds.Sort();
                std::cout << "\nOUTPUT= HEAP SORTED";
                break;
            case 2:
                SpecificMapFunctions(ds, '1');
                break;
            case 3:
                SpecificMapFunctions(ds, '2');
                break;
            case 4:
                SpecificFoldFunctions(ds, '1');
                break;
            case 5:
                SpecificFoldFunctions(ds, '2');
                break;
            case 6:
                std::cout<< "\nELEMENT: ";
                std::cin>> elem;
                if(ds.Exists(elem)){
                    std::cout<< "\nOUTPUT= ESISTS";
                }
                else{
                    std::cout<< "\nOUTPUT= DOESN'T EXISTS";
                }
                break;
            case 7:
                std::cout<< "\n TEST OVER";
                break;
            default:
                std::cout<< "****WRONG CHOICE****";
        }
    }while(choice != 7);
}
template <typename Data>
void MainMenu_PriorityQueue(lasd::PriorityQueue<Data>& ds){
    short choice;
    Data elem;
    do{
        std::cout<< "\nSTATUS OF MY PRIORITY QUEUE:\n\n";
        if(ds.Empty()){
            std::cout<< "- - - EMPTY - - -\n";
        }
        else{
            std::cout<< "SIZE= " << ds.Size() << "\nTREE= ";
            ds.MapPreOrder(PrintElem<Data>, nullptr);
        }
        std::cout<< "\n\n 1: Sort Tree\n 2: Insert Element\n 3: Tip\n 4: Remove Tip\n 5: TipNRemove\n 6: Navigate Queue starting from the Root\n 7: Apply specific Map Function in Pre Order\n 8: Apply specific Map Function in Post Order\n 9: Apply specific Fold Function in Pre Order\n 10: Apply specific Fold Function in Post Order\n 11: Search Element\n 12: Exit" << std::endl;
        std::cin>> choice;
        switch(choice){
            case 1:
                ds.Sort();
                std::cout<< "\nOUTPUT= PRIORITY QUEUE SORTED";
                break;
            case 2:
                std::cout<< "\nELEMENT: ";
                std::cin>> elem;
                ds.Insert(elem);
                std::cout<< "OUTPUT= ELEMENT ADDED";
                break;
            case 3:
                std::cout<< "\nOUTPUT= TIP IS " << ds.Tip();
                break;
            case 4:
                ds.RemoveTip();
                std::cout<< "\nOUTPUT= TIP REMOVED";
                break;
            case 5:
                std::cout<< "\nOUTPUT= " << ds.TipNRemove() << " HAS BEEN REMOVED";
                break;
            case 6:
                if(!ds.Empty()){
                    std::cout<< "\nENTERING NAVIGATION MODE FROM ROOT. . .";
                    NavigateTree(ds);
                }
                break;
            case 7:
                SpecificMapFunctions(ds, '1');
                break;
            case 8:
                SpecificMapFunctions(ds, '2');
                break;
            case 9:
                SpecificFoldFunctions(ds, '1');
                break;
            case 10:
                SpecificFoldFunctions(ds, '2');
                break;
            case 11:
                std::cout<< "\nElement: ";
                std::cin>> elem;
                if(ds.Exists(elem)){
                    std::cout<< "\nOUTPUT= ESISTS";
                }
                else{
                    std::cout<< "\nOUTPUT= DOESN'T EXISTS";
                }
                break;
            case 12:
                std::cout<< "\n TEST OVER";
                break;
            default:
                std::cout<< "****WRONG CHOICE****";
        }
    }while(choice != 12);
}

template <typename Data>
void NavigateTree(lasd::PriorityQueue<Data>& ds){
    char choice;
    Data newValue;

    typename lasd::BinaryTreeVec<Data>::NodeVec* curr = &(ds.Root());
    do{
        std::cout << "\n\n\n-- Current Status --\n";
        std::cout << "\nCURRENT NODE= " << curr->Element() << "\nLEFT CHILD = " << ((curr->HasLeftChild() ? curr->LeftChild().Element() : 0)) << "\nRIGHT CHILD = " << (curr->HasRightChild() ? curr->RightChild().Element() : 0) << std::endl << std::endl;
        std::cout << " 1: Print Node's properties\n 2: Change Priority\n 3: Move To Left\n 4: Move to Right\n 5: Go back to the other Menu\n\n My Choice: ";
        std::cin >> choice;
        switch(choice){
            case '1':
                std::cout << "\nNODE-Priority: " << curr->Element() << "\nNODE-Left : " << ((curr->HasLeftChild() ? curr->LeftChild().Element() : 0)) << "\nNODE-Right: " << (curr->HasRightChild() ? curr->RightChild().Element() : 0) << std::endl;
                break;
            case '2':
                std::cout << "\nNODE-Priority: " << curr->Element();
                std::cout << "\n New Priority: ";
                std::cin >> newValue;
                ds.ChangePriority(*curr, newValue);
                std::cout << "\n THE PRIORITY QUEUE MAY BE CHANGED";
                break;
            case '3':
                if(curr->HasLeftChild()){
                    curr = &(curr->LeftChild()); 
                }
                else{
                    std::cout << "\nThere's no Left Child here" << std::endl;
                }
                break;
            case '4':
                if(curr->HasRightChild()){
                    curr = &(curr->RightChild()); 
                }
                else{
                    std::cout << "\nThere's no Right Child here" << std::endl;
                }
                break;
            case '5':
                break;
            default:
                std::cout<< "****WRONG CHOICE****";
        }
    }while(choice != '5');
}
/* template <typename Data>
void PrintTree(const lasd::BinaryTreeVec<Data>::NodeVec& mRoot){
    int levelCounter = 0;
    lasd::BinaryTreeVec<Data>::NodeVec* curr = &mTree;
    std::cout << "\nPrinting Tree\n";
    std::cout << curr->Element() << std::endl;
    for(unsigned long  i = 1; i < 20; i++){
        if(pow(2, levelCounter) == i+1){
            levelCounter++;
            std::cout << "\n";
        }
        if(i % 2 == 1){
            std::cout<< curr->LeftChild().Element() << " ";
        }
        else{
            std::cout<< curr->RightChild().Element() << " ";

        }
    }
} */