#!/usr/bin/env python3
from sys import argv

print("Particle Conf files (.particle) generator:")
file_name = input('name of file: ')
name = input('name of Particle: ')
print("[OK]: name of particle set --> %s" % name)
nb = input('Number of particles: ')
print("[OK]: number of particles set --> %s" % nb)
lenght = input('lenght of system: ')
print("[OK]: lenght set --> %s" % lenght)
_range = input('range of the system: ')
print("[OK]: range set --> %s" % _range)
print("------------------Generation------------------")

def str_join(*args):
	return ''.join(map(str, args))

gene = open(file_name, 'x')
g_name = str_join('name=(', name, ')', '\n')
gene.write(g_name)
g_nb_particles = str_join('nb_particle=(', nb, ')', '\n')
gene.write(g_nb_particles)
g_lenght = str_join('lenght=(', lenght, ')', '\n')
gene.write(g_lenght)
gene.write("type=(explosion)\n")
gene.write("origin=(0, 0)\n")
g_range = str_join('range=(', _range, ')', '\n')
gene.write(g_range)
gene.write("min_speed=(1)\n")
gene.write("max_speed=(1)\n")
gene.write("max_R_speed=(1)\n")
gene.write("fade=(false)\n")
gene.write("p_path=()\n")
g_EOF = "#end\n"
gene.write(g_EOF)
print("Generated!")
print("DON'T FORGET TO FILL THE PATH!")
