main: main.o Clases/Arribo.o Clases/Barco.o Clases/BarcoPasajeros.o Clases/BarcoPesquero.o Clases/Puerto.o Datatypes/DtArribo.o Datatypes/DtBarco.o Datatypes/DtBarcoPasajeros.o Datatypes/DtBarcoPesquero.o Datatypes/DtPuerto.o Datatypes/DtFecha.o Otros/ingresarFecha.o Clases/Col.o
	g++ main.o Clases/Arribo.o Clases/Barco.o Clases/BarcoPasajeros.o Clases/BarcoPesquero.o Clases/Puerto.o Datatypes/DtArribo.o Datatypes/DtBarco.o Datatypes/DtBarcoPasajeros.o Datatypes/DtBarcoPesquero.o Datatypes/DtPuerto.o Datatypes/DtFecha.o Otros/ingresarFecha.o Clases/Col.o

main.o: main.cpp
	g++ -c main.cpp

Arribo.o: Clases/Arribo.cpp
	g++ -c Clases/Arribo.cpp
 
Barco.o: Clases/Barco.cpp
	g++ -c Clases/Barco.cpp

BarcoPasajeros.o: Clases/BarcoPasajeros.cpp
	g++ -c Clases/BarcoPasajeros.cpp

BarcoPesquero.o: Clases/BarcoPesquero.cpp
	g++ -c Clases/BarcoPesquero.cpp

Puerto.o: Clases/Puerto.cpp
	g++ -c Clases/Puerto.cpp

DtArribo.o: Datatypes/DtArribo.cpp
	g++ -c Datatypes/DtArribo.cpp

DtBarco.o: Datatypes/DtBarco.cpp
	g++ -c Datatypes/DtBarco.cpp

DtBarcoPasajeros.o: Datatypes/DtBarcoPasajeros.cpp
	g++ -c Datatypes/DtBarcoPasajeros.cpp

DtBarcoPesquero.o: Datatypes/DtBarcoPesquero.cpp
	g++ -c Datatypes/DtBarcoPesquero.cpp

DtPuerto.o: Datatypes/DtPuerto.cpp
	g++ -c Datatypes/DtPuerto.cpp

DtFecha.o: Datatypes/DtFecha.cpp
	g++ -c Datatypes/DtFecha.cpp

ingresarFecha.o: Otros/ingresarFecha.cpp
	g++ -c Otros/ingresarFecha.cpp

Col.o: Clases/Col.cpp
	g++ -c Clases/Col.cpp

clean: 
	rm */*.o main.o a.out