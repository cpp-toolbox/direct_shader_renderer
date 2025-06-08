#ifndef RENDERER_HPP
#define RENDERER_HPP
// A renderer is simply a thing that lets you draw stuff for particular shaders easily without having to do the opengl
// rigamaroll
#include <vector>
#include <glm/glm.hpp>
#include "sbpt_generated_includes.hpp"

// this class is like a batcher, but it has no concept of a drawable object
// instead you just give it the direct geometry and it cannot cache things
// drawn frequently like that
class CW_V_TransformationWithColoredVertexDirectShaderRenderer {
  private:
    ShaderCache &shader_cache;

    GLuint vertex_attribute_object;
    GLuint positions_buffer_object;
    GLuint rgb_colors_buffer_object;
    GLuint indices_buffer_object;

    std::vector<glm::vec3> batched_positions;
    std::vector<glm::vec3> batched_rgb_colors;
    std::vector<unsigned int> batched_indices;

  public:
    explicit CW_V_TransformationWithColoredVertexDirectShaderRenderer(ShaderCache &shader_cache);
    ~CW_V_TransformationWithColoredVertexDirectShaderRenderer();

    void draw_immediate(const std::vector<unsigned int> &indices, const std::vector<glm::vec3> &positions,
                        const std::vector<glm::vec3> &rgb_colors);

    void queue_draw(const std::vector<unsigned int> &indices, const std::vector<glm::vec3> &positions,
                    const std::vector<glm::vec3> &rgb_colors);

    void draw_everything();

    size_t get_queued_vertex_count() const { return batched_positions.size(); }
    size_t get_queued_index_count() const { return batched_indices.size(); }

    CW_V_TransformationWithColoredVertexDirectShaderRenderer(
        const CW_V_TransformationWithColoredVertexDirectShaderRenderer &) = delete;
    CW_V_TransformationWithColoredVertexDirectShaderRenderer &
    operator=(const CW_V_TransformationWithColoredVertexDirectShaderRenderer &) = delete;
};

#endif // RENDERER_HPP
