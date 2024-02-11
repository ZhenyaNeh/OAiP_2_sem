#pragma once

struct stack {
    int inf;
    stack* next;
};
int menu();
stack* addElements(stack* begin);
stack* addElementsFile(stack* begin, int buff);
stack* deleteValueMore(stack* begin);
void showStack(stack* begin);
void deleteStack(stack** begin);
void input(int& a);
int write_In_File(stack** begin);
