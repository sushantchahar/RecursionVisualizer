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

    Variable variable;
    Variable ReturnValue;

    int CallDepth = 0;
};

#endif //RECURSIONVISUALIZER_EXECUTIONEVENT_H
