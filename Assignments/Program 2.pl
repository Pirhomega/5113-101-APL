% Corbin Matamoros
% This program will establish rules and axioms pertaining to volleyball

% define axioms
contact(pass).
contact(set).
contact(hit).
specialContact(dump).
specialContact(tip).
specialContact(downball).
legal(pass).
legal(set).
legal(hit).
play(pass, set).
play(set, hit).

% define rules
legalPlay(X,Y) :- play(X,Y).                        % all plays are legal plays
legalPlay(X,Z) :- play(X,Y),legalPlay(Y,Z).         % recursive rule to declare pass to hit is legal
illegal(X) :- not(specialContact(X)),not(legal(X)). % contact is illegal if not special nor legal
illegalPlay(Y,X) :- play(X,Y).                      % plays defined backwards are illegal
illegalPlay(Z,X) :- play(X,Y),illegalPlay(Z,Y).     % recursive rule to declare hit to pass is illegal

