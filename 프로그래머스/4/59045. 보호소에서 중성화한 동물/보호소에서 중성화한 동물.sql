with IN_TABLE as (
    select * from ANIMAL_INS i
    where i.SEX_UPON_INTAKE like "Intact%"
)



-- 코드를 입력하세요
SELECT i.ANIMAL_ID, i.ANIMAL_TYPE, i.NAME
from IN_TABLE i
inner join ANIMAL_OUTS o on i.ANIMAL_ID = o.ANIMAL_ID
where o.SEX_UPON_OUTCOME like 'SPAYED%' or o.SEX_UPON_OUTCOME like 'Neutered%'
order by i.ANIMAL_ID asc