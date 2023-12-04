# -- 코드를 입력하세요
SELECT ap.APNT_NO, 
    (select _p.PT_NAME from PATIENT _p
        where ap.PT_NO = _p.PT_NO
    ) as PT_NAME
, ap.PT_NO, ap.MCDP_CD, 
    (select _d.DR_NAME from DOCTOR _d
        where ap.MDDR_ID = _d.DR_ID
    ) as DR_NAME
    , ap.APNT_YMD
from 
    (
    select APNT_NO, PT_NO, MCDP_CD, MDDR_ID, APNT_YMD from APPOINTMENT
        where APNT_YMD between '2022-04-13' and "2022-04-14" 
            and MCDP_Cd = "CS" and APNT_CNCL_YMD is null
    ) as ap
order by ap.APNT_YMD