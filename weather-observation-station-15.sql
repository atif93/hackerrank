WITH temp AS (
    SELECT long_w, lat_n FROM station WHERE lat_n < 137.2345)
SELECT ROUND(long_w, 4) FROM temp WHERE lat_n = (SELECT MAX(lat_n) FROM temp);