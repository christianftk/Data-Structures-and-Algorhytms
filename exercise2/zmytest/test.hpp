
#ifndef ZMYTEST_HPP
#define ZMYTEST_HPP
#include <iostream>
/* ************************************************************************** */
//User Selection
void PickDataStructure(char&);
void PickDataStructureImplementation(char&);
void PickDataType(char&);
void LogDecision()noexcept;
void StartMyTest(char&, char&, char&);

//Structure selector
void StackLstType(char);
void StackVecType(char);
void QueueLstType(char);
void QueueVecType(char);

//Accessory functions for Generating Structures
unsigned long GetDimension();
std::string generateRandomString(int);

//GeneratorFunctions
//-Stack
void GenerateStackLstOfStrings();
void GenerateStackLstOfIntegers();
void GenerateStackVecOfIntegers();
void GenerateStackVecOfStrings();
//-Queue
void GenerateQueueLstOfIntegers();
void GenerateQueueLstOfStrings();
void GenerateQueueVecOfIntegers();
void GenerateQueueVecOfStrings();

//Random values generators
//-Stack
void RandomSequence(lasd::Stack<int>&, unsigned long);
void RandomSequence(lasd::Stack<std::string>&, unsigned long);
//-Queue
void RandomSequence(lasd::Queue<int>&, unsigned long);
void RandomSequence(lasd::Queue<std::string>&, unsigned long);

//Menus
template <typename Data>
void MainMenu_Stack(lasd::Stack<Data>&);
template <typename Data>
void MainMenu_Queue(lasd::Queue<Data>&);

//Menu Options
//-Stack
template <typename Data>
void Push(lasd::Stack<Data>&);
template <typename Data>
void Top(lasd::Stack<Data>&);
template <typename Data>
void TopNPop(lasd::Stack<Data>&);
template <typename Data>
void Pop(lasd::Stack<Data>&);
template <typename Data>
void Clear(lasd::Stack<Data>&);
//-Queue
template <typename Data>
void Enqueue(lasd::Queue<Data>&);
template <typename Data>
void Head(lasd::Queue<Data>&);
template <typename Data>
void Dequeue(lasd::Queue<Data>&);
template <typename Data>
void HeadNDequeue(lasd::Queue<Data>&);
template <typename Data>
void Clear(lasd::Queue<Data>&);

#include "test.cpp"
/* ************************************************************************** */

#endif
