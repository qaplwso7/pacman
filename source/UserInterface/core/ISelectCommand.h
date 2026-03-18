#pragma once

class ISelectCommand {
public:
    virtual ~ISelectCommand() = default;
    virtual void execute() = 0;
};
