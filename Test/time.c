#include <stdio.h>
#include <time.h>

int main() {
    time_t t = time(NULL);
    printf("Secondi dal 01/01/1970: %ld\n", t);
    printf("Anni dal 0101/1970: %ld\n", t/60/60/24/365);

    struct tm *data = localtime(&t);
    printf("data (UTC): giorno:%d mese:%d anno:%d ore:%d minuti:%d secondi:%d\n",
       data->tm_mday, data->tm_mon+1,1900+data->tm_year,
       data->tm_hour, data->tm_min, data->tm_sec);

    char* string_data = asctime(data);
    printf("data (stringa): %s\n", string_data);
}