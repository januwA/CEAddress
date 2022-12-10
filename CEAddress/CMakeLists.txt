file(GLOB libs_SRC src/*.cpp)
add_library(CEAddress STATIC ${libs_SRC})
set_target_properties(CEAddress PROPERTIES OUTPUT_NAME "CEAddress")
set_target_properties(CEAddress PROPERTIES CLEAN_DIRECT_OUTPUT 1)


add_library(CEAddress_shared SHARED ${libs_SRC})
set_target_properties(CEAddress_shared PROPERTIES OUTPUT_NAME "CEAddress")
set_target_properties(CEAddress_shared PROPERTIES CLEAN_DIRECT_OUTPUT 1)

include_directories(include)

install(TARGETS CEAddress CEAddress_shared 
  DESTINATION ${CMAKE_BINARY_DIR}/dist
)