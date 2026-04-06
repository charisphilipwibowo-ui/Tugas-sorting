def bubble_sort(data):
    n = len(data)
    for i in range(n):
        for j in range(0, n - i - 1):
            if data[j] > data[j + 1]:
                data[j], data[j + 1] = data[j + 1], data[j]
        print(f"Iterasi {i + 1}: {data}")
    return data

def selection_sort(data):
    n = len(data)
    for i in range(n):
        min_idx = i
        for j in range(i + 1, n):
            if data[j] < data[min_idx]:
                min_idx = j
        data[i], data[min_idx] = data[min_idx], data[i]
        print(f"Iterasi {i+1}: {data}")
    return data

def insertion_sort(data):
    for i in range(1, len(data)):
        key = data[i]
        j = i - 1
        while j >= 0 and key < data[j]:
            data[j + 1] = data[j]
            j -= 1
        data[j + 1] = key
        print(f"Iterasi {i}: {data}")
    return data

# 1. Input jumlah data
n = int(input("Masukkan jumlah data: "))

# 2. Input data ke dalam list
data_user = []
for i in range(n):
    angka = int(input(f"Data ke-{i+1}: "))
    data_user.append(angka)

# 3. Pilih algoritma dan jalankan
print("\n--- Proses Bubble Sort ---")
# Kita copy data agar data asli tidak berubah
bubble_sort(data_user.copy())

print("\n--- Proses Selection Sort ---")
selection_sort(data_user.copy())

print("\n--- Proses Insertion Sort ---")
insertion_sort(data_user.copy())