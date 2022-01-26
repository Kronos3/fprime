####
# coverage.cmake:
#
# Coverage target adds in gcov endpoint for calculating the coverage of F prime modules. This
# coverage requires the system supply a `gcov` target and the code be built with the `TESTING`
# build type.  This means the  following things to be setup:
# 
# 1. `gcov` must be available on the path
# 2. `-DBUILD_TESTING=ON` must be supplied
# 
# Once the CMake build directory has been created the user can run the CMake targets
# `<MODULE>_coverage` where <MODULE> is the name of the module to generate coverage for. These
# _coverage targets perform the following steps:
#
# 1. Build and run UT dependencies using the `<MODULE>_check` target
# 2. Run the `gcov` program on the Module's source files
# 3. Copy the .gcov reports into a "coverage" subdirectory of the module's source
#
# These targets can be run using the build system as shown in the example below:
# 
# **Example**
# ```
# make Svc_CmdDispatcher_Cmd
# ```
# **Note:** although a global `coverage` target is created, it typically should not be used as
# CTest provides better global coverage with the `Coverage` target.
#
# ## Detailed Function Descriptions
# 
# The following functions are used to register the _coverage targets into the target system. They
# are required for the system to register custom targets.
####
####
#  Function `add_global_target`:
#
#  Adds a global target. Note: only run for "BUILD_TESTING=ON" builds.
#
# - **TARGET_NAME:** target name to be generated
####
function(add_global_target TARGET_NAME)
    if (FPRIME_ENABLE_UT_COVERAGE)
        find_program(GCOV_EXE "gcov")
        if (GCOV_EXE)
            add_custom_target(${TARGET_NAME})
        elseif()
            add_custom_target(${TARGET_NAME} COMMAND ${CMAKE_COMMAND} -E echo "[WARNING] 'gcov' not found. Will not calculate coverage.")
        endif()
    endif()
endfunction(add_global_target)


####
# Dict function `add_module_target`:
#
# Creates each module's coverage targets. Note: only run for "BUILD_TESTING=ON" builds.
#
# - **MODULE_NAME:** name of the module
# - **TARGET_NAME:** name of target to produce
# - **SOURCE_FILES:** list of source file inputs
# - **DEPENDENCIES:** MOD_DEPS input from CMakeLists.txt
####
function(add_module_target MODULE_NAME TARGET_NAME SOURCE_FILES DEPENDENCIES)
    get_target_property(FINAL_SOURCES "${MODULE_NAME}" SOURCES)
    # Protects against multiple calls to fprime_register_ut()
    if (TARGET ${MODULE_NAME}_${TARGET_NAME} OR NOT FINAL_SOURCES OR NOT FPRIME_ENABLE_UT_COVERAGE)
        return()
    endif()

    # Test for the 'gcov' program or bail with WARNING
    find_program(GCOV_EXE "gcov")
    if (NOT GCOV_EXE)
        add_custom_target(${MODULE}_${TARGET_NAME} COMMAND ${CMAKE_COMMAND} -E echo "[WARNING] 'gcov' not found. Will not calculate coverage.")
    else()
        add_custom_target(
            ${MODULE_NAME}_${TARGET_NAME}
            COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_LIST_DIR}/coverage
            COMMAND ${GCOV_EXE} -o ${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/${MODULE_NAME}.dir/ ${FINAL_SOURCES}
            COMMAND ${CMAKE_COMMAND} -E copy *.gcov ${CMAKE_CURRENT_LIST_DIR}/coverage
        )
        add_dependencies(${MODULE_NAME}_${TARGET_NAME} ${MODULE_NAME}_check)
        add_dependencies(${TARGET_NAME} ${TARGET_NAME})
    endif()
endfunction(add_module_target)
