## Auction DB

Design a Database Management System for an auction company.

```
|---------------------------------------------------------------|
|   Asset   |   Type    |   User    |   UserName    |   Price   |
|---------------------------------------------------------------|
|   A0001   |   Chair   | A Ramesh  |    a_ramesh   |    410    |
|   B0012   |   Table   |  Manish   |      m003     |   1011    |
|   A0001   |   Chair   | Pankaj J  |    j_pankaj   |    520    |
|   A0001   |   Chair   |  Suresh   |    sure002    |   1203    |
|---------------------------------------------------------------|
```

The Interface should be interactive.
- First, it should list all the products ask the auction manager which one he/she would like to view -

```
Products Listed
Chair
Table

Which product do you want to view?
```
- It should then display all the assets of that type and ask to select a specific product -

```
A0001
A0003
```
- The BDMS should then fetch the highest bidder for that product -

```
Highest Bidder for the product A0001 is -
Name - Pankaj J
Bid - 520
```
