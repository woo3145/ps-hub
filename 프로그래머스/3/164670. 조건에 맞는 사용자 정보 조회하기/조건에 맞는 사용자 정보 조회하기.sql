-- 코드를 입력하세요
SELECT USER_ID, NICKNAME, concat(gu.CITY, " ",gu.STREET_ADDRESS1," ", gu.STREET_ADDRESS2) as 전체주소, 
concat(substring(gu.TLNO, 1, 3), "-", substring(gu.TLNO, 4, 4), "-", substr(gu.TLNO, 8, 4))
as 전화번호 
    from 
        (
        select WRITER_ID, count(*) as _COUNT from USED_GOODS_BOARD
        group by WRITER_ID
        ) gb
    inner join
        USED_GOODS_USER gu on gb.WRITER_ID = gu.USER_ID
where gb._COUNT >= 3
order by gu.USER_ID desc 


