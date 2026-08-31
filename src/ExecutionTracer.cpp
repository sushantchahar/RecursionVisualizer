#include "../header/ExecutionTracer.h"
#include <iostream>

ExecutionTracer::ExecutionTracer(ExecutionEngine &executionEngine) : engine(executionEngine) {}

void ExecutionTracer::EnterFunction(std::string FunctionName, std::vector<Variable> &Parameters)
{
    ExecutionEvent FunctionEnterEvent;
    FunctionEnterEvent.FunctionName = FunctionName;
    FunctionEnterEvent.Type = EventType::FunctionEnter;
    FunctionEnterEvent.Parameters = Parameters;
    engine.ProcessEvent(FunctionEnterEvent);
}

void ExecutionTracer::ExitFunction(std::string FunctionName)
{
    ExecutionEvent FunctionExitEvent;
    FunctionExitEvent.FunctionName = FunctionName;
    FunctionExitEvent.Type = EventType::FunctionExit;
    engine.ProcessEvent(FunctionExitEvent);
}

void ExecutionTracer::VariableCreate(Variable &variable)
{
    ExecutionEvent VariableCreateEvent;
    VariableCreateEvent.Type = EventType::VariableCreate;
    VariableCreateEvent.variable = variable;
    engine.ProcessEvent(VariableCreateEvent);
}

void ExecutionTracer::VariableUpdate(Variable &variable)
{
    ExecutionEvent VariableUpdateEvent;
    VariableUpdateEvent.Type = EventType::VariableUpdate;
    VariableUpdateEvent.variable = variable;
    engine.ProcessEvent(VariableUpdateEvent);
}