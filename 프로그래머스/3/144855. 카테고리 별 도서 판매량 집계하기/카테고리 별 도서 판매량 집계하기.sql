with S as (
    SELECT BOOK_ID, sum(SALES) as SALES
    from BOOK_SALES
    where SALES_DATE between "2022-01-01" and "2022-01-31"
    group by BOOK_ID
)

-- 코드를 입력하세요
SELECT b.CATEGORY, sum(s.SALES) as TOTAL_SALES
    from BOOk b
    inner join S s on b.BOOK_ID = s.BOOK_ID
group by CATEGORY
order by b.CATEGORY asc
