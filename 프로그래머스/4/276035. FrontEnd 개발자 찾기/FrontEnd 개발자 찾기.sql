SELECT DISTINCT id, email, first_name, last_name
FROM DEVELOPERS as D LEFT JOIN SKILLCODES as S
    ON D.SKILL_CODE & S.CODE = S.CODE
WHERE category = "Front End"
ORDER BY id;