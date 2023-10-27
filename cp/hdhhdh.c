#include <stdio.h>

int main() {
    int rohit_in_h, rohit_in_m, rohit_in_s;
    int rohit_out_h, rohit_out_m, rohit_out_s;
    int rahul_in_h, rahul_in_m, rahul_in_s;
    int rahul_out_h, rahul_out_m, rahul_out_s;

    // Extract hours, minutes, and seconds for Rohit's in and out times
    sscanf("09:45:56", "%d:%d:%d", &rohit_in_h, &rohit_in_m, &rohit_in_s);
    sscanf("14:45:56", "%d:%d:%d", &rohit_out_h, &rohit_out_m, &rohit_out_s);

    // Extract hours, minutes, and seconds for Rahul's in and out times
    sscanf("09:45:56", "%d:%d:%d", &rahul_in_h, &rahul_in_m, &rahul_in_s);
    sscanf("15:45:56", "%d:%d:%d", &rahul_out_h, &rahul_out_m, &rahul_out_s);

    // Calculate the total seconds for Rohit and Rahul
    int rohit_in_seconds = rohit_in_h * 3600 + rohit_in_m * 60 + rohit_in_s;
    int rohit_out_seconds = rohit_out_h * 3600 + rohit_out_m * 60 + rohit_out_s;
    int rahul_in_seconds = rahul_in_h * 3600 + rahul_in_m * 60 + rahul_in_s;
    int rahul_out_seconds = rahul_out_h * 3600 + rahul_out_m * 60 + rahul_out_s;

    // Calculate the total office duration
    int total_office_duration = (rohit_out_seconds - rohit_in_seconds) + (rahul_out_seconds - rahul_in_seconds);

    printf("%d\n", total_office_duration);

    return 0;
}
