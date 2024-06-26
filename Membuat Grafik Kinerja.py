import matplotlib.pyplot as plt

# Data untuk plotting
sizes = [10, 100, 500, 1000, 10000]
data_acak = {
    'Bubble Sort': [1, 54, 1459, 5535, 675813],
    'Insertion Sort': [0, 13, 281, 906, 87696],
    'Selection Sort': [1, 23, 423, 1564, 153386],
    'Merge Sort': [1, 14, 75, 193, 2111],
    'Quick Sort': [0, 10, 76, 197, 2272]
}
data_terurut_terbalik = {
    'Bubble Sort': [1, 64, 1873, 6770, 737652],
    'Insertion Sort': [0, 17, 408, 1774, 182633],
    'Selection Sort': [0, 17, 414, 1483, 160313],
    'Merge Sort': [1, 10, 68, 123, 1649],
    'Quick Sort': [1, 43, 1006, 4182, 445111]
}
data_sudah_terurut = {
    'Bubble Sort': [0, 19, 354, 1446, 167873],
    'Insertion Sort': [0, 0, 2, 4, 50],
    'Selection Sort': [0, 19, 383, 1758, 151793],
    'Merge Sort': [1, 11, 59, 148, 1377],
    'Quick Sort': [1, 71, 1581, 8369, 601150]
}

# Plotting
def plot_performance(data, title):
    for algo, times in data.items():
        plt.plot(sizes, times, marker='o', label=algo)
    plt.xlabel('Ukuran Data (N)')
    plt.ylabel('Waktu Eksekusi (µs)')
    plt.title(title)
    plt.legend()
    plt.xscale('log')
    plt.yscale('log')
    plt.grid(True)
    plt.show()

# Grafik untuk data acak
plot_performance(data_acak, 'Kinerja Algoritma pada Data Acak')

# Grafik untuk data terurut terbalik
plot_performance(data_terurut_terbalik, 'Kinerja Algoritma pada Data Terurut Terbalik')

# Grafik untuk data yang sudah terurut
plot_performance(data_sudah_terurut, 'Kinerja Algoritma pada Data yang Sudah Terurut')
