import re


nodes = {}

file_name = "./netlist.dspf"

def func_reg(file_name, fileregular_exp):
	"""
	Функция итератор по файлу с именем file_name,
	в каждой строчке при нахождении паттерна отправляет результат 
	"""
	file = open(file_name)
	for line in file.readlines():
		result = re.findall(fileregular_exp, line)
		if (len(result)):
			yield result[0]

"""
Записываем в словарь информацию об именнах узлов
"""
for instanse_name, name in func_reg(file_name, r"^(\w+).+?name=(.+)$"):
	nodes[instanse_name] = name

"""
Выводим сопротивление паразитного резистора
"""
for left, right, value in func_reg(file_name, r"^\w+? (.+?)\:\w+ (.+?)\:.+? ([\d\.]+)"):
	if ((left in nodes) and (right in nodes) and nodes[left] == nodes[right]):
		print(nodes[left], value, sep="\t\t")
