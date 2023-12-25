with REVIEW as (
    Select REST_ID, round(avg(REVIEW_SCORE), 2) as SCORE
    From REST_REVIEW
    group by REST_ID
)



-- 코드를 입력하세요
SELECT i.REST_ID, REST_NAME, FOOD_TYPE, sum(FAVORITES) as FAVORITES, ADDRESS, SCORE
    from REST_INFO i
    inner join REVIEW r on i.REST_ID = r.REST_ID
    where ADDRESS like '서울%'
    group by i.REST_ID
    order by SCORE desc, FAVORITES desc