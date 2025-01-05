# Create an executable for FurnitureFactory
add_executable(PrototypeApp
    Prototype.cpp
)

# Include the current directory to locate headers
target_include_directories(PrototypeApp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
