Problem Title
Optimized Aggregation & Fair Distribution of Warehouse Orders (Multiple Products per Order)
Problem Statement
You have
w
warehouses (1 ≤ w ≤ 10,000).
For each warehouse:
You have
n
procurement partners.
You receive
o
orders (1 ≤ o ≤ 100).
Each order contains
c
(product, quantity) entries (where c can vary per order).
Step 1 (Aggregation):
Combine all (product, quantity) data in the warehouse to figure out the total quantity for eachunique product.
Step 2 (Distribution):
Distribute the total quantity of each product
as evenly as possible
among the n partners.
If a product’s total quantity is 1, assign it to
any one
partner.
Goal:
Provide an output that shows, for each partner, the quantities of each product they areresponsible for.
Input Format
1.
An integer
w
for the number of warehouses.
2.
For each warehouse:
An integer
n
for the number of procurement partners.
An integer
o
for the number of orders.
For each of the
o
orders:
An integer
c
, the number of (product, quantity) entries in that order.
Then
c
lines follow, each with:
A
product ID
(integer).
A
quantity
(integer).
Output Format
For each warehouse:
Print
n
lines (one per procurement partner).
Each line shows a mapping of product IDs to quantities, for example:
Partner X: {product_id1: quantity1, product_id2: quantity2, ...}
Example
Input
1 // w = 1 warehouse5 // n = 5 partners2 // o = 2 orders2 // First order has 2 (product, quantity) entries101 2101 33 // Second order has 3 (product, quantity) entries202 1303 4303 6
Aggregation
Product 101 → 2 + 3 = 5
Product 202 → 1
Product 303 → 4 + 6 = 10
Distribution (One Possible Valid Output)
Partner 1: {101: 1, 202: 1, 303: 2}Partner 2: {101: 1, 303: 2}Partner 3: {101: 1, 303: 2}Partner 4: {101: 1, 303: 2}Partner 5: {101: 1, 303: 2}
Constraints and Considerations
Up to 20 unique products per warehouse (after aggregation).
Quantities can be very large (up to 1e9).
Keep
aggregation
efficient (roughly O(total number of product entries per warehouse)).
Keep
distribution
efficient (roughly proportional to the number of unique products).
Minimize extra storage, ideally using a structure sized around the number of partners and number ofunique products
