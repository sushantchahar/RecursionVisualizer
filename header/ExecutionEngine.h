#ifndef RECURSIONVISUALIZER_EXECUTIONENGINE_H
#define RECURSIONVISUALIZER_EXECUTIONENGINE_H
#include "CallStack.h"
#include "ExecutionEvent.h"
#include "ExecutionHistory.h"

class ExecutionEngine
{
private:
    CallStack &callstack;
    ExecutionHistory &history;
public:
    explicit ExecutionEngine(CallStack &callstack, ExecutionHistory &history);
    void ProcessEvent(ExecutionEvent &event);
};

#endif //RECURSIONVISUALIZER_EXECUTIONENGINE_H
