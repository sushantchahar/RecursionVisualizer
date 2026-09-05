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
    size_t CurrentEventIndex = 0;
public:
    explicit ExecutionEngine(CallStack &callstack, ExecutionHistory &history);
    void ProcessEvent(ExecutionEvent &event);
    void Replay(size_t index);
    void ApplyEvent(ExecutionEvent &event);
    void StepForward();
    void StepBackward();
};

#endif //RECURSIONVISUALIZER_EXECUTIONENGINE_H
