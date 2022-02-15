#include <string>

struct Node;

extern Node *head;
extern Node *end;

void Print_List();
void Add_Node_End(std::string data);
void Add_Node_Start(std::string data);
void Add_Node_Position(std::string data, size_t position);
void Del_Node_End();
void Del_Node_Start();
void Del_Node_Position(size_t position);
void Edit_Data(std::string data, size_t position);
void Del_List();