project(example VERSION 0.1.0)

add_executable(example main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/CEAddress/include)

target_link_directories(${PROJECT_NAME} PUBLIC 
  ${CMAKE_BINARY_DIR}/CEAddress/(Debug|Release) 
)

target_link_libraries(${PROJECT_NAME} PUBLIC CEAddress)

# POST_BUILD: 在执行完目标中的所有其他规则后运行
# https://stackoverflow.com/questions/10671916/how-to-copy-dll-files-into-the-same-folder-as-the-executable-using-cmake
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_BINARY_DIR}/CEAddress/$<CONFIG>/CEAddress.dll
    $<TARGET_FILE_DIR:${PROJECT_NAME}>
)