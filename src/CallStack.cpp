#include "../header/CallStack.h"
#include <iostream>
using namespace std;

void CallStack::PushFrame(const StackFrame& stackframe)
{
    StackFrames.push_back(stackframe);
}

void CallStack::PopFrame()
{
    if (StackFrames.empty()) return;
    StackFrames.pop_back();
}

void CallStack::EnterFunction(std::string FunctionName)
{
    StackFrame stackframe;
    stackframe.FunctionName = FunctionName;
    stackframe.FunctionDepth = StackFrames.size() + 1;
    PushFrame(stackframe);
}

void CallStack::ExitFunction()
{
    CallStack::PopFrame();
}

void CallStack::ShowStackFrames()
{
    for (auto stackframe : StackFrames)
    {
        cout << "Function Name = " << stackframe.FunctionName << "\n";
        cout << "Call Depth = " << stackframe.FunctionDepth << "\n";
    }

    cout << "<------------------------------------------------------------------------------------------>" << "\n";
}
