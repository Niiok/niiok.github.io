# OpenGL

- [Function](#function)
- [Shader](#shader)
  - [Vertex shader](#vertex-shader)


Function
======

- **void** glClearBufferfv (**GLenum**, buffer, **GLint** drawBuffer, **const GLfloat**\* value);
>clear *buffer* of *drawBuffer* with *value*
<!-- >*drawBuffer*의 *buffer*를 *value*로 지운다.  -->

- **GLuint** glCreateShader (**GLenum** type);
>create *type* of shader(structure that manage shader code compile and linking it) and return *GLuint* as identifier.

- **void** glShaderSource (**GLuint** shader, **GLsizei** count, **const GLchar\* const \***string, **const GLint \***length);

- **void** glCompileShader (**GLuint** shader);

- **GLuint** glCreateSource (**void**);

- **void** glAttachShader (**GLuint** program, **GLuint** shader);

- **void** glLinkProgram (**GLuint** program);

- **void** glDeleteShader (**GLuint** shader);


Shader
=====
## Vertex Shader

- gl_Position
>represents transform of vertex