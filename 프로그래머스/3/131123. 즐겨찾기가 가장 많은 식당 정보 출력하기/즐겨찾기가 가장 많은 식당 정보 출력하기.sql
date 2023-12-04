-- 코드를 입력하세요
SELECT r.FOOD_TYPE, r.REST_ID, r.REST_NAME, r.FAVORITES
from 
    REST_INFO r
inner join 
    (
        select FOOD_TYPE, max(FAVORITES) as MAX_FAVORITES from REST_INFO
        group by FOOD_TYPE
    ) mf on mf.MAX_FAVORITES = r.FAVORITES
group by r.FOOD_TYPE
order by r.FOOD_TYPE desc



