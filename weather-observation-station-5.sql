WITH max_ids AS (
    SELECT id FROM station WHERE LENGTH(city) = (SELECT MAX(LENGTH(city)) from station) ORDER BY city),
    max_id AS (
        SELECT id FROM max_ids WHERE ROWNUM <= 1),
    min_ids AS (
    SELECT id FROM station WHERE LENGTH(city) = (SELECT MIN(LENGTH(city)) from station) ORDER BY city),
    min_id AS (
        SELECT id FROM min_ids WHERE ROWNUM <= 1)
SELECT city, LENGTH(city) FROM station, max_id, min_id WHERE max_id.id = station.id OR min_id.id = station.id;