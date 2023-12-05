with recursive TIME as (
    select 0 as HOUR
    union all
    select HOUR + 1
    from TIME
    where HOUR < 23
)


SELECT t.HOUR as HOUR, count(o.ANIMAL_ID) as COUNT
    from TIME t
    left join ANIMAL_OUTS o on hour(o.DATETIME) = t.HOUR
    group by t.HOUR
    order by t.HOUR