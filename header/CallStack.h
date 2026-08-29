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

public:
    void ShowStackFrames();
    void PushFrame(const StackFrame &stackframe);
    void PopFrame();
};


#endif //RECURSIONVISUALIZER_CALLSTACK_H
