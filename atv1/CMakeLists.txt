cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)  # Importa o SDK do Raspberry Pi Pico

# Defina o nome do projeto
project(trafficlightC CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Inicializa o SDK do Pico
pico_sdk_init()

# Adicione aqui os arquivos do seu projeto
add_executable(
    trafficlight
    trafficlight.c  # Substitua pelos arquivos do seu projeto
)

# Adicione bibliotecas do Pico se necessário
target_link_libraries(trafficlight pico_stdlib hardware_pwm hardware_timer stdio_h)

# Adicione os diretórios de include
target_include_directories(trafficlight PRIVATE {CMAKE_CURRENT_LIST_DIR})

# Habilita a saída USB ou UART para logs
pico_enable_stdio_usb(trafficlight 1)
pico_enable_stdio_uart(trafficlight 0)

# Cria o arquivo .uf2 para upload ao Raspberry Pi Pico
pico_add_extra_outputs(trafficlight)

