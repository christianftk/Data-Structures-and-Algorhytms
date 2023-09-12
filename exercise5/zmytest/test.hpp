
#ifndef ZMYTEST_HPP
#define ZMYTEST_HPP

#include "../bst/bst.hpp"
#include "../bst/avl/avl.hpp"
#include "../bst/rb/rb.hpp"

/* ************************************************************************** */
void StartMyTest();

// Structure Selectors
void BSTType(char&);
void AVLType(char&);
void RBType(char&);

// Accessory functions for Generating Structures
unsigned long GetDimension();
std::string generateRandomString(const int&);

// Generator Functions
void GenerateBSTInteger();
void GenerateBSTDouble();
void GenerateBSTString();

void GenerateAVLInteger();
void GenerateAVLDouble();
void GenerateAVLString();

void GenerateRBInteger();
void GenerateRBDouble();
void GenerateRBString();

// FoldFunc Callers
void SpecificFoldFunctions(lasd::BST<int>&, char orderType);
void SpecificFoldFunctions(lasd::BST<double>&, char orderType);
void SpecificFoldFunctions(lasd::BST<std::string>&, char orderType);

void FoldFunc_int(const int&, const void*, void*);
void FoldFunc_double(const double&, const void*, void*);
void FoldFunc_string(const std::string&, const void*, void*);

template <typename Data>
void SpecificBSTFunctions(lasd::BST<Data>&);
template <typename Data>
void PrintElem(Data&, void*);
template <typename Data>
void MainMenu(lasd::BST<Data>&);

/* ************************************************************************** */
#include "test-inc.cpp"

#endif
