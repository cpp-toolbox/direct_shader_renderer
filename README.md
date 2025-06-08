# direct_shader_renderer

This project lets you draw raw geometry directly for a given shader, it doesn't require you to setup the opengl buffers yourself. It sits below the level of a batcher because it know about the concept of objects having id's and reusing the geometry from previous draw calls. Good for when you just need to directly draw some arbitrary geometry without the idea of a re-usable object.
