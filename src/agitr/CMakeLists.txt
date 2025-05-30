cmake_minimum_required(VERSION 3.8)
project(agitr)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)

# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

add_executable(hello_world src/hello_world.cpp)
ament_target_dependencies(hello_world rclcpp)

add_executable(publish_read_analog src/publish_read_analog.cpp)
ament_target_dependencies(publish_read_analog rclcpp geometry_msgs)

add_executable(subsrcibe_positon src/subsrcibe_positon.cpp)
ament_target_dependencies(subsrcibe_positon rclcpp geometry_msgs)

install(TARGETS
hello_world
subsrcibe_positon
publish_read_analog
DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
