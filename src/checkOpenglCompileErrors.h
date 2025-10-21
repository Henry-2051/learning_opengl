#ifndef OPENGL_COMP_CHECKER27
#define OPENGL_COMP_CHECKER27

#include <GL/glew.h>
#include <iostream>
#include <optional>

namespace ShaderUtils {
    inline std::optional<std::string> getCompileErrors(unsigned int shader, std::string type)
    {
        int success;
        char infoLog[1024];

        if (type != "PROGRAM")
        {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(shader, 1024, NULL, infoLog);
                return "ERROR::SHADER_COMPILATION_ERROR of type: " + type + "\n" + infoLog + "\n -- --------------------------------------------------- -- \n";
            }
        }
        else
        {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if (!success)
            {
                glGetProgramInfoLog(shader, 1024, NULL, infoLog);
                return "ERROR::PROGRAM_LINKING_ERROR of type: " + type + "\n" + infoLog + "\n -- --------------------------------------------------- -- \n" ;
            }
        }
        return std::nullopt;
    }
}

#endif