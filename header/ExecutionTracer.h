#ifndef RECURSIONVISUALIZER_EXECUTIONTRACER_H
#define RECURSIONVISUALIZER_EXECUTIONTRACER_H
#include "../header/ExecutionEngine.h"

class ExecutionTracer
{
private:
    ExecutionEngine &engine;

public:
    explicit ExecutionTracer(ExecutionEngine &executionengine);

    void EnterFunction(std::string FunctionName, std::vector<Variable> &Parameters);
    void ExitFunction(std::string FunctionName);
    void VariableCreate(const std::string FunctionName, Variable &variable);
    void VariableUpdate(const std::string FunctionName, Variable &variable);
    void ReturnFunctionValue(std::string FunctionName, const Variable &ReturnValue);
};

#endif //RECURSIONVISUALIZER_EXECUTIONTRACER_H
