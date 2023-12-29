with TOTALS as (
    Select BOOK_ID, sum(SALES) as TOTAL
    From BOOK_SALES
    where SALES_DATE between "2022-01-01" and "2022-01-31"
    group by BOOK_ID
)


-- 코드를 입력하세요
SELECT a.AUTHOR_ID, a.AUTHOR_NAME, b.CATEGORY, sum(b.PRICE * t.TOTAL) as TOTAL_SALES
    from BOOK b
    inner join AUTHOR a on b.AUTHOR_ID = a.AUTHOR_ID
    inner join TOTALS t on b.BOOK_ID = t.BOOK_ID
group by b.CATEGORY, a.AUTHOR_ID
order by a.AUTHOR_ID asc, b.CATEGORY desc