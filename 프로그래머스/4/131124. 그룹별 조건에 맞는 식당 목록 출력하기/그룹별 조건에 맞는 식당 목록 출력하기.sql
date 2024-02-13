with TEMP as (
    select MEMBER_ID, count(*) as COUNT from REST_REVIEW
    group by MEMBER_ID
), MAX_COUNT as (
    select max(COUNT) as COUNT from temp
), FILTERED_TEMP as (
    select MEMBER_ID from temp t
    inner join MAX_COUNT m on t.COUNT = m.COUNT
)


SELECT m.MEMBER_NAME, r.REVIEW_TEXT, date_format(r.REVIEW_DATE, "%Y-%m-%d") from REST_REVIEW r
inner join MEMBER_PROFILE m on r.MEMBER_ID = m.MEMBER_ID
inner join FILTERED_TEMP f on r.MEMBER_ID = f.MEMBER_ID
order by r.REVIEW_DATE asc, r.REVIEW_TEXT asc
