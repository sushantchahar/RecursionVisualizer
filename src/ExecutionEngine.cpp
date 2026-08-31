#include "../header/ExecutionEngine.h"
#include "../header/ExecutionEvent.h"
#include "../header/CallStack.h"

ExecutionEngine::ExecutionEngine(CallStack &callstack, ExecutionHistory &history) : callstack(callstack), history(history){}

void ExecutionEngine::ProcessEvent(ExecutionEvent &event)
{
    history.AddEvent(event);
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
    }
}