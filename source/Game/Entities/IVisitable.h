#pragma once

#include <memory>

class IGameEvent;
class IVisitor;

class IVisitable {
public:
    virtual ~IVisitable() = default;
    virtual std::unique_ptr<IGameEvent> accept(IVisitor* ptr_visitor) = 0;
};