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
    
_`size`_ is size of data store.    
    
_`data`_ is pointer indicating where data storage copy initial data from.    
 can be setted as NULL and data store won't be initalized.    
    
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


<!---------------------------------------------------------------------------------------------------------------->


- glBufferSubData()
~~~ C
void glBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data);
~~~

_`target`_ enum list is same with glBindBuffer.
    
_`offset`_ is position inside buffer to start inserting data
    
_`size`_ is byte size of inserting data
    
_`data`_ is pointer for data to insert in buffer


<!---------------------------------------------------------------------------------------------------------------->


- glGenBuffers()
~~~ C
void glGenBuffers (GLsizei n, GLuint * buffers);
~~~
glGenBuffers generate _`n`_ of buffers and insert their buffer names into GLuint array _`buffers`_.
<!--
_`n`_ is number of buffer object names to be generated.    
_`buffers`_ is array of GLuint buffer names will be allocated
-->


<!---------------------------------------------------------------------------------------------------------------->


- glMapBuffer ()
~~~ C
void* glMapBuffer (GLenum target, GLenum access);
~~~

map data store of _`target`_ buffer object into client's address space and return its void* pointer address.
    
_`target`_ enum list is same with glBindBuffer.
    
  - _`access`_ enum list
    - **GL_READ_ONLY**	: returned pointer will be used for reading buffer object's data
    - **GL_WRITE_ONLY**	: returned pointer will be used for writing buffer object's data
    - **GL_READ_WRITE**	: returned pointer will be used for both reading and writing

using returned pointer address for GL function parameter is nonstandard. it may occur unexpected result.
    
can unmap with `glUnmapBuffer (_target_);`.


<!---------------------------------------------------------------------------------------------------------------->


<!--
~~~ C
void glCreateBuffers (GLsizei n, GLuint * buffers);
~~~
-->

## Texture