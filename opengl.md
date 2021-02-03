# OpenGL

- [Function](#function)
- [Shader](#shader)
  - [Vertex shader](#vertex-shader)


Function
======
### Buffer
- **void** glClearBufferfv (**GLenum**, buffer, **GLint** drawBuffer, **const GLfloat**\* value);
>clear *buffer* of *drawBuffer* with *value*
<!-- >*drawBuffer*의 *buffer*를 *value*로 지운다.  -->

### Shader & Program
- **GLuint** glCreateShader (**GLenum** type);
>create *type* of shader(structure that manage shader code compile and linking it) and return *GLuint* as identifier.

- **void** glShaderSource (**GLuint** shader, **GLsizei** count, **const GLchar\* const \***string, **const GLint \***length);

- **void** glCompileShader (**GLuint** shader);

- **GLuint** glCreateSource (**void**);

- **void** glAttachShader (**GLuint** program, **GLuint** shader);

- **void** glLinkProgram (**GLuint** program);

- **void** glDeleteShader (**GLuint** shader);

- **void** glDeleteProgram (**GLuint** program);

### Vertex Array
- **void** glGenVertexArrays (**GLsizei** n, **GLuint \***arrays);

- **void** glBindVertexArray (**GLuint** array);

<!-- ### not done
- glUseProgram ();

- **void** glDrawArrays (**GLenum** mode, **GLint** first, **GLsizei** count);
>send vertexes to pipeline. started from *first*, *count* of vertexes with premitive *mode*
>mode list: GL_POINTS, GL_TRIANGLES, GL_STRIPES, GL_LINES ...

- **void** glPointSize (**GLfloat** size);
>change point pixel size
-->

Shader
=====
## Vertex Shader

- gl_Position
>represents transform of vertex