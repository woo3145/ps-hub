-- 코드를 입력하세요
SELECT p.PRODUCT_CODE as PRODUCT_CODE, p.PRICE * (
select sum(SALES_AMOUNT) from OFFLINE_SALE
    where PRODUCT_ID = p.PRODUCT_ID
) as SALES 
    from PRODUCT p
    inner join OFFLINE_SALE o
    on p.PRODUCT_ID = o.PRODUCT_ID
    group by o.PRODUCT_ID
    order by SALES desc, p.PRODUCT_CODE asc

