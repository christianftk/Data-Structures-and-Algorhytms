#include <iostream>
#include <random>
#include "../heap/heap.hpp"
#include "../priorityqueue/priorityqueue.hpp"
#include "test.hpp"
/* ************************************************************************** */
void RandomSequenceInteger(lasd::Vector<int>& ds, unsigned long dim){
    std::default_random_engine seq(std::random_device{}());
    std::uniform_int_distribution<int> distr(1,1000);
    for(unsigned long i = 0; i < dim; i++){
        ds[i] = distr(seq);
    }
}

void RandomSequenceDouble(lasd::Vector<double>& ds, unsigned long dim){
    std::default_random_engine seq(std::random_device{}());
    std::uniform_real_distribution<double> distr(0,1);
    for(unsigned long i = 0; i < dim; i++){
        ds[i] = round(distr(seq)*10000)/100;
    }
}
void RandomSequenceString(lasd::Vector<std::string>& ds, unsigned long dim){
    std::default_random_engine seq(std::random_device{}());
    std::uniform_int_distribution<int> distr(1,15);
    for(unsigned long i = 0; i < dim; i++){
        ds[i] = generateRandomString(distr(seq));
    }
}
void StartMyTest(){
    char data_structure, data_type;

    do{
        std::cout<< "Choose the data structure for your Binary Tree\n h: Heap\n p: Priority Queue" << std::endl;
        std::cin>> data_structure;
    }while (data_structure != 'h' && data_structure != 'p');

    do{
        std::cout<< "Choose the data type you want to test\n i: Integers\n d: Doubles\n s: Strings" << std::endl;
        std::cin>> data_type;
    }while (data_type != 'i' && data_type != 'd' && data_type != 's');

    std::cout << "\n YOU PICKED:  ";
    switch(data_structure){
        case 'h':
            HeapType(data_type);
            break;
        case 'p':
            PriorityQueueType(data_type);
            break;
        default:
            std::cout << " Something went wrong ";
    }
}

// Structure Selectors
void HeapType(char& dt){
    std::cout<< "Heap of ";
    switch(dt){
        case 'i':
            std::cout<<"Integers\n\n";
            GenerateHeapInteger();
            break;
         case 'd':
            std::cout<<"Doubles\n\n";
            GenerateHeapDouble();
            break; 
         case 's':
            std::cout<<"Strings\n\n";
            GenerateHeapString();       
            break;
        default:
            std::cout<< " Something went wrong ";
    }
}

void PriorityQueueType(char& dt){
    std::cout<< "Priority Queue of ";
    switch(dt){
        case 'i':
            std::cout<<"Integers\n\n";
            GeneratePriorityQueueInteger();
            break;
        case 'd':
            std::cout<<"Doubles\n\n";
            GeneratePriorityQueueDouble();
            break;
        case 's':
            std::cout<<"Strings\n\n";
            GeneratePriorityQueueString();       
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
void GenerateHeapInteger(){
    unsigned long dim = GetDimension();
    lasd::Vector<int> vec(dim);
    RandomSequenceInteger(vec, dim);
    lasd::Heap<int> mHeap(vec);
    MainMenu_Heap(mHeap); 
}
void GenerateHeapDouble(){
    unsigned long dim = GetDimension();
    lasd::Vector<double> vec(dim);
    RandomSequenceDouble(vec, dim);
    lasd::Heap<double> mHeap(vec);
    MainMenu_Heap(mHeap); 
}
void GenerateHeapString(){
    unsigned long dim = GetDimension();
    lasd::Vector<std::string> vec(dim);
    RandomSequenceString(vec, dim);
    lasd::Heap<std::string> mHeap(vec);
    MainMenu_Heap(mHeap); 
}

void GeneratePriorityQueueInteger(){
    unsigned long dim = GetDimension();
    lasd::Vector<int> vec(dim);
    RandomSequenceInteger(vec, dim);
    lasd::PriorityQueue<int> mQueue(vec);
    MainMenu_PriorityQueue(mQueue); 
}
void GeneratePriorityQueueDouble(){
    unsigned long dim = GetDimension();
    lasd::Vector<double> vec(dim);
    RandomSequenceDouble(vec, dim);
    lasd::PriorityQueue<double> mQueue(vec);
    MainMenu_PriorityQueue(mQueue); 
}
void GeneratePriorityQueueString(){
    unsigned long dim = GetDimension();
    lasd::Vector<std::string> vec(dim);
    RandomSequenceString(vec, dim);
    lasd::PriorityQueue<std::string> mQueue(vec);
    MainMenu_PriorityQueue(mQueue);
}

void MapFunc_int(int& dat, void*){
    dat *= pow(-1, dat);
}
void MapFunc_double(double& dat, void*){
    dat *= -1;
} 
void MapFunc_string(std::string& dat, void* ToAdd){
    dat += *(std::string*)ToAdd;
}

void SpecificMapFunctions(lasd::Heap<int>& mHeap, char orderType){
    if(orderType == '1'){
        mHeap.MapPreOrder(MapFunc_int, nullptr);
    }
    else if(orderType == '2'){
        mHeap.MapPostOrder(MapFunc_int, nullptr);
    }
}
void SpecificMapFunctions(lasd::Heap<double>& mHeap, char orderType){
    if(orderType == '1'){
        mHeap.MapPreOrder(MapFunc_double, nullptr);
    }
    else if(orderType == '2'){
        mHeap.MapPostOrder(MapFunc_double, nullptr);
    }
}
void SpecificMapFunctions(lasd::Heap<std::string>& mHeap, char orderType){
    std::string ToAdd = {""};
    std::cout << "\nInsert String to append: ";
    std::cin>> ToAdd;
    if(orderType == '1'){
        mHeap.MapPreOrder(MapFunc_string, &ToAdd);
    }
    else if(orderType == '2'){
        mHeap.MapPostOrder(MapFunc_string, &ToAdd);
    }
}
void SpecificMapFunctions(lasd::PriorityQueue<int>& mQueue, char orderType){
    if(orderType == '1'){
        mQueue.MapPreOrder(MapFunc_int, nullptr);
    }
    else if(orderType == '2'){
        mQueue.MapPostOrder(MapFunc_int, nullptr);
    }
}
void SpecificMapFunctions(lasd::PriorityQueue<double>& mQueue, char orderType){
    if(orderType == '1'){
        mQueue.MapPreOrder(MapFunc_double, nullptr);
    }
    else if(orderType == '2'){
        mQueue.MapPostOrder(MapFunc_double, nullptr);
    }
}
void SpecificMapFunctions(lasd::PriorityQueue<std::string>& mQueue, char orderType){
    std::string ToAdd = {""};
    std::cout << "\nInsert String to append: ";
    std::cin>> ToAdd;
    if(orderType == '1'){
        mQueue.MapPreOrder(MapFunc_string, &ToAdd);
    }
    else if(orderType == '2'){
        mQueue.MapPostOrder(MapFunc_string, &ToAdd);
    }
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

void SpecificFoldFunctions(lasd::Heap<int>& mHeap, char orderType){
    int res = 1;
    int limit = 0;
    std::cout<< "\nMultiply all the integers smaller than: ";
    std::cin>> limit;
    if(orderType == '1'){
        mHeap.FoldPreOrder(FoldFunc_int, &limit, &res);
    }
    else if(orderType == '2'){
        mHeap.FoldPostOrder(FoldFunc_int, &limit, &res);
    }
    std::cout << "\nOUTPUT= " << res;
}
void SpecificFoldFunctions(lasd::Heap<double>& mHeap, char orderType){
    double sum = 0;
    double limit = 0.0;
    std::cout<< "\nSum all the doubles bigger than: ";
    std::cin>> limit;
    if(orderType == '1'){
        mHeap.FoldPreOrder(FoldFunc_double, &limit, &sum);
    }
    else if(orderType == '2'){
        mHeap.FoldPostOrder(FoldFunc_double, &limit, &sum);
    }
    std::cout<< "\nOUTPUT= " << sum;
}
void SpecificFoldFunctions(lasd::Heap<std::string>& mHeap, char orderType){
    std::string concat = {""};
    int limit = 0;
    std::cout<< "\nConcatenate all the strings shorter or equals than: ";
    std::cin>> limit;
    if(orderType == '1'){
        mHeap.FoldPreOrder(FoldFunc_string, &limit, &concat);
    }
    else if(orderType == '2'){
        mHeap.FoldPostOrder(FoldFunc_string, &limit, &concat);
    }
    std::cout<< "\nOUTPUT= " << concat;
}
void SpecificFoldFunctions(lasd::PriorityQueue<int>& mQueue, char orderType){
    int res = 1;
    int limit = 0;
    std::cout<< "\nMultiply all the integers smaller than: ";
    std::cin>> limit;
    if(orderType == '1'){
        mQueue.FoldPreOrder(FoldFunc_int, &limit, &res);
    }
    else if(orderType == '2'){
        mQueue.FoldPostOrder(FoldFunc_int, &limit, &res);
    }
    std::cout << "\nOUTPUT= " << res;
}
void SpecificFoldFunctions(lasd::PriorityQueue<double>& mQueue, char orderType){
    double sum = 0;
    double limit = 0.0;
    std::cout<< "\nSum all the doubles bigger than: ";
    std::cin>> limit;
    if(orderType == '1'){
        mQueue.FoldPreOrder(FoldFunc_double, &limit, &sum);
    }
    else if(orderType == '2'){
        mQueue.FoldPostOrder(FoldFunc_double, &limit, &sum);
    }
    std::cout<< "\nOUTPUT= " << sum;
}
void SpecificFoldFunctions(lasd::PriorityQueue<std::string>& mQueue, char orderType){
    std::string concat = {""};
    int limit = 0;
    std::cout<< "\nConcatenate all the strings shorter or equals than: ";
    std::cin>> limit;
    if(orderType == '1'){
        mQueue.FoldPreOrder(FoldFunc_string, &limit, &concat);
    }
    else if(orderType == '2'){
        mQueue.FoldPostOrder(FoldFunc_string, &limit, &concat);
    }
    std::cout<< "\nOUTPUT= " << concat;
}