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
            printf("LINEARR[%d] IS %lf\n",i, lineArr[i]);
            printf("MIN IS %lf\n", min);
            min = lineArr[i];
        }
    }
    return min;
}

double findAverage(double lineArr[]){
    double sum = 0;
    for(int i = 0; i < 13; i++){
        sum = sum + lineArr[i];
    }
    return sum/12.0;
}

/*
TODO:
FIGURE OUT HOW TO RETURN A STRING FROM AN ARRAY
CREATE AN ARRAY OF STRINGS


WE ARE NOT MAKING IT THROUGH OUR IF
*/
const char *findMonth(double lineArr[], double value){
    static char months[12][12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"}; 
    for(int i = 0; i < 13; i++){
        if(lineArr[i] == value){
            return months[i];
        }
    }

}


void salesSummary(double lineArr[]){
    double max = findMax(lineArr);
    double min = findMin(lineArr);
    printf("%.2lf (%s)\n", min, findMonth(lineArr, min));
    printf("%.2lf (%s)\n", max, findMonth(lineArr, max));
    printf("%.2lf\n", findAverage(lineArr));
}

void monthlySales(double lineArr[]){
    static char months[12][12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"}; 
    printf("Month\t\tSales\n");
    for(int i = 0;i<12;i++){
        printf("%s\t\t%.2lf\n", months[i],lineArr[i]);
    }
}

void createReport(double lineArr[]){
    monthlySales(lineArr); //creates a list of each month and their sales
    printf("\n");
    salesSummary(lineArr); //prints, max, min, and average sales
    //sixMonthMoving(); //Finds the average of 6 month combos, jan-jun, feb-jul, mar-aug, apr-sep, may-oct, jun-nov, jul-dec
    //orderedReport(); //prints sales of each month from high to low

    printf("Final Report, press enter to exit");
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