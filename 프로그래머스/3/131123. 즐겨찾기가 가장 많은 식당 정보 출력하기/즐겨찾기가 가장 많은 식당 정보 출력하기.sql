-- 코드를 입력하세요
SELECT r.FOOD_TYPE,
(
    select _r.REST_ID from REST_INFO _r
    where r.FOOD_TYPE = _r.FOOD_TYPE
    order by _r.FAVORITES desc
    limit 1
)as REST_ID, 
(
    select _r.REST_NAME from REST_INFO _r
    where r.FOOD_TYPE = _r.FOOD_TYPE
    order by _r.FAVORITES desc
    limit 1
) as REST_NAME, 
(
    select _r.FAVORITES from REST_INFO _r
    where r.FOOD_TYPE = _r.FOOD_TYPE
    order by _r.FAVORITES desc
    limit 1
) as FAVORITES
from REST_INFO r
group by r.FOOD_TYPE
order by r.FOOD_TYPE desc



