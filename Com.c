#include <stdio.h>

int main() {
    int locks, stocks, barrels, tlocks = 0, tstocks = 0, tbarrels = 0;
    const float lprice = 45.0, sprice = 30.0, bprice = 25.0;
    float sales, comm;

    while (1) {
        printf("Enter locks (-1 to exit): ");
        scanf("%d", &locks);
        if (locks == -1) break;
        if (locks < 1 || locks > 70 || tlocks + locks > 70) {
            printf("Locks out of range or cumulative exceed limit (1-70)\n");
            continue;
        }

        printf("Enter stocks and barrels: ");
        scanf("%d %d", &stocks, &barrels);
        if (stocks < 1 || stocks > 80 || tstocks + stocks > 80 ||
            barrels < 1 || barrels > 90 || tbarrels + barrels > 90) {
            printf("Stocks (1-80) or barrels (1-90) out of range or cumulative exceed limits\n");
            continue;
        }

        tlocks += locks;
        tstocks += stocks;
        tbarrels += barrels;
    }

    if (tlocks && tstocks && tbarrels) {
        sales = tlocks * lprice + tstocks * sprice + tbarrels * bprice;
        comm = sales > 1800 ? 0.10 * 1000 + 0.15 * 800 + 0.20 * (sales - 1800)
              : sales > 1000 ? 0.10 * 1000 + 0.15 * (sales - 1000)
              : 0.10 * sales;
        printf("Total locks: %d, stocks: %d, barrels: %d\n", tlocks, tstocks, tbarrels);
        printf("Total sales: %.2f, Commission: %.2f\n", sales, comm);
    } else {
        printf("No sales recorded.\n");
    }

    return 0;
}
