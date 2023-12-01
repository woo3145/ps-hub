-- 코드를 입력하세요
SELECT distinct(f.FLAVOR)
    from FIRST_HALF f
    inner join JULY j
    on f.FLAVOR = j.FLAVOR
    order by (select sum(TOTAL_ORDER) from FIRST_HALF _f
        where _f.FLAVOR = f.FLAVOR
        group by _f.FLAVOR) + (select sum(TOTAL_ORDER) from JULY _j
        where _j.FLAVOR = j.FLAVOR
        group by _j.FLAVOR) desc
    limit 3
        






    
