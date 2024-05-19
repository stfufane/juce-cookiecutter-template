cmake_minimum_required(VERSION 3.27)

project({{ cookiecutter.__project_pascal }}
    VERSION 0.0.1
    DESCRIPTION "{{ cookiecutter.description }}"
    LANGUAGES CXX C
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs)
include(get_cpm.cmake)

CPMAddPackage(
    NAME JUCE
    GIT_TAG juce8
    GITHUB_REPOSITORY juce-framework/JUCE
    SOURCE_DIR ${LIB_DIR}/juce
)

option(JUCE_BUILD_EXTRAS "Build JUCE Extras" ON)
option(JUCE_BUILD_EXAMPLES "Build JUCE Examples" OFF)

# Adds all the module sources so they appear correctly in the IDE
set(JUCE_ENABLE_MODULE_SOURCE_GROUPS "Enable Module Source Groups" ON)
set_property(GLOBAL PROPERTY USE_FOLDERS YES)

if (MSVC)
    string(REGEX REPLACE "/W3" "" CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
    string(REGEX REPLACE "-W3" "" CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif ()

# Generate the ProjectInfo struct.
set(PROJECT_COMPANY "{{ cookiecutter.author }}")
set(PROJECT_VERSION_STRING "${PROJECT_VERSION}")
set(PROJECT_VERSION_NUMBER 0x000100)
configure_file(ProjectInfo.h.in ${CMAKE_CURRENT_SOURCE_DIR}/data/ProjectInfo.h)

juce_add_plugin("${PROJECT_NAME}"
    COMPANY_NAME "${PROJECT_COMPANY}"
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT FALSE
    NEEDS_MIDI_OUTPUT FALSE
    IS_MIDI_EFFECT FALSE
    EDITOR_WANTS_KEYBOARD_FOCUS FALSE
    COPY_PLUGIN_AFTER_BUILD FALSE
    PLUGIN_MANUFACTURER_CODE Stfe
    PLUGIN_CODE PnkN
    FORMATS Standalone VST3
    PRODUCT_NAME "{{ cookiecutter.project_name }}")

target_compile_features(${PROJECT_NAME}
PUBLIC
    cxx_std_17)

target_sources(${PROJECT_NAME} PRIVATE
    src/processor/BaseProcessor.cpp
    src/processor/PluginProcessor.cpp
    src/gui/PluginEditor.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/data)

target_compile_definitions(${PROJECT_NAME}
    PUBLIC
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
    DONT_SET_USING_JUCE_NAMESPACE=1
    JUCE_VST3_CAN_REPLACE_VST2=0
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        juce_dsp
        juce_audio_utils
        juce_gui_extra
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
)

if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /Wall /WX)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()