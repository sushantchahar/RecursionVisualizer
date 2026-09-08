#include "../header/ExecutionHistory.h"
#include <iostream>
using namespace std;

int ExecutionHistory::counter = 0;

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

ostream& operator<<(ostream &os, EventType type)
{
    switch (type)
    {
        case EventType::FunctionEnter:
            os << "Function Enter";
            break;
        case EventType::FunctionExit:
            os << "Function Exit";
            break;
        case EventType::VariableCreate:
            os << "Variable Create";
            break;
        case EventType::VariableUpdate:
            os << "Variable Update";
            break;
        case EventType::FunctionReturn:
            os << "Function Return";
            break;
    }

    return os;
}

void ExecutionHistory::PrintEvent(const ExecutionEvent& Event)
{
    ExecutionHistory::counter++;
    cout << "Event: #" << ExecutionHistory::counter << "\n";
    cout << "Type: " << Event.Type << "\n";
    cout << "Function: " << Event.FunctionName << "\n";
    cout << "Call Depth: " << Event.CallDepth << "\n";
    cout << "Return Value: " << Event.ReturnValue.VariableValue << "\n";
    if (Event.Type == EventType::FunctionEnter)
    {
        cout << "Parameters: " << "\n";
        for (const auto &Param : Event.Parameters)
        {
            cout << Param.VariableName << " = " << Param.VariableValue << "\n";
        }
    }
    cout << "\n";
}
