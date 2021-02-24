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
~~~ C
void glBindBuffer (GLenum target, GLuint buffer);
~~~
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
~~~ C
void glBufferData (GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage);
~~~
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
~~~ C
void glBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data);
~~~

> _`target`_ enum list is same with glBindBuffer.    
> _`offset`_ is position inside buffer to start inserting data    
> _`size`_ is byte size of inserting data    
> _`data`_ is pointer for data to insert in buffer


<!---------------------------------------------------------------------------------------------------------------->


- glClearBufferSubData()
~~~ C
void glClearBufferSubData (GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data);
~~~
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
~~~ C
vod glCopyBufferSubData (GLenum readtarget, GLenum writetarget, GLintptr readoffset, GLintptr writeoffset, GLsizeiptr size);
~~~
> this function use buffer binding points_`readtarget, writetarget`_. and this way of copying has unwanted sideeffects sometime.     
> so **GL_COPY_READ_BUFFER** and **GL_COPY_WRITE_BUFFER** are provided for dedicated binding point.


<!---------------------------------------------------------------------------------------------------------------->


- glGenBuffers()
~~~ C
void glGenBuffers (GLsizei n, GLuint * buffers);
~~~
> glGenBuffers generate _`n`_ of buffers and insert their buffer names into GLuint array _`buffers`_.
<!--
_`n`_ is number of buffer object names to be generated.    
_`buffers`_ is array of GLuint buffer names will be allocated
-->


<!---------------------------------------------------------------------------------------------------------------->


- glMapBuffer ()
~~~ C
void* glMapBuffer (GLenum target, GLenum access);
~~~
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
~~~ C
void glCreateBuffers (GLsizei n, GLuint * buffers);
~~~
-->


<!---------------------------------------------------------------------------------------------------------------->
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
<!---------------------------------------------------------------------------------------------------------------->


- glVertexAttribPointer()
~~~ C
void glVertexAttribPointer (GLuint index,
		 GLint size = 0,
		 GLenum type = GL_FLOAT,
		 GLboolean normalized.
		 GLsizei stride = 0,
		 const GLvoid * pointer = 0 );
~~~
>  _`index`_ is index of vertex attribute inside "layout (location = index)" to insert.    
>  _`size`_ is number (1, 2, 3, 4) of components like '3 for vec3' or '4 for vec4'.    
>  _`type`_ is data types like **GL_FLOAT**, **GL_INT**, **GL_BYTE**, etc.    
> since **float** is standard type for opengl vector, they will be converted into float, and it's reason for _`normalized`_ is important.    
>  if _`normalized`_ is **GL_TRUE**, that means datas' values need to be float with value between 0.0 to 1.0 for unsigned, -1.0 to 1.0 for signed.    
>  _`stride`_ indicates offset gap size between first attribute and second attribute.  If this value is 0, it will be _`sizeof(type) * size`_.    
> _`pointer`_ parameter seems like pointer, but it's byte offset for where attribute starts inside of **GL_ARRAY_BUFFER**. 

<!---------------------------------------------------------------------------------------------------------------->


- glEnableVertexAttribArray()
~~~ C
void glEnableVertexAttribArray (GLuint index);
~~~

- glDisableVertexAttribArray()
~~~ C
void glDisableVertexAttribArray (GLuint index);
~~~





## Texture