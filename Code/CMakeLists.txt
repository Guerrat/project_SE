cmake_minimum_required(VERSION 3.9)

SET(CMAKE_SYSTEM_NAME Generic)

#============================================================================================
PROJECT(projet_se)

SET(DEVICE_COMPILER "ATmega128")
SET(DEVICE_UPLOADER "ATmega128")

SET(FREQ "13000000")

#============================================================================================

SET(CMAKE_C_COMPILER avr-gcc)
SET(CMAKE_CXX_COMPILER avr-g++)

SET(CMAKE_C_FLAGS  "-Os -mmcu=${DEVICE_COMPILER} -DF_CPU=${FREQ}UL -std=gnu99 -Wl,--gc-sections")
SET(CMAKE_CXX_FLAGS "-Os -mmcu=${DEVICE_COMPILER} -DF_CPU=${FREQ}UL -Wl,--gc-sections")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

#============================================================================================

file(GLOB Projet_src "*.c" "*.h" "*.cpp" "*.hpp")

#============================================================================================

ADD_EXECUTABLE(${PROJECT_NAME} ${Projet_src})

ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME} POST_BUILD COMMAND avr-objcopy -O ihex -R.eeprom ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.hex)

ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME} POST_BUILD COMMAND avr-objcopy -O ihex -j .eeprom --set-section-flags=.eeprom="alloc,load"  --change-section-lma .eeprom=0 ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.eep)

ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME} POST_BUILD COMMAND avr-size ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME} --mcu=${DEVICE_COMPILER} --format=avr)

#============================================================================================

add_custom_target(avr_UPLOAD)
ADD_CUSTOM_COMMAND(TARGET avr_UPLOAD POST_BUILD
        #COMMAND avrdude -c usbasp -p ${DEVICE_UPLOADER} -U flash:w:${PROJECT_NAME}.hex noreset -F -B 9600
        COMMAND avrdude -c jtagmkI -P COM3 -p m128 -U flash:w:${PROJECT_NAME}.hex noreset -F -B 38400
        WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
