-- 코드를 입력하세요
SELECT author_id, author_name, category, SUM(price * sales) AS total_sales
FROM book JOIN book_sales USING(book_id) JOIN author USING(author_id)
WHERE SALES_DATE >= '2022-01-01 00:00:00' AND SALES_DATE <'2022-02-01 00:00:00'
GROUP BY author_id, category
ORDER BY author_id, author_name, category DESC;