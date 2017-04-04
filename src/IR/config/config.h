#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <deque>

static const int FIRST_MEMORY_FUNCTION_OFFSET = 0;

static const std::deque<std::string> ASM_X64_AVAILABLE_REGISTER_LIST = \
       { /*"rax",*/ "rcx", "rdx", "rsi", "rdi", "r8", "r9"};

static const std::deque<std::string> ASM_X64_PRESERVED_REGISTER_LIST = \
       { "rbx", "rbp", "r12", "r13", "r14", "r15"};

static const std::deque<std::string> ASM_X64_VOLATILE_REGISTER_LIST = \
       { "rax", "rcx", "rdx", "r8", "r9", "r10", "r11"};

static const std::deque<std::string> ASM_X64_NON_VOLATILE_REGISTER_LIST = \
       { "rbx", "rbp", "rsp", "rsi", "rdi", "r12", "r13", "r14", "r15"};

static const std::deque<std::string> ASM_X64_CALL_PARAMETERS_REGISTRY = \
       { "r9", "r8", "rcx", "rdx", "rsi", "rdi"};


#endif // CONFIG_H
