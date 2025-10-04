% Aryan Bhagat - sl5310
% Venkata Sai Krishna Aditya Vatturi - by4412

% Task 2: Get the last element of a list
last_element([X], X). 
last_element([_|Tail], X) :- 
    last_element(Tail, X).

