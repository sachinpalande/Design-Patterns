# Create an executable for FurnitureFactory
add_executable(CarBuilderApp
    CarBuilder.cpp
)

# Include the current directory to locate headers
target_include_directories(CarBuilderApp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
