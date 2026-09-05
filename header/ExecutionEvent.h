#ifndef RECURSIONVISUALIZER_EXECUTIONEVENT_H
#define RECURSIONVISUALIZER_EXECUTIONEVENT_H

#include <string>
#include "../header/CallStack.h"

enum class EventType
{
    FunctionEnter,
    FunctionExit,
    VariableCreate,
    VariableUpdate,
    FunctionReturn
};

struct ExecutionEvent
{
    EventType Type;
    std::string FunctionName;

    std::vector<Variable> Parameters;
    std::vector<Variable> Variables;

    Variable variable;
    Variable ReturnValue;
};

#endif //RECURSIONVISUALIZER_EXECUTIONEVENT_H
