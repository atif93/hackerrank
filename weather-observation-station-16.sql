WITH temp AS (
    SELECT lat_n FROM station WHERE lat_n > 38.7780)
SELECT ROUND(lat_n, 4) FROM temp WHERE lat_n = (SELECT MIN(lat_n) FROM temp);