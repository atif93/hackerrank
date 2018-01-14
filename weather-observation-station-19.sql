SELECT ROUND(POWER(POWER(MIN(lat_n) - MAX(lat_n), 2) + POWER(MIN(long_w) - MAX(long_w), 2), 0.5), 4) FROM station;
