#include <string>

struct Node;

class Linked_List {
private:
  Node *head;
  Node *end;

public:
  Linked_List();
  Linked_List(std::string str);
  Linked_List(Linked_List &list);
  ~Linked_List();

  void operator=(Linked_List &copy);
  
  void Print_List();
  void Add_Node_End(std::string data);
  void Add_Node_Start(std::string data);
  void Add_Node_Position(std::string data, size_t position);
  void Del_Node_End();
  void Del_Node_Start();
  void Del_Node_Position(size_t position);
  void Edit_Data(std::string data, size_t position);
  void Del_List();
  void Copy_List(Linked_List &copy);
};