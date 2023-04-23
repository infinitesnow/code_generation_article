#include "common.hpp"
#include "messages.hpp"

int main(int argc, char *argv[])
{
    auto msg_int = PolymorphicMessage::make<MessageA>(420, 777, 69.0f);
    auto msg_float = PolymorphicMessage::make<MessageB>(
        /* std::initializer_list is needed to infer the template arguments types */
        std::initializer_list<int>{1, 2, 3, 4, 5, 6, 7}, 
        std::initializer_list<float>{7.0f, 6.1f, 5.2f, 4.3f, 3.4f, 2.5f, 1.6f, 0.7f},
        42);
    
    std::cout << "int0: "           << msg_int.as<MessageA>()->m_int0 << std::endl;
    std::cout <<  "vec_float[0]: "  << msg_float.as<MessageB>()->m_vec_float[0] << std::endl;
    // msg_float.as<MessageA>()  // Fails predictably!

    MessageProcessor msg_proc;
    std::cout << std::endl;
    std::cout << "msg_int:" << std::endl;
    msg_proc.process_message(msg_int);

    std::cout << std::endl;
    std::cout << "msg_float:" << std::endl;
    msg_proc.process_message(msg_float);
}