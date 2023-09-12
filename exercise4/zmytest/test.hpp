
#ifndef ZMYTEST_HPP
#define ZMYTEST_HPP

#include "../heap/heap.hpp"
#include "../priorityqueue/priorityqueue.hpp"

/* ************************************************************************** */
void StartMyTest();

// Structure Selectors
void HeapType(char&);
void PriorityQueueType(char&);

// Accessory functions for Generating Structures
unsigned long GetDimension();
std::string generateRandomString(const int&);

// Generator Functions
void GenerateHeapInteger();
void GenerateHeapDouble();
void GenerateHeapString();

void GeneratePriorityQueueInteger();
void GeneratePriorityQueueDouble();
void GeneratePriorityQueueString();

// MapFunc Callers
void SpecificMapFunctions(lasd::Heap<int>& mHeap, char orderType);
void SpecificMapFunctions(lasd::Heap<double>& mHeap, char orderType);
void SpecificMapFunctions(lasd::Heap<std::string>& mHeap, char orderType);

void SpecificMapFunctions(lasd::PriorityQueue<int>& mHeap, char orderType);
void SpecificMapFunctions(lasd::PriorityQueue<double>& mHeap, char orderType);
void SpecificMapFunctions(lasd::PriorityQueue<std::string>& mHeap, char orderType);

void MapFunc_int(int&, void*);
void MapFunc_double(double&, void*);
void MapFunc_string(std::string&, void*);

// FoldFunc Callers
void SpecificFoldFunctions(lasd::Heap<int>& mHeap, char orderType);
void SpecificFoldFunctions(lasd::Heap<double>& mHeap, char orderType);
void SpecificFoldFunctions(lasd::Heap<std::string>& mHeap, char orderType);

void SpecificFoldFunctions(lasd::PriorityQueue<int>& mHeap, char orderType);
void SpecificFoldFunctions(lasd::PriorityQueue<double>& mHeap, char orderType);
void SpecificFoldFunctions(lasd::PriorityQueue<std::string>& mHeap, char orderType);

void FoldFunc_int(const int&, const void*, void*);
void FoldFunc_double(const double&, const void*, void*);
void FoldFunc_string(const std::string&, const void*, void*);

template <typename Data>
void NavigateTree(lasd::PriorityQueue<Data>& );

/* template <typename Data>
void MapFunc(Data&, void*); */
template <typename Data>
void PrintElem(Data&, void*);
/* template <typename Data>
void PrintTree(const lasd::BinaryTreeVec<Data>::NodeVec&); */
template <typename Data>
void MainMenu_Heap(lasd::Heap<Data>&);
template <typename Data>
void MainMenu_PriorityQueue(lasd::PriorityQueue<Data>&);
/* ************************************************************************** */
#include "test-inc.cpp"
#endif
