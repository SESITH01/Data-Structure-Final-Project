#define MAXSIZE 1000
#include <string>

struct BoardGame {
std::string name;
int year;
int time;
int rating;
BoardGame* left = nullptr;
BoardGame* right = nullptr;

//Default constructor
BoardGame() : year(0), time(0), rating(0) {}

// Parameterized constructor
BoardGame(std::string n, int y, int t, int r)
    : name(std::move(n)), year(y), time(t), rating(r) {}
};

class BST {

public:
  
  BST(); // Constructor
  
  BoardGame*& GetRoot();

  void AfterYear(BoardGame* node, int targetYear);

  void AfterYear(int targetYear);

  void PrintAll(BoardGame* node); //Prints all elements 

  void PrintAll();

  void InsertBST(BoardGame*& curnode, BoardGame newitem);


private:
    
    int length;
    BoardGame* root;
    int currentPos;
    
    
 
};

