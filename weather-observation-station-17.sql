WITH temp AS (
    SELECT long_w, lat_n FROM station WHERE lat_n > 38.7780)
SELECT ROUND(long_w, 4) FROM temp WHERE lat_n = (SELECT MIN(lat_n) FROM temp);