/* ************************************************************************** */
//Data Structure Selection functions
void PickDataStructure(char& ds){
    do{
        std::cout<< "Choose the data structure you want to test?\n v: Vector\n l: List" << std::endl;
        std::cin>> ds;
    }while (ds != 'v' && ds != 'l');
}
void PickDataType(char& dt){
    do{
        std::cout<< "Choose the data type you want to test?\n i: Integers\n d: Doubles\n s: Strings" << std::endl;
        std::cin>> dt;
    }while (dt != 'i' && dt != 'd' && dt != 's');
}
void LogDecision(char ds, char dt)noexcept{
    std::cout << "\n YOU PICKED\n";
}
void StartMyTest(char& ds, char& dt){
    switch(ds){
        case 'l':
            ListType(dt);
            break;
        case 'v':
            VectorType(dt);
            break;
        default:
            std::cout << "!! - - Something went wrong - - !!";
    }
}
void ListType(char dt){
    switch(dt){
        case 'i':
            std::cout<<"List of Integers\n\n";
            GenerateListOfIntegers();
            break;
        case 'd':
            std::cout<<"List of Doubles\n\n";
            GenerateListOfDoubles();
            break;
        case 's':
            std::cout<<"List of Strings\n\n";
            GenerateListOfStrings();       
            break;
    }
}
void VectorType(char dt){
    switch(dt){
        case 'i':
              std::cout<<"Vector of Integers\n\n";
              GenerateVectortOfIntegers();
              break;
        case 'd':
              std::cout<<"Vector of Doubles\n\n";
              GenerateVectorOfDoubles();
              break;
        case 's':
              std::cout<<"Vector of Strings\n\n";
              GenerateVectorOfStrings();
              break;
    }
}

/* ************************************************************************** */

//Generators of selected Data Structure with relative program execution
void GenerateListOfIntegers(){
    unsigned long dim = GetDimension();
    lasd::List<int> mlist;
    RandomSequence(mlist, dim);
    MainMenu_List(mlist);
}
void GenerateListOfDoubles(){
    unsigned long dim = GetDimension();
    lasd::List<double> mlist;
    RandomSequence(mlist, dim);
    MainMenu_List(mlist);
}
void GenerateListOfStrings(){
    unsigned long dim = GetDimension();    
    lasd::List<std::string> mlist;
    RandomSequence(mlist, dim);
    MainMenu_List(mlist);
}
void GenerateVectortOfIntegers(){
    unsigned long dim = GetDimension();
    lasd::Vector<int> mvec = lasd::Vector<int>(dim);
    RandomSequence(mvec);
    MainMenu_Vector(mvec);
}
void GenerateVectorOfDoubles(){
    unsigned long dim = GetDimension();
    lasd::Vector<double> mvec = lasd::Vector<double>(dim);
    RandomSequence(mvec);
    MainMenu_Vector(mvec);
}
void GenerateVectorOfStrings(){
    unsigned long dim = GetDimension();
    lasd::Vector<std::string> mvec = lasd::Vector<std::string>(dim);
    RandomSequence(mvec);
    MainMenu_Vector(mvec);
}
/* ------------------------------------------------------------------------------------ */

unsigned long GetDimension(){   // Get Dimension of the Data Structure from the user
    unsigned long dim = 0;
    std::cout<< "How many elements do you want to generate randomly?!" << std::endl;
    std::cin>> dim;
    return dim;
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
// - For Vectors
void RandomSequence(const lasd::Vector<int>& ds){
    std::default_random_engine seq(10);
    std::uniform_int_distribution<int> distr(1,1000);
    for(unsigned long i = 0; i < ds.Size(); i++){
        ds[i]= distr(seq);
    }
}
void RandomSequence(const lasd::Vector<double>& ds){
    std::default_random_engine seq(9);
    std::uniform_real_distribution<double> distr(0,1);
    for(unsigned long i = 0; i < ds.Size(); i++){
        ds[i]= (round(distr(seq)*10000))/100;
    }
}
void RandomSequence(const lasd::Vector<std::string>& ds){
    std::default_random_engine seq(23);
    std::uniform_int_distribution<int> distr(1,15);
    for(unsigned long i = 0; i < ds.Size(); i++){
        ds[i]=generateRandomString(distr(seq));
    }
}
// - For Lists
void RandomSequence(lasd::List<int>& ds, unsigned long dim){
    std::default_random_engine seq(10);
    std::uniform_int_distribution<int> distr(1,1000);
    for(unsigned long i = 0; i < dim; i++){
        ds.InsertAtFront(distr(seq));
    }
}
void RandomSequence(lasd::List<double>& ds, unsigned long dim){
    std::default_random_engine seq(5);
    std::uniform_real_distribution<double> distr(0,1);
    for(unsigned long i = 0; i < dim; i++){
        ds.InsertAtFront((round(distr(seq)*10000))/100);
    }
}
void RandomSequence(lasd::List<std::string>& ds, unsigned long dim){
    std::default_random_engine seq(5);
    std::uniform_int_distribution<int> distr(1,15);
    for(unsigned long i = 0; i < dim; i++){
        ds.InsertAtFront(generateRandomString(distr(seq)));
    }
}

//Print Functions
template <typename Data>
void PrintSequence(lasd::LinearContainer<Data>& ds){  //Print function of classes extending LinearContainer
  for(unsigned long i = 0; i < ds.Size(); i++){
    std::cout<<ds[i]<<" ";
  }
  std::cout<<std::endl;
}
template <typename Data>
void PrintElement(const Data& dat, void* separator){
    std::cout<< dat << (char*)separator;
}
template <typename Data>
void PrintActions(const lasd::LinearContainer<Data>& ds){
    unsigned long index;
    std::cout<< "Element[0]= " << ds.Front() <<"\nElement[" << (ds.Size()-1) << "]= " << ds.Back() << "\nWrite the index of the element you want to read\n";
    std::cin>> index;
    std::cout<< "\nElement[" << index << "]= " << ds[index] << std::endl;
}
//Search Function
template <typename Data>
void SearchElement(const lasd::SearchableContainer<Data>& ds){
    Data myData;
    std::cout<< "Insert Element: ";
    std::cin>> myData;
    if(ds.Exists(myData)){
        std::cout<< "Your Element IS in the Data Structure\n";
    }
    else{
        std::cout<< "Your Element IS NOT in the Data Structure\n";
    }
}

/* ------------------------------------------------------------------------------------ */

//Specific Fold Functions for both Data Structures
void FoldFunction_int(const int& dt, const void* par, void* acc){
    if(dt < *((int*)par)){
        *((int*)acc) += dt;
    }
}
void FoldFunction_double(const double& dt, const void* par, void* acc){
    if(dt > *((double*)par)){
        *((double*)acc) *= dt;
    }
}
void FoldFunction_string(const std::string& dt, const void* par, void* acc){
    if((int)dt.length() < *((int*)par)){
        *((std::string*)acc) += dt;
    }
}
// - Vectors
void SpecificFoldFunction(const lasd::Vector<int>& ds){
    int acc = 0;
    int res = 0;
    std::cout<<"Insert parameter: ";
    std::cin>>res;
    ds.FoldPreOrder(FoldFunction_int, &res, &acc);
    std::cout<< "The sum of all the values smaller than " << res << " is: " << acc;
}
void SpecificFoldFunction(const lasd::Vector<double>& ds){
    double acc = 1;
    double par;
    std::cout<<"Insert parameter: ";
    std::cin>>par;
    ds.FoldPreOrder(&FoldFunction_double, &par, &acc);
    std::cout<< "The product of all the values bigger than " << par << " is: " << acc;
}
void SpecificFoldFunction(const lasd::Vector<std::string>& ds){
    std::string acc = {""};
    int par = 0;
    std::cout<<"Insert parameter: ";
    std::cin>>par;
    ds.FoldPreOrder(&FoldFunction_string, &par, &acc);
    std::cout<< "The string obtained by concatenation of all the strings shorter than "<< par << " is:\n " << acc;
}
// - Lists
void SpecificFoldFunction(const lasd::List<int>& ds){
    int acc = 0;
    int par = 0;
    std::cout<<"Insert parameter: ";
    std::cin>>par;
    ds.FoldPreOrder(FoldFunction_int, &par, &acc);
    std::cout<< "The sum of all the values smaller than " << par << " is: " << acc;
}
void SpecificFoldFunction(const lasd::List<double>& ds){
    double acc = 1;
    double par = 0;
    std::cout<< "Insert parameter: ";
    std::cin>> par;
    ds.FoldPreOrder(&FoldFunction_double, &par, &acc);
    std::cout<< "The product of all the values bigger than " << par << " is: " << acc;
}
void SpecificFoldFunction(const lasd::List<std::string>& ds){
    std::string acc = {""};
    int par = 0;
    std::cout<<"Insert parameter: ";
    std::cin>>par;
    ds.FoldPreOrder(&FoldFunction_string, &par, &acc);
    std::cout<< "The string obtained by concatenation of all the strings shorter than "<< par << " is:\n " << acc;
}

/* ------------------------------------------------------------------------------------ */

//Specific Map Function for both Data Structures
// - Vectors
void SpecificMapFunction(lasd::Vector<int>& ds){
    int factor = 0;
    std::cout<<"Insert Parameter: ";
    std::cin>> factor;
    std::cout<< "Applying the following function to your vector:\nf(n) = " << factor << "n" << std::endl;
    ds.MapPreOrder(&MapFunction_int, &factor);
    std::cout<< "Values modified correctly" << std::endl;
}
void SpecificMapFunction(lasd::Vector<double>& ds){
    std::cout<< "Applying the following function to your vector:\nf(n) = n^2" << std::endl;
    ds.MapPreOrder(&MapFunction_double, nullptr);
    std::cout<< "Values modified correctly" << std::endl;
}
void SpecificMapFunction(lasd::Vector<std::string>& ds){
    std::cout<< "Executing Uppercase function of strings:\n" << std::endl;
    ds.MapPreOrder(&MapFunction_string, nullptr);
    std::cout<< "Strings modified correctly" << std::endl;
}
// - Lists
void SpecificMapFunction(lasd::List<int>& ds){
    int factor = 0;
    std::cout<<"Insert Parameter: ";
    std::cin>> factor;
    std::cout<< "Applying the following function to your list:\nf(n) = " << factor << "n" << std::endl;
    ds.MapPreOrder(&MapFunction_int, &factor);
    std::cout<< "Values modified correctly" << std::endl;
}
void SpecificMapFunction(lasd::List<double>& ds){
    std::cout<< "Applying the following function to your list:\nf(n) = n^2" << std::endl;
    ds.MapPreOrder(&MapFunction_double, nullptr);
    std::cout<< "Values modified correctly" << std::endl;
}
void SpecificMapFunction(lasd::List<std::string>& ds){
    std::cout<< "Executing Uppercase function of strings:\n" << std::endl;
    ds.MapPreOrder(&MapFunction_string, nullptr);
    std::cout<< "Strings modified correctly" << std::endl;
}

void MapFunction_int(int& myInteger, void* N){
    myInteger *= *((int*)N);
}
void MapFunction_double(double& myDouble, void*){
    myDouble *= myDouble;
}
void MapFunction_string(std::string& myString, void*){
    for(int i = 0; i < myString.length(); i++){
        if(myString[i] <= 'z' && myString[i] >= 'a'){
            myString[i] -= 32;
        }
    }
}

/* ------------------------------------------------------------------------------------ */

//Vector-only function
template <typename Data>
void ChangeSize(lasd::Vector<Data>& ds){
    unsigned long newSize;
    std::cout<< "Pick the new dimension for your Vector (0 will clear the vector)";
    std::cin>> newSize;
    ds.Resize(newSize);
}

//List-only functions
template <typename Data>
void InsertAtFront(lasd::List<Data>& ds){
    Data newElem;
    std::cout<< "Type the element to insert ";
    std::cin>> newElem;
    ds.InsertAtFront(newElem);
}
template <typename Data>
void InsertAtBack(lasd::List<Data>& ds){
    Data newElem;
    std::cout<< "Type the element to insert ";
    std::cin>> newElem;
    ds.InsertAtBack(newElem);
}
template <typename Data>
void Pop(lasd::List<Data>& ds){
    ds.RemoveFromFront();
    std::cout<< "Element successfully removed";
}
template <typename Data>
void TopNPop(lasd::List<Data>& ds){
    std::cout<< "This element has been successfully removed: " << ds.FrontNRemove();;
}
// Menus
template <typename Data>
void MainMenu_List(lasd::List<Data>& ds){
    char choice = '0';
    char separator[] = "->";
    do{
        std::cout<< "\nSTATUS OF MY LIST:\n\n";
        ds.MapPreOrder(PrintElement<Data>, separator);
        std::cout<< "\n\n 1: Print Element\n 2: Search Element\n 3: Fold Function associated to the current Data Structure\n 4: Map Function associated to the current Data Structure\n 5: Insert a new element at front\n 6: Insert a new element at back\n 7: Pop\n 8: TopNPop\n 9: Exit\n" << std::endl;
        std::cin>> choice;
        switch(choice){
            case '1':
                PrintActions(ds);
                break;
            case '2':
                SearchElement(ds);
                break;
            case '3':
                SpecificFoldFunction(ds);
                break;
            case '4':
                SpecificMapFunction(ds);
                break;
            case '5':
                InsertAtFront(ds);
                break;
            case '6':
                InsertAtBack(ds);
                break;
            case '7':
                Pop(ds);
                break;
            case '8':
                TopNPop(ds);
                break;
            case '9':
                std::cout<< "\n!-----HAVE A GOOD DAY-----!" << std::endl;
                break;
            default:
                std::cout<< "****WRONG CHOICE****";
        }
    }while(choice != '9');
}
template <typename Data>
void MainMenu_Vector(lasd::Vector<Data>& ds){
    char choice = '0';
    char separator[] = " ";
    do{
        std::cout<< "\nSTATUS OF MY Vector:\n\n";
        ds.MapPreOrder(PrintElement<Data>, separator);
        std::cout<< "\n\n 1: Print Element\n 2: Search Element\n 3: Fold Function associated to the current Data Structure\n 4: Map Function associated to the current Data Structure\n 5: Resize your vector\n 6: Exit\n" << std::endl;
        std::cin>> choice;
        switch(choice){
            case '1':
                PrintActions(ds);
                break;
            case '2':
                SearchElement(ds);
                break;
            case '3':
                SpecificFoldFunction(ds);
                break;
            case '4':
                SpecificMapFunction(ds);
                break;
            case '5':
                ChangeSize(ds);
                break;
            case '6':
                std::cout<< "\n!-----HAVE A GOOD DAY-----!" << std::endl;
                break;
            default:
                std::cout<< "****WRONG CHOICE****";
        }
    }while(choice != '6');
}
