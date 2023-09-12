
#ifndef ZMYTEST_HPP
#define ZMYTEST_HPP
#include <iostream>
/* ************************************************************************** */

void PickDataStructure(char&);
void PickDataType(char&);
void LogDecision(char, char)noexcept;
void StartMyTest(char&, char&);
void ListType(char);
void VectorType(char);

//GeneratorFunctions
void GenerateListOfIntegers();
void GenerateListOfDoubles();
void GenerateListOfStrings();

void GenerateVectortOfIntegers();
void GenerateVectorOfDoubles();
void GenerateVectorOfStrings();
/* ************************************************************************** */

//Random values generators
unsigned long GetDimension();
void RandomSequence(const lasd::Vector<int>&);
void RandomSequence(const lasd::Vector<double>&);
void RandomSequence(const lasd::Vector<std::string>&);
void RandomSequence(lasd::List<int>&, unsigned long);
void RandomSequence(lasd::List<double>&, unsigned long);
void RandomSequence(lasd::List<std::string>&, unsigned long);
std::string generateRandomString(int);

//Menus
template <typename Data>
void MainMenu_List(lasd::List<Data>&);
template <typename Data>
void MainMenu_Vector(lasd::Vector<Data>&);

//Print functions
template <typename Data>
void PrintSequence(const lasd::LinearContainer<Data>&);
template <typename Data>
void PrintElement(const Data&, void*);
template <typename Data>
void PrintActions(const lasd::LinearContainer<Data>&);

//Search function
template <typename Data>
void SearchElement(const lasd::SearchableContainer<Data>&);

//Fold Functions
void SpecificFoldFunction(const lasd::List<int>&);
void SpecificFoldFunction(const lasd::List<double>&);
void SpecificFoldFunction(const lasd::List<std::string>&);

void SpecificFoldFunction(const lasd::Vector<int>&);
void SpecificFoldFunction(const lasd::Vector<double>&);
void SpecificFoldFunction(const lasd::Vector<std::string>&);

void FoldFunction_int(const int&, const void*, void*);
void FoldFunction_double(const double&, const void*, void*);
void FoldFunction_string(const std::string&, const void*, void*);

//Map Functions
void SpecificMapFunction(lasd::List<int>&);
void SpecificMapFunction(lasd::List<double>&);
void SpecificMapFunction(lasd::List<std::string>&);

void SpecificMapFunction(lasd::Vector<int>&);
void SpecificMapFunction(lasd::Vector<double>&);
void SpecificMapFunction(lasd::Vector<std::string>&);

void MapFunction_int(int&, void*);
void MapFunction_double(double&, void*);
void MapFunction_string(std::string&, void*);

//Vector-only functions
template <typename Data>
void ChangeSize(lasd::Vector<Data>&);

//List-only functions
template <typename Data>
void InsertAtFront(lasd::List<Data>&);
template <typename Data>
void InsertAtBack(lasd::List<Data>&);
template <typename Data>
void Pop(lasd::List<Data>&);
template <typename Data>
void TopNPop(lasd::List<Data>&);

#include "test.cpp"
#endif
