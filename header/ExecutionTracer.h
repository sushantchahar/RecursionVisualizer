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
    void VariableCreate(Variable &variable);
    void VariableUpdate(Variable &variable);
};

#endif //RECURSIONVISUALIZER_EXECUTIONTRACER_H
