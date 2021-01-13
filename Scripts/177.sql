CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  declare M int default N-1;
  RETURN (
      # Write your MySQL query statement below.
      
     # select IFNULL(
     select Distinct Salary from Employee order by Salary DESC limit M , 1
    #,null)
  );
END
