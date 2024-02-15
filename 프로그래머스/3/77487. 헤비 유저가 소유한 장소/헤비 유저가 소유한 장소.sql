with COUNTING as (
    select HOST_ID ,count(*) as COUNT from PLACES
    group by HOST_ID
    having 1 < COUNT
)

SELECT p.ID, p.NAME, p.HOST_ID from PLACES p
inner join COUNTING c on p.HOST_ID = c.HOST_ID
order by p.ID