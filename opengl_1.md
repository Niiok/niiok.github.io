Data type
================================================================
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

## Buffer
- need name to identify
- memory allocated for buffer object is called **data storage**.
- two method to put data in buffer are ; using command ; _mapping_ with pointer
- can _bind_ into context's _buffer binding point_ with buffer's name.
- _binding point_ can be refered as _target_ in most cases. (but target may have multiple binging point)
    
- buffer binding process
> glGenBuffers -> glBindBuffer -> glBufferData
    
- There's 3 way to manipulate buffer object's data
  - using _`data`_ parameter of _glBufferData()_
  - using _glBufferSubData()_
  - using _glMapBuffer()_


- - - - - - - - - - - - - - - - - - - - 
<!---------------------------------------------------------------------------------------------------------------->


- glBindBuffer()
```C
void glBindBuffer (GLenum target, GLuint buffer);
```
  - _`target`_ enum list
    - **GL_ARRAY_BUFFER**			: Vertex attributes
    - **GL_ATOMIC_COUNTER_BUFFER**	: Atomic counter storage
    - **GL_COPY_READ_BUFFER**		: Buffer copy source
    - **GL_COPY_WRITE_BUFFER**		: Buffer copy destination
    - **GL_DISPATCH_INDIRECT_BUFFER**	: Indirect compute dispatch commands
    - **GL_DRAW_INDIRECT_BUFFER**		: Indirect command arguments
    - **GL_ELEMENT_ARRAY_BUFFER**		: Vertex array indices
    - **GL_PIXEL_PACK_BUFFER**		: Pixel read target
    - **GL_PIXEL_UNPACK_BUFFER**		: Texture data source
    - **GL_QUERY_BUFFER**			: Query result buffer
    - **GL_SHADER_STORAGE_BUFFER**	: Read-write storage for shaders
    - **GL_TEXTURE_BUFFER**		: Texture data buffer
    - **GL_TRANSFORM_FEEDBACK_BUFFER**	: Transform feedback buffer
    - **GL_UNIFORM_BUFFER**		: Uniform block storage


<!---------------------------------------------------------------------------------------------------------------->


- glBufferData()
```C
void glBufferData (GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage);
```
create 'data store'(memory) for current buffer object of _`target`_.
  - _`target`_ enum list
    - **GL_ARRAY_BUFFER**
    - **GL_ELEMENT_ARRAY_BUFFER**
    - **GL_PIXEL_PACK_BUFFER**
    - **GL_PIXEL_UNPACK_BUFFER**

  - _`usage`_ enum list
    - **GL_STREAM_DRAW**  	: modified once by application, accessed rarely, used for drawing and imaging.
    - **GL_STREAM_READ** 	 	: modified once by GL reading, accessed rarely, used for returning data for queries of application.
    - **GL_STREAM_COPY** 	 	: modified once by GL reading, accessed rarely, used for drawing and imaging.
    - **GL_STATIC_DRAW** 	 	: modified once by GL application, accessed often, used for drawing and imaging.
    - **GL_STATIC_READ**  	  	: modified once by GL reading, accessed often, used for returning data for queries of application.
    - **GL_STATIC_COPY**  		: modified once by GL reading, accessed often, used for drawing and imaging.
    - **GL_DYNAMIC_DRAW**  	: modified multiple time by GL application, accessed often, used for drawing and imaging.
    - **GL_DYNAMIC_READ**  	: modified multiple time by GL reading, accessed often, used for returning data for queries of application.
    - **GL_DYNAMIC_COPY**  	: modified multiple time by GL reading, accessed often, used for drawing and imaging.
    
> _`size`_ is size of data store.        
> _`data`_ is pointer indicating where data storage copy initial data from.    
> can be setted as NULL and data store won't be initalized.    
    



<!---------------------------------------------------------------------------------------------------------------->


- glBufferSubData()
```C
void glBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data);
```

> _`target`_ enum list is same with glBindBuffer.    
> _`offset`_ is position inside buffer to start inserting data    
> _`size`_ is byte size of inserting data    
> _`data`_ is pointer for data to insert in buffer


<!---------------------------------------------------------------------------------------------------------------->


- glClearBufferSubData()
```C
void glClearBufferSubData (GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data);
```
  - _`format`_ enum list
    - **GL_RED**	: 1 channel
    - **GL_RG**	: 2 channel
    - **GL_RGB**	: 3 channel
    - **GL_RGBA**	: 4 channel

  - _`type`_ basic types
    - **GL_BYTE**			: GLchar
    - **GL_UNSIGNED_BYTE**		: GLuchar
    - **GL_SHORT**			: GLshort
    - **GL_UNSIGNED_SHORT**	: GLushort
    - **GL_INT**			: GLint
    - **GL_UNSINGED_INT**		: GLuint
    - **GL_FLOAT**			: GLfloat
    - **GL_DOUBLE.**		: GLdouble

> _`target`_ is buffer to clear with constant value    
> _`internalformat`_ is specific format to convert    
> _`offset`_ is offset byte to start clear    
> _`size`_ is bytes to continue clear    
> _`format`_ and _`type`_ are method to adjust data in _`data`_


<!---------------------------------------------------------------------------------------------------------------->


- glCopyBufferSubData()
```C
vod glCopyBufferSubData (GLenum readtarget, GLenum writetarget, GLintptr readoffset, GLintptr writeoffset, GLsizeiptr size);
```
> this function use buffer binding points_`readtarget, writetarget`_. and this way of copying has unwanted sideeffects sometime.     
> so **GL_COPY_READ_BUFFER** and **GL_COPY_WRITE_BUFFER** are provided for dedicated binding point.


<!---------------------------------------------------------------------------------------------------------------->


- glGenBuffers()
```C
void glGenBuffers (GLsizei n, GLuint * buffers);
```
> glGenBuffers generate _`n`_ of buffers and insert their buffer names into GLuint array _`buffers`_.
<!--
_`n`_ is number of buffer object names to be generated.    
_`buffers`_ is array of GLuint buffer names will be allocated
-->


<!---------------------------------------------------------------------------------------------------------------->


- glMapBuffer ()
```C
void* glMapBuffer (GLenum target, GLenum access);
```
  - _`access`_ enum list
    - **GL_READ_ONLY**	: returned pointer will be used for reading buffer object's data
    - **GL_WRITE_ONLY**	: returned pointer will be used for writing buffer object's data
    - **GL_READ_WRITE**	: returned pointer will be used for both reading and writing

> map data store of _`target`_ buffer object into client's address space and return its void* pointer address.    
> _`target`_ enum list is same with glBindBuffer.    
> using returned pointer address for GL function parameter is nonstandard. it may occur unexpected result.    
> can unmap with `glUnmapBuffer (_target_);`.


<!---------------------------------------------------------------------------------------------------------------->


<!--
```C
void glCreateBuffers (GLsizei n, GLuint * buffers);
```
-->


<!---------------------------------------------------------------------------------------------------------------->
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
<!---------------------------------------------------------------------------------------------------------------->


- glVertexAttribPointer()
```C
void glVertexAttribPointer (GLuint index,
		 GLint size = 0,
		 GLenum type = GL_FLOAT,
		 GLboolean normalized.
		 GLsizei stride = 0,
		 const GLvoid * pointer = 0 );
```
>  _`index`_ is index of vertex attribute inside "layout (location = index)" to insert.    
>  _`size`_ is number (1, 2, 3, 4) of components like '3 for vec3' or '4 for vec4'.    
>  _`type`_ is data types like **GL_FLOAT**, **GL_INT**, **GL_BYTE**, etc.    
> since **float** is standard type for opengl vector, they will be converted into float, and it's reason for _`normalized`_ is important.    
>  if _`normalized`_ is **GL_TRUE**, that means datas' values need to be float with value between 0.0 to 1.0 for unsigned, -1.0 to 1.0 for signed.    
>  _`stride`_ indicates offset gap size between first attribute and second attribute.  If this value is 0, it will be _`sizeof(type) * size`_.    
> _`pointer`_ parameter seems like pointer, but it's byte offset for where attribute starts inside of **GL_ARRAY_BUFFER**. 

<!---------------------------------------------------------------------------------------------------------------->


- glEnableVertexAttribArray()
```C
void glEnableVertexAttribArray (GLuint index);
```

- glDisableVertexAttribArray()
```C
void glDisableVertexAttribArray (GLuint index);
```

> if vertex attrib array is disabled, vertex attributes will be modified with glVertexAttrib*() funcionts.    
> if vertex attrib array is abled, vertex attributes will be binded with glVertexAttribPointer() funtion.


<!---------------------------------------------------------------------------------------------------------------->


- glGetAttribLocation()
```C
GLint glGetAttribLocation (GLuint program, const GLchar * name);
```
> if your put program that owning vertex shader in _`program`_ and    
> name of vertex attribute's name(identifier) in _`name`_,    
> it will return _`name`_'s location number.        
> if there no attribute with name, _`name`_, it will return -1.


<!---------------------------------------------------------------------------------------------------------------->
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
<!---------------------------------------------------------------------------------------------------------------->


## Uniform
- While attributes contribute in per-vertex sahder values (like position of vertice),    
 uniform contirbute in same values to several vertex shaders (like transform matrix).

- Uniform can exist in all kind of shaders.

-Uniform in shaders are always constant and cannot be assigned by shader.

- uniform may disappear after compile if none of shader use that uniform.

- variable names are case-sensitive.



1. Default block
    - Default block uniforms are just like sending vertex attributes but use glUniform*() instead glVertexAttrib*().

2. Uniform block (buffer)
    - stored in buffer with interface form (UBO) just like vertex buffer.
    - UBO is manipulated with functions like **glBufferData()** or **glMapBuffer()**.
    - two way to store data in buffer
      - standard : store data with just same order as members of uniform block.     
         extensive and safe but not efficient for memory space usage.    
         since standard layout is not default, you need to put _`layout (std140)`_ before uniform block declaration.
      - shared : opengl make proper structure itself.  shared layout is default layout if there's none specification.    
         most efficient for performance but need resource to let OpenGL manage them and application can be more complicated.    
         shaders and programs **share** layout of buffer once buffer layout is decided into shared layout.
  - standard layout
    - _`std140`_ or any standard layouts have certain offset boundary and field packing rule.
      - array or vector of GLSL types have boundary offset of _`N*sizeof(vector)`_. (e.g. vector of 2 floats has 4*2 byte boundary offset.)
      - but array or vector with 3, 4 elements have boundary offset of _`N*4`_ bytes. (I think it's for keeping binaric integrity.)
      - every arrays aligned( =packed) just like _`vec4`_ in size.  i.e. every arrays without vec4 and N*4 matricies - element arrays won't be packed tightly.
      - so you need to keep in mind to bind application array with proper offsets.
      - structure and structure array's boundary offsets defined by its largest member. (ceiled into size of vec4.)
      - **all of these rules look complex, but this is the way how standard layout guarantee cross-platform layout.**
      - **you can check more about this from _`ARB_uniform_buffer_obect`_ extention's specification.**
  - shared layout
    - shared layout **may** be more efficient than standard layout. but many people think it's not worth to invest that much effort on it.
    - you need to search block members' size and location wih indices of them.
    - you can get indices' by using _`glGetUniformIndices()`_.
      ```C
      void glGetUniformIndices (GLuint program, GLsizei uniformCount, const GLchar **uniformNames, GLuint *uniformIndices);
      ```
      > _`program`_ : program that you will get uniform index from.
      > _`uniformCount`_ : number of uniform indices you want to get.
      > _`uniformNames`_ : array of GLchar array( =string) that contains uniforms' name you want to get index of.
      > _`uniformIndices`_ : this funtion will write indices of uniform you selected in this array.
    - after getting array contain indices, you can get location of uniform block elements by _`glGetActiveUniformsiv()`_.
      ```C
      void glGetActiveUniformsiv (GLuint program, GLsizei uniformCount, const  GLuint *uniformIndices, GLenum pname, GLint *params);
      ```
      > _`program`_ : program that you will get 
      > _`uniformCount`_ : number of strides or offsets you want to get
      > _`uniformIndices`_ : array of indices you want to use for getting stride or offset.
      > _`pname`_ : enum for data type that this function will get.
      > _`params`_ : result of this function will be stored at here.
      - _`pname`_ enum list 
        - **GL_UNIFORM_TYPE** 		: data type of uniform block members
        - **GL_UNIFORM_SIZE**		: array's size of member regardless of which GL_UNIFORM_TYPE gives. 1 will be stored if indexed member is not array.
        - **GL_UNIFORM_NAME_LENGTH**	: length of uniform block member's name (character array's length)
        - **GL_UNIFORM_BLOCK_INDEX**	: index of uniform block that member is located. (it's not index of uniform block member. it's useless since parameter include them!)
        - **GL_UNIFORM_OFFSET**		: offset of uniform block member
        - **GL_UNIFORM_ARRAY_STRIDE**	: byte stride of uniform block member array. if indexed member is not array, 0 will be stored.
        - **GL_UNIFORM_MATRIX_STRIDE**	: byte stride between uniform block member matrix' column or row. if indexed member is not matrix, 0 will be stored.
        - **GL_UNIFORM_IS_ROW_MAJOR**	: 1 will be stored if indexed matrix is row-major. 0 will be stored if index matrix is column-major or even not matrix at all.
    - with offset and stride informations, application need to set data in proper location of buffer to send data for shared layout shader.


- - - - - - - - - - - - - - - - - - - - 
<!---------------------------------------------------------------------------------------------------------------->


- glGetUniformLocation()
```C
GLint glGetUniformLocation (GLuint program, const GLchar * name);
```
> if you put program that owning vertex shader in _`program`_ and    
> name of uniform's name(identifier) in _`name`_,    
> it will return _`name`_'s location number.        
> if there no attribute with name, _`name`_, it will return -1.


<!---------------------------------------------------------------------------------------------------------------->


- glUniform*()
```C
//functions below are sample glUniform*().
void glUniform1f (GLint location, GLfloat v0); //glUniform1~4f
void glUniform2i (GLint location, GLint v0, GLint v1); //glUniform1~4i
void glUniform4ui (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);  //glUniform1~4ui

//functions below are glUniform*v() that use pointer (i.e. array, vector) to store multiple uniform data.
void glUniform1fv (GLint location, GLuint count, const GLfloat* value);  //glUniform1~4fv
void glUniform2iv (GLint location, GLuint count, const GLint* value);  //glUniform1~4iv
void glUniform4uiv (GLint location, GLuint count, const GLuint* value);  //glUniform1~4uiv
```
> put _`value`_ or _`v*`_ into uniform with layout(location = _`location`_).    
> boolean can be sent by any type of funtion like how C works.    
> _`count`_ is length of _`value`_, array that contain arrays(i.e. vectors).    
> value is pointer (not pointer-pointer). and that means you dont need to put parameter _`value`_ into form of array[][], instead just put array's name (pointer).


<!---------------------------------------------------------------------------------------------------------------->


- glUniformMatrix*()
```C
//matrix that store single-precision floating values
glUniformMatrix2fv (GLint location, GLuint count, GLboolean transpose, const GLfloat *m);
glUniformMatrix3fv (GLint location, GLuint count, GLboolean transpose, const GLfloat *m);
glUniformMatrix4fv (GLint location, GLuint count, GLboolean transpose, const GLfloat *m);

//matrix that store double-precition floating values
glUniformMatrix2dv (GLint location, GLuint count, GLboolean transpose, const GLdouble *m);
glUniformMatrix3dv (GLint location, GLuint count, GLboolean transpose, const GLdouble *m);
glUniformMatrix4dv (GLint location, GLuint count, GLboolean transpose, const GLdouble *m);
```
> shader matrices only stores single and double precision floating-point variety.    
> this function can store array of matrices by setting _`count`_ into larger than 1.    
> OpenGL's matrix is column-major. if sending matrix is not column-major, set _`transpose`_ into **GL_TRUE**.    
> so, use _`transpose`_ parameter in handy if you use another graphic library that uses row-major matrix.


## Texture
