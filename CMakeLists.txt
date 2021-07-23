cmake_minimum_required(VERSION "3.21")

if("${CMAKE_TOOLCHAIN_FILE}" STREQUAL "")
    message(FATAL_ERROR "ERROR: You need to specify a Toolchain file on the toolchains folder !")
endif()

project("furrany-engine")

add_executable("furrany-engine" "src/main.cpp")

target_include_directories("furrany-engine" PRIVATE "includes")

if("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
    set(libraries "SDL2")

    if("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "x86")
        target_link_directories("furrany-engine" PRIVATE "libs/windows/x86")
        foreach(lib IN LISTS libraries)
            file(COPY "libs/windows/x86/${lib}.dll" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Debug/")
            file(COPY "libs/windows/x86/${lib}.dll" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Release/")
        endforeach()
    elseif("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "x64")
        target_link_directories("furrany-engine" PRIVATE "libs/windows/x64")
        foreach(lib IN LISTS libraries)
            file(COPY "libs/windows/x64/${lib}.dll" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Debug/")
            file(COPY "libs/windows/x64/${lib}.dll" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Release/")
        endforeach()
    endif()

    target_link_libraries("furrany-engine" "${libraries}" "SDL2main")
elseif("${CMAKE_SYSTEM_NAME}" STREQUAL "Darwin")
    set(libraries "SDL2")

    if("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "arm64")
        target_link_directories("furrany-engine" PRIVATE "libs/macOS/arm64")
        foreach(lib IN LISTS libraries)
            file(COPY "libs/macOS/arm64/lib${lib}.dylib" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Debug/")
            file(COPY "libs/macOS/arm64/lib${lib}.dylib" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Release/")
        endforeach()
    elseif("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "x64")
        target_link_directories("furrany-engine" PRIVATE "libs/macOS/x64")
        foreach(lib IN LISTS libraries)
            file(COPY "libs/macOS/x64/lib${lib}.dylib" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Debug/")
            file(COPY "libs/macOS/x64/lib${lib}.dylib" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Release/")
        endforeach()
    endif()

    target_link_libraries("furrany-engine" "${libraries}" "-framework Foundation" "-framework Cocoa")
endif()

