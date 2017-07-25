
link_libraries(glfw)

include_directories("${PROJECT_SOURCE_DIR}/deps")
include_directories("${PROJECT_SOURCE_DIR}/include")
set(HEADERS "${PROJECT_SOURCE_DIR}/deps/KHR/khrplatform.h")
set(SOURCES "main.cpp" "lightVBO.cpp" "${PROJECT_SOURCE_DIR}/engine/window.cpp" shader.cpp Shape.cpp vbo.cpp ebo.cpp "${HEADERS}" stb_image.cpp Texture.cpp)
add_library("glad" "${PROJECT_SOURCE_DIR}/deps/glad.c" "${PROJECT_SOURCE_DIR}/deps/glad/glad.h")
add_executable (GameEngine "${SOURCES}")
target_link_libraries(GameEngine glad "${HEADERS}")