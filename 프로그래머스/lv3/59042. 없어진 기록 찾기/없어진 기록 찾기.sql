-- 코드를 입력하세요
SELECT T2.ANIMAL_ID, T2.NAME
FROM ANIMAL_INS T1 RIGHT JOIN ANIMAL_OUTS T2 USING (ANIMAL_ID)
WHERE T1.NAME IS NULL
    AND T2.NAME IS NOT NULL