#include "../header/ExecutionHistory.h"

void ExecutionHistory::AddEvent(ExecutionEvent &Event)
{
    Events.push_back(Event);
}

const ExecutionEvent& ExecutionHistory::GetEvent(size_t index) const
{
    return Events.at(index);
}

const size_t ExecutionHistory::GetEventCount() const
{
    return Events.size();
}

void ExecutionHistory::Clear()
{
    Events.clear();
}
