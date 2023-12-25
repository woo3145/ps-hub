with BOARD as (
    select WRITER_ID, sum(PRICE) as PRICE
    from USED_GOODS_BOARD
    where STATUS = "DONE"
    group by WRITER_ID
)



SELECT USER_ID, NICKNAME, PRICE as TOTAL_SALES 
    from USED_GOODS_USER u
    inner join BOARD b on u.USER_ID = b.WRITER_ID
    having 700000 <= PRICE
    order by PRICE asc