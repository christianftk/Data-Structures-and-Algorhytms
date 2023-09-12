#include <iostream>
#include <random>
#include "../binarytree/binarytree.hpp"
#include "../binarytree/lnk/binarytreelnk.hpp"
#include "../binarytree/vec/binarytreevec.hpp"
#include "test.hpp"

void PrintSubTree(const lasd::BinaryTree<int>::Node&, const std::string&);
void PrintTree(const lasd::BinaryTree<int>::Node&);
void PrintSubTree(const lasd::BinaryTree<double>::Node&, const std::string&);
void PrintTree(const lasd::BinaryTree<double>::Node&);
void PrintSubTree(const lasd::BinaryTree<std::string>::Node&, const std::string&);
void PrintTree(const lasd::BinaryTree<std::string>::Node&);

//Accessory functions
void RandomSequenceInteger(lasd::BinaryTreeLnk<int>& ds, unsigned long dim);
void RandomSequenceDouble(lasd::BinaryTreeLnk<double>& ds, unsigned long dim);
void RandomSequenceString(lasd::BinaryTreeLnk<std::string>& ds, unsigned long dim);
void GenerateRandomTreeStructureOfIntegers(lasd::BinaryTreeLnk<int>& mtree, lasd::BinaryTreeLnk<int>::NodeLnk& curr, int& valToAdd);
void GenerateRandomTreeStructureOfDoubles(lasd::BinaryTreeLnk<double>& mtree, lasd::BinaryTreeLnk<double>::NodeLnk& curr, double& valToAdd);
void GenerateRandomTreeStructureOfStrings(lasd::BinaryTreeLnk<std::string>& mtree, lasd::BinaryTreeLnk<std::string>::NodeLnk& curr, const std::string& valToAdd);
void MainMenu_BinaryTreeLnk_Integer(lasd::BinaryTreeLnk<int>& ds);
void MainMenu_BinaryTreeLnk_Double(lasd::BinaryTreeLnk<double>& ds);
void MainMenu_BinaryTreeLnk_String(lasd::BinaryTreeLnk<std::string>& ds);
void VisitTree_Integer(lasd::BinaryTreeLnk<int>& ds);
void VisitTree_Double(lasd::BinaryTreeLnk<double>& ds);
void VisitTree_String(lasd::BinaryTreeLnk<std::string>& ds);

void RandomSequenceInteger(lasd::BinaryTreeVec<int>& ds, unsigned long dim);
void RandomSequenceDouble(lasd::BinaryTreeVec<double>& ds, unsigned long dim);
void RandomSequenceString(lasd::BinaryTreeVec<std::string>& ds, unsigned long dim);
void GenerateRandomTreeStructureOfIntegers(lasd::BinaryTreeVec<int>& mtree, lasd::BinaryTreeVec<int>::NodeVec& curr, int& valToAdd);
void GenerateRandomTreeStructureOfDoubles(lasd::BinaryTreeVec<double>& mtree, lasd::BinaryTreeVec<double>::NodeVec& curr, double& valToAdd);
void GenerateRandomTreeStructureOfStrings(lasd::BinaryTreeVec<std::string>& mtree, lasd::BinaryTreeVec<std::string>::NodeVec& curr, const std::string& valToAdd);
void MainMenu_BinaryTreeVec_Integer(lasd::BinaryTreeVec<int>& ds);
void MainMenu_BinaryTreeVec_Double(lasd::BinaryTreeVec<double>& ds);
void MainMenu_BinaryTreeVec_String(lasd::BinaryTreeVec<std::string>& ds);
void VisitTree_Integer(lasd::BinaryTreeVec<int>& ds);
void VisitTree_Double(lasd::BinaryTreeVec<double>& ds);
void VisitTree_String(lasd::BinaryTreeVec<std::string>& ds);


/* ************************************************************************** */
void VisitTree_Integer(lasd::BinaryTreeLnk<int>& ds){
    char choice;
    char answer;
    int newValue;

    lasd::BinaryTreeLnk<int>::NodeLnk* curr = &(ds.Root());
    do{
        std::cout << "\n\n\n-- Current Status --\n";
        std::cout << "\nROOT = " << curr->Element() << "\nLEFT CHILD = " << ((curr->HasLeftChild() ? curr->LeftChild().Element() : 0)) << "\nRIGHT CHILD = " << (curr->HasRightChild() ? curr->RightChild().Element() : 0) << std::endl << std::endl;
        std::cout << " 1: Print Node's properties\n 2: Read/write the data in the current Node\n 3: Move To Left\n 4: Move to Right\n 5: Add a Left Child\n 6: Add a Right Child\n 7: Remove Left Subtree\n 8: Remove Right Subtree\n 9: Go back to the other Menu\n\n My Choice: ";
        std::cin >> choice;
        switch(choice){
            case '1':
                std::cout << "\nNODE-value: " << curr->Element() << "\nNODE-left : " << ((curr->HasLeftChild() ? curr->LeftChild().Element() : 0)) << "\nNODE-right: " << (curr->HasRightChild() ? curr->RightChild().Element() : 0) << std::endl;
                break;
            case '2':
                std::cout << "\nNODE-Value: " << curr->Element() << "\nDo you want to change the value? (y/n)";
                std::cin >> answer;
                if(answer == 'y'){
                    std::cout << "\n New Value: ";
                    std::cin >> newValue;
                    curr->Element() = newValue;
                }
                else{
                    std::cout << "\n ok\n";
                }
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
                if(curr->HasLeftChild()){
                    std::cout << "You can't add a Left Child here cause it's already present\nDo you want to delete the old Left Child? (y/n)\n";
                    std::cin >> answer;
                    if(answer == 'y'){
                        ds.RemoveLeftChild(curr->LeftChild());
                        ds.RemoveRightChild(curr->LeftChild());
                        std::cout << "\n New Value: ";
                        std::cin >> newValue;
                        curr->LeftChild().Element() = newValue;
                    }else{
                        std::cout << "\nok\n";
                    }
                }else{
                        std::cout << "\n New Value: ";
                        std::cin >> newValue;
                        ds.AddLeftChild(*curr, newValue);
                }
                break;
            case '6':
                if(curr->HasRightChild()){
                    std::cout << "You can't add a Right Child here cause it's already present\nDo you want to delete the old Right Child? (y/n)\n";
                    std::cin >> answer;
                    if(answer == 'y'){
                        ds.RemoveLeftChild(curr->RightChild());
                        ds.RemoveRightChild(curr->RightChild());
                        std::cout << "\n New Value: ";
                        std::cin >> newValue;
                        curr->RightChild().Element() = newValue;
                    }else{
                        std::cout << "\nok\n";
                    }
                }else{
                        std::cout << "\n New Value: ";
                        std::cin >> newValue;
                        ds.AddRightChild(*curr, newValue);
                }
                break;
            case '7':
                if(curr->HasLeftChild()){
                    ds.RemoveLeftChild(*curr);
                }
                std::cout << "\nSubTree removed\n";
                break;
            case '8':
                if(curr->HasRightChild()){
                    ds.RemoveRightChild(*curr);
                }
                std::cout << "\nSubTree removed";
                break;
            case '9':
                break;
            default:
                std::cout<< "****WRONG CHOICE****";
        }
    }while(choice != '9');
}

void VisitTree_Double(lasd::BinaryTreeLnk<double>& ds){
    char choice;
    char answer;
    double newValue;

    lasd::BinaryTreeLnk<double>::NodeLnk* curr = &(ds.Root());
    do{
        std::cout << "\n\n\n-- Current Status --\n";
        std::cout << "\nROOT = " << curr->Element() << "\nLEFT CHILD = " << ((curr->HasLeftChild() ? curr->LeftChild().Element() : 0)) << "\nRIGHT CHILD = " << (curr->HasRightChild() ? curr->RightChild().Element() : 0) << std::endl << std::endl;
        std::cout << " 1: Print Node's properties\n 2: Read/write the data in the current Node\n 3: Move To Left\n 4: Move to Right\n 5: Add a Left Child\n 6: Add a Right Child\n 7: Remove Left Subtree\n 8: Remove Right Subtree\n 9: Go back to the other Menu\n\n My Choice: ";
        std::cin >> choice;
        switch(choice){
            case '1':
                std::cout << "\nNODE-value: " << curr->Element() << "\nNODE-left : " << ((curr->HasLeftChild() ? curr->LeftChild().Element() : 0)) << "\nNODE-right: " << (curr->HasRightChild() ? curr->RightChild().Element() : 0) << std::endl;
                break;
            case '2':
                std::cout << "\nNODE-Value: " << curr->Element() << "\nDo you want to change the value? (y/n)";
                std::cin >> answer;
                if(answer == 'y'){
                    std::cout << "\n New Value: ";
                    std::cin >> newValue;
                    curr->Element() = newValue;
                }
                else{
                    std::cout << "\n ok\n";
                }
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
                if(curr->HasLeftChild()){
                    std::cout << "You can't add a Left Child here cause it's already present\nDo you want delete the old Left Child? (y/n)\n";
                    std::cin >> answer;
                    if(answer == 'y'){
                        ds.RemoveLeftChild(curr->LeftChild());
                        ds.RemoveRightChild(curr->LeftChild());
                        std::cout << "\n New Value: ";
                        std::cin >> newValue;
                        curr->LeftChild().Element() = newValue;
                    }else{
                        std::cout << "\nok\n";
                    }
                }else{
                        std::cout << "\n New Value: ";
                        std::cin >> newValue;
                        ds.AddLeftChild(*curr, newValue);
                }
                break;
            case '6':
                if(curr->HasRightChild()){
                    std::cout << "You can't add a Right Child here cause it's already present\nDo you want delete the old Right Child? (y/n)\n";
                    std::cin >> answer;
                    if(answer == 'y'){
                        ds.RemoveLeftChild(curr->RightChild());
                        ds.RemoveRightChild(curr->RightChild());
                        std::cout << "\n New Value: ";
                        std::cin >> newValue;
                        curr->RightChild().Element() = newValue;
                    }else{
                        std::cout << "\nok\n";
                    }
                }else{
                        std::cout << "\n New Value: ";
                        std::cin >> newValue;
                        ds.AddRightChild(*curr, newValue);
                }
                break;
            case '7':
                if(curr->HasLeftChild()){
                    ds.RemoveLeftChild(*curr);
                }
                std::cout << "\nSubTree removed\n";
                break;
            case '8':
                if(curr->HasRightChild()){
                    ds.RemoveRightChild(*curr);
                }
                std::cout << "\nSubTree removed";
                break;
            case '9':
                break;
            default:
                std::cout<< "****WRONG CHOICE****";
        }
    }while(choice != '9');
}
void VisitTree_String(lasd::BinaryTreeLnk<std::string>& ds){
    char choice;
    char answer;
    std::string newValue;

    lasd::BinaryTreeLnk<std::string>::NodeLnk* curr = &(ds.Root());
    do{
        std::cout << "\n\n\n-- Current Status --\n";
        std::cout << "\nROOT = " << curr->Element() << "\nLEFT CHILD = " << ((curr->HasLeftChild() ? curr->LeftChild().Element() : " ")) << "\nRIGHT CHILD = " << (curr->HasRightChild() ? curr->RightChild().Element() : " ") << std::endl << std::endl;
        std::cout << " 1: Print Node's properties\n 2: Read/write the data in the current Node\n 3: Move To Left\n 4: Move to Right\n 5: Add a Left Child\n 6: Add a Right Child\n 7: Remove Left Subtree\n 8: Remove Right Subtree\n 9: Go back to the other Menu\n\n My Choice: ";
        std::cin >> choice;
        switch(choice){
            case '1':
                std::cout << "\nNODE-value: " << curr->Element() << "\nNODE-left : " << ((curr->HasLeftChild() ? curr->LeftChild().Element() : " ")) << "\nNODE-right: " << (curr->HasRightChild() ? curr->RightChild().Element() : " ") << std::endl;
                break;
            case '2':
                std::cout << "\nNODE-Value: " << curr->Element() << "\nDo you want to change the value? (y/n)";
                std::cin >> answer;
                if(answer == 'y'){
                    std::cout << "\n New Value: ";
                    std::cin >> newValue;
                    curr->Element() = newValue;
                }
                else{
                    std::cout << "\n ok\n";
                }
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
                if(curr->HasLeftChild()){
                    std::cout << "You can't add a Left Child here cause it's already present\nDo you want delete the old Left Child? (y/n)\n";
                    std::cin >> answer;
                    if(answer == 'y'){
                        ds.RemoveLeftChild(curr->LeftChild());
                        ds.RemoveRightChild(curr->LeftChild());
                        std::cout << "\n New Value: ";
                        std::cin >> newValue;
                        curr->LeftChild().Element() = newValue;
                    }else{
                        std::cout << "\nok\n";
                    }
                }else{
                        std::cout << "\n New Value: ";
                        std::cin >> newValue;
                        ds.AddLeftChild(*curr, newValue);
                }
                break;
            case '6':
                if(curr->HasRightChild()){
                    std::cout << "You can't add a Right Child here cause it's already present\nDo you want delete the old Right Child? (y/n)\n";
                    std::cin >> answer;
                    if(answer == 'y'){
                        ds.RemoveLeftChild(curr->RightChild());
                        ds.RemoveRightChild(curr->RightChild());
                        std::cout << "\n New Value: ";
                        std::cin >> newValue;
                        curr->RightChild().Element() = newValue;
                    }else{
                        std::cout << "\nok\n";
                    }
                }else{
                        std::cout << "\n New Value: ";
                        std::cin >> newValue;
                        ds.AddRightChild(*curr, newValue);
                }
                break;
            case '7':
                if(curr->HasLeftChild()){
                    ds.RemoveLeftChild(*curr);
                }
                std::cout << "\nSubTree removed\n";
                break;
            case '8':
                if(curr->HasRightChild()){
                    ds.RemoveRightChild(*curr);
                }
                std::cout << "\nSubTree removed";
                break;
            case '9':
                break;
            default:
                std::cout<< "****WRONG CHOICE****";
        }
    }while(choice != '9');
}
void VisitTree_Integer(lasd::BinaryTreeVec<int>& ds){
    int choice;
    char answer;
    int newValue;

    lasd::BinaryTreeVec<int>::NodeVec* curr = &(ds.Root());
    do{
        std::cout << "\n\n\n-- Current Status --\n";
        std::cout << "\nROOT = " << curr->Element() << "\nLEFT CHILD = " << ((curr->HasLeftChild() ? curr->LeftChild().Element() : 0)) << "\nRIGHT CHILD = " << (curr->HasRightChild() ? curr->RightChild().Element() : 0) << std::endl << std::endl;
        std::cout << " 1: Print Node's properties\n 2: Read/write the data in the current Node\n 3: Move To Left\n 4: Move to Right\n 5: Add a Left Child\n 6: Add a Right Child\n 7: Remove Left Subtree\n 8: Remove Right Subtree\n 9: Move to Parent\n 10: Move to Left Sibling\n 11: Move to Right Sibling\n 12: Go back to the other Menu\n\n My Choice: ";
        std::cin >> choice;
        switch(choice){
            case 1:
                std::cout << "\nNODE-value: " << curr->Element() << "\nNODE-left : " << ((curr->HasLeftChild() ? curr->LeftChild().Element() : 0)) << "\nNODE-right: " << (curr->HasRightChild() ? curr->RightChild().Element() : 0) << std::endl;
                break;
            case 2:
                std::cout << "\nNODE-Value: " << curr->Element() << "\nDo you want to change the value? (y/n)";
                std::cin >> answer;
                if(answer == 'y'){
                    std::cout << "\n New Value: ";
                    std::cin >> newValue;
                    curr->Element() = newValue;
                }
                else{
                    std::cout << "\n ok\n";
                }
                break;
            case 3:
                if(curr->HasLeftChild()){
                    curr = &(curr->LeftChild()); 
                }
                else{
                    std::cout << "\nThere's no Left Child here" << std::endl;
                }
                break;
            case 4:
                if(curr->HasRightChild()){
                    curr = &(curr->RightChild()); 
                }
                else{
                    std::cout << "\nThere's no Right Child here" << std::endl;
                }
                break;
            case 5:
                if(curr->HasLeftChild()){
                    std::cout << "You can't add a Left Child here cause it's already present\nDo you want to delete the old Left Child? (y/n)\n";
                    std::cin >> answer;
                    if(answer == 'y'){
                        ds.RemoveLeftChild(curr->LeftChild());
                        ds.RemoveRightChild(curr->LeftChild());
                        std::cout << "\n New Value: ";
                        std::cin >> newValue;
                        curr->LeftChild().Element() = newValue;
                    }else{
                        std::cout << "\nok\n";
                    }
                }else{
                        std::cout << "\n New Value: ";
                        std::cin >> newValue;
                        ds.AddLeftChild(*curr, newValue);
                }
                break;
            case 6:
                if(curr->HasRightChild()){
                    std::cout << "You can't add a Right Child here cause it's already present\nDo you want to delete the old Right Child? (y/n)\n";
                    std::cin >> answer;
                    if(answer == 'y'){
                        ds.RemoveLeftChild(curr->RightChild());
                        ds.RemoveRightChild(curr->RightChild());
                        std::cout << "\n New Value: ";
                        std::cin >> newValue;
                        curr->RightChild().Element() = newValue;
                    }else{
                        std::cout << "\nok\n";
                    }
                }else{
                        std::cout << "\n New Value: ";
                        std::cin >> newValue;
                        ds.AddRightChild(*curr, newValue);
                }
                break;
            case 7:
                if(curr->HasLeftChild()){
                    ds.RemoveLeftChild(*curr);
                }
                std::cout << "\nSubTree removed\n";
                break;
            case 8:
                if(curr->HasRightChild()){
                    ds.RemoveRightChild(*curr);
                }
                std::cout << "\nSubTree removed";
                break;
            case 9:
                if(curr->HasParent()){
                    curr = &(curr->Parent());
                }
                else{
                    std::cout << "\nNo Parent found :(\n";
                }
                break;
            case 10:
                if(curr->HasLeftSibling()){
                    curr = &(curr->LeftSibling());
                }
                else{
                    std::cout << "\nNo Left Sibling found :(\n";
                }
                break;
            case 11:
                if(curr->HasRightSibling()){
                    curr = &(curr->RightSibling());
                }
                else{
                    std::cout << "\nNo Right Sibling found :(\n";
                }
                break;
            case 12:
                break;
            default:
                std::cout<< "****WRONG CHOICE****";
        }
    }while(choice != 12);
}

void VisitTree_Double(lasd::BinaryTreeVec<double>& ds){
    int choice;
    char answer;
    double newValue;

    lasd::BinaryTreeVec<double>::NodeVec* curr = &(ds.Root());
    do{
        std::cout << "\n\n\n-- Current Status --\n";
        std::cout << "\nROOT = " << curr->Element() << "\nLEFT CHILD = " << ((curr->HasLeftChild() ? curr->LeftChild().Element() : 0)) << "\nRIGHT CHILD = " << (curr->HasRightChild() ? curr->RightChild().Element() : 0) << std::endl << std::endl;
        std::cout << " 1: Print Node's properties\n 2: Read/write the data in the current Node\n 3: Move To Left\n 4: Move to Right\n 5: Add a Left Child\n 6: Add a Right Child\n 7: Remove Left Subtree\n 8: Remove Right Subtree\n 9: Move to Parent\n 10: Move to Left Sibling\n 11: Move to Right Sibling\n 12: Go back to the other Menu\n\n My Choice: ";
        std::cin >> choice;
        switch(choice){
            case 1:
                std::cout << "\nNODE-value: " << curr->Element() << "\nNODE-left : " << ((curr->HasLeftChild() ? curr->LeftChild().Element() : 0)) << "\nNODE-right: " << (curr->HasRightChild() ? curr->RightChild().Element() : 0) << std::endl;
                break;
            case 2:
                std::cout << "\nNODE-Value: " << curr->Element() << "\nDo you want to change the value? (y/n)";
                std::cin >> answer;
                if(answer == 'y'){
                    std::cout << "\n New Value: ";
                    std::cin >> newValue;
                    curr->Element() = newValue;
                }
                else{
                    std::cout << "\n ok\n";
                }
                break;
            case 3:
                if(curr->HasLeftChild()){
                    curr = &(curr->LeftChild()); 
                }
                else{
                    std::cout << "\nThere's no Left Child here" << std::endl;
                }
                break;
            case 4:
                if(curr->HasRightChild()){
                    curr = &(curr->RightChild()); 
                }
                else{
                    std::cout << "\nThere's no Right Child here" << std::endl;
                }
                break;
            case 5:
                if(curr->HasLeftChild()){
                    std::cout << "You can't add a Left Child here cause it's already present\nDo you want delete the old Left Child? (y/n)\n";
                    std::cin >> answer;
                    if(answer == 'y'){
                        ds.RemoveLeftChild(curr->LeftChild());
                        ds.RemoveRightChild(curr->LeftChild());
                        std::cout << "\n New Value: ";
                        std::cin >> newValue;
                        curr->LeftChild().Element() = newValue;
                    }else{
                        std::cout << "\nok\n";
                    }
                }else{
                        std::cout << "\n New Value: ";
                        std::cin >> newValue;
                        ds.AddLeftChild(*curr, newValue);
                }
                break;
            case 6:
                if(curr->HasRightChild()){
                    std::cout << "You can't add a Right Child here cause it's already present\nDo you want delete the old Right Child? (y/n)\n";
                    std::cin >> answer;
                    if(answer == 'y'){
                        ds.RemoveLeftChild(curr->RightChild());
                        ds.RemoveRightChild(curr->RightChild());
                        std::cout << "\n New Value: ";
                        std::cin >> newValue;
                        curr->RightChild().Element() = newValue;
                    }else{
                        std::cout << "\nok\n";
                    }
                }else{
                        std::cout << "\n New Value: ";
                        std::cin >> newValue;
                        ds.AddRightChild(*curr, newValue);
                }
                break;
            case 7:
                if(curr->HasLeftChild()){
                    ds.RemoveLeftChild(*curr);
                }
                std::cout << "\nSubTree removed\n";
                break;
            case 8:
                if(curr->HasRightChild()){
                    ds.RemoveRightChild(*curr);
                }
                std::cout << "\nSubTree removed";
                break;
            case 9:
                if(curr->HasParent()){
                    curr = &(curr->Parent());
                }
                else{
                    std::cout << "\nNo Parent found :(\n";
                }
                break;
            case 10:
                if(curr->HasLeftSibling()){
                    curr = &(curr->LeftSibling());
                }
                else{
                    std::cout << "\nNo Left Sibling found :(\n";
                }
                break;
            case 11:
                if(curr->HasRightSibling()){
                    curr = &(curr->RightSibling());
                }
                else{
                    std::cout << "\nNo Right Sibling found :(\n";
                }
                break;
            case 12:
                break;
        }
    }while(choice != 9);
}
void VisitTree_String(lasd::BinaryTreeVec<std::string>& ds){
    int choice;
    char answer;
    std::string newValue;

    lasd::BinaryTreeVec<std::string>::NodeVec* curr = &(ds.Root());
    do{
        std::cout << "\n\n\n-- Current Status --\n";
        std::cout << "\nROOT = " << curr->Element() << "\nLEFT CHILD = " << ((curr->HasLeftChild() ? curr->LeftChild().Element() : " ")) << "\nRIGHT CHILD = " << (curr->HasRightChild() ? curr->RightChild().Element() : " ") << std::endl << std::endl;
        std::cout << " 1: Print Node's properties\n 2: Read/write the data in the current Node\n 3: Move To Left\n 4: Move to Right\n 5: Add a Left Child\n 6: Add a Right Child\n 7: Remove Left Subtree\n 8: Remove Right Subtree\n 9: Move to Parent\n 10: Move to Left Sibling\n 11: Move to Right Sibling\n 12: Go back to the other Menu\n\n My Choice: ";
        std::cin >> choice;
        switch(choice){
            case 1:
                std::cout << "\nNODE-value: " << curr->Element() << "\nNODE-left : " << ((curr->HasLeftChild() ? curr->LeftChild().Element() : " ")) << "\nNODE-right: " << (curr->HasRightChild() ? curr->RightChild().Element() : " ") << std::endl;
                break;
            case 2:
                std::cout << "\nNODE-Value: " << curr->Element() << "\nDo you want to change the value? (y/n)";
                std::cin >> answer;
                if(answer == 'y'){
                    std::cout << "\n New Value: ";
                    std::cin >> newValue;
                    curr->Element() = newValue;
                }
                else{
                    std::cout << "\n ok\n";
                }
                break;
            case 3:
                if(curr->HasLeftChild()){
                    curr = &(curr->LeftChild()); 
                }
                else{
                    std::cout << "\nThere's no Left Child here" << std::endl;
                }
                break;
            case 4: 
                if(curr->HasRightChild()){
                    curr = &(curr->RightChild()); 
                }
                else{
                    std::cout << "\nThere's no Right Child here" << std::endl;
                }
                break;
            case 5:
                if(curr->HasLeftChild()){
                    std::cout << "You can't add a Left Child here cause it's already present\nDo you want delete the old Left Child? (y/n)\n";
                    std::cin >> answer;
                    if(answer == 'y'){
                        ds.RemoveLeftChild(curr->LeftChild());
                        ds.RemoveRightChild(curr->LeftChild());
                        std::cout << "\n New Value: ";
                        std::cin >> newValue;
                        curr->LeftChild().Element() = newValue;
                    }else{
                        std::cout << "\nok\n";
                    }
                }else{
                        std::cout << "\n New Value: ";
                        std::cin >> newValue;
                        ds.AddLeftChild(*curr, newValue);
                }
                break;
            case 6:
                if(curr->HasRightChild()){
                    std::cout << "You can't add a Right Child here cause it's already present\nDo you want delete the old Right Child? (y/n)\n";
                    std::cin >> answer;
                    if(answer == 'y'){
                        ds.RemoveLeftChild(curr->RightChild());
                        ds.RemoveRightChild(curr->RightChild());
                        std::cout << "\n New Value: ";
                        std::cin >> newValue;
                        curr->RightChild().Element() = newValue;
                    }else{
                        std::cout << "\nok\n";
                    }
                }else{
                        std::cout << "\n New Value: ";
                        std::cin >> newValue;
                        ds.AddRightChild(*curr, newValue);
                }
                break;
            case 7:
                if(curr->HasLeftChild()){
                    ds.RemoveLeftChild(*curr);
                }
                std::cout << "\nSubTree removed\n";
                break;
            case 8:
                if(curr->HasRightChild()){
                    ds.RemoveRightChild(*curr);
                }
                std::cout << "\nSubTree removed";
                break;
            case 9:
                if(curr->HasParent()){
                    curr = &(curr->Parent());
                }
                else{
                    std::cout << "\nNo Parent found :(\n";
                }
                break;
            case 10:
                if(curr->HasLeftSibling()){
                    curr = &(curr->LeftSibling());
                }
                else{
                    std::cout << "\nNo Left Sibling found :(\n";
                }
                break;
            case 11:
                if(curr->HasRightSibling()){
                    curr = &(curr->RightSibling());
                }
                else{
                    std::cout << "\nNo Right Sibling found :(\n";
                }
                break;
            case 12:
                break;
        }
    }while(choice != 12);
}

/* ************************************************************************** */
void PrintSubTree(const lasd::BinaryTree<int>::Node& mRoot, const std::string& prefix){
    if(mRoot.IsLeaf()){
        return;
    }

    std::cout << prefix;
    std::cout << ((mRoot.HasLeftChild() && mRoot.HasRightChild()) ? "|_ _ _  " : "");
    std::cout << ((!mRoot.HasLeftChild() && mRoot.HasRightChild()) ? "\\_ _ _ " : "");

    if(mRoot.HasRightChild()){
        bool printStrand = (mRoot.HasLeftChild() && mRoot.HasRightChild() && (!mRoot.RightChild().HasRightChild() || !mRoot.LeftChild().HasLeftChild()));
        std::string newPrefix = prefix + (printStrand ? "|    " : "     ");
        std::cout << mRoot.RightChild().Element() << std::endl;
        PrintSubTree(mRoot.RightChild(), newPrefix);
    }
    if(mRoot.HasLeftChild()){
        std::cout << (mRoot.HasRightChild() ? prefix : "") << "  \\_ _ _ " << mRoot.LeftChild().Element() << std::endl;
        PrintSubTree(mRoot.LeftChild(), prefix + "      ");
    }
}
void PrintTree(const lasd::BinaryTree<int>::Node& mRoot){
    std::cout << mRoot.Element() << std::endl;
    std::cout << std::endl;
    PrintSubTree(mRoot, "");
}
void PrintSubTree(const lasd::BinaryTree<double>::Node& mRoot, const std::string& prefix){
    if(mRoot.IsLeaf()){
        return;
    }

    std::cout << prefix;
    std::cout << ((mRoot.HasLeftChild() && mRoot.HasRightChild()) ? "|_ _ _  " : "");
    std::cout << ((!mRoot.HasLeftChild() && mRoot.HasRightChild()) ? "\\_ _ _ " : "");

    if(mRoot.HasRightChild()){
        bool printStrand = (mRoot.HasLeftChild() && mRoot.HasRightChild() && (!mRoot.RightChild().HasRightChild() || !mRoot.LeftChild().HasLeftChild()));
        std::string newPrefix = prefix + (printStrand ? "|    " : "     ");
        std::cout << mRoot.RightChild().Element() << std::endl;
        PrintSubTree(mRoot.RightChild(), newPrefix);
    }
    if(mRoot.HasLeftChild()){
        std::cout << (mRoot.HasRightChild() ? prefix : "") << "  \\_ _ _ " << mRoot.LeftChild().Element() << std::endl;
        PrintSubTree(mRoot.LeftChild(), prefix + "      ");
    }
}
void PrintTree(const lasd::BinaryTree<double>::Node& mRoot){
    std::cout << mRoot.Element() << std::endl;
    std::cout << std::endl;
    PrintSubTree(mRoot, "");
}
void PrintSubTree(const lasd::BinaryTree<std::string>::Node& mRoot, const std::string& prefix){
    if(mRoot.IsLeaf()){
        return;
    }

    std::cout << prefix;
    std::cout << ((mRoot.HasLeftChild() && mRoot.HasRightChild()) ? "|_ _ _  " : "");
    std::cout << ((!mRoot.HasLeftChild() && mRoot.HasRightChild()) ? "\\_ _ _ " : "");

    if(mRoot.HasRightChild()){
        bool printStrand = (mRoot.HasLeftChild() && mRoot.HasRightChild() && (!mRoot.RightChild().HasRightChild() || !mRoot.LeftChild().HasLeftChild()));
        std::string newPrefix = prefix + (printStrand ? "|    " : "     ");
        std::cout << mRoot.RightChild().Element() << std::endl;
        PrintSubTree(mRoot.RightChild(), newPrefix);
    }
    if(mRoot.HasLeftChild()){
        std::cout << (mRoot.HasRightChild() ? prefix : "") << " \\_ _ _ " << mRoot.LeftChild().Element() << std::endl;
        PrintSubTree(mRoot.LeftChild(), prefix + "      ");
    }
}
void PrintTree(const lasd::BinaryTree<std::string>::Node& mRoot){
    std::cout << mRoot.Element() << std::endl;
    std::cout << std::endl;
    PrintSubTree(mRoot, "");
}
/* ************************************************************************** */
//Data Structure Selection functions
void PickDataStructure(char& ds){
    do{
        std::cout<< "Choose the data structure for your Binary Tree\n l: List\n v: Vector" << std::endl;
        std::cin>> ds;
    }while (ds != 'l' && ds != 'v');
}
void PickDataType(char& dt){
    do{
        std::cout<< "Choose the data type you want to test\n i: Integers\n d: Doubles\n s: Strings" << std::endl;
        std::cin>> dt;
    }while (dt != 'i' && dt != 'd' && dt != 's');
}
void LogDecision()noexcept{
    std::cout << "\n FOR YOUR BINARY TREE YOU PICKED \n";
}
void StartMyTest(char& ds, char& dt){
    switch(ds){
        case 'l':
            BinaryTreeLnkType(dt);
            break;
        case 'v':
            BinaryTreeVecType(dt);
            break;
        default:
            std::cout << " Something went wrong ";
    }
}

void BinaryTreeLnkType(char& dt){
    switch(dt){
        case 'i':
            std::cout<<"Integers\n\n";
            GenerateBinaryTreeLnkOfIntegers();
            break;
         case 'd':
            std::cout<<"Doubles\n\n";
            GenerateBinaryTreeLnkOfDoubles();
            break; 
         case 's':
            std::cout<<"Strings\n\n";
            GenerateBinaryTreeLnkOfStrings();       
            break;
        default:
            std::cout<< " Something went wrong ";
    }
}

void BinaryTreeVecType(char& dt){
    switch(dt){
        case 'i':
            std::cout<<"Integers\n\n";
            GenerateBinaryTreeVecOfIntegers();
            break;
        case 'd':
            std::cout<<"Doubles\n\n";
            GenerateBinaryTreeVecOfDoubles();
            break;
        case 's':
            std::cout<<"Strings\n\n";
            GenerateBinaryTreeVecOfStrings();       
            break;
        default:
            std::cout<< " Something went wrong ";
    }
}

// Generator Functions
// -Lists
void GenerateBinaryTreeLnkOfStrings(){
    unsigned long dim = GetDimension();    
    lasd::BinaryTreeLnk<std::string> mtree;
    RandomSequenceString(mtree, dim);
    MainMenu_BinaryTreeLnk_String(mtree);
}
void GenerateBinaryTreeLnkOfIntegers(){
    unsigned long dim = GetDimension();
    lasd::BinaryTreeLnk<int> mtree;
    RandomSequenceInteger(mtree, dim);
    MainMenu_BinaryTreeLnk_Integer(mtree);
}
void GenerateBinaryTreeLnkOfDoubles(){
    unsigned long dim = GetDimension();
    lasd::BinaryTreeLnk<double> mtree;
    RandomSequenceDouble(mtree, dim);
    MainMenu_BinaryTreeLnk_Double(mtree);
}

// -Vectors
void GenerateBinaryTreeVecOfStrings(){
    unsigned long dim = GetDimension();    
    lasd::BinaryTreeVec<std::string> mtree;
    RandomSequenceString(mtree, dim);
    MainMenu_BinaryTreeVec_String(mtree);
}
void GenerateBinaryTreeVecOfIntegers(){
    unsigned long dim = GetDimension();
    lasd::BinaryTreeVec<int> mtree;
    RandomSequenceInteger(mtree, dim);
    MainMenu_BinaryTreeVec_Integer(mtree);
}
void GenerateBinaryTreeVecOfDoubles(){
    unsigned long dim = GetDimension();
    lasd::BinaryTreeVec<double> mtree;
    RandomSequenceDouble(mtree, dim);
    MainMenu_BinaryTreeVec_Double(mtree);
}
 
unsigned long GetDimension(){   // Get Dimension of the Data Structure from the user
    unsigned long dim = 0;
    std::cout<< "How many elements do you want to generate randomly?!" << std::endl;
    std::cin>> dim;
    return dim;
}
//Generators of Random Sequence of values according to the type of the Data Structure
  std::string generateRandomString(const int& n_reps){   //Accessory function for random string generation
  std::default_random_engine seed(std::random_device{}());
  std::uniform_int_distribution<char> fillString('a','z');
  std::string newString = {""};
  for(int i = 0 ;i<n_reps;i++){
    newString += fillString(seed);
  }
  return newString;
} 

void RandomSequenceInteger(lasd::BinaryTreeLnk<int>& ds, unsigned long dim){
    std::default_random_engine seq(1566);
    std::uniform_int_distribution<int> distr(1,1000);
    int ToAdd;

    for(unsigned long i = 0; i < dim; i++){
        if(ds.Empty()){
            ds.NewRoot(distr(seq));
        }
        else{
            ToAdd = distr(seq);
            GenerateRandomTreeStructureOfIntegers(ds, ds.Root(), ToAdd);
        }
    }
}
void RandomSequenceDouble(lasd::BinaryTreeLnk<double>& ds, unsigned long dim){
    std::default_random_engine seq(123);
    std::uniform_real_distribution<double> distr(0,1);
    double ToAdd;
    for(unsigned long i = 0; i < dim; i++){
        if(ds.Empty()){
            ds.NewRoot((round(distr(seq)*10000))/100);
        }
        else{
            ToAdd = round(distr(seq)*10000)/100;
            GenerateRandomTreeStructureOfDoubles(ds, ds.Root(), ToAdd);
        }
    }
}
void RandomSequenceString(lasd::BinaryTreeLnk<std::string>& ds, unsigned long dim){
    std::default_random_engine seq(2113);
    std::uniform_int_distribution<int> distr(1,15);
    for(unsigned long i = 0; i < dim; i++){
        if(ds.Empty()){
            ds.NewRoot(generateRandomString(distr(seq)));
        }
        else{
            GenerateRandomTreeStructureOfStrings(ds, ds.Root(), generateRandomString(distr(seq)));
        }
    }
}

void RandomSequenceInteger(lasd::BinaryTreeVec<int>& ds, unsigned long dim){
    std::default_random_engine seq(42);
    std::uniform_int_distribution<int> distr(1,1000);
    int ToAdd;
    for(unsigned long i = 0; i < dim; i++){
        if(ds.Empty()){
            ds.NewRoot(distr(seq));
        }
        else{
            ToAdd = distr(seq);
            GenerateRandomTreeStructureOfIntegers(ds, ds.Root(), ToAdd);
        }
    }
}
void RandomSequenceDouble(lasd::BinaryTreeVec<double>& ds, unsigned long dim){
    std::default_random_engine seq(21);
    std::uniform_real_distribution<double> distr(0,1);
    double ToAdd;
    for(unsigned long i = 0; i < dim; i++){
        if(ds.Empty()){
            ds.NewRoot((round(distr(seq)*10000))/100);
        }
        else{
            ToAdd = round(distr(seq)*10000)/100;
            GenerateRandomTreeStructureOfDoubles(ds, ds.Root(), ToAdd);
        }
    }
}
void RandomSequenceString(lasd::BinaryTreeVec<std::string>& ds, unsigned long dim){
    std::default_random_engine seq(2466);
    std::uniform_int_distribution<int> distr(1,15);
    for(unsigned long i = 0; i < dim; i++){
        if(ds.Empty()){
            ds.NewRoot(generateRandomString(distr(seq)));
        }
        else{
            GenerateRandomTreeStructureOfStrings(ds, ds.Root(), generateRandomString(distr(seq)));
        }
    }
}

void GenerateRandomTreeStructureOfIntegers(lasd::BinaryTreeLnk<int>& mtree, lasd::BinaryTreeLnk<int>::NodeLnk& curr, int& valToAdd){
    if(valToAdd % 6 < 3){
        valToAdd *= 4;
        if(curr.HasLeftChild())
            GenerateRandomTreeStructureOfIntegers(mtree,curr.LeftChild(), valToAdd);
        else
            mtree.AddLeftChild(curr, valToAdd);
    }else{
        valToAdd *= 3;
        if(curr.HasRightChild())
            GenerateRandomTreeStructureOfIntegers(mtree, curr.RightChild(),valToAdd);
        else
            mtree.AddRightChild(curr, valToAdd);
    }

}
void GenerateRandomTreeStructureOfDoubles(lasd::BinaryTreeLnk<double>& mtree, lasd::BinaryTreeLnk<double>::NodeLnk& curr, double& valToAdd){
    if(valToAdd/10.0 > 5.0){
        valToAdd += 7.5;
        if(curr.HasLeftChild())
            GenerateRandomTreeStructureOfDoubles(mtree,curr.LeftChild(), valToAdd);
        else
            mtree.AddLeftChild(curr, valToAdd);
    }else{
        valToAdd -= 2.72;
        if(curr.HasRightChild())
            GenerateRandomTreeStructureOfDoubles(mtree, curr.RightChild(), valToAdd);
        else
            mtree.AddRightChild(curr, valToAdd);
    }
}
void GenerateRandomTreeStructureOfStrings(lasd::BinaryTreeLnk<std::string>& mtree, lasd::BinaryTreeLnk<std::string>::NodeLnk& curr, const std::string& valToAdd){
    if(valToAdd.length() < 7){
        if(curr.HasLeftChild())
            GenerateRandomTreeStructureOfStrings(mtree,curr.LeftChild(), valToAdd);
        else
            mtree.AddLeftChild(curr, valToAdd);
    }else{
        if(curr.HasRightChild())
            GenerateRandomTreeStructureOfStrings(mtree, curr.RightChild(), valToAdd);
        else
            mtree.AddRightChild(curr, valToAdd);
    }
}

void GenerateRandomTreeStructureOfIntegers(lasd::BinaryTreeVec<int>& mtree, lasd::BinaryTreeVec<int>::NodeVec& curr, int& valToAdd){
    if(valToAdd % 6 < 3){
        valToAdd += 9 ;
        if(curr.HasLeftChild())
            GenerateRandomTreeStructureOfIntegers(mtree,curr.LeftChild(), valToAdd);
        else
            mtree.AddLeftChild(curr, valToAdd);
    }else{
        valToAdd -= 7;
        if(curr.HasRightChild())
            GenerateRandomTreeStructureOfIntegers(mtree, curr.RightChild(),valToAdd);
        else
            mtree.AddRightChild(curr, valToAdd);
    }
}
void GenerateRandomTreeStructureOfDoubles(lasd::BinaryTreeVec<double>& mtree, lasd::BinaryTreeVec<double>::NodeVec& curr, double& valToAdd){
    if((int)valToAdd%100 > 30){
        valToAdd *= 3.75;
        if(curr.HasLeftChild())
            GenerateRandomTreeStructureOfDoubles(mtree,curr.LeftChild(), valToAdd);
        else
            mtree.AddLeftChild(curr, valToAdd);
    }else{
        valToAdd *= 0.80;
        if(curr.HasRightChild())
            GenerateRandomTreeStructureOfDoubles(mtree, curr.RightChild(), valToAdd);
        else
            mtree.AddRightChild(curr, valToAdd);
    }
}
void GenerateRandomTreeStructureOfStrings(lasd::BinaryTreeVec<std::string>& mtree, lasd::BinaryTreeVec<std::string>::NodeVec& curr, const std::string& valToAdd){
    if(valToAdd.length() < 7){
        if(curr.HasLeftChild())
            GenerateRandomTreeStructureOfStrings(mtree,curr.LeftChild(), valToAdd);
        else
            mtree.AddLeftChild(curr, valToAdd);
    }else{
        if(curr.HasRightChild())
            GenerateRandomTreeStructureOfStrings(mtree, curr.RightChild(), valToAdd);
        else
            mtree.AddRightChild(curr, valToAdd);
    }
}

void PrintElemInteger(const int& val, void*){
    std::cout << val << " ";
}
void PrintElemDouble(const double& val, void*){
    std::cout << val << " ";
}
void PrintElemString(const std::string& val, void*){
    std::cout << val << " ";
}
// ...
void MapFunctionInteger(int& x, void*){
    x *= 3;
}
void MapFunctionDouble(double& x, void*){
    x = x*x*x;
}
void MapFunctionString(std::string& x, void* valToAppend){
    x = x + (*(std::string*)valToAppend);
}
void FoldFunctionInteger(const int& x, const void* n, void* res){
    if(x < (*(int*)n))
        (*(int*)res) *= x;
}
void FoldFunctionDouble(const double& x, const void* n, void* res){
    if(x > (*(double*)n))
        (*(double*)res) += x;
}
void FoldFunctionString(const std::string& x, const void* n, void* res){
    std::cout << x << " ha lenght " << x.length() << std::endl;
    if(x.length() <= (*(int*)n))
        (*(std::string*)res) += x;
}
void MainMenu_BinaryTreeLnk_Integer(lasd::BinaryTreeLnk<int>& ds){
    char choice;
    int elem;
    int res;
    do{
        std::cout<< "\nSTATUS OF MY BINARY TREE:\n\n";
        PrintTree(ds.Root());
        std::cout<< "\n\n 1: Print in pre order\n 2: Print in order\n 3: Print in post order\n 4: Print in breadth\n 5: Search Element\n 6: Apply specific Fold Function for Integers\n 7: Apply specific Map Function for Integers\n 8: Visit Tree starting from the root\n 9: Exit\n" << std::endl;
        std::cin>> choice;
        switch(choice){
            case '1':
                std::cout<< "PRINT- PRE ORDER\nOUTPUT= ";
                ds.MapPreOrder(PrintElemInteger, nullptr);
                break;
            case '2':
                std::cout<< "PRINT- IN ORDER\nOUTPUT= ";
                ds.MapInOrder(PrintElemInteger, nullptr);
                break;
            case '3':
                std::cout<< "PRINT- POST ORDER\nOUTPUT= ";
                ds.MapPostOrder(PrintElemInteger, nullptr);
                break;
            case '4':
                std::cout<< "PRINT- BREADTH\nOUTPUT= ";
                ds.MapBreadth(PrintElemInteger, nullptr);
                break;
            case '5':
                std::cout << "SEARCH ELEMENT: ";
                std::cin >> elem;
                std::cout << "OUTPUT= " << (ds.Exists(elem) ? "true" : "false");
                break;
            case '6':
                res = 1;
                std::cout << "MULTIPLY ALL THE ELEMENTS LESS THAN: ";
                std::cin >> elem;
                ds.FoldBreadth(FoldFunctionInteger, ((const void*)&elem), ((void*)&res));
                std::cout << "OUTPUT= " << res;
                break;
            case '7':
                std::cout << "APPLYING THE FOLLOWING FUNCTION\n  F(x) = 3x" << std::endl;
                ds.MapBreadth(MapFunctionInteger, nullptr);
                break;
            case '8':
                std::cout << "NOW VISITING TREE STARTING FROM ROOT:\n\n";
                VisitTree_Integer(ds);
                break;
            case '9':
                std::cout<< "\n!-----HAVE A GOOD DAY-----!" << std::endl;
                break;
            default:
                std::cout<< "****WRONG CHOICE****";
        }
    }while(choice != '9');
}
void MainMenu_BinaryTreeLnk_Double(lasd::BinaryTreeLnk<double>& ds){
    char choice;
    double elem;
    double res;
    do{
        PrintTree(ds.Root());
        std::cout<< "\nSTATUS OF MY BINARY TREE:\n\n";
        std::cout<< "\n\n 1: Print in pre order\n 2: Print in order\n 3: Print in post order\n 4: Print in breadth\n 5: Search Element\n 6: Apply specific Fold Function for Doubles\n 7: Apply specific Map Function for Doubles\n 8: Visit Tree starting from the root\n 9: Exit\n" << std::endl;
        std::cin>> choice;
        switch(choice){
            case '1':
                std::cout<< "PRINT- PRE ORDER\nOUTPUT= ";
                ds.MapPreOrder(PrintElemDouble, nullptr);
                break;
            case '2':
                std::cout<< "PRINT- IN ORDER\nOUTPUT= ";
                ds.MapInOrder(PrintElemDouble, nullptr);
                break;
            case '3':
                std::cout<< "PRINT- POST ORDER\nOUTPUT= ";
                ds.MapPostOrder(PrintElemDouble, nullptr);
                break;
            case '4':
                std::cout<< "PRINT- BREADTH\nOUTPUT= ";
                ds.MapBreadth(PrintElemDouble, nullptr);
                break;
            case '5':
                std::cout << "SEARCH ELEMENT: ";
                std::cin >> elem;
                std::cout << "OUTPUT= " << (ds.Exists(elem) ? "true" : "false" );
                break;
            case '6':
                res = 0.0;
                std::cout << "SUM ALL THE ELEMENTS GREATER THAN: ";
                std::cin >> elem;
                ds.FoldBreadth(FoldFunctionDouble, ((const void*)&elem), ((void*)&res));
                std::cout << "OUTPUT= " << res;
                break;
            case '7':
                std::cout << "APPLYING THE FOLLOWING FUNCTION\n  F(x) = x^3";
                ds.MapBreadth(MapFunctionDouble, nullptr);
                break;
            case '8':
                std::cout << "NOW VISITING TREE STARTING FROM ROOT:\n\n";
                VisitTree_Double(ds);
                break;
            case '9':
                std::cout<< "\n!-----HAVE A GOOD DAY-----!" << std::endl;
                break;
            default:
                std::cout<< "****WRONG CHOICE****";
        }
    }while(choice != '9');
}
void MainMenu_BinaryTreeLnk_String(lasd::BinaryTreeLnk<std::string>& ds){
    char choice;
    std::string elem;
    std::string res;
    int n;
    do{
        std::cout<< "\nSTATUS OF MY BINARY TREE:\n\n";
        PrintTree(ds.Root());
        std::cout<< "\n\n 1: Print in pre order\n 2: Print in order\n 3: Print in post order\n 4: Print in breadth\n 5: Search Element\n 6: Apply specific Fold Function for Strings\n 7: Apply specific Map Function for Strings\n 8: Visit Tree starting from the root\n 9: Exit\n" << std::endl;
        std::cin>> choice;
        switch(choice){
            case '1':
                std::cout<< "PRINT- PRE ORDER\nOUTPUT= ";
                ds.MapPreOrder(PrintElemString, nullptr);
                break;
            case '2':
                std::cout<< "PRINT- IN ORDER\nOUTPUT= ";
                ds.MapInOrder(PrintElemString, nullptr);
                break;
            case '3':
                std::cout<< "PRINT- POST ORDER\nOUTPUT= ";
                ds.MapPostOrder(PrintElemString, nullptr);
                break;
            case '4':
                std::cout<< "PRINT- BREADTH\nOUTPUT= ";
                ds.MapBreadth(PrintElemString, nullptr);
                break;
            case '5':
                std::cout << "SEARCH ELEMENT: ";
                std::cin >> elem;
                std::cout << "OUTPUT= " << (ds.Exists(elem) ? "true" : "false" );
                break;
            case '6':
                res = "";
                std::cout << "CONCATENATION OF ALL THE STRINGS SHORTER THAN OR EQUAL TO: ";
                std::cin >> n;
                ds.FoldInOrder(FoldFunctionString, ((const void*)&n), ((void*)&res));
                std::cout << "OUTPUT= " << res;
                break;
            case '7':
                std::cout << "STRING TO APPEND: ";
                std::cin >> elem;
                std::cout << "APPLYING THE FOLLOWING FUNCTION\n  F(x) = x + " << elem;
                ds.MapBreadth(MapFunctionString, (void*)&elem);
                break;
            case '8':
                std::cout << "NOW VISITING TREE STARTING FROM ROOT:\n\n";
                VisitTree_String(ds);
                break;
            case '9':
                std::cout<< "\n!-----HAVE A GOOD DAY-----!" << std::endl;
                break;
            default:
                std::cout<< "****WRONG CHOICE****";
        }
    }while(choice != '9');
}
void MainMenu_BinaryTreeVec_Integer(lasd::BinaryTreeVec<int>& ds){
    char choice;
    int elem;
    int res;
    do{
        std::cout<< "\nSTATUS OF MY BINARY TREE:\n\n";
        PrintTree(ds.Root());
        std::cout<< "\n\n 1: Print in pre order\n 2: Print in order\n 3: Print in post order\n 4: Print in breadth\n 5: Search Element\n 6: Apply specific Fold Function for Integers\n 7: Apply specific Map Function for Integers\n 8: Visit Tree starting from the root\n 9: Exit\n" << std::endl;
        std::cin>> choice;
        switch(choice){
            case '1':
                std::cout<< "PRINT- PRE ORDER\nOUTPUT= ";
                ds.MapPreOrder(PrintElemInteger, nullptr);
                break;
            case '2':
                std::cout<< "PRINT- IN ORDER\nOUTPUT= ";
                ds.MapInOrder(PrintElemInteger, nullptr);
                break;
            case '3':
                std::cout<< "PRINT- POST ORDER\nOUTPUT= ";
                ds.MapPostOrder(PrintElemInteger, nullptr);
                break;
            case '4':
                std::cout<< "PRINT- BREADTH\nOUTPUT= ";
                ds.MapBreadth(PrintElemInteger, nullptr);
                break;
            case '5':
                std::cout << "SEARCH ELEMENT: ";
                std::cin >> elem;
                std::cout << "OUTPUT= " << (ds.Exists(elem) ? "true" : "false");
                break;
            case '6':
                res = 1;
                std::cout << "MULTIPLY ALL THE ELEMENTS LESS THAN: ";
                std::cin >> elem;
                ds.FoldBreadth(FoldFunctionInteger, ((const void*)&elem), ((void*)&res));
                std::cout << "OUTPUT= " << res;
                break;
            case '7':
                std::cout << "APPLYING THE FOLLOWING FUNCTION\n  F(x) = 3x" << std::endl;
                ds.MapBreadth(MapFunctionInteger, nullptr);
                break;
            case '8':
                std::cout << "NOW VISITING TREE STARTING FROM ROOT:\n\n";
                VisitTree_Integer(ds);
                break;
            case '9':
                std::cout<< "\n!-----HAVE A GOOD DAY-----!" << std::endl;
                break;
            default:
                std::cout<< "****WRONG CHOICE****";
        }
    }while(choice != '9');
}
void MainMenu_BinaryTreeVec_Double(lasd::BinaryTreeVec<double>& ds){
    char choice;
    double elem;
    double res;
    do{
        std::cout<< "\nSTATUS OF MY BINARY TREE:\n\n";
        PrintTree(ds.Root());
        std::cout<< "\n\n 1: Print in pre order\n 2: Print in order\n 3: Print in post order\n 4: Print in breadth\n 5: Search Element\n 6: Apply specific Fold Function for Doubles\n 7: Apply specific Map Function for Doubles\n 8: Visit Tree starting from the root\n 9: Exit\n" << std::endl;
        std::cin>> choice;
        switch(choice){
            case '1':
                std::cout<< "PRINT- PRE ORDER\nOUTPUT= ";
                ds.MapPreOrder(PrintElemDouble, nullptr);
                break;
            case '2':
                std::cout<< "PRINT- IN ORDER\nOUTPUT= ";
                ds.MapInOrder(PrintElemDouble, nullptr);
                break;
            case '3':
                std::cout<< "PRINT- POST ORDER\nOUTPUT= ";
                ds.MapPostOrder(PrintElemDouble, nullptr);
                break;
            case '4':
                std::cout<< "PRINT- BREADTH\nOUTPUT= ";
                ds.MapBreadth(PrintElemDouble, nullptr);
                break;
            case '5':
                std::cout << "SEARCH ELEMENT: ";
                std::cin >> elem;
                std::cout << "OUTPUT= " << (ds.Exists(elem) ? "true" : "false" );
                break;
            case '6':
                res = 0.0;
                std::cout << "SUM ALL THE ELEMENTS GREATER THAN: ";
                std::cin >> elem;
                ds.FoldBreadth(FoldFunctionDouble, ((const void*)&elem), ((void*)&res));
                std::cout << "OUTPUT= " << res;
                break;
            case '7':
                std::cout << "APPLYING THE FOLLOWING FUNCTION\n  F(x) = x^3";
                ds.MapBreadth(MapFunctionDouble, nullptr);
                break;
            case '8':
                std::cout << "NOW VISITING TREE STARTING FROM ROOT:\n\n";
                VisitTree_Double(ds);
                break;
            case '9':
                std::cout<< "\n!-----HAVE A GOOD DAY-----!" << std::endl;
                break;
            default:
                std::cout<< "****WRONG CHOICE****";
        }
    }while(choice != '9');
}
void MainMenu_BinaryTreeVec_String(lasd::BinaryTreeVec<std::string>& ds){
    char choice;
    std::string elem;
    std::string res;
    int n;
    do{
        std::cout<< "\nSTATUS OF MY BINARY TREE:\n\n";
        PrintTree(ds.Root());
        std::cout<< "\n\n 1: Print in pre order\n 2: Print in order\n 3: Print in post order\n 4: Print in breadth\n 5: Search Element\n 6: Apply specific Fold Function for Strings\n 7: Apply specific Map Function for Strings\n 8: Visit Tree starting from the root\n 9: Exit\n" << std::endl;
        std::cin>> choice;
        switch(choice){
            case '1':
                std::cout<< "PRINT- PRE ORDER\nOUTPUT= ";
                ds.MapPreOrder(PrintElemString, nullptr);
                break;
            case '2':
                std::cout<< "PRINT- IN ORDER\nOUTPUT= ";
                ds.MapInOrder(PrintElemString, nullptr);
                break;
            case '3':
                std::cout<< "PRINT- POST ORDER\nOUTPUT= ";
                ds.MapPostOrder(PrintElemString, nullptr);
                break;
            case '4':
                std::cout<< "PRINT- BREADTH\nOUTPUT= ";
                ds.MapBreadth(PrintElemString, nullptr);
                break;
            case '5':
                std::cout << "SEARCH ELEMENT: ";
                std::cin >> elem;
                std::cout << "OUTPUT= " << (ds.Exists(elem) ? "true" : "false" );
                break;
            case '6':
                res = "";
                std::cout << "CONCATENATION OF ALL THE STRINGS SHORTER THAN OR EQUAL TO: ";
                std::cin >> n;
                ds.FoldInOrder(FoldFunctionString, ((const void*)&n), ((void*)&res));
                std::cout << "OUTPUT= " << res;
                break;
            case '7':
                std::cout << "STRING TO APPEND: ";
                std::cin >> elem;
                std::cout << "APPLYING THE FOLLOWING FUNCTION\n  F(x) = x + " << elem;
                ds.MapBreadth(MapFunctionString, (void*)&elem);
                break;
            case '8':
                std::cout << "NOW VISITING TREE STARTING FROM ROOT:\n\n";
                VisitTree_String(ds);
                break;
            case '9':
                std::cout<< "\n!-----HAVE A GOOD DAY-----!" << std::endl;
                break;
            default:
                std::cout<< "****WRONG CHOICE****";
        }
    }while(choice != '9');
}

