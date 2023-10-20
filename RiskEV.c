#include <stdio.h>

// Function to round a double to two decimal places
double roundTwoDecimal(double num) {
    return ((int)(num * 100 + 0.5)) / 100.0;
}

// Function to calculate the probability of winning a fight
double fight(int a, int d) {
    if (a == 1) {
        if (d == 1) {
            return 0.4167;
        } else {
            return 0.2546 * fight(a, d - 1);
        }
    } else if (a == 2) {
        if (d == 1) {
            return 0.5787 + 0.4213 * fight(a - 1, d);
        } else if (d == 2) {
            return 0.1870 + 0.4054 * fight(a - 1, d - 1);
        } else {
            return 0.1870 * fight(a, d - 2) + 0.4054 * fight(a - 1, d - 1);
        }
    } else {
        if (d == 1) {
            return 0.6597 + 0.3403 * fight(a - 1, d);
        } else if (d == 2) {
            return 0.3355 + 0.4080 * fight(a - 1, d - 1) + 0.2565 * fight(a - 2, d);
        } else {
            return 0.3355 * fight(a, d - 2) + 0.4080 * fight(a - 1, d - 1) + 0.2565 * fight(a - 2, d);
        }
    }
}
double ev(int a, int d) {
    if (a == 1) {
        if (d == 1) {
            return -0.1666667;
        } else {
            return 0.2546 * ev(a, d - 1) + 0.7454 * -2;
        }
    } else if (a == 2) {
        if (d == 1) {
            return 0.5787 * 2 + 0.4213 * ev(a - 1, d);
        } else if (d == 2) {
            return 0.1870 * 2 + 0.4054 * ev(a - 1, d - 1) + 0.4076 * -2 ;
        } else {
            return 0.1870 * ev(a, d - 2) + 0.4054 * ev(a - 1, d - 1) + 0.4076 * -2;
        }
    } else {
        if (d == 1) {
            return 0.6597 * a + 0.3403 * ev(a - 1, d);
        } else if (d == 2) {
            return 0.3355 * a + 0.4080 * ev(a - 1, d - 1) + 0.2565 * ev(a - 2, d);
        } else {
            return 0.3355 * ev(a, d - 2) + 0.4080 * ev(a - 1, d - 1) + 0.2565 * ev(a - 2, d);
        }
    }
}

// Function to calculate the probability of winning the battle
double battle(int a, int d) {
    double x = fight(a, d);
    return roundTwoDecimal(x * 100);
}

int main() {
    int a, d;
    printf("Enter number of attackers: ");
    scanf("%d", &a);
    printf("Enter number of defenders: ");
    scanf("%d", &d);

    double x = battle(a, d);
    double y = ev(a,d);
    printf("The probability of the attack succeeding is %.2f%%\nENATR = %.2f\n", x, y);

    return 0;
}
