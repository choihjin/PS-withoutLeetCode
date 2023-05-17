SELECT history.id,
    CEIL((
        CASE
            WHEN rental_term < 7 THEN rental_term * history.fee
            WHEN rental_term < 30 THEN rental_term * (history.fee - (history.fee * (SELECT discount_rate 
                                                                                    FROM car_rental_company_discount_plan 
                                                                                    WHERE car_type = '트럭' AND duration_type = '7일 이상') / 100))
            WHEN rental_term < 90 THEN rental_term * (history.fee - (history.fee * (SELECT discount_rate 
                                                                                    FROM car_rental_company_discount_plan 
                                                                                    WHERE car_type = '트럭' AND duration_type = '30일 이상') / 100))
            ELSE rental_term * (history.fee - (history.fee * (SELECT discount_rate 
                                                              FROM car_rental_company_discount_plan 
                                                              WHERE car_type = '트럭' AND duration_type = '90일 이상') / 100))
        END
    )) AS 'FEE'
FROM (
        SELECT history.history_id AS id, car.car_type AS type
            , car.daily_fee AS fee, DATEDIFF(history.end_date, history.start_date) + 1 AS rental_term
        FROM car_rental_company_rental_history AS history
            INNER JOIN car_rental_company_car AS car ON history.car_id = car.car_id
        WHERE car.car_type = '트럭'
    ) history
ORDER BY FEE DESC, history.id DESC