template <typename Data>
void PrintElem(Data& dat, void* noPe){
    std::cout << dat << "  ";
}

template <typename Data>
void MainMenu(lasd::BST<Data>& ds){
    short choice;
    Data elem;
    do{
        std::cout<< "\nSTATUS OF MY TREE:\n\n";
        if(ds.Empty()){
            std::cout<< "- - - EMPTY - - -\n";
        }
        else{
            std::cout<< "SIZE= " << ds.Size() << "\nTREE:";
            std::cout << "\nPREORDER-\t";
            ds.MapPreOrder(PrintElem<Data>, nullptr);
            std::cout << "\nINORDER-\t";
            ds.MapInOrder(PrintElem<Data>, nullptr);
            std::cout << "\nPOSTORDER-\t";
            ds.MapPostOrder(PrintElem<Data>, nullptr);
            std::cout << "\nBREADTH-\t";
            ds.MapBreadth(PrintElem<Data>, nullptr);
        }
        std::cout<< "\n\n 1: Search Element\n 2: Apply specific Fold Function in Pre Order\n 3: Apply specific Fold Function in Order\n 4: Apply specific Fold Function in Post Order\n 5: Apply specific Fold Function in Breadth\n 6: Binary Search Tree Functions\n 7: Exit" << std::endl;
        std::cin>> choice;
        switch(choice){
            case 1:
                std::cout << "INPUT= ";
                std::cin >> elem;
                if(ds.Exists(elem)){
                    std::cout << "OUTPUT= true";
                }
                else{
                    std::cout << "OUTPUT= false";
                }
                break;
            case 2:
                SpecificFoldFunctions(ds, '1');
                break;
            case 3:
                SpecificFoldFunctions(ds, '2');
                break;
            case 4:
                SpecificFoldFunctions(ds, '3');
                break;
            case 5:
                SpecificFoldFunctions(ds, '4');
                break;
            case 6:
                std::cout << "\nOther Menu"; 
                SpecificBSTFunctions(ds);
                break;
        }
    }while(choice != 7);
}
template <typename Data>
void SpecificBSTFunctions(lasd::BST<Data>& ds){
    short choice;
    Data newValue;
    do{
        std::cout << "\n\n\n-- Current Status --\n";
        ds.MapPreOrder(PrintElem<Data>, nullptr);
        std::cout << "\n1: Insert Element\n 2: Remove Element\n 3: Read Min\n 4: Remove Min\n 5: MinNRemove\n 6: Read Max\n 7: Remove Max\n 8: MaxNRemove\n 9: Find Successor\n 10: Remove Successor\n 11: SuccessorNRemove\n 12: Find Predecessor\n 13: Remove Predecessor\n 14: PredecessorNRemove\n 15: Back to previous Menu\n\nMy Choice: ";
        std::cin >> choice;
        switch(choice){
            case 1:
                std::cout << "\nINPUT= ";
                std::cin >> newValue;
                ds.Insert(newValue);
                std::cout << "\nOUTPUT= Element added";
                break;
            case 2:
                std::cout << "\nINPUT= ";
                std::cin >> newValue;
                ds.Remove(newValue);
                std::cout << "\nOUTPUT= Element Removed";
                break;
            case 3:
                std::cout << "\nOUTPUT= Min is " << ds.Min();
                break;
            case 4:
                std::cout << "\nOUTPUT= Min Removed";
                ds.RemoveMin();
                break;
            case 5:
                std::cout << "\nOUTPUT= Min removed is " << ds.MinNRemove();
                break;
            case 6:
                std::cout << "\nOUTPUT= Max is " << ds.Max();
                break;
            case 7:
                std::cout << "\nOUTPUT= Max Removed";
                ds.RemoveMax();
                break;
            case 8:
                std::cout << "\nOUTPUT= Max removed is " << ds.MaxNRemove();
                break;
            case 9:
                std::cout << "\nINPUT= FInd successor of ";
                std::cin >> newValue;
                std::cout << "\nOUTPUT= Successor is " << ds.Successor(newValue);
                break;
            case 10:
                std::cout << "\nINPUT= Remove successor of ";
                std::cin >> newValue;
                std::cout << "\nOUTPUT= Successor Removed";
                ds.RemoveSuccessor(newValue);
                break;
            case 11:
                std::cout << "\nINPUT= Remove successor of ";
                std::cin >> newValue;
                std::cout << "\nOUTPUT= Successor removed is " << ds.SuccessorNRemove(newValue);
                break;
            case 12:
                std::cout << "\nINPUT= FInd predecessor of ";
                std::cin >> newValue;
                std::cout << "\nOUTPUT= Predecessor is " << ds.Predecessor(newValue);
                break;
            case 13:
                std::cout << "\nINPUT= Remove predecessor of ";
                std::cin >> newValue;
                std::cout << "\nOUTPUT= Predecessor Removed";
                ds.RemovePredecessor(newValue);
                break;
            case 14:
                std::cout << "\nINPUT= Remove predecessor of ";
                std::cin >> newValue;
                std::cout << "\nOUTPUT= Predecessor removed is " << ds.PredecessorNRemove(newValue);
                break;
            case 15:
                std::cout << "\n Other Menu";
            default:
                std::cout<< "****WRONG CHOICE****";
        }
    }while(choice != 5);
}