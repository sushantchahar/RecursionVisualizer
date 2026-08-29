#ifndef RECURSIONVISUALIZER_CALLSTACK_H
#define RECURSIONVISUALIZER_CALLSTACK_H
#include <string>
#include <vector>

struct StackFrame
{
    std::string FunctionName;
    int FunctionDepth = 0;
};

class CallStack
{
private:
    std::vector<StackFrame> StackFrames;

private:
    void PushFrame(const StackFrame &stackframe);
    void PopFrame();

public:
    void EnterFunction(std::string FunctionName);
    void ExitFunction();
    void ShowStackFrames();
};


#endif //RECURSIONVISUALIZER_CALLSTACK_H
