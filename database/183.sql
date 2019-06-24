SELECT Name Customers
FROM Customers
WHERE Id NOT IN 
(SELECT CustomerId FROM Orders);


SELECT C1.Name Customers
FROM Customers C1 LEFT JOIN Orders O1
ON C1.Id = O1.CustomerId
WHERE O1.CustomerId IS null;

