select ID, EMAIL, FIRST_NAME, LAST_NAME
    from DEVELOPERS d
    where d.SKILL_CODE & (select CODE from SKILLCODES where NAME = "Python") or d.SKILL_CODE & (select CODE from SKILLCODES where NAME = "C#")
    order by ID