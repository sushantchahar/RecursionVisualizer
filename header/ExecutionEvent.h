#ifndef RECURSIONVISUALIZER_EXECUTIONEVENT_H
#define RECURSIONVISUALIZER_EXECUTIONEVENT_H

#include <string>

enum class EventType
{
    FunctionEnter,
    FunctionExit
};

struct ExecutionEvent
{
    EventType Type;
    std::string FunctionName;

    std::vector<Variable> Parameters;
    std::vector<Variable> Variables;
};

#endif //RECURSIONVISUALIZER_EXECUTIONEVENT_H
