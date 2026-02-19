# CMakeList.txt : CMake project for Dchart_backend, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.10)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Dchart_backend")

find_package(fmt CONFIG REQUIRED) 
find_package(libwebsockets CONFIG REQUIRED)
find_package(Boost REQUIRED COMPONENTS log)
find_package(nlohmann_json CONFIG REQUIRED)


# Add source to this project's executable.
add_executable (Dchart_backend 
                        "Dchart_backend.cpp" 
                        "Dchart_backend.h" 
                        "PriceGenerator.h" 
                        "PriceGenerator.cpp" 
                        "WebSocketConnection.h" 
                        "WebSocketConnection.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Dchart_backend PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
target_link_libraries(Dchart_backend
    PRIVATE
        fmt::fmt
        websockets_shared
        Boost::log
        nlohmann_json::nlohmann_json
)
