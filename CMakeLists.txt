cmake_minimum_required(VERSION 3.2)
project(msgboard)

set(CMAKE_CXX_STANDARD 11)

find_library(NAMES uv hane)
find_path(HANE_INCLUDE_DIRS hane/hane.hpp)
include_directories(${HANE_INCLUDE_DIRS})

execute_process(COMMAND ${PROJECT_SOURCE_DIR}/ecpgen WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

file(GLOB TEMPLATE_FILES "templates/*/*.cpp")
set(SOURCE_FILES main.cpp templates/messages/list.html.hpp models/message.cpp models/message.hpp models/user.cpp models/user.hpp controllers/messages_controller.cpp controllers/messages_controller.hpp controllers/users_controller.cpp controllers/users_controller.hpp controllers/sessions_controller.cpp controllers/sessions_controller.hpp templates/sessions/new.html.hpp
        templates/users/new.html.hpp)
add_executable(msgboard ${SOURCE_FILES} ${TEMPLATE_FILES})
target_link_libraries(msgboard hane uv pthread)