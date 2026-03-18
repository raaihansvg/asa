jumlah = int(input())
daftar_spirit = []

for i in range(jumlah):
    nama, kekuatan = input().split()
    daftar_spirit.append([nama, int(kekuatan)])


def urut_merge(data_list):
    if len(data_list) <= 1:
        return data_list

    tengah = len(data_list) // 2
    kiri = urut_merge(data_list[:tengah])
    kanan = urut_merge(data_list[tengah:])

    return gabungkan(kiri, kanan)


def gabungkan(a, b):
    hasil = []
    i = 0
    j = 0

    while i < len(a) and j < len(b):
        if a[i][1] <= b[j][1]:
            hasil.append(a[i])
            i += 1
        else:
            hasil.append(b[j])
            j += 1

    hasil += a[i:]
    hasil += b[j:]

    return hasil


spirit_urut = urut_merge(daftar_spirit)

nama_spirit = []
for item in spirit_urut:
    nama_spirit.append(item[0])

print(" ".join(nama_spirit))