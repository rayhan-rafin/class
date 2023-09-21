SELECT customers.name FROM customers INNER JOIN orders ON customers.id = orders.customer_id HAVING COUNT(*)>2;
SELECT orders.customer_id, COUNT(orders.order_id) AS total_orders FROM orders GROUP BY orders.customer_id order by total_orders desc;
(2 WITH NAME) SELECT customers.name, COUNT(*) FROM customers INNER JOIN orders ON customers.id = orders.customer_id GROUP BY orders.customer_id ORDER BY COUNT(*) DESC;
