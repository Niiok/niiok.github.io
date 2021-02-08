# OpenGL

- [Function](#function)
- [Shader Built-in variable](#shader-built-in-variable)
  - [Vertex shader](#vertex-shader)


- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

Function
================================================================
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
### Buffer


~~~ C
void glClearBufferfv (GLenum buffer, GLint drawBuffer, const GLfloat *value);
~~~
>clear ***buffer*** of ***drawBuffer*** with ***value***
<!-- >*drawBuffer*의 *buffer*를 *value*로 지운다.  -->

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
### Shader & Program


- **GLuint** glCreateShader (**GLenum** type);
>create ***type*** of shader(structure that manage shader code compile and linking it) and return ***GLuint*** as identifier.

- **void** glShaderSource (**GLuint** shader, **GLsizei** count, **const GLchar\* const \***string, **const GLint \***length);
>will add more explains

- **void** glCompileShader (**GLuint** shader);
>as-is name

- **GLuint** glCreateProgram (**void**);
>as-is name

- **void** glAttachShader (**GLuint** program, **GLuint** shader);
>as-is name

- **void** glLinkProgram (**GLuint** program);
>as-is name

- **void** glDeleteShader (**GLuint** shader);
>as-is name

- **void** glDeleteProgram (**GLuint** program);
>as-is name


- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
### Vertex Shader manage


#### Vertex Array
- **void** glGenVertexArrays (**GLsizei** n, **GLuint \***arrays);
>Generate ***n*** number of VAO(Vertex Array Object)s in ***arrays***.    
>since this function access GLuint as array, it requires ***arrays***' address as parameter.

- **void** glBindVertexArray (**GLuint** array);
>bind ***array***(VAO) to current context.


#### ood
- **void** glDrawArrays (**GLenum** mode, **GLint** first, **GLsizei** count);
>send vertexes to pipeline. started from ***first***, ***count*** of vertexes with premitive ***mode***    
>mode example: GL_POINTS, GL_LINES, GL_TRIANGLES, GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN, ...

~~~ C
void glVertexAttrib4fv(GLuint index, const GLfloat *v);
~~~
>4fv means 4 float vector


- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
### Tessellation Shader manage


~~~ C
void glPatchParameteri (GLenum pname, GLint value);
~~~
> tname example: GL_PATCH_VETICES



<!-- ### not done
- glUseProgram ();


- **void** glPointSize (**GLfloat** size);
>change point pixel size into ***size***

~~~ c
void glPolygonMode (GLenum face, GLenum mode);
~~~

-->


- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 


Shader Built-in variable
================================================================
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
<!--## Vertex Shader-->


- gl_Position
>(out) represents transform of vertex

- gl_VertexID
>specify id used in vertex shader    
>(in) Ex: glDrawArrays) started from ***first*** , ***count*** number of vertex

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
<!--## Tesselation Control Shader-->


- gl_InvocationID
>(in) used fo 0-based index of gl_in, gl_out

- gl_TessLeevelInner
- gl_TessLevelOuter
>(out) Tessellation factor variable array    
>contain tessellation level


- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 



gl_TessCoord


- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
## ???


- gl_in
- gl_out
>not simple variable, but array


<!--
- **void** glClearBufferfv (**GLenum** buffer, **GLint** drawBuffer, **const GLfloat**\* value);
-->