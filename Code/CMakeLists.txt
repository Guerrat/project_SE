cmake_minimum_required(VERSION 3.9)
SET(CMAKE_SYSTEM_NAME Generic)

#============================================================================================
# Nom du projet
PROJECT(projet_SE)

#============================================================================================
# Paramètres
SET(DEVICE_COMPILER "ATmega128")    # à changer suivant le proco
SET(DEVICE_UPLOADER "m128")         # à changer suivant le proco
SET(UPLOAD_PORT "COM3")            # à changer suivant le PC
SET(FREQ "13000000")                # à changer suivant le circuit

#============================================================================================
# Setup du compilateur et du build
SET(CMAKE_C_COMPILER avr-gcc)
SET(CMAKE_CXX_COMPILER avr-g++)

SET(CMAKE_C_FLAGS "-Os -mmcu=${DEVICE_COMPILER} -DF_CPU=${FREQ}UL -std=gnu99 -Wl,-u,vfprintf -lprintf_flt -lm -Wl,--gc-sections")
SET(CMAKE_CXX_FLAGS "-Os -mmcu=${DEVICE_COMPILER} -DF_CPU=${FREQ}UL -Wl,--gc-sections")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

#============================================================================================
# Check des fichiers sources (on prend tout dans le dossier src)
file(GLOB Projet_src "*.c" "*.h" "*.cpp" "*.hpp")

#============================================================================================
# Commande de build
ADD_EXECUTABLE(${PROJECT_NAME} ${Projet_src})
ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME} POST_BUILD COMMAND avr-objcopy -O ihex -R.eeprom ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.hex)
ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME} POST_BUILD COMMAND avr-objcopy -O ihex -j .eeprom --set-section-flags=.eeprom="alloc,load" ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.eep)
ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME} POST_BUILD COMMAND avr-size ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME} --mcu=${DEVICE_COMPILER} --format=avr)

#============================================================================================
# Commande d'upload
add_custom_target(UPLOAD)
ADD_CUSTOM_COMMAND(TARGET UPLOAD POST_BUILD
        #COMMAND avrdude -c usbasp -p ${DEVICE_UPLOADER} -U flash:w:${PROJECT_NAME}.hex noreset -F -B 9600
        COMMAND avrdude -c jtagmkI -p ${DEVICE_UPLOADER} -P ${UPLOAD_PORT} -U flash:w:${PROJECT_NAME}.hex:a
        WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

#============================================================================================
# Commande de build et upload en même temps
#add_custom_target(BUILD_UPLOAD ${Projet_src})
#ADD_CUSTOM_COMMAND(TARGET BUILD_UPLOAD POST_BUILD COMMAND avr-objcopy -O ihex -j .eeprom --set-section-flags=.eeprom="alloc,load" ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.eep)
#ADD_CUSTOM_COMMAND(TARGET BUILD_UPLOAD POST_BUILD
#        COMMAND avrdude -c jtagmkI -p ${DEVICE_UPLOADER} -P ${UPLOAD_PORT} -U flash:w:${PROJECT_NAME}.hex:a
#        WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
