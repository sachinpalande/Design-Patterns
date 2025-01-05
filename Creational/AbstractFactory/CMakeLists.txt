# Create an executable for FurnitureFactory
add_executable(FurnitureFactoryApp
    FurnitureFactory.cpp
)

# Include the current directory to locate headers
target_include_directories(FurnitureFactoryApp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Create an executable for ThemeFactory
add_executable(ThemeFactoryApp
    ThemeFactory.cpp
)

# Include the current directory to locate headers
target_include_directories(ThemeFactoryApp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
