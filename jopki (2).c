#include "inter.h"

int laba1(void) {
    double v, t, s, v0, v1;

    v = 3;
    t = 3;

    v0 = v / 3.6;
    v1 = 2 * v0;

    s = (v0 + v1) / 2 * t;

    printf("%.2f\n", s);
    int end;
    printf("Erofeev D.O. gr1311:\n");
    printf("Enter any number to escape:\n");
    scanf("%d",&end);
}

int laba1dop(void) {
    double v, t, s, v0, v1;

    printf("Vvedite skorost samoleta v: ");
    scanf("%lf", &v);

    printf("Vvedite vremya t: ");
    scanf("%lf", &t);

    v0 = v / 3.6;
    v1 = 2 * v0;
    s = (v0 + v1) / 2 * t;

    printf("Samolet proidet %.2f metrov po vzletno-posadochnoy polose.\n", s);
    return 0;
}

int laba2(void) {
    int N, i;
    double sum = 0.0;

    printf("Vvedite kolvo elementov N: ");
    scanf("%d", &N);

    for(i = 1; i <= N; i++){
        if (i % 2 == 1) {
            sum += (i + 2.0) / (i * (i + 1.0));
        }else{
            sum -= (i + 2.0) / (i * (i + 1.0));
        }
    }
    printf("Summa pervih %d elementov ryada: %0.2f\n", N, sum);
    int end;
    printf("Erofeev D.O. gr1311:\n");
    printf("Enter any number to escape:\n");
    scanf("%d",&end);
}

double abs(double x) {
    if (x < 0) {
        return -x;
    } else {
        return x;
    }
}

double nechetni(int i, int N, double eps) {
    double a = (i + 2.0) / (i * (i + 1.0));
    if (i > N || abs(a) < eps) {
        return 0;
    } else {
        return a + nechetni(i + 2, N, eps);
    }
}

double chetni(int i, int N, double eps) {
    double b = -((i + 2.0) / (i * (i + 1.0)));
    if (i > N || abs(b) < eps) {
        return 0;
    } else {
        return b + chetni(i + 2, N, eps);
    }
}

int laba2dop() {
    int N;
    double sum = 0.0;
    double eps = 1e-6; 

    printf("Vvedite kolvo elementov N: ");
    scanf("%d", &N);

    sum = nechetni(1, N, eps) + chetni(2, N, eps); 

    printf("Summa pervih %d elementov ryada: %0.2f\n", N, sum);

    return 0;
}

int laba3(void){
    char line[1024]; 
    int wordCount = 0;

    printf("Vvedite text postrochno (pystaya stroka dlya zaversheniya):\n");

    while (1) {
        int i = 0;
        int inWord = 0;
        int isVowel = 0;

        while ((line[i] = getchar()) != '\n' && line[i] != EOF) {
            i++;
        }

        if (line[0] == '\n' || line[0] == EOF) {
            break;
        }

        for (int j = 0; line[j] != '\0'; j++) {
            char ch = line[j];

            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) { 
                if (!inWord) {
                    inWord = 1;
                    isVowel = (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                              ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
                }
            } else {
                inWord = 0;
                isVowel = 0;
            }

            if (inWord && isVowel && j == 0) {
                wordCount++;
            }
        }
    }

    printf("Kolvo slov, nachin s glasnoy: %d\n", wordCount);
    int end;
    printf("Erofeev D.O. gr1311:\n");
    printf("Enter any number to escape:\n");
    scanf("%d",&end);
}

int laba3dop(void){
    int count[5] = {0};
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    char c;
    int inWord = 0;

    printf("Vvedite text:\n");

    while ((c = getchar()) != EOF && c != '\n') {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if (!inWord) {
                inWord = 1;
                for (int i = 0; i < 5; i++) {
                    if ((c == vowels[i]) || (c == vowels[i] - ('a' - 'A'))) {
                        count[i]++;
                    }
                }
            }
        } else {
            inWord = 0;
        }
    }

    printf("\nKolvo slov, nachin s kazhdoy glasnoy bykvi:\n");
    for (int i = 0; i < 5; i++) {
        printf("%c: %d\n", vowels[i], count[i]);
    }

    return 0;
}

int laba4() {
    char str[100];
    char result[100] = "";
    int word_count = 0;
    int odd_word_count = 0;
    int i = 0;
    int j = 0;

    printf("Vvedite stroky: ");

    while ((str[i] = getchar()) != '\n' && str[i] != EOF) {
        i++;
    }
    str[i] = '\0'; 

    while (str[j] != '\0') {
        if (str[j] != ' ' && (str[j + 1] == ' ' || str[j + 1] == '\0')) {
            word_count++;
        }
        j++;
    }

    j = 0; 

    int in_word = 0;
    while (str[j] != '\0') {
        if (str[j] == ' ') {
            in_word = 0;
            result[i++] = str[j]; 
        } else {
            if ((word_count % 2) && !in_word) {
                odd_word_count++; 
                in_word = 1; 
                word_count++; 
            }

            if (odd_word_count % 2) {
                result[i++] = str[j];
            }

            if (str[j + 1] == ' ' || str[j + 1] == '\0') { 
                word_count++; 
            }
        }
        j++;
    }

    result[i] = '\0'; 

    printf("Result: %s\n", result);
    int end;
    printf("Erofeev D.O. gr1311:\n");
    printf("Enter any number to escape:\n");
    scanf("%d",&end);
}

int laba4dop(){
    char str[100];
    char result[100] = "";
    int word_count = 0;
    int odd_word_count = 0;
    int i = 0;
    int j = 0;

    printf("Vvedite stroky: ");

    while ((str[i] = getchar()) != '\n' && str[i] != EOF) {
        i++;
    }
    str[i] = '\0'; 

    j = 0;
    while (str[j] != '\0') {
        if (str[j] != ' ' && (str[j + 1] == ' ' || str[j + 1] == '\0')) {
            word_count++;
        }
        j++;
    }

    j = 0;

    int in_word = 0; 
    while (str[j] != '\0') {
        if (str[j] == ' ') {
            in_word = 0;
            result[i++] = str[j]; 
        } else {
            if ((word_count % 2) && !in_word) {
                odd_word_count++; 
                in_word = 1; 
                word_count++; 
            }

            if (odd_word_count % 2) {
                result[i++] = str[j];
            }

            if (str[j + 1] == ' ' || str[j + 1] == '\0') { 
                word_count++; 
            }
        }
        j++;
    }

    result[i] = '\0'; 

    printf("Result: %s\n", result);
    printf("Kolvoslov v stroke: %d\n", word_count); 

    return 0;
}

int laba5() {
    int arr[10];
    int max = arr[0];
    int i;

    printf("Vvedite 10 celih chisel:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
        
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    for (i = 0; i < 10; i++) {
        if (arr[i] < 0) {
            arr[i] = arr[i] / max;
        }
    }

    printf("Izmenenniy massiv:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    int end;
    printf("Erofeev D.O. gr1311:\n");
    printf("press enter to escape:\n");
    scanf("%d",&end);
}

int laba5dop() {
    int arr[10];
    int max = arr[0];
    int min = arr[0];
    int i;

    printf("Vvedite 10 celih chisel:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    for (i = 0; i < 10; i++) {
        if (arr[i] < 0) {
            arr[i] = arr[i] / max; 
        } else if (arr[i] != min) {
            arr[i] = arr[i] / min; 
        }
    }
    printf("Izmenenniy massiv:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

int laba6() {
    int N, K;

    printf("Vvedite kolichestvo strok (N): ");
    scanf("%d", &N);

    printf("Vvedite kolichestvo stolbcov (K): ");
    scanf("%d", &K);

    int array[N][K];

    printf("Vvedite elementi massiva:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    int swapped = 1;
    int start = 0, end = N - 1;
    while (swapped) {
        swapped = 0;

        for (int i = start; i < end; i++) {
            int rowSum1 = 0, rowSum2 = 0;
            for (int j = 0; j < K; j++) {
                rowSum1 += array[i][j];
                rowSum2 += array[i + 1][j];
            }
            if (rowSum1 > rowSum2) {
                for (int j = 0; j < K; j++) {
                    int temp = array[i][j];
                    array[i][j] = array[i + 1][j];
                    array[i + 1][j];
                }
                swapped = 1;
            }
        }

        end--;

        for (int i = end; i > start; i--) {
            int rowSum1 = 0, rowSum2 = 0;
            for (int j = 0; j < K; j++) {
                rowSum1 += array[i][j];
                rowSum2 += array[i - 1][j];
            }
            if (rowSum1 < rowSum2) {
                for (int j = 0; j < K; j++) {
                    int temp = array[i][j];
                    array[i][j] = array[i - 1][j];
                    array[i - 1][j] = temp;
                }
                swapped = 1;
            }
        }

        start++;
    }

    printf("Otsortirovannuy massiv:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    printf("Erofeev D.O. gr1311:\n");
    printf("Enter any number to escape:\n");
    scanf("%d",&end);
}
	
int laba7() {
    long long N;

    printf("Vvedite dlinnoe celoe chisclo N: ");
    scanf("%lld", &N);

    int position = 0;
    while (N != 0) {
        if (N % 2 == 1) {
            break; 
        }
        position++;
        N /= 2; 
    }

    printf("Polozhenie starshey edinizi: %d\n", position);

    return 0;
}