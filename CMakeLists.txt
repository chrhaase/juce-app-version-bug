cmake_minimum_required(VERSION 3.29)
project(JUCE_APP_VERSION_BUG VERSION 2.0.0)

include(FetchContent)
FetchContent_Declare(juce
        GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
        GIT_TAG master)
FetchContent_MakeAvailable(juce)

juce_add_gui_app(JUCE_APP_VERSION_BUG
        PRODUCT_NAME "JUCE App Version Bug"
        VERSION ${PROJECT_VERSION}
        COMPANY_NAME "MyCompany"
        COMPANY_COPYRIGHT "Copyright 2024")

target_sources(JUCE_APP_VERSION_BUG PRIVATE main.cpp)

target_link_libraries(JUCE_APP_VERSION_BUG PRIVATE
        juce::juce_gui_extra
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags)

target_compile_definitions(JUCE_APP_VERSION_BUG PRIVATE
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_MODAL_LOOPS_PERMITTED=1
        APP_VERSION="${PROJECT_VERSION}")