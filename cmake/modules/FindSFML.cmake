set(MODULE_NAME SFML)

set(${MODULE_NAME}_LIBRARIES sfml-graphics sfml-window sfml-system)
find_path(${MODULE_NAME}_INCLUDE_DIRS NAMES Window.hpp PATH_SUFFIXES ${MODULE_NAME})
find_library(${MODULE_NAME}_LIBRARY_DIRS NAMES ${${MODULE_NAME}_LIBRARIES})

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(${MODULE_NAME}
                                  FOUND_VAR ${MODULE_NAME}_FOUND
                                  REQUIRED_VARS ${MODULE_NAME}_INCLUDE_DIRS ${MODULE_NAME}_LIBRARY_DIRS
                                  )

mark_as_advanced(${MODULE_NAME}_INCLUDE_DIRS)
mark_as_advanced(${MODULE_NAME}_LIBRARIES)
mark_as_advanced(${MODULE_NAME}_LIBRARY_DIRS)
