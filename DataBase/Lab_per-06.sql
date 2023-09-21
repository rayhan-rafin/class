SELECT customers.name FROM customers
INNER JOIN orders ON customers.id = orders.customer_id
HAVING COUNT(*)>2;
