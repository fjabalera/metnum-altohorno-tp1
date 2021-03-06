#!/bin/bash

#Modo de uso= ./tests.sh nombre_test iso_o_temps 
#arg1 = Cantidad de instancias de tests.

nombre_test=''

argc=$#

# Nombre del test y resultado deseado
if [ $argc -eq 2 ]
then
	nombre_test=$1
	iso_o_temps=$2
else
	echo "Modo de uso: ./tests.sh nombre_test iso_o_temps
  nombre_test:
   isotermaVsGranularidad
   isotermaVsBordes
   tiempoVsGranularidad
  iso_o_temps:
   0 = Devolver vector Isotermas
   1 = Devolver vector Temps"
	exit 1
fi

#Compilo
g++ -O2 -o base/tp base/main.cpp

#Borro resultados anteriores
rm -f testsInforme/$nombre_test/*.out

#Corro los tests con Gauss

files=./testsInforme/$nombre_test/*.in

i=1
for f in $files
do
	echo "$i"
	echo "Running $f"

	if [ $iso_o_temps -eq 0 ]
	then
		./base/tp "$f" "testsInforme/$nombre_test/testIso$i.out" 0 $iso_o_temps
	else
		./base/tp "$f" "testsInforme/$nombre_test/testTemp$i.out" 0 $iso_o_temps
	fi
	echo "OK"
	i=$((i + 1))
done
