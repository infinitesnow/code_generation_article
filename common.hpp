#pragma once

#include <memory>
#include <stdexcept>

struct AbstractMessage
{
    virtual void print() = 0;
};

/* Wrapper class with convenient factories and cast methods */
class PolymorphicMessage : public AbstractMessage
{
    public:

        void print()
        {
            m_msg->print();
        }

        template<typename T, typename... Args>
        static PolymorphicMessage make(Args... args)
        {
            auto wrapped = std::make_shared<T>(std::forward<Args>(args)...);
            return PolymorphicMessage(wrapped);
        }

        template<typename T>
        std::shared_ptr<T> as()
        {
            auto ptr = std::dynamic_pointer_cast<T>(m_msg);
            if (ptr.get() == nullptr)
            {
                throw std::logic_error("Invalid cast!");
            }
            return ptr;
        }

    private:
        PolymorphicMessage(std::shared_ptr<AbstractMessage> _msg) : m_msg(_msg) {}
        std::shared_ptr<AbstractMessage> m_msg;

};

class MessageProcessor
{
    public:
        void process_message(AbstractMessage &msg)
        {
            msg.print();
        }
};