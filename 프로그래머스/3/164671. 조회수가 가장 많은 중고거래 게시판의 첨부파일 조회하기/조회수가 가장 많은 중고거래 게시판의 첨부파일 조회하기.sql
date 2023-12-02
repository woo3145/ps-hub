-- 코드를 입력하세요
SELECT concat("/home/grep/src/", b.BOARD_ID, "/", f.FILE_ID, f.FILE_NAME, f.FILE_EXT) as FILE_PATH 
    from USED_GOODS_BOARD b
    inner join USED_GOODS_FILE f
    on b.BOARD_ID = f.BOARD_ID
    where b.BOARD_ID = (select BOARD_ID from USED_GOODS_BOARD
    order by VIEWS desc
    limit 1)
    order by f.FILE_ID desc
    
    

