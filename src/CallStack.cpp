#include "../header/CallStack.h"
#include <iostream>
using namespace std;

void CallStack::PushFrame(const StackFrame &stackframe)
{
    StackFrames.push_back(stackframe);
}

void CallStack::PopFrame()
{
    if (StackFrames.empty()) return;
    StackFrames.pop_back();
}

void CallStack::EnterFunction(const std::string FunctionName, vector<Variable> &variables, vector<Variable> &parameters)
{
    StackFrame stackframe;
    stackframe.FunctionName = FunctionName;
    stackframe.CallDepth = StackFrames.size() + 1;
    for (auto parameter : parameters)
    {
        AddParameter(stackframe, parameter);
    }
    PushFrame(stackframe);
}

void CallStack::ExitFunction(string &FunctionName)
{
    if (StackFrames.back().FunctionName != FunctionName) return;
    CallStack::PopFrame();
}

void CallStack::AddVariable(StackFrame &stackframe, const Variable &variable)
{
    stackframe.Variables.push_back(variable);
}

void CallStack::AddParameter(StackFrame &stackframe, const Variable &variable)
{
    stackframe.Parameters.push_back(variable);
}

StackFrame& CallStack::GetCurrentStackFrame()
{
    return StackFrames.back();
}

void CallStack::UpdateVariable(StackFrame &stackframe, const Variable &variable)
{
    for (auto &var : stackframe.Variables)
    {
        if (variable.VariableName == var.VariableName)
        {
            var.VariableValue = variable.VariableValue;
        }
    }
}

void CallStack::ShowStackFrames()
{
    for (const StackFrame& frame : StackFrames)
    {
        cout << "Function Name = " << frame.FunctionName << "\n";
        cout << "Call Depth = " << frame.CallDepth << "\n";

        cout << "Parameters\n";

        for (const Variable& parameter : frame.Parameters)
        {
            cout << "    Parameter Name = "
                 << parameter.VariableName << "\n";

            cout << "    Parameter Type = "
                 << parameter.VariableType << "\n";

            cout << "    Parameter Value = "
                 << parameter.VariableValue << "\n";
        }

        cout << "Variables\n";

        for (const Variable& variable : frame.Variables)
        {
            cout << "    Variable Name = "
                 << variable.VariableName << "\n";

            cout << "    Variable Type = "
                 << variable.VariableType << "\n";

            cout << "    Variable Value = "
                 << variable.VariableValue << "\n";
        }
        cout << "\n";
    }
    cout << "<------------------------------------------------------------------------------------------>\n";
}
