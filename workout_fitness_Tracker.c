#include <stdio.h>

int main() {
    int tickets[5] = {500, 300, 700, 450, 600};

    double prices[5] = {12.50, 10.00, 15.00, 13.00, 11.00};
    //note to self:multiply tickets and prices
    double revenue[5];

    double total = 0;
    double average;
    int maxIndex = 0, minIndex = 0, mostTickets = 0;

    for (int i = 0; i < 5; i++) {
        revenue[i] = tickets[i] * prices[i];
        total += revenue[i];

        if (revenue[i] > revenue[maxIndex]) {
            maxIndex = i;
        }
        if (revenue[i] < revenue[minIndex]) {
            minIndex = i;
        }
        if (tickets[i] > tickets[mostTickets]) {
            mostTickets = i;
        }

        printf("Movie %d revenue: $%.2f\n", i + 1, revenue[i]);
    }
    average = total / 5;

    printf("\nTotal revenue: $%.2f\n", total);
    printf("Average revenue: $%.2f\n", average);

    printf("\nHighest revenue: Movie %d ($%.2f)\n", maxIndex + 1, revenue[maxIndex]);
    printf("Lowest revenue: Movie %d ($%.2f)\n", minIndex + 1, revenue[minIndex]);
    printf("Most tickets sold: Movie %d (%d tickets)\n", mostTickets + 1, tickets[mostTickets]);

    return 0;
}
