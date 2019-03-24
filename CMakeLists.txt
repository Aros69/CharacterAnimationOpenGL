cmake_minimum_required(VERSION 3.12)
project(gkit2light_master_CharAnim)

set(CMAKE_CXX_STANDARD 14)
set(PROJECT_SOURCE_DIR "src")

include_directories(${PROJECT_SOURCE_DIR}/gKit)
include_directories(${PROJECT_SOURCE_DIR}/master_CharAnim)

# Create two list of src files (all files in src/gKit ans src/master_CharAnim)
# Not reccomended practice by cmake developer
# You must rerun cmake when new files added
file(GLOB_RECURSE GKIT_SRC_FILES
        "${PROJECT_SOURCE_DIR}/gKit/*")
file(GLOB_RECURSE MASTER_CHARANIM_SRC_FILES
        "${PROJECT_SOURCE_DIR}/master_CharAnim/*")

# Include SDL2, GLEW and OpenGL
find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
# Special treatment for SDL2Image
INCLUDE(FindPkgConfig)
pkg_check_modules(SDL2_IMG REQUIRED SDL2_image)

include_directories(${SDL2_INCLUDE_DIRS}
        ${SDL2_IMG_INCLUDE_DIRS}
        ${GLEW_INCLUDE_DIRS}
        ${OPENGL_INCLUDE_DIRS})

# Create execute file
add_executable(gkit2light_master_CharAnim
        ${GKIT_SRC_FILES}
        ${MASTER_CHARANIM_SRC_FILES}
        src/master_CharAnim/Animations/AnimState.h
        src/master_CharAnim/Animations/Idle.cpp
        src/master_CharAnim/Animations/Idle.h
        src/master_CharAnim/Animations/Walk.h
        src/master_CharAnim/Animations/Walk.cpp
        src/master_CharAnim/Animations/Run.h
        src/master_CharAnim/Animations/Run.cpp
        src/master_CharAnim/Animations/Kick.h
        src/master_CharAnim/Animations/Crouch.cpp
        src/master_CharAnim/Animations/Crouch.h
        src/master_CharAnim/Animations/CrouchWalk.cpp
        src/master_CharAnim/Animations/CrouchWalk.h
        src/master_CharAnim/Animations/NonStopAnim.cpp
        src/master_CharAnim/Animations/NonStopAnim.h
        src/master_CharAnim/Animations/Dance.h
        src/master_CharAnim/Animations/SmokeIdle.cpp
        src/master_CharAnim/Animations/SmokeIdle.h
        src/master_CharAnim/Animations/Smoke.h
        src/master_CharAnim/Animations/Smoke.cpp)

# Link SDL2, OpenGL and GLEW
target_link_libraries(gkit2light_master_CharAnim
        ${SDL2_LIBRARIES}
        ${SDL2_IMG_LIBRARIES}
        ${GLEW_LIBRARIES}
        ${OPENGL_LIBRARIES})



