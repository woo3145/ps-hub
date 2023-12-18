with PRODUCT AS (
    select p.PRODUCT_ID, p.PRODUCT_NAME, p.PRICE, o.AMOUNT
    from FOOD_ORDER o
    inner join FOOD_PRODUCT p 
    on o.PRODUCT_ID = p.PRODUCT_ID
    where o.PRODUCE_DATE between "2022-05-01" and "2022-05-31"
)


SELECT p.PRODUCT_ID, p.PRODUCT_NAME, sum(p.AMOUNT) * p.PRICE as TOTAL_SALES 
from PRODUCT p
group by p.PRODUCT_ID
order by TOTAL_SALES desc, p.PRODUCT_ID asc