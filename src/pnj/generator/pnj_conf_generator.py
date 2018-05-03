#!/usr/bin/env python3
from sys import argv

print("PNJ Conf files (.tlk) generator:")
name = input('name of PNJ: ')
print("[OK]: name of PNJ set --> %s" % name)
text = input('Text of PNJ: ')
print("[OK]: text of PNJ set --> %s" % text)
dialogbox_pos = input('Position of dialog_box: ')
print("[OK]: pos of DB set --> %s" % dialogbox_pos)
file_name = input('File name: ')
print("[OK]: name of file set --> %s" % file_name)
print("------------------Generation------------------")

def str_join(*args):
	return ''.join(map(str, args))

gene = open(file_name, 'x')
g_name = str_join('name=(', name, ')', '\n')
gene.write(g_name)
g_text = str_join('text=(', text, ')', '\n')
gene.write(g_text)
g_DBpos = str_join('dialogbox_pos=(', dialogbox_pos, ')', '\n')
gene.write(g_DBpos)
g_EOF = "#end\n"
gene.write(g_EOF)
print("Generated!")
