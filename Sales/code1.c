/*
Phoenix Brehm
EECS 348
Th 11AM
Lab05
Goal: To take in an input file, and then generate a report, one is just a month breakdown, one shows the highest sales month, the lowest, and the average, another shows the sixmonth moving average, and another is to order them from most to least revenue
*/

#include <stdio.h>
#include <stdlib.h>

double findMax(double lineArr[]){
    double max = lineArr[0];
    for(int i = 0; i < 12; i++){
        if(lineArr[i] > max){
            max = lineArr[i];
        }
    }
    return max;
}
double findMin(double lineArr[]){
    double min = lineArr[0];
    for(int i = 0; i < 12; i++){
        if(lineArr[i] < min){
            min = lineArr[i];
        }
    }
    return min;
}

double findAverage(double lineArr[], float len){
    double sum = 0;
    for(int i = 0; i < len; i++){
        sum = sum + lineArr[i];
    }
    return sum/len;
}

const char *findMonth(double lineArr[], double value){
    static char months[12][12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"}; 
    for(int i = 0; i < 13; i++){
        if(lineArr[i] == value){
            return months[i];
        }
    }

}


void salesSummary(double lineArr[]){
    printf("Sales Summary Report");
    double max = findMax(lineArr);
    double min = findMin(lineArr);
    printf("Minimum sales: %.2lf (%s)\n", min, findMonth(lineArr, min));
    printf("Maximum sales: %.2lf (%s)\n", max, findMonth(lineArr, max));
    printf("Average sales: %.2lf\n", findAverage(lineArr, 12.0));
}

void monthlySales(double lineArr[]){
    static char months[12][12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"}; 
    printf("Month\t\tSales\n");
    for(int i = 0;i<12;i++){
        if(i != 1 && i != 8 && i != 10 && i != 11){ //standard output except Feb, Sept, Nov, Dec because they are longer names
            printf("%s\t\t%.2lf\n", months[i],lineArr[i]);
        }
        else{
            printf("%s\t%.2lf\n", months[i],lineArr[i]);
        }
    }
}

void sixMonthMoving(double lineArr[]){
    printf("Six Month Moving Average:\n");
    static char months[12][12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"}; 
    for(int i = 0;i<7;i++){
        /*lineArr[0:5]
        lineArr[1:6]
        lineArr[2:7]
        lineArr[3:8]
        lineArr[4:9]
        lineArr[5:10]
        lineArr[6:11]*/
        double lineArrMove[6];
        lineArrMove[0] = lineArr[i];
        lineArrMove[1] = lineArr[i+1];
        lineArrMove[2] = lineArr[i+2];
        lineArrMove[3] = lineArr[i+3];
        lineArrMove[4] = lineArr[i+4];
        lineArrMove[5] = lineArr[i+5];
        printf("%s-%s\t%.2lf\n", months[i], months[i+5], findAverage(lineArrMove, 6));
    }

}

void orderedReport(double lineArr[]){
    printf("Sales Report: Highest to Lowest\nMonth\t\tSales\n");

   //Go through, pick the biggest one
    double max[12];
    for(int i = 0;i<12;i++){
        max[i] = lineArr[i]; //creates a full copy of lineArr in max
    }


    for(int i = 0;i<12;i++){
        for(int j=0;j<12-i;j++){
            if(max[j] < max[j+1]){
                double temp = max[j];
                max[j] = max[j+1];
                max[j+1] = temp;
            }
        }
    }

    for(int i = 0; i<12;i++){
        if(i!= 0 && i != 1 && i != 8 && i != 9 && i != 10 && i != 11){
            printf("%s:\t\t%.2lf\n", findMonth(lineArr, max[i]),max[i]);
        }
        else{
            printf("%s:\t%.2lf\n", findMonth(lineArr, max[i]),max[i]);
        }
    }
}

void createReport(double lineArr[]){
    printf("Monthly Sales Report\n\n");
    monthlySales(lineArr); //creates a list of each month and their sales
    printf("\n");
    salesSummary(lineArr); //prints, max, min, and average sales
    printf("\n");
    sixMonthMoving(lineArr); //Finds the average of 6 month combos, jan-jun, feb-jul, mar-aug, apr-sep, may-oct, jun-nov, jul-dec
    printf("\n");
    orderedReport(lineArr); //prints sales of each month from high to low

    printf("\nFinal Report, press enter to exit");
    getchar();
}


int main(){
    printf("Name your file input.txt\nPress enter to continue");
    getchar();
    FILE* uFile = fopen("input.txt", "r");
    if(uFile == NULL){
        printf("Error: input.txt is not found.\nPress enter to exit");  
        getchar();
    }
    else{
        char lineString[100];
        double lineArr[12];
        double num;
        int i = -1;

        while(fscanf(uFile, "%lf", &num) != EOF){
            lineArr[++i] = num;
        }
        //above reads from file and puts each item in an array of doubles
        fclose(uFile);
        createReport(lineArr);
    }
}