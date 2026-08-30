#include "../header/ExecutionEngine.h"
#include "../header/ExecutionEvent.h"
#include "../header/CallStack.h"

ExecutionEngine::ExecutionEngine(CallStack &callstack) : callstack(callstack){}

void ExecutionEngine::ProcessEvent(ExecutionEvent &event)
{
    switch (event.Type)
    {
        case EventType::FunctionEnter:
            callstack.EnterFunction(event.FunctionName, event.Variables, event.Parameters);
            break;

        case EventType::FunctionExit:
            callstack.ExitFunction(event.FunctionName);
            break;
    }
}