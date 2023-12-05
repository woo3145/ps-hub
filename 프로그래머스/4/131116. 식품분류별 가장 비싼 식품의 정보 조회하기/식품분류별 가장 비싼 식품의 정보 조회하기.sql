-- 코드를 입력하세요
SELECT f.CATEGORY, tb.MAX_PRICE, f.PRODUCT_NAME 
from FOOD_PRODUCT f
inner join (
    select CATEGORY, max(PRICE) as MAX_PRICE from FOOD_PRODUCT
    group by CATEGORY
) tb
where f.CATEGORY in ('과자', '국', '김치', '식용유') and tb.CATEGORY = f.CATEGORY and tb.MAX_PRICE = f.PRICE
order by tb.MAX_PRICE desc



