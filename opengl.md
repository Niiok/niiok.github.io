# OpenGL

- [Function](#function)
- [Shader Built-in variable](#shader-built-in-variable)
  - [Vertex shader](#vertex-shader)


- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 










Function
================================================================
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
## Buffer


- glClearBuffer
~~~ C
void glClearBufferfv (GLenum buffer, GLint drawBuffer, const GLfloat *value);
~~~
>clear _`buffer`_ of _`drawBuffer`_ with _`value`_
<!-- >_drawBuffer_의 _buffer_를 _value_로 지운다.  -->



- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
## Shader & Program object manage


- glCreateShader
~~~ C
GLuint glCreateShader (GLenum type);
~~~
>create _`type`_ of shader(structure that manage shader code compile and linking it) and return _`GLuint`_ as identifier.


- glShaderSource
~~~ C
void glShaderSource (GLuint shader, GLsizei count, const GLchar* const *string, const GLint *length);
~~~
>will add more explains


- glCompileShader
~~~ C
void glCompileShader (GLuint shader);
~~~
> Compile _`shader`_ type sader.


- glCreateProgram
~~~ C
GLuint glCreateProgram (void);
~~~
>create a program object and return it.


- glAttachShader
~~~ C
void glAttachShader (GLuint program, GLuint shader);
~~~
>attach _`shader`_ to _`program`_


- glLinkProgram
~~~ C
void glLinkProgram (GLuint program);
~~~
>as-is name


- glDeleteShader
~~~ C
void glDeleteShader (GLuint shader);
~~~
>as-is name


- glDeleteProgram
~~~ C
void glDeleteProgram (GLuint program);
~~~
>as-is name



- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
## Vertex Shader manage


#### Vertex Array

- glGenVertexArrays
~~~ C
void glGenVertexArrays (GLsizei n, GLuint *arrays);
~~~
>Generate _`n`_ number of VAO(Vertex Array Object)s in _`arrays`_.    
>since this function access GLuint as array, it requires _`arrays`_' address as parameter.


- glBindVertexArray
~~~ C
void glBindVertexArray (GLuint array);
~~~
>bind _`array`_(VAO) to current context.



#### ood

- glDrawArrays
~~~ C
void glDrawArrays (GLenum mode, GLint first, GLsizei count);
~~~
>send vertexes to pipeline. started from _`first`_, _`count`_ of vertexes with premitive _`mode`_    
>mode example: GL_POINTS, GL_LINES, GL_TRIANGLES, GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN, GL_PATCHES, ...


- glVertexAttrib
~~~ C
void glVertexAttrib4fv(GLuint index, const GLfloat *v);
~~~
>set 4fv of vertex attribute to layout(loaction = _`index`_).    
>4fv means 4 float vector(array)



- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
## Tessellation Shader manage


- glPatchParameteri
~~~ C
void glPatchParameteri (GLenum pname, GLint value);
~~~
> tname example: GL_PATCH_VETICES


- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
## Geometry Shader manage





<!-- ## not done
- glUseProgram ();


- void glPointSize (GLfloat size);
>change point pixel size into _`size`_

~~~ C
void glPolygonMode (GLenum face, GLenum mode);
~~~

~~~ C
void glViewport (GLint x, GLint y, GLsizei width, GLsizei height);
~~~

~~~ C
void glDepthRange (GLdouble nearVal, GLdouble farVal);
~~~

~~~ C
glFrontFace()
~~~
>Gets winding order and set _`dir`_ order primitive as front face of culling process.    
>dir : GL_CW(clockwise), GL_CCW(counterclockwise)    
>default front face when glFrontFace was never called is GL_CCW.

~~~ C
glEnable
~~~
>cap :     GL_CULL_FACE : enable culling

~~~ C
glCullFace()
~~~
>choose which faces to cull.  ex) GL_FRONT, GL_BACK, GL_FRONT_AND_BACK

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
>(in) Ex: glDrawArrays) started from _`first`_ , _`count`_ number of vertex

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
<!--## Tesselation Control Shader-->


- gl_InvocationID
>(in) used fo 0-based index of gl_in, gl_out

- gl_TessLevelInner
- gl_TessLevelOuter
>(out) Tessellation factor variable array    
>contain tessellation level


- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 



- gl_TessCoord
>(in)barycentric coodinate of vertex

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 



~~~ C
EmitVertex()
~~~
>make vertex with gl_Position of geometry shader

~~~ C
EndPrimitive()
~~~
>automatically called when geometry shader end

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
<!--## Fragment Shader-->


- gl_FragCoord
>(in)coordinate of fragment to manipulate


- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
## General


- gl_in
- gl_out
>not simple variable, but array


- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
## layout

- Vertex    
	layout (location = 0) in vec4 variablename;    
	//location used as attribute index 
   
- Tesselation Control    
	layout (vertices = 3) out;    
	//output control point(vertices) per patch 
   
- Tesselation Evaluation    
	layout (triangles, equal_spacing, cw) in;    
	//setting for tessellation mode
   
- Geometry    
	layout (triangles) in;    
	layout (points, max_vertices = 3) out;    
	//get input as triangle and divide them into points
   
- Fragment    
   
- Compute    
	layout (local_size_x = 32, local_size_y = 32) in;    
	//local workgroup szie is 32*32
   

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
## extension


	#extension GL_extension_feature_en : enable  //enable feature both device support it or not    
	#extension GL_extension_feature_re : required  //if this extensio is not replaceable, use required for assertive code    
	    
	#if GL_extension_feature_en    
	//extension's name will be defined with macro so you can manage code    
	#else    
	//alternative codes if extension doesn't supported    
	#endif






Fixed Block
================================================================
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
## Pixel Operations
	scissor test => stencil test => depth test => 


- Model (Object?)
- World
- View
- Clip
- Normalized device coordinate
- Window

