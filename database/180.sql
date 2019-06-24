SELECT 
    DISTINCT Num ConsecutiveNums 
FROM
    Logs L1
WHERE
    Num=(SELECT Num FROM Logs WHERE Id=L1.Id+1)
    AND
    Num=(SELECT Num FROM Logs WHERE Id=L1.Id+2);

