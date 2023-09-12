#include <iostream>
#include <random>
#include "../bst/bst.hpp"
#include "../bst/avl/avl.hpp"
#include "../bst/rb/rb.hpp"
#include "test.hpp"
/* ************************************************************************** */

void RandomSequenceInteger(lasd::BST<int>& ds, unsigned long dim){
    std::default_random_engine seq(std::random_device{}());
    std::uniform_int_distribution<int> distr(1,1000);
    for(unsigned long i = 0; i < dim; i++){
        ds.Insert(distr(seq));
    }
}

void RandomSequenceDouble(lasd::BST<double>& ds, unsigned long dim){
    std::default_random_engine seq(std::random_device{}());
    std::uniform_real_distribution<double> distr(0,1);
    for(unsigned long i = 0; i < dim; i++){
        ds.Insert((distr(seq)*10000)/100);
    }
}
void RandomSequenceString(lasd::BST<std::string>& ds, unsigned long dim){
    std::default_random_engine seq(std::random_device{}());
    std::uniform_int_distribution<int> distr(1,15);
    for(unsigned long i = 0; i < dim; i++){
        ds.Insert(generateRandomString(distr(seq)));
    }
}
void StartMyTest(){
    char data_structure, data_type;

    do{
        std::cout<< "Choose the data structure for your Binary Tree\n b: BST\n a: AVL\n r: RB" << std::endl;
        std::cin>> data_structure;
    }while (data_structure != 'b' && data_structure != 'a' && data_structure != 'r');

    do{
        std::cout<< "Choose the data type you want to test\n i: Integers\n d: Doubles\n s: Strings" << std::endl;
        std::cin>> data_type;
    }while (data_type != 'i' && data_type != 'd' && data_type != 's');

    std::cout << "\n YOU PICKED:  ";
    switch(data_structure){
        case 'b':
            BSTType(data_type);
            break;
        case 'a':
            AVLType(data_type);
            break;
        case 'r':
            RBType(data_type);
            break;
        default:
            std::cout << " Something went wrong ";
    }
}

// Structure Selectors
void BSTType(char& dt){
    std::cout<< "Heap of ";
    switch(dt){
        case 'i':
            std::cout<<"Integers\n\n";
            GenerateBSTInteger();
            break;
         case 'd':
            std::cout<<"Doubles\n\n";
            GenerateBSTDouble();
            break; 
         case 's':
            std::cout<<"Strings\n\n";
            GenerateBSTString();       
            break;
        default:
            std::cout<< " Something went wrong ";
    }
}
void AVLType(char& dt){
    std::cout<< "Heap of ";
    switch(dt){
        case 'i':
            std::cout<<"Integers\n\n";
            GenerateAVLInteger();
            break;
         case 'd':
            std::cout<<"Doubles\n\n";
            GenerateAVLDouble();
            break; 
         case 's':
            std::cout<<"Strings\n\n";
            GenerateAVLString();       
            break;
        default:
            std::cout<< " Something went wrong ";
    }
}
void RBType(char& dt){
    std::cout<< "Heap of ";
    switch(dt){
        case 'i':
            std::cout<<"Integers\n\n";
            GenerateRBInteger();
            break;
         case 'd':
            std::cout<<"Doubles\n\n";
            GenerateRBDouble();
            break; 
         case 's':
            std::cout<<"Strings\n\n";
            GenerateRBString();       
            break;
        default:
            std::cout<< " Something went wrong ";
    }
}

// Accessory functions for Generating Structures
unsigned long GetDimension(){
    unsigned long dim = 0;
    std::cout<< "\nHow many elements do you want to generate randomly?!" << std::endl;
    std::cin>> dim;
    return dim;
}
std::string generateRandomString(const int& n_reps){
  std::default_random_engine seed(std::random_device{}());
  std::uniform_int_distribution<char> fillString('a','z');
  std::string newString = {""};
  for(int i = 0 ;i<n_reps;i++){
    newString += fillString(seed);
  }
  return newString;
} 

// Generator Functions
void GenerateBSTInteger(){
    unsigned long dim = GetDimension();
    lasd::BST<int> mTree;
    RandomSequenceInteger(mTree, dim);
    MainMenu(mTree); 
}
void GenerateBSTDouble(){
    unsigned long dim = GetDimension();
    lasd::BST<double> mTree;
    RandomSequenceDouble(mTree, dim);
    MainMenu(mTree); 
}
void GenerateBSTString(){
    unsigned long dim = GetDimension();
    lasd::BST<std::string> mTree;
    RandomSequenceString(mTree, dim);
    MainMenu(mTree); 
}

void GenerateAVLInteger(){
    unsigned long dim = GetDimension();
    lasd::AVL<int> mTree;
    RandomSequenceInteger(mTree, dim);
    MainMenu(mTree); 
}
void GenerateAVLDouble(){
    unsigned long dim = GetDimension();
    lasd::AVL<double> mTree;
    RandomSequenceDouble(mTree, dim);
    MainMenu(mTree); 
}
void GenerateAVLString(){
    unsigned long dim = GetDimension();
    lasd::AVL<std::string> mTree;
    RandomSequenceString(mTree, dim);
    MainMenu(mTree); 
}
void GenerateRBInteger(){
    unsigned long dim = GetDimension();
    lasd::RB<int> mTree;
    RandomSequenceInteger(mTree, dim);
    MainMenu(mTree); 
}
void GenerateRBDouble(){
    unsigned long dim = GetDimension();
    lasd::RB<double> mTree;
    RandomSequenceDouble(mTree, dim);
    MainMenu(mTree); 
}
void GenerateRBString(){
    unsigned long dim = GetDimension();
    lasd::RB<std::string> mTree;
    RandomSequenceString(mTree, dim);
    MainMenu(mTree); 
}
void FoldFunc_int(const int& dat, const void* n, void* res){
    if(dat < (*(int*)n))
        (*(int*)res) *= dat;
}
void FoldFunc_double(const double& dat, const void* n, void* res){
    if(dat > (*(double*)n))
        (*(double*)res) += dat;
} 
void FoldFunc_string(const std::string& dat, const void* n, void* res){
    if(dat.length() <= (*(int*)n))
        (*(std::string*)res) += dat;
}

void SpecificFoldFunctions(lasd::BST<int>& mTree, char orderType){
    int res = 1;
    int limit = 0;
    std::cin>> limit;
    std::cout << "ORDER TYPE IS .. " << orderType;
    if(orderType == '1'){
        mTree.FoldPreOrder(FoldFunc_int, &limit, &res);
    }
    else if(orderType == '2'){
        mTree.FoldInOrder(FoldFunc_int, &limit, &res);
    }
    else if(orderType == '3'){
        mTree.FoldPostOrder(FoldFunc_int, &limit, &res);
    }
    else if(orderType == '4'){
        mTree.FoldBreadth(FoldFunc_int , &limit, &res);
    }
    std::cout << "\nOUTPUT= " << res;
}
void SpecificFoldFunctions(lasd::BST<double>& mTree, char orderType){
    double sum = 0;
    double limit = 0.0;
    std::cout<< "\nSum all the doubles bigger than: ";
    std::cin>> limit;
    if(orderType == '1'){
        mTree.FoldPreOrder(FoldFunc_double, &limit, &sum);
    }
    else if(orderType == '2'){
        mTree.FoldInOrder(FoldFunc_double, &limit, &sum);
    }
    else if(orderType == '3'){
        mTree.FoldPostOrder(FoldFunc_double, &limit, &sum);
    }
    else if(orderType == '4'){
        mTree.FoldBreadth(FoldFunc_double , &limit, &sum);
    }
    std::cout<< "\nOUTPUT= " << sum;
}
void SpecificFoldFunctions(lasd::BST<std::string>& mTree, char orderType){
    std::string concat = {""};
    int limit = 0;
    std::cout<< "\nConcatenate all the strings shorter or equals than: ";
    std::cin>> limit;
    if(orderType == '1'){
        mTree.FoldPreOrder(FoldFunc_string, &limit, &concat);
    }
    else if(orderType == '2'){
        mTree.FoldInOrder(FoldFunc_string, &limit, &concat);
    }
    else if(orderType == '3'){
        mTree.FoldPostOrder(FoldFunc_string, &limit, &concat);
    }
    else if(orderType == '4'){
        mTree.FoldBreadth(FoldFunc_string , &limit, &concat);
    }
    std::cout<< "\nOUTPUT= " << concat;
}