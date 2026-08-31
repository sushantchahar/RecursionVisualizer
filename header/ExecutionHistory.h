#ifndef RECURSIONVISUALIZER_EXECUTIONHISTORY_H
#define RECURSIONVISUALIZER_EXECUTIONHISTORY_H
#include <vector>
#include "ExecutionEvent.h"

class ExecutionHistory
{
private:
    std::vector<ExecutionEvent> Events;

public:
    void AddEvent(ExecutionEvent &Event);
    const ExecutionEvent& GetEvent(size_t index) const;
    const size_t GetEventCount() const;
    void Clear();
};

#endif //RECURSIONVISUALIZER_EXECUTIONHISTORY_H
