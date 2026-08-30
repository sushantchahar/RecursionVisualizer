#ifndef RECURSIONVISUALIZER_EXECUTIONENGINE_H
#define RECURSIONVISUALIZER_EXECUTIONENGINE_H
#include "CallStack.h"
#include "ExecutionEvent.h"

class ExecutionEngine
{
private:
    CallStack &callstack;
public:
    explicit ExecutionEngine(CallStack &callstack);
    void ProcessEvent(ExecutionEvent &event);
};

#endif //RECURSIONVISUALIZER_EXECUTIONENGINE_H
