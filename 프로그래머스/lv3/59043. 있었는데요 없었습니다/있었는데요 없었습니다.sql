-- 코드를 입력하세요
SELECT ANIMAL_ID, T1.NAME
FROM ANIMAL_INS T1 JOIN ANIMAL_OUTS T2 USING (ANIMAL_ID)
WHERE T1.DATETIME > T2.DATETIME
ORDER BY T1.DATETIME;
