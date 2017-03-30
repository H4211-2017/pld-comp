#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <deque>

static const int FIRST_MEMORY_FUNCTION_OFFSET = 0;

//TODO: set the real list
static const std::deque<std::string> ASM_X86_REGISTER_LIST = { "reg9", "reg10", "reg11", "reg12"};

#endif // CONFIG_H
