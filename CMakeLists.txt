cmake_minimum_required(VERSION 3.0.0)
project(RSUConnector VERSION 0.0.0)
include_directories("/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.12.sdk/usr/include" "/Users/jamesharris/Documents/boost_1_63_0" "/Users/jamesharris/Google Drive/Design/RaceJoy/RSUConnectorMAC/src/TriUtilities/include")

# TriUtilities DLL
add_library(TriUtilities SHARED src/TriUtilities/stdafx.cpp src/TriUtilities/dllmain.cpp src/TriUtilities/TriUtilities.cpp)
set_target_properties(TriUtilities PROPERTIES DEFINE_SYMBOL "TRIUTILITIES_EXPORTS")

# RSUConnector EXE
add_executable(RSUConnector src/main.cpp)
set_target_properties(RSUConnector PROPERTIES COMPILE_DEFINITIONS "BOOST_LOG_DYN_LINK")
target_link_libraries (RSUConnector "/Users/jamesharris/Documents/boost_1_63_0/stage/lib/libboost_log.dylib" "/Users/jamesharris/Documents/boost_1_63_0/stage/lib/libboost_system.dylib" "/Users/jamesharris/Documents/boost_1_63_0/stage/lib/libboost_filesystem.dylib" "/Users/jamesharris/Documents/boost_1_63_0/stage/lib/libboost_log_setup.dylib" "/Users/jamesharris/Documents/boost_1_63_0/stage/lib/libboost_thread.dylib")
add_dependencies(RSUConnector TriUtilities)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
