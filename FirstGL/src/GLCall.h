#pragma once
#define ASSERT(x) if(!(x)) __debugbreak();
#define GLCall(x)\
    GLCLearError();\
    x;\
    ASSERT(GLLogCall(#x,__FILE__,__LINE__))

void GLCLearError();

bool GLLogCall(const char* function, const char* file, int line);