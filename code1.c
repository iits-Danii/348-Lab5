#include <stdio.h>

void monthly_sales(float arr[], int size);
void sales_summary(float arr[], int size);
void moving_average(float arr[], int size);
void sales_report(float arr[], int size);

char months[12][20] = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

int main() {
    float sales_figures[12];
    int size = 12;
    FILE *file_ptr;
    file_ptr = fopen("in.txt", "r");

    float num;
    int index = 0;

    if (file_ptr == NULL) {
        printf("Can't open file\n");
        return 1;
    }

    for (index = 0; index < 12; index++) {
        fscanf(file_ptr, "%f", &num);
        sales_figures[index] = num;
    }

    fclose(file_ptr);

    monthly_sales(sales_figures, size);
    sales_summary(sales_figures, size);
    moving_average(sales_figures, size);
    sales_report(sales_figures, size);

}

void monthly_sales(float arr[], int size) {

}

void sales_summary(float arr[], int size) {
    float max = arr[0];
    float min = arr[0];
    int fin_min = 0;
    int fin_max = 0;
    float avg = 0;
    float sum = arr[0];

    for (int index = 1; index < size+1; index++) {
        if (arr[index] > max) {
            max = arr[index];
            fin_max = index;
        }
        if (arr[index] < min) {
            min = arr[index];
            fin_min = index;

        }
    }
    for (int index = 1; index < size+1; index++){
        sum += arr[index];
    }
    avg = sum/12;

    printf("Minimum sales: %.2f (%s)\n", min, months[fin_min]);
    printf("Maximum sales: %.2f (%s)\n", max, months[fin_max]);
    printf("Average sales: %.2f\n", avg);
}

void moving_average(float arr[], int size) {

}

void sales_report(float arr[], int size) {

}
