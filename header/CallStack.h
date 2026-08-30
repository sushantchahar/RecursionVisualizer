#ifndef RECURSIONVISUALIZER_CALLSTACK_H
#define RECURSIONVISUALIZER_CALLSTACK_H
#include <string>
#include <vector>

struct Variable
{
    std::string VariableName;
    std::string VariableType;
    std::string VariableValue;
};

struct StackFrame
{
    std::string FunctionName;
    int FunctionDepth = 0;

    std::vector<Variable> Variables;
    std::vector<Variable> Parameters;
};

class CallStack
{
private:
    std::vector<StackFrame> StackFrames;

private:
    void PushFrame(const StackFrame &stackframe);
    void PopFrame();
    void AddVariable(StackFrame &stackframe, const Variable &variable);
    void AddParameter(StackFrame &stackframe, const Variable &variable);

public:
    void EnterFunction(const std::string FunctionName, std::vector<Variable> &variables, std::vector<Variable> &parameters);
    void ExitFunction(std::string &FunctionName);
    void ShowStackFrames();
};


#endif //RECURSIONVISUALIZER_CALLSTACK_H
