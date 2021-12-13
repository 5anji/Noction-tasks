#include <string>

struct Node;

class Linked_List {
private:
  Node *head;
  Node *end;

public:
  Linked_List();
  void Print_List();
  void Add_Node_End(std::string data);
  void Add_Node_Start(std::string data);
  void Add_Node_Position(std::string data, int position);
  void Del_Node_End();
  void Del_Node_Start();
  void Del_Node_Position(int position);
  void Edit_Data(std::string data, int position);
  void Del_List();
  void Copy_List(Linked_List &copy);
};