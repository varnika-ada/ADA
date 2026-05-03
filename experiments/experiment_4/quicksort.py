import matplotlib.pyplot as plt
import math

array_size = []
duration = []

with open("quicksortoutput.txt", "r") as file:
    for line in file:
        parts = line.strip().split()

        if parts and parts[0].isdigit():
            array_size.append(int(parts[0]))
            duration.append(float(parts[1]))

best_case = []
avg_case = []
worst_case = []

for n in array_size:
    logn = math.log2(n)

    best_case.append(n * logn)     # O(n log n)
    avg_case.append(n * logn)      # O(n log n)
    worst_case.append(n * n)       # O(n²)

# scaling
scale = max(duration) / max(worst_case)

best_case = [x * scale for x in best_case]
avg_case = [x * scale for x in avg_case]
worst_case = [x * scale for x in worst_case]

plt.figure(figsize=(10, 6))

plt.plot(array_size,
         duration,
         marker='o',
         linewidth=3,
         label="Actual Time")

plt.plot(array_size,
         best_case,
         linestyle='--',
         linewidth=2,
         label="Best Case O(n log n)")

plt.plot(array_size,
         avg_case,
         linestyle='-.',
         linewidth=2,
         label="Average Case O(n log n)")

plt.plot(array_size,
         worst_case,
         linestyle=':',
         linewidth=3,
         label="Worst Case O(n²)")

plt.xlabel("Array Size")
plt.ylabel("Duration")
plt.title("Quick Sort Analysis")
plt.legend()
plt.grid(True)
plt.show()