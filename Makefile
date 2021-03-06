FLAGS = -g -c --std=c++17

all:
	mkdir -p bin
	g++ $(FLAGS) src/empleado.cpp -o bin/empleado.o	
	g++ $(FLAGS) src/empleadoNomina.cpp -o bin/empleadoNomina.o	
	g++ $(FLAGS) src/empleadoPorHora.cpp -o bin/empleadoPorHora.o	
	g++ $(FLAGS) src/horasTrabajadas.cpp -o bin/horasTrabajadas.o
	g++ $(FLAGS) src/nomina.cpp -o bin/nomina.o	
	g++ $(FLAGS) src/planilla.cpp -o bin/planilla.o
	g++ $(FLAGS) src/registroHora.cpp -o bin/registroHora.o
	g++ $(FLAGS) src/registroPago.cpp -o bin/registroPago.o
	g++ $(FLAGS) src/main.cpp -o bin/main.o	
	g++ -g -o bin/pagosalarios bin/empleado.o bin/empleadoNomina.o bin/empleadoPorHora.o bin/horasTrabajadas.o bin/nomina.o bin/planilla.o bin/registroHora.o bin/registroPago.o bin/main.o

test:
	mkdir -p bin
	g++ $(FLAGS) src/empleado.cpp -o bin/empleado.o	
	g++ $(FLAGS) src/empleadoNomina.cpp -o bin/empleadoNomina.o	
	g++ $(FLAGS) src/empleadoPorHora.cpp -o bin/empleadoPorHora.o	
	g++ $(FLAGS) src/horasTrabajadas.cpp -o bin/horasTrabajadas.o
	g++ $(FLAGS) src/nomina.cpp -o bin/nomina.o	
	g++ $(FLAGS) src/planilla.cpp -o bin/planilla.o
	g++ $(FLAGS) src/registroHora.cpp -o bin/registroHora.o
	g++ $(FLAGS) src/registroPago.cpp -o bin/registroPago.o
	g++ $(FLAGS) tests/empleado_tests.cpp -o bin/empleado_tests.o
	g++ $(FLAGS) tests/empleado_nomina_tests.cpp -o bin/empleado_nomina_tests.o
	g++ $(FLAGS) tests/empleado_por_hora_tests.cpp -o bin/empleado_por_hora_tests.o
	g++ $(FLAGS) tests/horas_trabajadas_tests.cpp -o bin/horas_trabajadas_tests.o
	g++ $(FLAGS) tests/nomina_tests.cpp -o bin/nomina_tests.o	
	g++ $(FLAGS) tests/planilla_tests.cpp -o bin/planilla_tests.o
	g++ $(FLAGS) tests/registro_hora_tests.cpp -o bin/registro_hora_tests.o
	g++ $(FLAGS) tests/registro_pago_tests.cpp -o bin/registro_pago_tests.o
	g++ -g -o bin/tests bin/empleado.o bin/empleadoNomina.o bin/empleadoPorHora.o bin/horasTrabajadas.o bin/nomina.o bin/planilla.o bin/registroHora.o bin/registroPago.o bin/empleado_tests.o bin/empleado_nomina_tests.o bin/empleado_por_hora_tests.o bin/horas_trabajadas_tests.o bin/nomina_tests.o bin/planilla_tests.o bin/registro_hora_tests.o bin/registro_pago_tests.o -lgtest -lgtest_main -lpthread
	
clean:
	rm -Rf bin