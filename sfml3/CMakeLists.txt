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

add_subdirectory( ${FETCHCONTENT_BASE_DIR}/sfml-src/examples/window )
target_include_directories( window PRIVATE ${FETCHCONTENT_BASE_DIR}/sfml-src/examples/include )

add_subdirectory( ${FETCHCONTENT_BASE_DIR}/sfml-src/examples/opengl )
target_include_directories( opengl PRIVATE ${FETCHCONTENT_BASE_DIR}/sfml-src/examples/include )
file(COPY ${FETCHCONTENT_BASE_DIR}/sfml-src/examples/opengl/resources DESTINATION ${CMAKE_BINARY_DIR}/bin )

add_subdirectory( ${FETCHCONTENT_BASE_DIR}/sfml-src/examples/event_handling )
file(COPY ${FETCHCONTENT_BASE_DIR}/sfml-src/examples/event_handling/resources DESTINATION ${CMAKE_BINARY_DIR}/bin )

add_subdirectory( ${FETCHCONTENT_BASE_DIR}/sfml-src/examples/keyboard )
file(COPY ${FETCHCONTENT_BASE_DIR}/sfml-src/examples/keyboard/resources DESTINATION ${CMAKE_BINARY_DIR}/bin )

    
add_subdirectory( ${CMAKE_SOURCE_DIR}/src/sprite_test )

add_subdirectory( ${CMAKE_SOURCE_DIR}/src/vertexarray_test )

# runtime deps for mingw
file(   COPY        /usr/lib/gcc/x86_64-w64-mingw32/14-win32/libstdc++-6.dll build/bin/libstdc++-6.dll
                    /usr/lib/gcc/x86_64-w64-mingw32/14-win32/libgcc_s_seh-1.dll build/bin/libgcc_s_seh-1.dll
        DESTINATION ${CMAKE_BINARY_DIR}/bin/ )

