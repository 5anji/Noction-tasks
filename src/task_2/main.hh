#include <iostream>
#include <csignal>

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
};

std::string Black(std::string str);
std::string Red(std::string str);
std::string Green(std::string str);
std::string Orange(std::string str);
std::string Blue(std::string str);
std::string Purple(std::string str);
std::string Cyan(std::string str);
std::string Gray(std::string str);
std::string Bold(std::string str);
std::string Underline(std::string str);

void signalHandler(int n);