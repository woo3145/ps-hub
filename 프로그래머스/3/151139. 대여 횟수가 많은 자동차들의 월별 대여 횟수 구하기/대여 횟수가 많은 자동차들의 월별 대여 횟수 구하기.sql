with RENTAL_COUNT as (
    select CAR_ID, count(*) as CNT from CAR_RENTAL_COMPANY_RENTAL_HISTORY
    where START_DATE between "2022-08-01" and "2022-10-31"
    group by CAR_ID
)

select month(START_DATE) as MONTH, h.CAR_ID, count(*) as RECORDS 
    from CAR_RENTAL_COMPANY_RENTAL_HISTORY h
    inner join RENTAL_COUNT rc on rc.CAR_ID = h.CAR_ID
    where START_DATE between "2022-08-01" and "2022-10-31" and rc.CNT >= 5
    group by CAR_ID, month(START_DATE)
    order by MONTH, h.CAR_ID desc