# OpenGL

- [Function](#function)
- [Shader](#shader)
  - [Vertex shader](#vertex-shader)


Function
======

- **void** glClearBufferfv (**GLenum**, buffer, **GLint** drawBuffer, **const GLfloat**\* value)
>clear *buffer* of *drawBuffer* with *value*
<!-- >*drawBuffer*의 *buffer*를 *value*로 지운다.  -->

- **GLuint** glCreateShader(**GLenum** type)
>create *type* of shader(structure that manage shader code compile and linking it) and return *GLuint* as identifier.

- glShaderSource

- glCompileSouce

- glCreateSource

- glAttachShader

- glLinkProgram

- glDeleteShader


Shader
=====
## Vertex Shader

- gl_Position
>represents transform of vertex