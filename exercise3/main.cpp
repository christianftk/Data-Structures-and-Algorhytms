#include <iostream>
#include "zmytest/test.hpp"
#include "zlasdtest/test.hpp"

int main()
{
  int test_choice;
    do{
    std::cout<< "Type 1 for Christian's test\nType 2 for your test\n\n My choice is: ";
    std::cin>> test_choice;
    std::cout<< std::endl;
  }while(test_choice != 1 && test_choice != 2);

  switch(test_choice){
    case 1: 
      char data_structure, data_type;
      PickDataStructure(data_structure);
      PickDataType(data_type);
      LogDecision();
      StartMyTest(data_structure, data_type);
    break;
     case 2:
      test();
      break; 
    default:
      std::cout<< "Unexpected behavior" << std::endl;
  }

  return 0;
}
