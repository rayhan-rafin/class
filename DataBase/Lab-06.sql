//inner
  
SELECT customers.id,customers.NAME, orders.order_id,orders.order_date
from customers
INNER JOIN ORDERS ON customers.id = orders.customer_id

//left
SELECT customers.id,customers.NAME, orders.order_id,orders.order_date
from customers
LEFT JOIN ORDERS ON customers.id = orders.customer_id;

//
