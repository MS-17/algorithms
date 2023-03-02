import matplotlib.pyplot as plt
import time
from sys import getsizeof


print("Execute python script")

with open('data.txt', encoding='utf-8') as file1:
	content = file1.readlines()


# collecting data about c++ map
elems_c = []
estimated_time_c = []
estimated_mem_size_c = []
for i in content:
	a = i[:-1].split()
	elems_c.append(a[0])
	estimated_time_c.append(a[1])
	estimated_mem_size_c.append(a[2])

print(f'elems_c: {elems_c}')
print(f'estimated_time_c: {estimated_time_c}')
print(f'estimated_mem_size_c: {estimated_mem_size_c}')



# python dict time and memory check
elems_py = []
estimated_time_py = []
estimated_mem_size_py = []
dict1 = {}
n = 1
for i in range(6):

	n = 10 ** i
	elems_py.append(n)

	t = time.perf_counter()

	for j in range(n):
		dict1[j] = j

	estimated_time_py.append((time.perf_counter() - t) * 1000)
	estimated_mem_size_py.append(getsizeof(dict1))

	dict1.clear()


print(f'elemes_py: {elems_py}')
print(f'estimated_time_py: {estimated_time_py}')
print(f'estimated_mem_size_py: {estimated_mem_size_py}')



#plotting
plt.figure(constrained_layout=True)

ax1 = plt.subplot(221)
ax1.plot(elems_c, estimated_time_c, label="estimated time")
ax1.set_xlabel("elements")
ax1.set_ylabel("millisec")
ax1.set_title("C++ map time complexity")


ax2 = plt.subplot(222)
ax2.plot(elems_c, estimated_mem_size_c, label="estimated memory size")
ax2.set_xlabel("elements")
ax2.set_ylabel("bytes")
ax2.set_title("C++ map memory usage")

ax3 = plt.subplot(223)
ax3.plot(elems_py, estimated_time_py, label="estimated time")
ax3.set_xlabel("elements")
ax3.set_ylabel("millisec")
ax3.set_title("Python map time complexity")

ax4 = plt.subplot(224)
ax4.plot(elems_py, estimated_mem_size_py, label="estimated memory size")
ax4.set_xlabel("elements")
ax4.set_ylabel("bytes")
ax4.set_title("Python map memory usage")

plt.show()