-- 코드를 입력하세요
SELECT car_id, 
    MAX(CASE 
        WHEN end_date >= '2022-10-16 00:00:00'
        THEN '대여중'ELSE '대여 가능'
    END) AS AVAILABILITY
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
WHERE start_date <'2022-10-17 00:00:00'
GROUP BY car_id
ORDER BY car_id DESC;