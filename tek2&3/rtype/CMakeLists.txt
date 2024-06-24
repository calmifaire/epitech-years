cmake_minimum_required(VERSION 3.19)
project(RTYPE LANGUAGES CXX)

set(DEBUG_MODE TRUE)
set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
  CACHE STRING "Vcpkg toolchain file")

set(CLIENT r-type_client)
set(SERVER r-type_server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR TRUE)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

# add_definitions("-fPIC -Wall -Wextra -Wno-empty-body -Wno-switch")
if(CMAKE_BUILD_TYPE MATCHES DEV)
    add_definitions("")
endif()

if(CMAKE_BUILD_TYPE MATCHES RELEASE)
    add_definitions("-O3 -lto")
endif()

if(DEBUG_MODE MATCHES TRUE)
    add_definitions("-DDEBUG")
endif()

#include_directories(${SFML_INCLUDE_DIRS})
#include_directories("/opt/homebrew/Cellar/sfml/2.5.1_1/include")

if (WIN32)
    find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
else()
    include(FetchContent)
    FetchContent_Declare(sfml                             # name of the content
        GIT_REPOSITORY https://github.com/SFML/SFML.git  # the repository
        GIT_TAG        2.5.1                             # the tag
    )
    FetchContent_MakeAvailable(sfml)
endif()
# CONAN_CALLS
# include(build/conanbuildinfo.cmake)
# include(build/conan_paths.cmake)
# conan_basic_setup(KEEP_RPATHS)

set(SRC_SERVER
    Network/NetworkServer.cpp
    Network/NetworkRoom.cpp
    Graphics/Events.cpp
    Graphics/InitSfml.cpp
    Ecs/Entity/Entity.cpp
    Ecs/Entity/EntityManager.cpp
    Ecs/Component/ComponentManager.cpp
    Ecs/Component/sources/Acceleration.cpp
    Ecs/Component/sources/Controlable.cpp
    Ecs/Component/sources/Bullet.cpp
    Ecs/Component/sources/Bonus.cpp
    Ecs/Component/sources/Damage.cpp
    Ecs/Component/sources/Health.cpp
    Ecs/Component/sources/Hitbox.cpp
    Ecs/Component/sources/Id.cpp
    Ecs/Component/sources/Pattern.cpp
    Ecs/Component/sources/Position.cpp
    Ecs/Component/sources/Rotate.cpp
    Ecs/Component/sources/Speed.cpp
    Ecs/Component/sources/Sprite.cpp
    Ecs/Component/sources/Text.cpp
    Ecs/System/CollisionSystem.cpp
    Ecs/System/EnemyShootSystem.cpp
    Ecs/System/BonusSystem.cpp
    Ecs/System/EventsSystem.cpp
    Ecs/System/MoveSystem.cpp
    Ecs/System/PatternSystem.cpp
    Ecs/System/GraphicSystem.cpp
    Ecs/System/TextSystem.cpp
    Ecs/System/SystemManager.cpp
    Ecs/System/System.cpp
    Ecs/Manager.cpp
    Ecs/Clock.cpp
    server/GameInstance/GameServer.cpp
    server/Server.cpp
    server/main.cpp
)

set(SRC_CLIENT
    Client/GameClient.cpp
    Client/main.cpp
    Network/NetworkClient.cpp
    Ecs/Clock.cpp Ecs/Manager.cpp
    Ecs/System/System.cpp
    Ecs/Entity/Entity.cpp
    Ecs/System/EventsSystem.cpp
    Ecs/System/GraphicSystem.cpp
    Ecs/System/CollisionSystem.cpp
    Ecs/System/SystemManager.cpp
    Ecs/Component/sources/Acceleration.cpp
    Ecs/Component/sources/Controlable.cpp
    Ecs/Component/sources/Health.cpp
    Ecs/Component/sources/Position.cpp
    Ecs/Component/sources/Speed.cpp
    Ecs/Component/sources/Text.cpp
    Ecs/Component/sources/Bullet.cpp
    Ecs/Component/sources/Damage.cpp
    Ecs/Component/sources/Hitbox.cpp
    Ecs/Component/sources/Pattern.cpp
    Ecs/Component/sources/Rotate.cpp
    Ecs/Component/sources/Sprite.cpp
    Graphics/InitSfml.cpp
    Graphics/Events.cpp
    Ecs/Component/ComponentManager.cpp
    Ecs/Entity/EntityManager.cpp
    Ecs/System/TextSystem.cpp
    Ecs/System/MoveSystem.cpp
    Ecs/Component/sources/Bonus.cpp
)

# file(GLOB_RECURSE SRC_CLIENT ${PROJECT_SOURCE_DIR}/client/*)
# file(GLOB_RECURSE SRC_SERVER ${PROJECT_SOURCE_DIR}/server/*)
# file(GLOB_RECURSE SRC_CLIENT ${PROJECT_SOURCE_DIR}/Client/*)
# file(GLOB_RECURSE SRC_ECS ${PROJECT_SOURCE_DIR}/Ecs/*)
# file(GLOB_RECURSE SRC_GRAPHICS ${PROJECT_SOURCE_DIR}/Graphics/*)
# file(GLOB_RECURSE SRC_ECS ${PROJECT_SOURCE_DIR}/shared/*)

add_executable(${CLIENT} ${SRC_CLIENT})
add_executable(${SERVER} ${SRC_SERVER})

# set(SHARED_INCLUDE_FOLDER shared)
# target_include_directories(${SERVER} PUBLIC SHARED_INCLUDE_FOLDER)
# add_executable(${CLIENT} ${SRC_CLIENT} ${SRC_ECS} ${SRC_GRAPHICS})
target_include_directories(${CLIENT} PUBLIC SHARED_INCLUDE_FOLDER)

target_link_libraries(${CLIENT} sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
target_link_libraries(${SERVER} sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
