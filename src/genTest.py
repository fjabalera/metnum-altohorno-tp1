#!/usr/bin/python
# coding: utf-8

from sys import argv
from random import randint
from random import seed

#Parametro 1 = Archivo de salida
#Parametro 2 = m
#Parametro 3 = n
#Parametro 4 = cantidad de instancias
# Parametro 5 (opcional) = Semilla, si no se proporciona ninguna, la semilla es "aleatoria", por lo que cada llamada al programa arrojará diferentes instancias
def main(arg = argv):
	if(len(arg) < 6):
		seed()
	else:
		seed( int(arg[5]) )

	# start y end = comienzo y final del intervalo del random respectivamente
	start_ri = 1
	end_ri = 5
	

	start_m = 10
	end_m = 40
	start_n = start_m
	end_n = end_m


	ri = randint(start_ri, end_ri)
	start_re = ri+1
	end_re = start_re+2*start_ri
	re = randint(start_re, end_re)
	m = int(arg[2])
	n = int(arg[3])


	start_temp_int = 1500
	end_temp_int = 1500

	start_temp_ext = 50
	end_temp_ext = 200


	# Deberia estar entre max de temp_int y min de temp_exte, asumo que las temperaturas internas son mayores o iguales a las externas
	start_iso = 200
	end_iso = 1500

	iso = randint(start_iso, end_iso)

	f = open(arg[1], 'w')
	f.write(  str(ri) )
	f.write(" ")
	f.write(  str(re) )
	f.write(" ")
	f.write(  str(m) )
	f.write(" ")
	f.write(  str(n) )
	f.write(" ")
	f.write(  str(iso) )
	f.write(" ")
	f.write( str(arg[4]) )
	f.write("\n")

	
	for j in range( int(arg[4]) ):

		temp_int = []
		temp_ext = []

		for i in range(n):
			temp_int.append( randint(start_temp_int, end_temp_int) )
			temp_ext.append( randint(start_temp_ext, end_temp_ext) )

		for i in range(n):
			f.write( str(temp_int[i]) )
			f.write(" ")

		for i in range(n):
			f.write( str(temp_ext[i]) )
			f.write(" ")

		f.write("\n")
	
	f.close()
				
		

if __name__ == "__main__":
    main()
