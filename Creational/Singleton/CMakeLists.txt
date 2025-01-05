# Create an executable for FurnitureFactory
add_executable(SingletonApp
    Singleton.cpp
)

# Include the current directory to locate headers
target_include_directories(SingletonApp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Singleton)

# Create an executable for FurnitureFactory
add_executable(SingletonWithMutexApp
    SingletonWithMutex.cpp
)

# Include the current directory to locate headers
target_include_directories(SingletonWithMutexApp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/SingletonWithMutex)

# Find the pthread library
find_package(Threads REQUIRED)

# Link your executable to the pthread library
target_link_libraries(SingletonWithMutexApp PRIVATE Threads::Threads)


