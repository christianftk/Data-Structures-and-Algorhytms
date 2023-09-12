#include <iostream>
#include <random>
/* #include "zmytest/test.hpp"
#include "zlasdtest/test.hpp" */
#include "priorityqueue/priorityqueue.hpp"

template <typename Data>
void PrintElem(Data& dat, void* noPe){
    std::cout << dat << "  ";
}
using namespace lasd;
int main()
{
  PriorityQueue<int>* p;
  p = new PriorityQueue<int>();
  p->Insert(23);
  p->Insert(22);
  PriorityQueue<int> p1 = PriorityQueue<int>(*p);
  p->MapPreOrder(PrintElem<int>, nullptr);
  p1.MapPreOrder(PrintElem<int>, nullptr);
  p1.AddLeftChild(p1.Root(), 2);
/*   int test_choice;
  do{
    std::cout<< "Type 1 for Christian's test\nType 2 for your test\n\n My choice is: ";
    std::cin>> test_choice;
    std::cout<< std::endl;
  }while(test_choice != 1 && test_choice != 2);

  switch(test_choice){
    case 1: 
      StartMyTest();
      break;

    case 2:
      test();
      break;

    default:
      std::cout<< "Unexpected behavior" << std::endl;
  } */

  return 0;
}
