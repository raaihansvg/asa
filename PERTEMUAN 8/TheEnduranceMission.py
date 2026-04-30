import heapq

def main():
    jumlahSistem, jumlahJalur = map(int, input().split())
    namaSistemAwal, namaSistemTujuan = input().split()

    indeksSistem = {}
    penghitung = [0]

    def ambilIndeks(nama):
        if nama not in indeksSistem:
            indeksSistem[nama] = penghitung[0]
            penghitung[0] += 1
        return indeksSistem[nama]

    ambilIndeks(namaSistemAwal)
    ambilIndeks(namaSistemTujuan)

    daftarTetangga = {}

    for _ in range(jumlahJalur):
        bagian = input().split()
        sistemU = bagian[0]
        sistemV = bagian[1]
        bobotWaktu = int(bagian[2])

        indeksU = ambilIndeks(sistemU)
        indeksV = ambilIndeks(sistemV)

        if indeksU not in daftarTetangga:
            daftarTetangga[indeksU] = []
        if indeksV not in daftarTetangga:
            daftarTetangga[indeksV] = []

        daftarTetangga[indeksU].append((indeksV, bobotWaktu))
        daftarTetangga[indeksV].append((indeksU, bobotWaktu))

    indeksAwal   = indeksSistem[namaSistemAwal]
    indeksTujuan = indeksSistem[namaSistemTujuan]
    totalSistem  = penghitung[0]

    jarakTerpendek = [float('inf')] * totalSistem
    jarakTerpendek[indeksAwal] = 0

    antrianPrioritas = []
    heapq.heappush(antrianPrioritas, (0, indeksAwal))

    while antrianPrioritas:
        jarakSekarang, sistemSekarang = heapq.heappop(antrianPrioritas)

        if jarakSekarang > jarakTerpendek[sistemSekarang]:
            continue

        if sistemSekarang not in daftarTetangga:
            continue

        for tetangga, bobot in daftarTetangga[sistemSekarang]:
            jarakBaru = jarakTerpendek[sistemSekarang] + bobot
            if jarakBaru < jarakTerpendek[tetangga]:
                jarakTerpendek[tetangga] = jarakBaru
                heapq.heappush(antrianPrioritas, (jarakBaru, tetangga))

    if jarakTerpendek[indeksTujuan] == float('inf'):
        print(-1)
    else:
        print(jarakTerpendek[indeksTujuan])

main()