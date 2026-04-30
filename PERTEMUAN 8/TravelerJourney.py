import heapq
#Raihan Lazuardi
#24060124140178
#B2
def main():
    banyakBaris, banyakKolom = map(int, input().split())

    peta = []
    for i in range(banyakBaris):
        peta.append(input())

    barisTraveler, kolomTraveler = -1, -1
    barisTujuan,   kolomTujuan   = -1, -1

    for i in range(banyakBaris):
        for j in range(banyakKolom):
            if peta[i][j] == 'T':
                barisTraveler = i
                kolomTraveler = j
            if peta[i][j] == 'D':
                barisTujuan = i
                kolomTujuan = j

    def hitungHeuristik(baris, kolom):
        return abs(baris - barisTujuan) + abs(kolom - kolomTujuan)

   
    antrianPrioritas = []
    nilaiFAwal = hitungHeuristik(barisTraveler, kolomTraveler)
    heapq.heappush(antrianPrioritas, (nilaiFAwal, 0, barisTraveler, kolomTraveler))

    biayaDariAwal = [[float('inf')] * banyakKolom for _ in range(banyakBaris)]
    biayaDariAwal[barisTraveler][kolomTraveler] = 0

    arahGerak = [(-1, 0), (1, 0), (0, -1), (0, 1)]

    while antrianPrioritas:
        nilaiF, nilaiG, barisSaat, kolomSaat = heapq.heappop(antrianPrioritas)

        if barisSaat == barisTujuan and kolomSaat == kolomTujuan:
            print(nilaiG)
            return

        if nilaiG > biayaDariAwal[barisSaat][kolomSaat]:
            continue

        for gerakBaris, gerakKolom in arahGerak:
            barisBerikut = barisSaat + gerakBaris
            kolomBerikut = kolomSaat + gerakKolom

            if barisBerikut < 0 or barisBerikut >= banyakBaris:
                continue
            if kolomBerikut < 0 or kolomBerikut >= banyakKolom:
                continue
            if peta[barisBerikut][kolomBerikut] == '#':
                continue

            biayaBaru = nilaiG + 1
            if biayaBaru < biayaDariAwal[barisBerikut][kolomBerikut]:
                biayaDariAwal[barisBerikut][kolomBerikut] = biayaBaru
                nilaiFBaru = biayaBaru + hitungHeuristik(barisBerikut, kolomBerikut)
                heapq.heappush(antrianPrioritas, (nilaiFBaru, biayaBaru, barisBerikut, kolomBerikut))

    print(-1)

main()