#include <stdio.h>

int get_string_size(char *s) {
    int size;
    for (size = 0; s[size] != '\0'; size++) {
    }

    return size;
}

void inverter(char *s) {
    int t = get_string_size(s);

    char aux[10012];

    int j = 0;
    for (int i = t - 1; i >= 0; i--) {
        aux[j] = s[i];
        j++;
    }

    for (int i = 0; i < t; i++)
        s[i] = aux[i];
}

void deslocar(char *s, int n) {
    n = n % 26;

    char c;

    int i;
    for (i = 0; s[i] != '\0'; i++) {
        c = s[i];

        if ('a' <= c && c <= 'z') {
            s[i] = c + n <= 'z' ? c + n : c + n - 26;
        }

        if ('A' <= c && c <= 'Z') {
            s[i] = c + n <= 'Z' ? c + n : c + n - 26;
        }

        if ('0' <= c && c <= '9') {
            s[i] = c + n <= '9' ? c + n : c + n - 10;
        }
    }
}

void trocarParesImpares(char *s) {
    int t = get_string_size(s);
    char aux[10012];
    if (t % 2 != 0) {
        for (int i = 0; i < t - 2; i += 2) {
            aux[i] = s[i];
            s[i] = s[i + 1];
            s[i + 1] = aux[i];
        }
    }
    else {
        for (int i = 0; i < t - 1; i += 2) {
            aux[i] = s[i];
            s[i] = s[i + 1];
            s[i + 1] = aux[i];
        }
    }
}

void inverterCaixa(char *s) {
    char c;

    int i;
    for (i = 0; s[i] != '\0'; i++) {
        c = s[i];

        if ('a' <= c && c <= 'z') {
            s[i] += 'A' - 'a';
        }

        if ('A' <= c && c <= 'Z') {
            s[i] += 'a' - 'A';
        }
    }
}

void rotacionar(char *s, int n) {
    int size = get_string_size(s);

    n = n % size;

    char tmp[size];

    int i;
    for (i = 0; i < size; i++) {
        tmp[i] = s[i];
    }

    for (i = 0; i < size; i++) {
        if (i + n < 0) {
            s[i + n + size] = tmp[i];
        }

        else if (i + n <= size - 1) {
            s[i + n] = tmp[i];
        }

        else {
            s[i + n - size] = tmp[i];
        }
    }
}

void trocarMetades(char *s) {
    int size = get_string_size(s);

    char tmp;

    int i, j;
    for (i = 0; i < size / 2; i++) {
        j = size - size / 2 + i;

        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

int main(void) {
    int n;
    char s[10000] = "";

    scanf("%[^\n]", s);

    int op;
    while (1) {
        scanf("%d", &op);

        switch (op) {
        case 1:
            inverter(s);

            break;
        case 2:
            scanf("%d", &n);

            deslocar(s, n);

            break;
        case 3:
            trocarParesImpares(s);

            break;
        case 4:
            inverterCaixa(s);

            break;
        case 5:
            scanf("%d", &n);

            rotacionar(s, n);

            break;
        case 6:
            trocarMetades(s);

            break;
        case 0:
            printf("%s\n", s);

            return 0;
        }
    }

    printf("%s\n", s);

    return 0;
}