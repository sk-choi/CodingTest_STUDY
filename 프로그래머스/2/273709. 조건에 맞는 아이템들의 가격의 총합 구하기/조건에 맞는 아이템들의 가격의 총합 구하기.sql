-- 코드를 작성해주세요
SELECT SUM(T.PRICE) AS TOTAL_PRICE FROM 
(SELECT * FROM ITEM_INFO WHERE RARITY = 'LEGEND') T