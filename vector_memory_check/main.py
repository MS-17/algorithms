import matplotlib.pyplot as plt


print("Execute python script")

with open('data.txt', encoding='utf-8') as file1:
	content = file1.readlines()
# print("Content: ", content)

x = []
y = []
for i in content:
	a = i[:-1].split()
	x.append(a[0])
	y.append(a[1])

print(f'x: {x}')
print(f'y: {y}')

plt.plot(x, y)
plt.show()
