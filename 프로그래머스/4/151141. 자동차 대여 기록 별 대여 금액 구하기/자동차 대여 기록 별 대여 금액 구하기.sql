select 
    aaa.HISTORY_ID, ((ccc.DAILY_FEE - floor(ccc.DAILY_FEE * aaa.DISCOUNT_RATE / 100)) * aaa.DIFF) as FEE 
from
    CAR_RENTAL_COMPANY_CAR ccc
left join 
    (
    select 
        ch.HISTORY_ID, ch.CAR_ID, datediff(h.END_DATE, h.START_DATE)+1 as DIFF,
        case when 0 <= cp.DISCOUNT_RATE then cp.DISCOUNT_RATE 
        else 0 end as DISCOUNT_RATE
    from 
        CAR_RENTAL_COMPANY_RENTAL_HISTORY h
    left join 
        (
        select _h.HISTORY_ID, _h.CAR_ID,
            case when datediff(_h.END_DATE, _h.START_DATE)+1 < 7 then 0
            when datediff(_h.END_DATE, _h.START_DATE)+1 between 7 and 29 then 7
            when datediff(_h.END_DATE, _h.START_DATE)+1 between 30 and 89 then 30
            when datediff(_h.END_DATE, _h.START_DATE)+1 >=90 then 90 end as DATE 
         from 
            CAR_RENTAL_COMPANY_RENTAL_HISTORY _h) ch on h.HISTORY_ID = ch.HISTORY_ID
    left join (
        select _p.CAR_TYPE,
            case when _p.DURATION_TYPE="7일 이상" then 7
            when _p.DURATION_TYPE="30일 이상" then 30
            when _p.DURATION_TYPE="90일 이상" then 90 end as DATE, _p.DISCOUNT_RATE
            from CAR_RENTAL_COMPANY_DISCOUNT_PLAN _p
            where _p.CAR_TYPE ="트럭") cp on cp.DATE = ch.DATE
    ) aaa on ccc.CAR_ID = aaa.CAR_ID
where 
    ccc.CAR_TYPE = "트럭"
order by FEE desc, aaa.HISTORY_ID desc





#