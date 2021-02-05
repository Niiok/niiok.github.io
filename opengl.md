# OpenGL

- [Function](#function)
- [Shader](#shader)
  - [Vertex shader](#vertex-shader)


Function
======

### Buffer
- **void** glClearBufferfv (**GLenum**, buffer, **GLint** drawBuffer, **const GLfloat**\* value);
>clear ***buffer*** of ***drawBuffer*** with ***value***
<!-- >*drawBuffer*의 *buffer*를 *value*로 지운다.  -->

### Shader & Program
- **GLuint** glCreateShader (**GLenum** type);
>create ***type*** of shader(structure that manage shader code compile and linking it) and return ***GLuint*** as identifier.

- **void** glShaderSource (**GLuint** shader, **GLsizei** count, **const GLchar\* const \***string, **const GLint \***length);
>will add more explains

- **void** glCompileShader (**GLuint** shader);
>as-is name

- **GLuint** glCreateSource (**void**);
>as-is name

- **void** glAttachShader (**GLuint** program, **GLuint** shader);
>as-is name

- **void** glLinkProgram (**GLuint** program);
>as-is name

- **void** glDeleteShader (**GLuint** shader);
>as-is name

- **void** glDeleteProgram (**GLuint** program);
>as-is name

### Vertex Array
- **void** glGenVertexArrays (**GLsizei** n, **GLuint \***arrays);
>Generate ***n*** number of VAO(Vertex Array Object)s in ***arrays***.
>since this function access GLuint as array, it requires ***arrays***' address as parameter.

- **void** glBindVertexArray (**GLuint** array);
>bind ***array***(VAO) to current context.

- **void** glDrawArrays (**GLenum** mode, **GLint** first, **GLsizei** count);
>send vertexes to pipeline. started from ***first***, ***count*** of vertexes with premitive ***mode***
>mode list: GL_POINTS, GL_TRIANGLES, GL_STRIPES, GL_LINES ...

<!-- ### not done
- glUseProgram ();


- **void** glPointSize (**GLfloat** size);
>change point pixel size into ***size***
-->


Shader
=====

## Vertex Shader

- gl_Position
>represents transform of vertex