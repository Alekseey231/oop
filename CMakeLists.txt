cmake_minimum_required(VERSION 2.8)	 # Проверка версии CMake.
										# Если версия установленой программы
										# старее указаной, произайдёт аварийный выход.
set(CMAKE_CXX_COMPILER "/usr/bin/gcc-12")
set(CMAKE_CXX_COMPILER "/usr/bin/g++-12")
project(lab_02)			# Название проекта
set (CMAKE_CXX_STANDARD 20)
SET(MYCOMPILE_FLAGS "-Wall -Werror -pedantic -fconcepts-diagnostics-depth=1")
SET(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} ${MYCOMPILE_FLAGS}")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${MYCOMPILE_FLAGS}")
set(SOURCE_EXE main.cpp ./matrix/matrix/matrix_base.cpp ./matrix/matrix/matrix_base.hpp ./matrix/matrix/matrix.h ./matrix/matrix/matrix.hpp
./matrix/iterator/const_matrix_iterator.h ./matrix/iterator/const_matrix_iterator.hpp ./matrix/iterator/matrix_iterator.h ./matrix/iterator/matrix_iterator.hpp
./matrix/errors/errors.cpp ./matrix/errors/errors.hpp)		# Установка переменной со списком исходников для исполняемого файла

add_executable(app.exe ${SOURCE_EXE})	# Создает исполняемый файл с именем main

