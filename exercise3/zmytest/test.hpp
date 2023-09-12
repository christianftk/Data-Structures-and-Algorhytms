#ifndef ZMYTEST_HPP
#define ZMYTEST_HPP

/* ************************************************************************** */
void PickDataStructure(char&);
void PickDataType(char&);
void LogDecision()noexcept;
void StartMyTest(char&, char&);

// Structure selectors
void BinaryTreeLnkType(char&);
void BinaryTreeVecType(char&);

// Accessory functions for Generating Structures
unsigned long GetDimension();
std::string generateRandomString(const int&);

// Generator Functions
void GenerateBinaryTreeLnkOfIntegers();
void GenerateBinaryTreeLnkOfDoubles();
void GenerateBinaryTreeLnkOfStrings();

void GenerateBinaryTreeVecOfIntegers();
void GenerateBinaryTreeVecOfDoubles();
void GenerateBinaryTreeVecOfStrings();
/* ************************************************************************** */


void PrintElemInteger(const int& , void*);
void PrintElemDouble(const double& , void*);
void PrintElemString(const std::string&, void*);

void MapFunctionInteger(int&, void*);
void MapFunctionDouble(double&, void*);
void MapFunctionString(std::string&, void*);

void FoldFunctionInteger(const int&, const void*, void*);
void FoldFunctionDouble(const double&, const void*, void*);
void FoldFunctionString(const std::string&, const void*, void*);



#endif
