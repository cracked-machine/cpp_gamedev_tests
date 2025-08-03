set(TARGET particle_test)
add_executable(${TARGET} ${CMAKE_SOURCE_DIR}/src/${TARGET}/main.cpp)
target_compile_features(${TARGET} PRIVATE cxx_std_17)
target_link_libraries(${TARGET} PRIVATE 
    SFML::Graphics 
    spdlog::spdlog
)
target_include_directories(${TARGET} SYSTEM PRIVATE 
    ${PROJECT_SOURCE_DIR}/src/logging
    ${CMAKE_SOURCE_DIR}/src/${TARGET}/inc
    ${PROJECT_SOURCE_DIR}/src/examples/include
)

