with REGISTER_USER as (
    select USER_ID, JOINED from USER_INFO
    where JOINED between "2021-01-01" and "2021-12-31"
), SALES as (
    select USER_ID, year(SALES_DATE) as YEAR, MONTH(SALES_DATE) as MONTH
    from ONLINE_SALE
    group by USER_ID, YEAR, MONTH
), USER_CNT as (
    select count(*) as CNT from USER_INFO
    where JOINED between "2021-01-01" and "2021-12-31"
)




SELECT YEAR, MONTH, count(*) as PUCHASED_USERS, round(count(*) / c.CNT, 1) as PUCHASED_RATIO
from SALES s
inner join REGISTER_USER r
inner join USER_CNT c
on s.USER_ID = r.USER_ID
group by YEAR, MONTH
order by YEAR, MONTH