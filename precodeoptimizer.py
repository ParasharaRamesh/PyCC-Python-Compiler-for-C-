with open("tac.txt") as f:
	lines = f.readlines()

k = -1
for i, line in enumerate(lines[::-1]):
	if "EXIT" in line:
		exit_label = line.split()[0]
		k = i
		break

del lines[k]

with open("TAC.txt", 'w') as f:
	for line in lines:
		line = line.strip()
		if line != '':
			if line.startswith(exit_label):
				continue
			if line == "goto " + exit_label:
				f.write("goto EXIT")
				f.write('\n')
			else:
				f.write(line)
				f.write('\n')
