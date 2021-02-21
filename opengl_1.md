Data type
================================================================
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

## Buffer
- need name to identify
- memory allocated for buffer object is called **data storage**.
- two method to put data in buffer are ; using command ; _mapping_ with pointer (mapping available since 4.5)
- can _bind_ into context's _buffer binding point_ with buffer's name.
- _binding point_ can be refered as _target_ in most cases. (but target may have multiple binging point)
    
    
- glBufferData()
~~~ C
void glBufferData (GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage);
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
  - **GL_STREAM_DRAW**  modified once by application, accessed rarely, used for drawing and imaging.
  - **GL_STREAM_READ**  modified once by GL reading, accessed rarely, used for returning data for queries of application.
  - **GL_STREAM_COPY**  modified once by GL reading, accessed rarely, used for drawing and imaging.
  - **GL_STATIC_DRAW**  modified once by GL application, accessed often, used for drawing and imaging.
  - **GL_STATIC_READ**    modified once by GL reading, accessed often, used for returning data for queries of application.
  - **GL_STATIC_COPY**  modified once by GL reading, accessed often, used for drawing and imaging.
  - **GL_DYNAMIC_DRAW**  modified multiple time by GL application, accessed often, used for drawing and imaging.
  - **GL_DYNAMIC_READ**    modified multiple time by GL reading, accessed often, used for returning data for queries of application.
  - **GL_DYNAMIC_COPY**  modified multiple time by GL reading, accessed often, used for drawing and imaging.




<!--
~~~ C
void glCreateBuffers (GLsizei n, GLuint* buffers);
~~~
-->

## Texture