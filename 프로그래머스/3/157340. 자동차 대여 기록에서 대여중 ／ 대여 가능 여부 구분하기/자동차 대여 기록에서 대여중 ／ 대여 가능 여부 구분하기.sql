with USED_CAR as (
    select CAR_ID as USED_CAR_ID
        from CAR_RENTAL_COMPANY_RENTAL_HISTORY
        where START_DATE <= "2022-10-16" and END_DATE >= "2022-10-16"
)

select c.CAR_ID, if(uc.USED_CAR_ID is null, "대여 가능", "대여중") as AVAILABILITY 
    from CAR_RENTAL_COMPANY_RENTAL_HISTORY c
    left join USED_CAR uc
        on uc.USED_CAR_ID = c.CAR_ID
    group by c.CAR_ID 
    order by c.CAR_ID desc