# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.21.0-rc3)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(thirdparty-glm-populate NONE)



include(ExternalProject)
ExternalProject_Add(thirdparty-glm-populate
                     "UPDATE_DISCONNECTED" "True" "URL" "C:/Users/matth/Documents/school/Classes/current/c371/labs/Lab03/code/thirdparty/glm-0.9.9.8.zip"
                    SOURCE_DIR          "C:/Users/matth/Documents/school/Classes/current/c371/labs/Lab03/code/build/_deps/thirdparty-glm-src"
                    BINARY_DIR          "C:/Users/matth/Documents/school/Classes/current/c371/labs/Lab03/code/build/_deps/thirdparty-glm-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
)


