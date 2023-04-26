cmake_minimum_required(VERSION 3.0)
project(turing-text)

# Add all the source files
set(SOURCES
    AiClass.cpp
    Delegator.h
    GameBook.cpp
    GameBook.h
    HelpTool.h
    human.cpp
    main.cpp
    twilio.cpp
)

# Add the executable target
add_executable(turing-text ${SOURCES})
