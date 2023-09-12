
#include "test.hpp"

/* ************************************************************************** */
//Data Structure Selection functions
void PickDataStructure(char& ds){
    do{
        std::cout<< "Choose the data structure you want to test\n s: Stack\n q: Queue" << std::endl;
        std::cin>> ds;
    }while (ds != 's' && ds != 'q');
}
void PickDataStructureImplementation(char& si){
    do{
        std::cout<< "Choose the implementation of the Data Structure you want to test\n v: Vector\n l: List" << std::endl;
        std::cin>> si;
    }while (si != 'v' && si != 'l');
}
void PickDataType(char& dt){
    do{
        std::cout<< "Choose the data type you want to test\n i: Integers\n s: Strings" << std::endl;
        std::cin>> dt;
    }while (dt != 'i' && dt != 's');
}
void LogDecision()noexcept{
    std::cout << "\n YOU PICKED\n";
}
void StartMyTest(char& ds, char& si, char& dt){
    switch(ds){
        case 's':{
            switch(si){
                case 'l':
                    StackLstType(dt);
                    break;
                case 'v':
                    StackVecType(dt);
                    break;
                default:
                    std::cout << "!! - - Something went wrong - - !!";
                }
            break;
        }
        case 'q':{
            switch(si){
                case 'l':
                    QueueLstType(dt);
                    break;
                case 'v':
                    QueueVecType(dt);
                    break;
                default:
                    std::cout << "!! - - Something went wrong - - !!";
            }
            break;
        }
        default:
            std::cout << "!! - - Something went wrong - - !!";
    }
}
void StackLstType(char dt){
    switch(dt){
        case 'i':
            std::cout<<"StackLst of Integers\n\n";
            GenerateStackLstOfIntegers();
            break;
        case 's':
            std::cout<<"StackLst of Strings\n\n";
            GenerateStackLstOfStrings();       
            break;
    }
}
void StackVecType(char dt){
    switch(dt){
        case 'i':
            std::cout<<"StackVec of Integers\n\n";
            GenerateStackVecOfIntegers();
            break;
        case 's':
            std::cout<<"StackVec of Strings\n\n";
            GenerateStackVecOfStrings();       
            break;
    }
}
void QueueLstType(char dt){
    switch(dt){
        case 'i':
            std::cout<<"QueueLst of Integers\n\n";
            GenerateQueueLstOfIntegers();
            break;
        case 's':
            std::cout<<"QueueLst of Strings\n\n";
            GenerateQueueLstOfStrings();       
            break;
    }
}
void QueueVecType(char dt){
    switch(dt){
        case 'i':
            std::cout<<"QueueVec of Integers\n\n";
            GenerateQueueVecOfIntegers();
            break;
        case 's':
            std::cout<<"QueueVec of Strings\n\n";
            GenerateQueueVecOfStrings();       
            break;
    }
}
unsigned long GetDimension(){   // Get Dimension of the Data Structure from the user
    unsigned long dim = 0;
    std::cout<< "How many elements do you want to generate randomly?!" << std::endl;
    std::cin>> dim;
    return dim;
}

//GeneratorFunctions
//-Stacks
void GenerateStackLstOfStrings(){
    unsigned long dim = GetDimension();    
    lasd::StackLst<std::string> mstack;
    RandomSequence(mstack, dim);
    MainMenu_Stack(mstack);
}
void GenerateStackLstOfIntegers(){
    unsigned long dim = GetDimension();
    lasd::StackLst<int> mstack;
    RandomSequence(mstack, dim);
    MainMenu_Stack(mstack);
}
void GenerateStackVecOfIntegers(){
    unsigned long dim = GetDimension();
    lasd::StackVec<int> mstack;
    RandomSequence(mstack, dim);
    MainMenu_Stack(mstack);
}
void GenerateStackVecOfStrings(){
    unsigned long dim = GetDimension();    
    lasd::StackVec<std::string> mstack;
    RandomSequence(mstack, dim);
    MainMenu_Stack(mstack);
}

void GenerateQueueLstOfIntegers(){
    unsigned long dim = GetDimension();
    lasd::QueueLst<int> mqueue;
    RandomSequence(mqueue, dim);
    MainMenu_Queue(mqueue);
}
void GenerateQueueLstOfStrings(){
    unsigned long dim = GetDimension();
    lasd::QueueLst<std::string> mqueue;
    RandomSequence(mqueue, dim);
    MainMenu_Queue(mqueue);
}
void GenerateQueueVecOfIntegers(){
    unsigned long dim = GetDimension();
    lasd::QueueLst<int> mqueue;
    RandomSequence(mqueue, dim);
    MainMenu_Queue(mqueue);
}
void GenerateQueueVecOfStrings(){
    unsigned long dim = GetDimension();
    lasd::QueueLst<std::string> mqueue;
    RandomSequence(mqueue, dim);
    MainMenu_Queue(mqueue);
}

//Generators of Random Sequence of values according to the type of the Data Structure
std::string generateRandomString(int n_reps){   //Accessory function for random string generation
  std::default_random_engine seed(n_reps);
  std::uniform_int_distribution<char> fillString('a','z');
  char newString[n_reps+1];
  for(int i=0;i<n_reps;i++){
    newString[i]=fillString(seed);
  }
  newString[n_reps]='\0';
  return newString;
}

void RandomSequence(lasd::Stack<int>& ds, unsigned long dim){
    std::default_random_engine seq(14);
    std::uniform_int_distribution<int> distr(1,1000);
    for(unsigned long i = 0; i < dim; i++){
        ds.Push(distr(seq));
    }
}
void RandomSequence(lasd::Stack<std::string>& ds, unsigned long dim){
    std::default_random_engine seq(5);
    std::uniform_int_distribution<int> distr(1,15);
    for(unsigned long i = 0; i < dim; i++){
        ds.Push(generateRandomString(distr(seq)));
    }
}
void RandomSequence(lasd::Queue<int>& ds, unsigned long dim){
    std::default_random_engine seq(14);
    std::uniform_int_distribution<int> distr(1,1000);
    for(unsigned long i = 0; i < dim; i++){
        ds.Enqueue(distr(seq));
    }
}
void RandomSequence(lasd::Queue<std::string>& ds, unsigned long dim){
    std::default_random_engine seq(5);
    std::uniform_int_distribution<int> distr(1,15);
    for(unsigned long i = 0; i < dim; i++){
        ds.Enqueue(generateRandomString(distr(seq)));
    }
}

//Menus
template <typename Data>
void MainMenu_Stack(lasd::Stack<Data>& ds){
    char choice = '0';
    do{
        std::cout<< "\n\n\nSTATUS OF MY STACK:\n";
        std::cout<< "SIZE= " << ds.Size();
        std::cout<< "\n 1: Push\n 2: Top \n 3: Pop\n 4: TopNPop\n 5: Clear\n 6: Exit" << std::endl;
        std::cout<< "\nACTION= ";
        std::cin>> choice;
        switch(choice){
            case '1':
                Push(ds);
                break;
            case '2':
                Top(ds);
                break;
            case '3':
                Pop(ds);
                break;
            case '4':
                TopNPop(ds);
                break;
            case '5':
                Clear(ds);
                break;
            case '6':
                std::cout<< "\n!-----HAVE A GOOD DAY-----!" << std::endl;
                break;
            default:
                std::cout<< "****WRONG CHOICE****";
        }
    }while(choice != '6');
}
template <typename Data>
void MainMenu_Queue(lasd::Queue<Data>& ds){
    char choice = '0';
    do{
        std::cout<< "\n\n\nSTATUS OF MY QUEUE:\n";
        std::cout<< "SIZE= " << ds.Size();
        std::cout<< "\n 1: Enqueue\n 2: Head \n 3: Dequeue\n 4: HeadNDequeue\n 5: Clear\n 6: Exit" << std::endl;
        std::cout<< "\nACTION= ";
        std::cin>> choice;
        switch(choice){
            case '1':
                Enqueue(ds);
                break;
            case '2':
                Head(ds);
                break;
            case '3':
                Dequeue(ds);
                break;
            case '4':
                HeadNDequeue(ds);
                break;
            case '5':
                Clear(ds);
                break;
            case '6':
                std::cout<< "\n!-----HAVE A GOOD DAY-----!" << std::endl;
                break;
            default:
                std::cout<< "****WRONG CHOICE****";
        }
    }while(choice != '6');
}
//Menu Options
//-Stack
template <typename Data>
void Push(lasd::Stack<Data>& ds){
    Data tmp;
    std::cout<< "Value to push: ";
    std::cin>> tmp;
    std::cout<< "\nOUTPUT= " << tmp << " successfully pushed\n";
    ds.Push(tmp);
}
template <typename Data>
void Top(lasd::Stack<Data>& ds){
    std::cout<< "OUTPUT= Top: " << ds.Top() << std::endl;
}
template <typename Data>
void TopNPop(lasd::Stack<Data>& ds){
    std::cout<< "OUTPUT= " << ds.TopNPop() << " successfully popped\n";
}
template <typename Data>
void Pop(lasd::Stack<Data>& ds){
    ds.Pop();
    std::cout<< "OUTPUT= Top successfully popped\n";
}
//-Queues
template <typename Data>
void Enqueue(lasd::Queue<Data>& ds){
    Data tmp;
    std::cout<< "Value to push: ";
    std::cin>> tmp;
    std::cout<< "\nOUTPUT= " << tmp << " successfully enqueued\n";
    ds.Enqueue(tmp);
}
template <typename Data>
void Head(lasd::Queue<Data>& ds){
    std::cout<< "OUTPUT= Head: " << ds.Head() << std::endl;
}
template <typename Data>
void HeadNDequeue(lasd::Queue<Data>& ds){
    std::cout<< "OUTPUT= " << ds.HeadNDequeue() << " successfully dequeued\n";
}
template <typename Data>
void Dequeue(lasd::Queue<Data>& ds){
    ds.Dequeue();
    std::cout<< "OUTPUT= Rear successfully dequeued\n";
}
template <typename Data>
void Clear(lasd::Queue<Data>& ds){
    ds.Clear();
    std::cout << "Successfully cleared";
}
template <typename Data>
void Clear(lasd::Stack<Data>& ds){
    ds.Clear();
    std::cout << "Successfully cleared";
}