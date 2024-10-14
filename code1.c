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

    //error checking
    if (file_ptr == NULL) {
        printf("Can't open file\n");
        return 1;
    }

    //gathers data from in.txt to store in sales figures array
    for (index = 0; index < 12; index++) {
        fscanf(file_ptr, "%f", &num);
        sales_figures[index] = num;
    }

    fclose(file_ptr);

    //calls all necessary functions
    monthly_sales(sales_figures, size);
    sales_summary(sales_figures, size);
    moving_average(sales_figures, size);
    sales_report(sales_figures, size);

}

void monthly_sales(float arr[], int size) {
    printf("Month   \tSales\n");
    for (int index = 0; index < size; index++){
        printf("%s      \t%.2f\n", months[index], arr[index]);
    }
}

void sales_summary(float arr[], int size) {
    float max = arr[0];
    float min = arr[0];
    int fin_min = 0;
    int fin_max = 0;
    float avg = 0;
    float sum = arr[0];

    //for loop and if statements determine minimum sales values and their index
    for (int index = 1; index < size; index++) {
        if (arr[index] > max) {
            max = arr[index];
            fin_max = index;
        }
        if (arr[index] < min) {
            min = arr[index];
            fin_min = index;

        }
    }
    for (int index = 1; index < size; index++){
        sum += arr[index];
    }
    avg = sum/12;

    printf("\nSales summary report:\n");
    printf("Minimum sales: %.2f (%s)\n", min, months[fin_min]);
    printf("Maximum sales: %.2f (%s)\n", max, months[fin_max]);
    printf("Average sales: %.2f\n", avg);
}

void moving_average(float arr[], int size) {
    printf("\nSix-Month moving average report:\n");
    
    //starting point for each possible iteration of 6 month period
    for (int i = 0; i <= size - 6; i++) {
        float sum = 0;
        
        //Gets the sum for a 6 month period
        for (int j = i; j < i + 6; j++) {
            sum += arr[j];
        }

        float avg = sum/6;
        printf("%s-%s: %.2f\n", months[i], months[i+5], avg);
    }
}

void sales_report(float arr[], int size) {
    float swap_sales;
    char temp_month[20];

    //bubble sort algorithm
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] < arr[j+1]) {

                swap_sales = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = swap_sales;

                //swaps months to correspond with sales values
                for (int k = 0; k < 20; k++) {
                    temp_month[k] = months[j][k];
                    months[j][k] = months[j + 1][k];
                    months[j + 1][k] = temp_month[k];
                }
            }
        }
    }

    printf("\nMonthly sales report (highest to lowest):\n");
    printf("Month   \tSales\n");
    for (int index = 0; index < size; index++) {
        printf("%s      \t%.2f\n", months[index], arr[index]);
    }
}
