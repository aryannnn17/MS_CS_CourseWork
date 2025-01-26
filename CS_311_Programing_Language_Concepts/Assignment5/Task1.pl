% Aryan Bhagat - sl5310
% Venkata Sai Krishna Aditya Vatturi - by4412

sister(X, Y) :-
    parent(P, X), % P is a parent of X
    parent(P, Y), % P is a parent of Y
    female(X),    % X is female
    X \= Y.       % X and Y are not the same person


parent(aryan, mary).
parent(aryan, anna).
parent(aryan, mike).
parent(dev, mary).
parent(dev, anna).
parent(dev, mike).
female(mary).
female(anna).
male(mike).