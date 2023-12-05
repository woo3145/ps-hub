with US as (
    select * from USER_INFO
    where GENDER is not null
), OS as (
    select * from ONLINE_SALE
    group by month(SALES_DATE), USER_ID
)

SELECT year(os.SALES_DATE) as YEAR, month(os.SALES_DATE) 
    as MONTH, GENDER as GENDER, count(*) as USERS
from OS os
inner join US u on os.USER_ID = u.USER_ID
group by YEAR, MONTH, GENDER
order by YEAR, MONTH, GENDER