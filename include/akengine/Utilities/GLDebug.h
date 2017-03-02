//
// Created by Adrian Krupa on 24.02.2017.
//

#ifndef AKENGINE_GLDEBUG_H
#define AKENGINE_GLDEBUG_H


#include <string>
#include <glbinding/gl/gl.h>
#include <glbinding/Meta.h>


void printErrorLog(std::string logMessage);

#ifndef NDEBUG
#define \
        GL_CHECK(stmt)\
        do {\
            gl::GLenum err;\
            std::string ERR;\
            while((err = gl::glGetError()) != gl::GL_NO_ERROR) {\
                printErrorLog(glbinding::Meta::getString(err) + " (previous GL call) " + #stmt + " " + std::string(__FILE__) + ": " + std::to_string(__LINE__));\
            }\
            stmt;\
            while((err = gl::glGetError()) != gl::GL_NO_ERROR) {\
                printErrorLog(glbinding::Meta::getString(err) + " " + #stmt + " " + std::string(__FILE__) + ": " + std::to_string(__LINE__));\
                }\
        } while (0)
#define \
        GL_CHECK_RETURN(stmt)\
        do {\
            gl::GLenum err;\
            while((err = gl::glGetError()) != gl::GL_NO_ERROR) {\
                printErrorLog(glbinding::Meta::getString(err) + " (previous GL call) " + #stmt + " " + std::string(__FILE__) + ": " + std::to_string(__LINE__));\
            }\
        } while(0);\
        stmt;\
        do {\
            gl::GLenum err;\
            while((err = gl::glGetError()) != gl::GL_NO_ERROR) {\
                printErrorLog(glbinding::Meta::getString(err) + " " + #stmt + " " + std::string(__FILE__) + ": " + std::to_string(__LINE__));\
            }\
        } while(0);
#else
    #define GL_CHECK(stmt) stmt
    #define GL_CHECK_RETURN(stmt) stmt
    #define GL_CHECK_CLEAR() ;
#endif

#endif //AKENGINE_GLDEBUG_H
