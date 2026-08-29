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

void CallStack::ShowStackFrames()
{
    for (auto stackframe : StackFrames)
    {
        cout << stackframe.FunctionName << "\n";
        cout << stackframe.FunctionDepth << "\n";
    }

    cout << "<------------------------------------------------------------------------------------------>" << "\n";
}
