# Write your MySQL query statement below
SELECT Score as score, DENSE_RANK() OVER(ORDER BY Score desc) `Rank` FROM Scores ORDER BY `Rank`;