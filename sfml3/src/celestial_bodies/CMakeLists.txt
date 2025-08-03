set(TARGET celestial_bodies)


add_executable(${TARGET} ${CMAKE_SOURCE_DIR}/src/${TARGET}/main.cpp)
target_compile_features(${TARGET} PRIVATE cxx_std_17)
target_link_libraries(${TARGET} PRIVATE 
    SFML::Graphics 
    SFML::Window
    SFML::Main
    spdlog::spdlog
    
)
target_include_directories(${TARGET} SYSTEM PRIVATE 
    ${PROJECT_SOURCE_DIR}/src/${TARGET}/inc
    ${PROJECT_SOURCE_DIR}/src/logging
    /usr/x86_64-w64-mingw32/include/GL/
)

