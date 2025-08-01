cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON EXCLUDE_FROM_ALL SYSTEM) 

FetchContent_Declare(SPDLog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG 6fa36017cfd5731d617e1a934f0e5ea9c4445b13    #v1.15.3
    GIT_SHALLOW ON EXCLUDE_FROM_ALL SYSTEM)

FetchContent_Declare(Quill
    GIT_REPOSITORY https://github.com/odygrd/quill.git
    GIT_TAG a29940ebe1122556fa6d99be1929264469d6ec99    #v10.0.1
    EXCLUDE_FROM_ALL SYSTEM
)

FetchContent_MakeAvailable(
    SFML 
    SPDLog
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# add_executable(main src/main.cpp)
# target_compile_features(main PRIVATE cxx_std_17)
# target_link_libraries(main PRIVATE SFML::Graphics)

set(TARGET window)
add_executable(${TARGET} ${CMAKE_SOURCE_DIR}/src/examples/window/Window.cpp)
target_compile_features(${TARGET} PRIVATE cxx_std_17)
target_link_libraries(${TARGET} PRIVATE SFML::Graphics SFML::Window)
target_include_directories(${TARGET} SYSTEM PRIVATE ${PROJECT_SOURCE_DIR}/src/examples/include)

set(TARGET opengl)
add_executable(${TARGET} ${CMAKE_SOURCE_DIR}/src/examples/opengl/OpenGL.cpp)
target_compile_features(${TARGET} PRIVATE cxx_std_17)
target_link_libraries(${TARGET} PRIVATE SFML::Graphics SFML::Audio)
target_include_directories(${TARGET} SYSTEM PRIVATE ${PROJECT_SOURCE_DIR}/src/examples/include)
file(COPY       ${CMAKE_SOURCE_DIR}/src/examples/opengl/resources/background.jpg
                ${CMAKE_SOURCE_DIR}/src/examples/opengl/resources/logo.png
                ${CMAKE_SOURCE_DIR}/src/examples/opengl/resources/tuffy.ttf
    DESTINATION ${CMAKE_BINARY_DIR}/bin/resources)

set(TARGET events)
add_executable(${TARGET} ${CMAKE_SOURCE_DIR}/src/examples/event_handling/EventHandling.cpp)
target_compile_features(${TARGET} PRIVATE cxx_std_17)
target_link_libraries(${TARGET} PRIVATE SFML::Graphics)
target_include_directories(${TARGET} SYSTEM PRIVATE ${PROJECT_SOURCE_DIR}/src/examples/include)
file(COPY       ${CMAKE_SOURCE_DIR}/src/examples/event_handling/resources/tuffy.ttf
    DESTINATION ${CMAKE_BINARY_DIR}/bin/resources)

set(TARGET keyboard)
add_executable(${TARGET} ${CMAKE_SOURCE_DIR}/src/examples/keyboard/Keyboard.cpp)
target_compile_features(${TARGET} PRIVATE cxx_std_17)
target_link_libraries(${TARGET} PRIVATE SFML::Graphics SFML::Audio)
target_include_directories(${TARGET} SYSTEM PRIVATE ${PROJECT_SOURCE_DIR}/src/examples/include)
file(COPY       ${CMAKE_SOURCE_DIR}/src/examples/keyboard/resources/error_005.ogg
                ${CMAKE_SOURCE_DIR}/src/examples/keyboard/resources/mouseclick1.ogg
                ${CMAKE_SOURCE_DIR}/src/examples/keyboard/resources/mouserelease1.ogg
                ${CMAKE_SOURCE_DIR}/src/examples/keyboard/resources/Tuffy.ttf
    DESTINATION ${CMAKE_BINARY_DIR}/bin/resources)
    
set(TARGET sprite_test)
add_executable(${TARGET} ${CMAKE_SOURCE_DIR}/src/${TARGET}.cpp)
target_compile_features(${TARGET} PRIVATE cxx_std_17)
target_link_libraries(${TARGET} PRIVATE 
    SFML::Graphics 
    SFML::Audio 
    spdlog::spdlog
)
target_include_directories(${TARGET} SYSTEM PRIVATE 
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/src/examples/include
)

# runtime deps for mingw
file(COPY       /usr/lib/gcc/x86_64-w64-mingw32/14-win32/libstdc++-6.dll build/bin/libstdc++-6.dll
                /usr/lib/gcc/x86_64-w64-mingw32/14-win32/libgcc_s_seh-1.dll build/bin/libgcc_s_seh-1.dll
    DESTINATION ${CMAKE_BINARY_DIR}/bin/)

