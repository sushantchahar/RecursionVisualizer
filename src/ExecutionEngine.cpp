#include "../header/ExecutionEngine.h"
#include "../header/ExecutionEvent.h"
#include "../header/CallStack.h"
#include <iostream>

ExecutionEngine::ExecutionEngine(CallStack &callstack, ExecutionHistory &history) : callstack(callstack), history(history){}

void ExecutionEngine::ProcessEvent(ExecutionEvent &event)
{
    history.AddEvent(event);
    ApplyEvent(event);
}

void ExecutionEngine::Replay(size_t index)
{
    if (history.GetEventCount() == 0) return;
    if (index >= history.GetEventCount()) index = history.GetEventCount() - 1;

    callstack.Clear();

    for (size_t i = 0; i <= index; ++i)
    {
        ExecutionEvent event = history.GetEvent(i);

        ApplyEvent(event);
    }
}

void ExecutionEngine::ApplyEvent(ExecutionEvent &event)
{
    switch (event.Type)
    {
    case EventType::FunctionEnter:
        callstack.EnterFunction(event.FunctionName, event.Parameters);
        break;

    case EventType::FunctionExit:
        callstack.ExitFunction(event.FunctionName);
        break;

    case EventType::VariableCreate:
        callstack.AddVariable(callstack.GetCurrentStackFrame(), event.variable);
        break;

    case EventType::VariableUpdate:
        callstack.UpdateVariable(callstack.GetCurrentStackFrame(), event.variable);
        break;

    case EventType::FunctionReturn:
        callstack.SetReturnedValue(event.ReturnValue);
        break;
    }
}

void ExecutionEngine::StepForward()
{
    if (history.GetEventCount() == 0) return;
    if (CurrentEventIndex >= history.GetEventCount()) return;

    ExecutionEvent event = history.GetEvent(CurrentEventIndex);
    ApplyEvent(event);
    CurrentEventIndex++;}

void ExecutionEngine::StepBackward()
{
    if (CurrentEventIndex == 0) return;

    --CurrentEventIndex;

    callstack.Clear();

    for (size_t i = 0; i < CurrentEventIndex; ++i)
    {
        ExecutionEvent event = history.GetEvent(i);
        ApplyEvent(event);
    }
}
