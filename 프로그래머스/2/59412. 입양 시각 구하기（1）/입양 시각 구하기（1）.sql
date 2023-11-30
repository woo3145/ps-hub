-- 코드를 입력하세요
SELECT hour(DATETIME) as HOUR, count(DATETIME) as COUNT from ANIMAL_OUTS
    where hour(DATETIME) between 9 and 20
    group by hour(DATETIME)
    order by hour(DATETIME) asc
